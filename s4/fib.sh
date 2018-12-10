#!/bin/bash
prev="0"
next="1"
sum="0"
echo -n "Enter limit: "
read limit
for (( i=0; i < limit; i=i+1 )); do
	echo $sum
	(( sum = $prev + $next ))
	(( prev = $next ))
	(( next = $sum ))
done
