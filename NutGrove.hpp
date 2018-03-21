/*************************************************************
** Program name: NutGrove.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Declaration of NutGrove class for CS162 final 
				project. This is a derived class of the Item
				parent class.
**************************************************************/

#ifndef NutGrove_hpp
#define NutGrove_hpp

#include "Item.hpp"
#include "Player.hpp"

class NutGrove : public Item
{
public:
	NutGrove(int xCoord, int yCoord, Player* thePlayer);
    int getHealthValue() const;
	virtual void itemInteract() override;
    virtual void useStoredItem() override;
	virtual ~NutGrove(){};		
};

#endif /* NutGrove_hpp */
