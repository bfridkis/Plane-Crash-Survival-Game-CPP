/*************************************************************
** Program name: Item.hpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Declaration of Item class for CS162 final 
				project. This is a pure virtual or 'abstract'
                base class.
**************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <string>
#include <iostream>
#include <vector>
#include "InputValidation.hpp"
using std::cout;
using std::endl;
using std::string;
using std::vector;

//This forward declarations are needed to workaround a
//cyclic dependency. (https://stackoverflow.com/questions/
//2133250/does-not-name-a-type-error)
class Player;

class Item
{
protected:
	int xCoord;
	int yCoord;
	string itemName;
	char itemChar;
	Player* thePlayer;
    bool isPerishable;
    
public:
	Item(int xCoord, int yCoord, Player* thePlayer);
	int getXCoord() const;
	int getYCoord() const;
    bool getIsPerishable() const;
	void setXCoord(int xCoord);
	void setYCoord(int yCoord);
	string getItemName() const;
	char getItemChar() const;
	virtual void itemInteract() = 0;
	virtual void useStoredItem() = 0;
	virtual ~Item(){};
};

#endif /* Item_hpp */

