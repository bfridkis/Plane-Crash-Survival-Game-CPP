/*************************************************************
** Program name: BerryBush.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of BerryBush class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef BerryBush_hpp
#define BerryBush_hpp

#include "Item.hpp"
#include "Player.hpp"

class BerryBush : public Item
{
public:
	BerryBush(int xCoord, int yCoord, Player* thePlayer);
    int getHealthValue() const;
	virtual void itemInteract() override;
    virtual void useStoredItem() override;
	virtual ~BerryBush(){};		
};

#endif /* BerryBush_hpp */


