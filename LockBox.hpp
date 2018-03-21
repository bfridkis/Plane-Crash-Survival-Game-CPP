/*************************************************************
** Program name: LockBox.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of LockBox class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef LockBox_hpp
#define LockBox_hpp

#include "Item.hpp"
#include "Player.hpp"

class LockBox : public Item
{
public:
	LockBox(int xCoord, int yCoord, Player* thePlayer);
	virtual void itemInteract() override;
    virtual void useStoredItem() override{};
	virtual ~LockBox(){};		
};

#endif /* LockBox_hpp */
