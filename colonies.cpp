#ifndef COLONIES_CPP
#define COLONIES_CPP

#include <iostream>
#include "struct.h"
#include "prototypes.h"
#include "globals.h"
#include <vector>
using namespace std;

/* Used just for generating initial colony*/
vector< pair<int, int> > findNeighbors(int i, int j){
    vector< pair<int, int> > ngh;
    //top left corner
    if((i-1) > -1 && (j-1) > -1) ngh.push_back(make_pair((i-1), (j-1)));
    //bottom right corner
    if((i+1) < 20 && (j+1) < 20) ngh.push_back(make_pair((i+1), (j+1)));
    //top right
    if((i-1) > -1 && (j+1) < 20) ngh.push_back(make_pair((i-1), (j+1)));
    //bottom left
    if((i+1) < 20 && (j-1) > -1) ngh.push_back(make_pair((i+1), (j-1)));
    if((i+1) < 20) ngh.push_back(make_pair((i+1), j)); //bottom
    if((i-1) > -1) ngh.push_back(make_pair((i-1), j)); //top
    if((j-1) > -1) ngh.push_back(make_pair(i, (j-1))); //left
    if((j+1) < 20) ngh.push_back(make_pair(i, (j+1))); //right

    return ngh;
}

/*parameter of the index where the current Generation is at*/
int findActiveNeighbors(int i, int j){
    vector< pair<int, int> > tempV = currGen[i][j].neighbors;
    int count = 0;
    for(int k = 0; k < tempV.size(); k++){
        if(currGen[tempV[k].first][tempV[k].second].value == FILLED){
            count++;
        }
    }
    return count;
}

void generateNextGeneration(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            //find the number of active neighbors for each cell
            //to determine what it should be for next Gen
            int active = findActiveNeighbors(i, j);
            if(active < 2 || currGen[i][j].numGenActive > 10 || active > 3){
                //0 or 1; make empty
                nextGen[i][j].value = EMPTY;
                nextGen[i][j].numGenActive = 0;
                //set generations active to 0
            }
            else if(active == 2){
                //set generations active up 1 if filled; no change in value
                nextGen[i][j].value = currGen[i][j].value;
                nextGen[i][j].numGenActive = currGen[i][j].numGenActive;
                if(currGen[i][j].value == FILLED){
                    nextGen[i][j].numGenActive++;
                }
            }
            else if(active == 3){
                //set generations active up 1
                nextGen[i][j].value = FILLED;
                nextGen[i][j].numGenActive = currGen[i][j].numGenActive+1;
            }
            nextGen[i][j].neighbors = currGen[i][j].neighbors;
        }
    }
}

/* Print out the current Generation*/
void printColony(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
          cout << currGen[i][j].value << " ";  
        }
        cout << endl;
    }
}
#endif