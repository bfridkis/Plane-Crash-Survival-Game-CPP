/*************************************************************
** Program name: Item.cpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Item base class member function definitions.
**************************************************************/

#include "Item.hpp"

/****************************************
			   Constructor
  Item constructor to establish an
  initial starting coordinates for the
  item. (The derived class constructors
  establish the Item's character. An 
  xCoord and yCoord == -1 indicates
  that the Player is holding the object.)
****************************************/
Item::Item(int xCoord, int yCoord,
	Player* player)
{
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	thePlayer = player;
}
/************************************
			  getXCoord
  Accessor to get xCoord data member.
*************************************/
int Item::getXCoord() const
{
	return xCoord;
}
/************************************
			  getYCoord
  Accessor to get yCoord data member.
*************************************/
int Item::getYCoord() const
{
	return yCoord;
}
/************************************
          getIsPerishable
  Accessor to get isPerishable data 
  member.
*************************************/
bool Item::getIsPerishable() const
{
	return isPerishable;
}
/************************************
			  setXCoord
  Mutator to get xCoord data member.
*************************************/
void Item::setXCoord(int xCoord)
{
	this->xCoord = xCoord;
}
/************************************
			  setYCoord
  Mutator to get yCoord data member.
*************************************/
void Item::setYCoord(int yCoord)
{
	this->yCoord = yCoord;
}
/***************************************
			    getItemName
  Accessor to get itemName data member.
****************************************/
string Item::getItemName() const
{
	return itemName;
}
/***************************************
			  getItemChar
  Accessor to get itemChar data member.
****************************************/
char Item::getItemChar() const
{
	return itemChar;
}
