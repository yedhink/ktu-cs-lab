#!/bin/bash
ps -e | awk '$1<1000{print $1,$4}' | awk '$1>100{print}'
