/*************************************************************
** Program name: SmallBeast.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of SmallBeast class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef SmallBeast_hpp
#define SmallBeast_hpp

#include "Item.hpp"
#include "Player.hpp"

class SmallBeast : public Item
{
public:
	SmallBeast(int xCoord, int yCoord, Player* thePlayer);
    int getHealthValue() const;
	virtual void itemInteract() override;
    virtual void useStoredItem() override;
	virtual ~SmallBeast(){};		
};

#endif /* SmallBeast_hpp */

