#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include <vector>
#include <string>
#include "prototypes.h"
#include "globals.h"
#include "constants.h"
#include "struct.h"
using namespace std;

/* Define Globals*/
//Cell currGen[20][20];
//Cell nextGen[20][20];
    
int main(int argc, char *argv[]){
    char tempArr[20][20];
    int generations = setUp();
    //fill into an array the initial colony
    if(argc > 1){
       readInitialColony(argv[1], tempArr);
    }else{
        generateRandomColony(tempArr);
    }

    //populate current generation array with initial colony
    processCellInput(tempArr);
    cout << "Initial Generation: " << endl;
    printColony(); //print out initial colony
    for(int i = 1; i <= generations; i++){
        generateNextGeneration();
        copy(&nextGen[0][0], &nextGen[0][0]+20*20, &currGen[0][0]);
        cout << "\n Generation " << i << endl;
        printColony(); //print new generation
    }
}
#endif