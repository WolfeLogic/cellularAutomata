//
//  main.cpp
//  Critters
//
//  Created by Drew Wolfe on 7/11/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void initialize();
void printGrid();
bool move(int i, int j, int* newI, int* newJ, bool breed);

typedef Critter* Row; //Row will become an array of Critter pointers
typedef Row* Grid; //Grid will become an array of Row pointers

int row = 20; //determines height of grid
int col = 20; //determines width of grid
Grid* G; //is what the grid is filled with
int numAnts = 100;
int numDoodlebugs = 5;


int main(int argc, const char * argv[])
{
    srand (time(NULL)); //used to seed the rand func to make more "random"
    initialize(); //creates the grid and seeds it with Critter objects
    while (true) {
        printGrid(); //prints the grid
        
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (G[i][j] != NULL && !(G[i][j]->getPassed()))
                {
                    //bool breed gets set to the breed value at the G[i][j]
                    //point in the grid. Reset variable is false because
                    //it should not reset breedCounter to 0
                    bool breed = G[i][j]->breed(false);
                    int newI = 0; //used to differentiate new from old index coordinate
                    int newJ = 0;
                    bool val = move(i, j, &newI, &newJ, breed); //calling move func
                    G[newI][newJ]->eat(val); //specific instance of G is -> (calling) eat func
                    if (G[newI][newJ]->die()) //calling die func
                    {
                        delete G[newI][newJ]; //deleting a critter object
                        G[newI][newJ] = NULL; //setting critter's pointer to NULL
                    }
                }
            }
        }
        //requires user input of enter key to cycle through and iteration of the
        //Critter lifecycle
        cin.get();
    }
    
    
    
    return 0;
}

void initialize()
{
    G = new Grid[row]; //G pointer of type Grid
    
    
    //fills grid
    for (int i = 0; i < row; i++)
    {
        G[i] = new Row[col];
        
        for (int j = 0; j < col; j++)
        {
            G[i][j] = NULL;
        }
    }
    //fill grid with ants
    for (int x = 0; x < numAnts; x++) {
        int i;
        int j;
        do {
            i = rand() % row;
            j = rand() % col;
        } while (G[i][j] != NULL);
        
        G[i][j] = new Ant();
    }
    
    //fill grid with doodlebugs
    for (int x = 0; x < numDoodlebugs; x++) {
        int i;
        int j;
        do {
            i = rand() % row;
            j = rand() % col;
        } while (G[i][j] != NULL);
        
        G[i][j] = new Doodlebug();
    }
}

void printGrid()
{
    for (int i = 0; i < col; ++i)
    {
        //Visually defines lefthand side of grid
        cout << "   |";
        for (int j = 0; j < row; ++j)
        {
            //Checks if space is occupied by Doodlebug
            if (G[i][j] != NULL)
            {
                cout << G[i][j]->display();
                //setPassed keeps the Critter lifecycle functions from
                //reiterating over a Critter that's moved back into the
                //path of the current loop
                G[i][j]->setPassed(false);
            }
            else cout << " ";
        }
        //Visually defines righthand side of grid
        cout << "|" << endl;
    }

}

bool move(int i, int j, int* newI, int* newJ, bool breed)
{
    G[i][j]->setPassed(true);
    *newI = i;
    *newJ = j;
    switch (G[i][j]->move()) {
        case 0:
            //up
            if (i == 0) // if can't go up
            {
                break;
            }
            else
            {
                *newI = i - 1;
                break;
            }
        case 1:
            //down
            if (i == row -1) //if can't go down
            {
                break;
            }
            else
            {
                *newI = i + 1;
                break;
            }
        case 2:
            //left
            if (j==0) //if can't go left
            {
                break;
            }
            else
            {
                *newJ = j - 1;
                break;
            }
        case 3:
            //right
            if (j == col - 1) // if can't go right
            {
                break;
            }
            else
            {
                *newJ = j + 1;
                break;
            }
            
        default:
            break;
    }
    if (G[*newI][*newJ] == NULL) //if the new space is empty
    {
        G[*newI][*newJ]=G[i][j]; //replace the old with new
        G[i][j] = NULL; //make old NULL
        //if breed true
        if (breed) {
            if (G[*newI][*newJ]->getType()==1) //if an ant
            {
                G[i][j] = new Ant(); //create a new ant in old space
                G[*newI][*newJ]->breed(true);
            }
            else //must be doodlebug
            {
                G[i][j] = new Doodlebug(); //create a new doodlebug in old space
                G[*newI][*newJ]->breed(true);
            }
        }
    }
    else if (G[i][j]->getType()==1)
    {
        //do nothing
    }
    else if (G[*newI][*newJ]->getType()==2)
    {
        //do nothing
    }
    else
    {
        delete G[*newI][*newJ]; //deleting ant object being pointed at
        G[*newI][*newJ] = NULL; //setting ant's pointer to NULL
        G[*newI][*newJ] = G[i][j]; //moving doodlebug object to new space
        G[i][j] = NULL; //updating pointer to old space to NULL
        if (breed)
        {
            G[i][j] = new Doodlebug(); //create a new doodlebug in old space after eating ant
            G[*newI][*newJ]->breed(true);
        }
        return true;
    }
    return false;
}