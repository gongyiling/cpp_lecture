#!/bin/bash

# NAME: set-hyper-threading
# PATH: /usr/local/bin
# DESC: Turn Hyper threading off or on.

# DATE: Aug. 5, 2017.

# NOTE: Written Part of testing for Ubuntu answer:
#       https://askubuntu.com/questions/942728/disable-hyper-threading-in-ubuntu/942843#942843

# PARM: 1="0" turn off hyper threading, "1" turn it on.

if [[ $# -ne 1 ]]; then
    echo 'One argument required. 0 to turn off hyper-threading or'
    echo '1 to turn hyper-threading back on'
    exit 1
fi

echo $1 > /sys/devices/system/cpu/cpu1/online
echo $1 > /sys/devices/system/cpu/cpu3/online
echo $1 > /sys/devices/system/cpu/cpu5/online
echo $1 > /sys/devices/system/cpu/cpu7/online

grep "" /sys/devices/system/cpu/cpu*/topology/core_id

grep -q '^flags.*[[:space:]]ht[[:space:]]' /proc/cpuinfo && \
    echo "Hyper-threading is supported"

grep -E 'model|stepping' /proc/cpuinfo | sort -u

