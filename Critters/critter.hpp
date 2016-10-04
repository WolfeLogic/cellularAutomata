//
//  critter.hpp
//  Critters
//
//  Created by Drew Wolfe on 7/11/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#ifndef critter_hpp
#define critter_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

class Critter
{

protected:
    bool passed = false;
    int cType = 0;
    int moveCounter = 0;
    int timeToLive = 0;
    int breedCounter = 0;
    int timeSinceLastBred = 0;
    
public:
    Critter();
    virtual char display();
    int move();
    bool getPassed();
    void setPassed(bool val);
    int getType();
    virtual void eat(bool val);
    bool die();
    bool breed(bool reset);
    
    


};




#endif /* critter_hpp */
