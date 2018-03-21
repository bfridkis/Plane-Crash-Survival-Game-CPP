/*************************************************************
** Program name: Snake.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of Snake class member functions. 
				Snake is a derived class of the parent class 
				Item.
**************************************************************/

#include "Snake.hpp"

/********************************************
			   Constructor
  Snake constructor to establish an
  initial starting coordinates for the
  Snake. Passes xCoord and yCoord parameters
  to the base class constructor, and 
  establishes the Item's name and character.
  Passes Player object pointer to the base 
  class constructor for interchange of Items
  between the Space and Player.
*********************************************/
Snake::Snake(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "Snake";
	itemChar = '~';
	isPerishable = false;
}
/********************************************************
			         itemInteract	
  Function to interact with Snake (a derived Item) when 
  in a space environment (as opposed to an item carried 
  by the player).
*********************************************************/
void Snake::itemInteract()
{
	cout << "\nAh! A Snake! -25 Health Points\n\n";
		 
	InputValidation::enterKeyPrompt();
    thePlayer->setHealth(-25);
}
