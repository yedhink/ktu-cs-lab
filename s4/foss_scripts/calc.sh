#!/bin/bash
echo "CALCULATOR"
echo -n 1st no:- ; read a
echo -n 2nd no:- ; read b
select op in "+" "-" "*" "/" "end"
do
	case $op in
	"+")
	((c=a+b))
	echo Sum is $c
	;;
	"-")
	((c=a-b))
	echo Subtracted is $c
	;;
	"/")
	((c=a/b))
	echo Quotient is $c
	;;
	"*")
	((c=a*b))
	echo Product is $c
	;;
	"end")
	echo "Exiting..."
	exit
	;;
	*)
	echo Default value is 0
	;;
	esac
done
