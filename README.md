# 42_N-Puzzle

The goal of this project is to solve the N-puzzle game using the A* search algorithm or one of its variants.

You start with a square board made up of N*N cells. One of these cells will be empty, the others will contain numbers, starting from 1, that will be unique in this instance of the puzzle.
Your search algorithm will have to find a valid sequence of moves in order to reach the final state, a.k.a the "snail solution", which depends on the size of the puzzle (Example below).

It checks if the N-Puzzle is soluble before the execution of the A* algorithm.

Exemple input :
```
# this is a comment
3
5 8 0
2 1 3
6 7 4
```

Exemple output :
```
5 8 0
2 1 3
6 7 4

Is it soluble ? True
Complexity in Time :   154
Complexity in Space :  50
Effective Complexity : 53
Nb Moves :             42

DOWN DOWN LEFT LEFT UP RIGHT UP LEFT DOWN RIGHT UP RIGHT DOWN LEFT DOWN RIGHT UP UP LEFT DOWN DOWN LEFT UP RIGHT UP LEFT DOWN DOWN RIGHT UP LEFT DOWN RIGHT UP LEFT UP RIGHT DOWN DOWN LEFT UP RIGHT
```

The complexity in time is the total number of states ever selected in the "opened" set (See A* algorithm)  
The complexity in space is the maximum number of states ever represented in memory at the same time
during the search.
The effective complexity is the total number of considered states in the A* search algorithm.

The printed moves is reversed, it means that the empty case in the example above is moving down, then down, then left...

A snail solution depends on the size:
```
# snail solution of size 3
1 2 3
8 0 4
7 6 5

# snail solution of size 4
 1  2  3  4
12 13 14  5
11  0 15  6
10  9  8  7

# snail solution of size 5
 1  2  3  4  5
16 17 18 19  6
15 24  0 20  7
14 23 22 21  8
13 12 11 10  9
```

## How to...

### Use the program

```
usage: ./main.py [-h] [-q] [--heuristic HEURISTIC] taquin
```

### To test program

```
make test_soluble
make test_non_soluble
make test_random # this command is a infinite loop. Care !
```

### To profile the program

```
make profile
```

### Get the full subject

See the subject.pdf

# Authors

 - Thibault Douge (tdouge [at] student.42.fr)
 - Joseph Priou (jpriou [at] student.42.fr)
