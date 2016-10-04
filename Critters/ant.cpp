//
//  ant.cpp
//  Critters
//
//  Created by Drew Wolfe on 7/11/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#include "ant.hpp"

Ant::Ant()
{
    cType = 1; //means to define Critter type
    timeToLive = 10; //amount of moves before death
    breedCounter = 3; //amount of moves before breed
}

char Ant::display()
{
    return 'A'; //show a A for ants in grid
}