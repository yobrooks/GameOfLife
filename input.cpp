#ifndef INPUT_CPP
#define INPUT_CPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "struct.h"
#include "globals.h"
#include "prototypes.h"
using namespace std;

//give user instructions and recieve number of generations to make
int setUp(){
    cout << "Artificial Simulation of Game of Life" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Each cell with one or no neighbors dies, as if by loneliness." << endl;
    cout << "Each cell with four or more neighbors dies, as if by overcrowding." << endl;
    cout << "Each cell with two or three neighbors survives." << endl;
    cout << "Each cell with three neighbors becomes populated." << endl;
    cout << "Each cell that ages over 10 generations dies.\n" << endl;
    cout << "How many generations would you like to simulate? Please keep response between 1 and 100." << endl;
    int numGen = 0;
    cin >> numGen;
    return numGen;
}


void readInitialColony(string fileName, char (&arr) [20][20]){
    ifstream in(fileName);
    char val;
    int i = 0, j = 0;
    if(!in){
        cout << "Unable to open file. Generating Random Colony." << endl;
        generateRandomColony(arr);
    }
    else{
            while(in >> val){
                arr[i][j] = val;
                if(j == 19){ //switch to next row
                    j = 0;
                    i++;
                }else{
                    j++;
                }
            }
    }
}

//might need to use a vector here or initialize all the values first
void generateRandomColony(char (&arr) [20][20]){
    //decide random number of cells to be full
    for(int i =0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            arr[i][j] = EMPTY;
        }
    }
    srand((unsigned) time(0));
    //up to 75% of the chart can be full
    int numFull = (rand()%300) + 1; 
   
    //make a loop with that number determining which cells are full
    int i = 0;
    while(i <= numFull){
        int row = (rand()%19) + 1;
        int col = (rand()%19) + 1;
        if(arr[row][col] != FILLED){
            arr[row][col] = FILLED;
            i++;
        }
    }
}

/*Val = FILLED OR EMPTY
    I = row number
    J = column number*/
//Fill the array of cell structs
void processCellInput(char arr[20][20]){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            Cell mycell;
            mycell.value = arr[i][j]; //input value
            if(arr[i][j] == FILLED){ //increase number of generations active
                mycell.numGenActive = 1;
            }
            else{
                mycell.numGenActive = 0;
            }
            //make a temp vector to store the neighbors
            vector< pair<int, int> > tempN;
            mycell.neighbors = findNeighbors(i, j);
            currGen[i][j] = mycell; //add to the actual cell vector
        }
    }
}
#endif
