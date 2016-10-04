//
//  doodlebug.hpp
//  Critters
//
//  Created by Drew Wolfe on 7/11/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#ifndef doodlebug_hpp
#define doodlebug_hpp

#include <stdio.h>
#include "critter.hpp"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

class Doodlebug : public Critter
{
    
public:
    Doodlebug();
    char display();
    void eat(bool val);
    
private:
    
};

#endif /* doodlebug_hpp */
