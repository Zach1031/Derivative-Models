# Derivative Models

## Overview
This is a collection of C++ classes that can be mixed and matched to price different options contracts based on certain models. The majority of this information comes from Implementing Derivative Models by Chris Strickland and Les Clewlow.

## Running
Any of the classes can be used by including the respective .h file and writing code in the main.cpp file. The project can be built by running `make` in your terminal.

## Folders
The old folder follows a direct implementation of the psuedo code from the first few chapters of Implementing Derivative Models. I ultimately switched to a tree based model because it allowed for flexibility between classes and easier implementation of inheritance. This is the structure for the code in the binomial and monte_carlo folders.