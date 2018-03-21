/*************************************************************
** Program name: LockBox.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of LockBox class member functions. 
				LockBox is a derived class of the parent class 
				Item.
**************************************************************/

#include "LockBox.hpp"

/****************************************
			   Constructor
  LockBox constructor to establish an
  initial starting coordinates for the
  LockBox. Passes xCoord and yCoord parameters
  to the base class constructor, and 
  establishes the Item's name and character.
  Passes Player object pointer to the base 
  class constructor for interchange of Items
  between the Space and Player and for
  related Player updates.
****************************************/
LockBox::LockBox(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "LockBox";
	itemChar = 'L';
	isPerishable = false;
}
/********************************************************
			         itemInteract	
  Function to interact with LockBox (a derived Item) when 
  in a space environment (as opposed to an item carried 
  by the player).
*********************************************************/
void LockBox::itemInteract()
{
	cout << "\nYou Found a LockBox!\n";
	
	if (thePlayer->getHasKey())
	{	
		cout << "o - open, i - ignore: ";
		char userSelection = 
			InputValidation::oOrIInputValidation();
		
		if (userSelection == 'O')
		{
			cout << "\nIt's the transmitter! Hallelujah!\n";
			thePlayer->setHasTransmitted();
		}	
	}
	else
	{
		cout << "But it's locked and too heavy to pickup.\n";
	}
}
