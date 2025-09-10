# Epic Sudoku Puzzle Generator
https://leahkerry.github.io/sudoku-website/
### I LOVE SUDOKU! 
So, I wanted to dig deeper and find out how they are generated. I wanted to program the algorithm in my favorite language, C++, and I wanted to make it an online playable game as well. 

You may be thinking, "Why would you not just make the sudoku algorithm in javascript and make it so much easier to fetch on a webpage?" You're right that would've been so much simpler. I knew I wanted to code in C++, but I learned so many tools. This gave me the opportunity to expand my knowledge in API creation, DockerFiles, shell scripting, and pybind. 

Workflow
## 1: Generate a board in C++
* Using memoization and backtracking, generate how many options you have 
* Remove squares at random from a randomly generated board (as longs as ways to solve < 2)
* Remove certain amount of squares as long as this condition is true
* Dont try same squares twice
Testing: 
* Python script to read in all of csv to test
* Shell script to loop through each puzzle test and compare against ground truth

## 2: Bind C++ code to Python API code
* APIs created in python are a lot simpler, so I used the PyBind11 module to achieve this. 
* Created a simple module to bind C++ board generation function to python code.
* Created API endpoints for Python file

## 3: Package API into a Dockerfile
* Because the API needed to dynamically generate puzzles from different C++ modules, it needed to be packaged with a Dockerfile
  
## 5: Host API using Render
* Render uses the dockerfile to create and host the API.
* The user can request puzzles to be generated based on different difficulties.
  
## 6: Website
* Create website using React
* Pull puzzle data from API
* Add features and gameplay to puzzle, including difficulty changes, notes mode, timer
* Host using github pages

## Continuation:
Generate different difficulties based on an intelligent model
* ML model in python using kaggle dataset? 
* Look at different patterns in python 



