/*************************************************************
** Program name: Lake.hpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Declaration of Lake class for CS162 final
				project. This is a derived class of the Space
				base class.
**************************************************************/

#ifndef Lake_hpp
#define Lake_hpp

#include "Space.hpp"
#include "Fish.hpp"
#include <cstdlib>
#include <ctime>

class Lake : public Space
{
private:
	int difficultyLevel;
public:
	Lake(Player* player, int spaceCode, 
		int difficultyLevel, bool hasRaft = 0);
    virtual void catastrophe() override;
	virtual ~Lake(){};
};

#endif /* Lake_hpp */

