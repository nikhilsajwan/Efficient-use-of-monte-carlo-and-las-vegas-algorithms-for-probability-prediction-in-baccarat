# An Application based on Probability Prediction using Randomization Algorithms.
An Application based on Probability Prediction using Randomization Algorithms. Where winning probability of player and banker is calculated simultaneously with the simulation of game Baccarat.

## Monte Carlo Algorithm:

Monte Carlo is that class of algorithm which may return the correct result or the incorrect result
with some probability. The algorithm resources used in this are often bounded and thus it has a deterministic
or fixed run time. It gives better probability results when it is run for a larger number of iterations.

## Las Vegas Algorithm:

A Las Vegas algorithm returns the correct or optimum result always, and informs when it fails.
Its run time differs at each run since it depends on a random value, even for the same input. 

## Pthread Library:
 POSIX threads or Pthreads are the thread implementations which adhere to this standard. Implementation of pthread is available with GCC compiler and has been used for multithreading. We have implemented all the algorithms in C language with a GCC
compiler only.

## Baccarat
Baccarat is a game of cards which contains 8 decks. There are 416*415*414*413 possible cases in first hand
which makes it almost impossible to be followed for patterns/predictions. To be able to even calculate the
probabilities with a great deal of accuracy, it takes a large amount of time. Hence, it served as a suitable
problem statement that could be solved by our algorithms

### The following algorithms are implemented in these ways:
 #### 1). Las Vegas
 #### 2). Las Vegas with Threading (416 POSIX Threads)
 #### 3). Monte Carlo
 #### 4). Monte Carlo with array of linked lists
 




