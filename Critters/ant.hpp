//
//  ant.hpp
//  Critters
//
//  Created by Drew Wolfe on 7/11/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#ifndef ant_hpp
#define ant_hpp

#include <stdio.h>
#include "critter.hpp"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

class Ant : public Critter
{
    
public:
    Ant();
    char display();
    
private:
    
};


#endif /* ant_hpp */
