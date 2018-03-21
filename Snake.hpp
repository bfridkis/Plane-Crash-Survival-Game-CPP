/*************************************************************
** Program name: Snake.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of Snake class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef Snake_hpp
#define Snake_hpp

#include "Item.hpp"
#include "Player.hpp"

class Snake : public Item
{
public:
	Snake(int xCoord, int yCoord, Player* thePlayer);
	virtual void itemInteract() override;
    virtual void useStoredItem() override{};
	virtual ~Snake(){};		
};

#endif /* Snake_hpp */
