#pragma once

#include <atomic>
#include <vector>
/*
    read1 read2
    read_index_

    write1 write2
    write_index_

    read write

*/
template <typename T, size_t N = 1024>
class LockFreeQueue
{
public:
    struct Element
    {
        std::atomic<bool> full_;
        T data_;
    };

    LockFreeQueue(): data_(N)
    {
        read_index_ = 0;
        write_index_ = 0;
    }

    // write_index_ == read_index_ + data_.size()
    bool Enqueue(T value)
    {
        size_t write_index = 0;
        Element* e = NULL;
        do
        {
            write_index = write_index_.load(std::memory_order_relaxed);
            if (write_index >= read_index_.load(std::memory_order_relaxed) + data_.size())
            {
                return false;
            }
            size_t index = write_index  % data_.size();
            e = &data_[index];
            if (e->full_.load(std::memory_order_relaxed))
            {
                return false;
            }
        } while (!write_index_.compare_exchange_weak(write_index, write_index + 1, std::memory_order_release, std::memory_order_relaxed));

        e->data_ = std::move(value);
        e->full_.store(true, std::memory_order_release);
        return true;
    }

    bool Dequeue(T& value)
    {
        size_t read_index = 0;
        Element* e = NULL;
        do
        {
            read_index = read_index_.load(std::memory_order_relaxed);
            if (read_index >= write_index_.load(std::memory_order_relaxed))
            {
                return false;
            }
            size_t index = read_index % data_.size();
            e = &data_[index];
            if (!e->full_.load(std::memory_order_relaxed))
            {
                return false;
            }
        } while (!read_index_.compare_exchange_weak(read_index, read_index + 1, std::memory_order_release, std::memory_order_relaxed));
        value = std::move(e->data_);
        e->full_.store(false, std::memory_order_release);
        return true;
    }

private:
    std::vector<Element> data_;
    std::atomic<size_t> read_index_;
    std::atomic<size_t> write_index_;
};
