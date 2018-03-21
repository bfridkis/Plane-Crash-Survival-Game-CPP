/*************************************************************
** Program name: FishingPole.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of FishingPole class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef FishingPole_hpp
#define FishingPole_hpp

#include "Item.hpp"
#include "Player.hpp"

class FishingPole : public Item
{
public:
	FishingPole(int xCoord, int yCoord, Player* thePlayer);
	virtual void itemInteract() override;
	virtual void useStoredItem() override;
	virtual ~FishingPole(){};		
};

#endif /* FishingPole_hpp */
