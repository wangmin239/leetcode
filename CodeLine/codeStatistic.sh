#! /bin/bash


for file in $(find ../ -type f -name "*.cpp"); do
    line=$(wc -l $file)
    echo $line
done | tee loc.txt

awk 'BEGIN{sum = 0} END{printf "Total line num is %d\n", sum} {printf "%-6d + %-3d = %-6d\n", sum, $1, sum + $1; sum = sum + $1}' loc.txt