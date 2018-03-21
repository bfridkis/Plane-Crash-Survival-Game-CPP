/*************************************************************
 ** Program name: Woods.hpp
 ** Author: Ben Fridkis
 ** Date: 5/31/2017
 ** Description: Declaration of Woods class for CS162 final
    project. This is a derived class of the Space
    base class.
 **************************************************************/

#ifndef Woods_hpp
#define Woods_hpp

#include "Space.hpp"
#include "NutGrove.hpp"
#include "Mushroom.hpp"
#include "randomOrderUniqueElementGenerator.hpp"
#include <cstdlib>
#include <ctime>

class Woods : public Space
{
public:
    Woods(Player* player, int spaceCode,
          int difficultyLevel, bool hasRaft = 0);
    virtual void catastrophe() override;
    virtual ~Woods(){};
};

#endif /* Woods_hpp*/
