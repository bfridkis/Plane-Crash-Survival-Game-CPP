/*************************************************************
** Program name: HackSaw.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of HackSaw class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef HackSaw_hpp
#define HackSaw_hpp

#include "Item.hpp"
#include "Player.hpp"

class HackSaw : public Item
{
private:
	bool isTreeToNorth, isTreeToSouth, 
		 isTreeToEast, isTreeToWest;
public:
	HackSaw(int xCoord, int yCoord, Player* thePlayer);
	virtual void itemInteract() override;
	virtual void useStoredItem() override;
	virtual ~HackSaw(){};
};

#endif /* HackSaw_hpp */