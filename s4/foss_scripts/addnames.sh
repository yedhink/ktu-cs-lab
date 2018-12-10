#!/bin/bash
echo Usage:./26-02-18.sh classlist username

if (( $# == 2 ))
then
	echo correct number of args
else
	echo Incorrect number of args
fi


if [[ -f "$1" ]]
then
	echo Classlist file exist
else
	echo Classlist file doesnt exist
	exit
fi

grep -q $2 $1 
status=$?
if (( status==0 ))
then
	echo Username already exist in file
else
	echo $2 >> $1
	echo Appended username to file
fi
