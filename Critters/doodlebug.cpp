//
//  doodlebug.cpp
//  Critters
//
//  Created by Drew Wolfe on 7/11/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#include "doodlebug.hpp"

Doodlebug::Doodlebug()
{
    cType = 2; //means to define Critter type
    timeToLive = 3; //amount of moves before death
    breedCounter = 8; //amount of moves before breed
}

char Doodlebug::display()
{
    return 'D'; //show a D for doodlebugs in grid
}

//overwrites Critter to account for moveCounter reset
void Doodlebug::eat(bool val)
{
    if (val)
    {
        moveCounter = 0;
    }
    else ++moveCounter;
}