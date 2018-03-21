/*************************************************************
** Program name: BackPack.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of BackPack class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef BackPack_hpp
#define BackPack_hpp

#include "Item.hpp"
#include "Player.hpp"

class BackPack : public Item
{
public:
	BackPack(int xCoord, int yCoord, Player* thePlayer);
	virtual void itemInteract() override;
    virtual void useStoredItem() override{};
	virtual ~BackPack(){};		
};

#endif /* BackPack_hpp */
