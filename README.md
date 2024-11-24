# Word Search Solver
## How to use?
- Run wordsolver.cpp
- Input 2 integers the dimensions of your grid (nxm).
- Input nxm lowercase latin letters, the content of your grid
- Input the number of words to be found(k).
- Input k words.
- The code will highlight words with different colours on the grid and output the grid.

## Algorithm used for solving

Generally the word search game is solved by using the graph traversal algorithms which gives a time complexity of O(word length * k * n * m). This code
optimizes the searching process by use of polynomial rolling hash algorithm and solves the game in O(word_length \* k + 8 \* n \* m \* k).




