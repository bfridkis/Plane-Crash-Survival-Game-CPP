/*************************************************************
** Program name: LargeBeast.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of LargeBeast class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef LargeBeast_hpp
#define LargeBeast_hpp

#include "Item.hpp"
#include "Player.hpp"

class LargeBeast : public Item
{
public:
	LargeBeast(int xCoord, int yCoord, Player* thePlayer);
    int getHealthValue() const;
	virtual void itemInteract() override;
    virtual void useStoredItem() override;
	virtual ~LargeBeast(){};		
};

#endif /* LargeBeast_hpp */
