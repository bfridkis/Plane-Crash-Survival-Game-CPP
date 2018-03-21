/*************************************************************
** Program name: BackPack.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of BackPack class member functions. 
				BackPack is a derived class of the parent class 
				Item.
**************************************************************/

#include "BackPack.hpp"

/***********************************************
			      Constructor
  BackPack constructor to establish an initial 
  starting coordinates for the BackPack. Passes 
  xCoord and yCoord parameters to the base class 
  constructor, and establishes the Item's name 
  and character. Passes Player object pointer to 
  the base class constructor for interchange of 
  Items between the Space and Player and for 
  related Player updates.
*************************************************/
BackPack::BackPack(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "BackPack";
	itemChar = '&';
	isPerishable = false;
}
/********************************************************
			         itemInteract	
  Function to interact with BackPack (a derived Item) when 
  in a space environment (as opposed to an item carried 
  by the player).
*********************************************************/
void BackPack::itemInteract()
{
    char** spaceBoard = thePlayer->getPlayerLocation()->
		getSpaceBoard();
	vector<Item*>& spaceItems = thePlayer->
		getPlayerLocation()->getSpaceItems();
        
	cout << "\nYou Found a BackPack!\n\n"
         << "Carrying Capacity +3.\n\n";
    
	InputValidation::enterKeyPrompt();
	
    thePlayer->setHasBackPack(true);
    
    Item* temp = nullptr;
    vector<Item*>::iterator iter = spaceItems.begin();
    for (unsigned i = 0; i < spaceItems.size() && temp == nullptr;
         i++, iter++)
    {
        Item* thisItem = spaceItems.at(i);
        if (typeid(*thisItem) == typeid(BackPack))
        {
            spaceBoard[thisItem->getXCoord()]
            [thisItem->getYCoord()] = ' ';
            
            delete thisItem;
            
            spaceItems.erase(iter);
        }
    }
}
