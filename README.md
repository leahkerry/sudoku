# Epic Sudoku Puzzle Generator
https://leahkerry.github.io/sudoku-website/
### I LOVE SUDOKU! 
So, I wanted to dig deeper and find out how they are generated. I wanted to program the algorithm in my favorite language, C++, and I wanted to make it an online playable game as well. 
Putting both of these goals into account, this gave me the opportunity to expand my knowledge in API creation, DockerFiles, shell scripting, and pybind. 

Here's how I did it...
## 1: Generate a board in C++
* Using memoization and backtracking, generate how many options you have 
* Remove squares at random from a randomly generated board (as longs as ways to solve < 2)
* Remove certain amount of squares as long as this condition is true
* Dont try same squares twice
Testing: 
* Python script to read in all of csv to test
* Shell script to loop through each puzzle test and compare against ground truth

## 2: Generate a board in C++


## Continuation:
Generate different difficulties based on an intelligent model
* ML model in python using kaggle dataset? 
* Look at different patterns in python 


