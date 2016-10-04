//
//  critter.cpp
//  Critters
//
//  Created by Drew Wolfe on 7/11/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#include "critter.hpp"

//Critter constructor
Critter::Critter()
{
    
}

char Critter::display()
{
    return 'C'; //shouldn't happen. Good for debugging
}

int Critter::move() //different from move in main()
{
//    up = 0;
//    down = 1;
//    left = 2;
//    right = 3;
    return rand() % 4; //used to return a direction
}

bool Critter::getPassed() //flag to identify modified critters
{
    return passed;
}

void Critter::setPassed(bool val)//protected so need get&set
{
    passed = val;
}

int Critter::getType()
{
    return cType;
}

void Critter::eat(bool val)
{
 ++moveCounter;
}

bool Critter::die()
{
    if (moveCounter > timeToLive)
    {
        return true;
    }
    else return false;
}

bool Critter::breed(bool reset)
{
    if (reset) {
        breedCounter = 0;
        return false;
    }
    else
    {
        if (moveCounter >= breedCounter)
        {
            return true;
        }
        else
        {
            ++timeSinceLastBred;
            return false;
        }
    }
}
