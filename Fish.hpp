/*************************************************************
** Program name: Fish.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of Fish class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef Fish_hpp
#define Fish_hpp

#include "Item.hpp"
#include "Player.hpp"

class Fish : public Item
{
public:
	Fish(int xCoord, int yCoord, Player* thePlayer);
    int getHealthValue() const;
	virtual void itemInteract() override;
    virtual void useStoredItem() override;
	virtual ~Fish(){};		
};

#endif /* Fish_hpp */
