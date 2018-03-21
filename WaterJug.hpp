/*************************************************************
** Program name: WaterJug.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of WaterJug class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef WaterJug_hpp
#define WaterJug_hpp

#include "Item.hpp"
#include "Player.hpp"

class WaterJug : public Item
{
private:
	int drinkCount;
	int playerXCoordAtTimeOfLastDrink;
	int playerYCoordAtTimeOfLastDrink;
	int drinkCountWithoutMoving;
	bool hasMovedSinceLastDrink;
public:
	WaterJug(int xCoord, int yCoord, Player* thePlayer);
	virtual void itemInteract() override;
	virtual void useStoredItem() override;
	virtual ~WaterJug(){};		
};

#endif /* WaterJug_hpp */
