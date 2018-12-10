#!/bin/bash
echo -n "Kernel Version "; uname -v
echo "OS Details:-"
cat /etc/os-release;uname -v
echo
echo "Avalable Shells:-"
cat /etc/shells
echo "Mouse setting:-"
Xinput --list-props 2
echo "Cpu info:-"
cat /proc/cpuinfo
echo "Memory info:-"
cat /proc/meminfo
echo "Hard Disk info:-"
cat /proc/diskstats
echo "Mounted Filesystem info:-"
cat /proc/mounts
