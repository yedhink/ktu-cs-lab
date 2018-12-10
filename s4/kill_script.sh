#!/bin/bash
read -p "Enter cpu %= " a
read -p "Enter mem %= " b
ps -Aeo pcpu=,pmem=,pid=,comm= --sort=-pcpu |
while read cpu mem pid comm
do
	echo $pid $comm
	if (( $(echo "$cpu > $a" |bc -l) ||	$(echo "$mem > $b" |bc -l) ))
	then
	echo $pid $comm
fi
done
