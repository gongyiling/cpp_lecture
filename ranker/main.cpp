
#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/indexed_by.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/ranked_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/node_allocator.hpp>

namespace bmi = boost::multi_index;
namespace bi = boost::interprocess;

typedef bi::managed_shared_memory managed_shared_memory_t;

struct rank_info
{
    uint32_t uid;
    uint32_t score;
    char name[16];
};

typedef bi::node_allocator<rank_info, managed_shared_memory_t::segment_manager> node_allocator_t;

struct tag_uid{};
struct tag_score{};

typedef bmi::multi_index_container<rank_info,
    bmi::indexed_by<
        bmi::ordered_unique<bmi::tag<tag_uid>, bmi::member<rank_info, uint32_t, &rank_info::uid> >,
        bmi::ranked_non_unique<bmi::tag<tag_score>, bmi::member<rank_info, uint32_t, &rank_info::score>, std::greater<uint32_t> >
    >,
    node_allocator_t
> container_t;

void gen_rand_name(char name[16])
{
    snprintf(name, 16, "%04x%04x%04x", rand() & 0xffff, rand() & 0xffff, rand() & 0xffff);
}

void insert_data(container_t& c, int n)
{
    for (int i = 0; i < n; i++)
    {
        rank_info info;
        info.uid = i;
        info.score = rand();
        auto pr = c.insert(info);
        gen_rand_name(const_cast<char*>(pr.first->name));
    }
}

std::vector<const rank_info*> get_ranks(const container_t& c, int start_rank, int count)
{
    std::vector<const rank_info*> ranks;
    if (count <= 0)
    {
        return ranks;
    }
    auto& index = c.get<tag_score>();
    ranks.reserve(count);
    for (auto it = index.nth(start_rank); it != index.end() && count-- > 0; ++it)
    {
        ranks.push_back(&(*it));
    }
    return ranks;
}

uint32_t get_rank_by_uid(const container_t& c, uint32_t uid)
{
    const auto& uid_index = c.get<tag_uid>();
    auto it = uid_index.find(uid);
    if (it == uid_index.end())
    {
        return -1;
    }
    const auto& score_index = c.get<tag_score>();
    return score_index.rank(c.project<tag_score>(it));
}

void modify_score(container_t& c, uint32_t uid, uint32_t score)
{
    auto& uid_index = c.get<tag_uid>();
    auto it = uid_index.find(uid);
    if (it == uid_index.end())
    {
        return;
    }
    c.modify(it, [score](rank_info& info){info.score = score;});
}

int main()
{
    static const int DATA_SIZE = 1000000;
    static const int MEMORY_SIZE = DATA_SIZE * sizeof(rank_info) * 10;
    managed_shared_memory_t shared_memory(bi::open_or_create, "__Ranker__", MEMORY_SIZE);
    node_allocator_t alloc(shared_memory.get_segment_manager());
    container_t* c = shared_memory.find_or_construct<container_t>("__Ranker__")(alloc);
    if (c->empty())
    {
        insert_data(*c, DATA_SIZE);
    }
    printf("free memory: %ld\n", shared_memory.get_free_memory());

    std::vector<const rank_info*> ranks = get_ranks(*c, 0, 100);
    for (size_t i = 0; i < ranks.size(); i++)
    {
        printf("%d\t%d\t%s\n", ranks[i]->score, ranks[i]->uid, ranks[i]->name);
    }
    printf("uid 41, rank: %d\n", get_rank_by_uid(*c, 41));
    modify_score(*c, 41, 2147481194 + 1);
    printf("uid 41, after modify rank: %d\n", get_rank_by_uid(*c, 41));
    ranks = get_ranks(*c, 0, 100);
    for (size_t i = 0; i < ranks.size(); i++)
    {
        printf("%d\t%d\t%s\n", ranks[i]->score, ranks[i]->uid, ranks[i]->name);
    }
    return 0;
}
