/*************************************************************
** Program name: Raft.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of Raft class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef Raft_hpp
#define Raft_hpp

#include "Item.hpp"
#include "Player.hpp"

class Raft : public Item
{
public:
	Raft(int xCoord, int yCoord, Player* thePlayer);
	virtual void itemInteract() override;
	virtual void useStoredItem() override;
	virtual ~Raft(){};		
};

#endif /* Raft_hpp */
