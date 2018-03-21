/*************************************************************
 ** Program name: Meadow.hpp
 ** Author: Ben Fridkis
 ** Date: 5/31/2017
 ** Description: Declaration of Meadow class for CS162 final
    project. This is a derived class of the Space
    base class.
 **************************************************************/

#ifndef Meadow_hpp
#define Meadow_hpp

#include "Space.hpp"
#include "LargeBeast.hpp"
#include "SmallBeast.hpp"
#include "BerryBush.hpp"
#include "randomOrderUniqueElementGenerator.hpp"
#include "Snake.hpp"
#include <cstdlib>
#include <ctime>

class Meadow : public Space
{
private:
	int difficultyLevel;
public:
    Meadow(Player* player, int spaceCode,
           int difficultyLevel, bool hasRaft = 0);
    virtual void catastrophe() override;
    virtual ~Meadow(){};
};

#endif /* Meadow_hpp */
