# cellular_automata
Program simulates a simple predator-prey model

- **Overview**
  - Design, implement, and test a cellular automata program.
    - The program will simulate a simple predator-prey model. You will have a 2D array populated by Ants, Doodlebugs and empty spaces.

- **Class hierarchy**
  - Critter base class
  - Ant subclass
  - Doodlebug subclass

- **Movement:**
  - The 2D array will have a data type of pointer to Critter.
    - That allows either type of Critter to be in any element of the array.
  - Movement is random.
    - The move function just returns one of the 4 possible directions the Critter can move, determined at random by the object.
  - The main function will hold the array.
  - If the Critter cannot move, it remains in the same element.
  - The Critter will have no knowledge of its location; it just wants to move.
  - Doodlebug cannot share a cell with another Doodlebug; a move attempt fails.
  - Ant cannot share a cell with another Ant; a move attempt fails.
  - Ant cannot share a cell with Doodlebug, a move attempt fails.
  - Doodlebug moves to cell with Ant, Ant is eaten.

- **Breeding** :
  - The Critter must know the number of turns since it last bred.
  - Before a Critter moves the main program must call its breed function.
  - When the move counter has reaches its breed trigger, a new Critter object must be left in the original position of the parent Critter.
    - 3 for an Ant
    - 8 for a Doodlebug
  - The Critter does not breed if it cannot move.
  - Reset the breed count to 0 after breeding.
    - When the breed function is called and the counter is not at the limit, the function will simply increment it by one.
  - Breed increments the time to breed counter or resets it.
  - It returns false if nothing happens, or true if it&#39;s time for a new Critter.
  - The main loop will know that the Critter didn&#39;t move so it will not create the new Critter.

- **Eating** :
  - Doodlebugs eat Ants.
    - When eaten the pointer to the Ant object is freed in the main program.
  - Programs calls the eat function.
    - This function resets the Move counter if the Doodlebug ate an Ant.
    - The function increments the counter for the Critter when it does not eat.
    - Use a Boolean parameter to indicate if the Doodlebug ate an Ant.
  - When eat is called for an Ant it will ignore the parameter.

- **Death** :
  - After the Move and Eat functions have been called, the main program must call the die function.
  - IFF a Critter&#39;s Move counter exceeds the TTL counter THEN Critter dies and is removed from the grid.
    - 10 moves for Ants
    -  3 moves for Doodlebugs
  - Use a Boolean function.

