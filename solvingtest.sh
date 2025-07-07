#!/bin/bash
# bash script to automate testing of backtracking

# echo "pATH: $PATH"

i=1
for file in puzzles/*; do
    if [[ -f $file ]]
        then
            echo $file
            ./sudoku $file > output/puzzle$i.out
            diff output/puzzle$i.out solutions/puzzle$i.gt
            # diff output/puzzle$i.out output/puzzle$i.out
            let i=i+1
        fi
    
done
