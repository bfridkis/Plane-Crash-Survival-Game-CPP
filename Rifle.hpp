/*************************************************************
** Program name: Rifle.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of Rifle class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef Rifle_hpp
#define Rifle_hpp

#include "Item.hpp"
#include "Player.hpp"

class Rifle : public Item
{
private:
	int ammo;
public:
	Rifle(int xCoord, int yCoord, Player* thePlayer);
    int getAmmo() const;
    void setAmmo(int decrement);
	virtual void itemInteract() override;
	virtual void useStoredItem() override;
	virtual ~Rifle(){};		
};

#endif /* Rifle_hpp */
