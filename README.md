# Word Search Solver
## How to use? 
- Clone the repository to your local machine.
- Open a terminal window.
- Navigate to the directory where you cloned the repository.
- Run `make` to compile the project.
- Run the program by executing `.\wordsolver`.
- Input the grid dimensions as two integers `(n x m)`, where n is the number of rows and m is the number of columns.
- Input the grid content: Provide `n x m` lowercase Latin letters for the grid.
- Input the number of words to be found `(k)`.
- Input the `k` words to be searched for in the grid.
- The program will highlight the found words in different colors on the grid and output the updated grid.

## Algorithm used for solving

Generally the word search game is solved by using the graph traversal algorithms which gives a time complexity of `O(word_length * k * n * m)`. 

This code optimizes the searching process by use of polynomial rolling hash algorithm and solves the game in `O(word_length * k + 8 * n * m * k)`.

This algorithm makes the search faster for larger grid sizes and multiple words search.

## Sample Input
```
7 7
f y y h n r d
r l j c i n u
a a w a a h r
n t k l p n e
c i l f s a p
e o g o t p n
h p o l a n d
8
france
ylati
japan
niaps
holland
peru
togo
poland

```

## Sample Output
![alt text](https://github.com/Rittin1/Word_Search-Solver/blob/main/output.png)
