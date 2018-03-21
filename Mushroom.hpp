/*************************************************************
** Program name: Mushroom.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of Mushroom class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef Mushroom_hpp
#define Mushroom_hpp

#include "Item.hpp"
#include "Player.hpp"

class Mushroom : public Item
{
public:
	Mushroom(int xCoord, int yCoord, Player* thePlayer);
    int getHealthValue() const;
	virtual void itemInteract() override;
    virtual void useStoredItem() override;
	virtual ~Mushroom(){};		
};

#endif /* Mushroom_hpp */
