#!/bin/bash
echo -n "Enter 1st number:-"
read a
echo -n "Enter 2nd number:-"
read b
echo -n "Enter 3rd number:-"
read c
((c=a+b+c))
echo "Sum is " $c 
