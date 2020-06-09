#ifndef PROTOTYPES_H
#define PROTOTYPES_H

std::vector< std::pair<int, int> > findNeighbors(int , int );
int findActiveNeighbors(int , int );
void generateNextGeneration();
void printColony();
int setUp();
void readInitialColony(std::string ,char (&) [20][20]);
void generateRandomColony(char (&) [20][20]);
void processCellInput(char [20][20]);
#endif