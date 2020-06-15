# GAME OF LIFE PROJECT

## Introduction
This project simulates Conway's "Game of Life", where the evolution of a colony of cells is mapped given an initial state. The project generates an initial state through an input or random generation. The program then simulates the life cycle of a specified number of future generations of the initial colony. 

## Guidelines/Rules
This version of the game is played on a 20x20 two dimensional grid. Each grid location is either empty or filled by a single cell (X). A location has up to eight neighbors that are adjacent to it. The births and deaths of the cells happen simultaneously and any changes in a given generation start to have effect on other neighboring cells in the next generation. 

Rule 1) A location that has zero or one active neighbors will be empty the next generation because it dies from loneliness.

Rule 2) A location with two active neighbors is stable and nothing about the state of the location changes.

Rule 3) A location with three active neighbors will contain a cell in the next generation.

Rule 4) A location with four or more active neighbors will be empty in the next generation because it will die of overcrowding. 

Rule 5) A cell that ages more than 10 generations dies, and will be empty the next generation regardless of how many active neighbors it has. 
