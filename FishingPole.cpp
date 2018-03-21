/***************************************************************
** Program name: FishingPole.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of FishingPole class member functions. 
				FishingPole is a derived class of the parent class 
				Item.
****************************************************************/

#include "FishingPole.hpp"

/************************************************
			       Constructor
  FishingPole constructor to establish an
  initial starting coordinates for the
  FishingPole. Passes xCoord and yCoord 
  parameters to the base class constructor, 
  and establishes the Item's name and character.
  Passes Player object pointer to the base class 
  constructor for interchange of Items between 
  the Space and Player and for related Player
  updates.
**************************************************/
FishingPole::FishingPole(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "Fishing Pole";
	itemChar = '/';
	isPerishable = false;
}
/********************************************************
			         itemInteract	
  Function to interact with FishingPole (a derived Item) 
  when in a space environment (as opposed to an item 
  carried by the player).
*********************************************************/
void FishingPole::itemInteract()
{
	char** spaceBoard = thePlayer->getPlayerLocation()->
		getSpaceBoard();
	vector<Item*>& spaceItems = thePlayer->
		getPlayerLocation()->getSpaceItems();
	
	thePlayer->printSpace(false);
	
	if ((thePlayer->getHasBackPack() &&
		thePlayer->getPlayerItemCount() < 4) ||
		thePlayer->getPlayerItemCount() == 0)
	{
		
		cout << "\nYou Found a Fishing Pole!\n"
			 << "p - pickup, i - ignore: ";
		char userSelection = 
			InputValidation::pOrIInputValidation();
		
		if (userSelection == 'P')
		{
			Item* temp = nullptr;
			vector<Item*>::iterator iter = spaceItems.begin();
			for (unsigned i = 0; i < spaceItems.size() && temp == nullptr; 
				 i++, iter++)
			{
                Item* thisItem = spaceItems.at(i);
				if (typeid(*thisItem) == typeid(FishingPole))
				{
					spaceBoard[spaceItems.at(i)->getXCoord()]
					   [spaceItems.at(i)->getYCoord()] = ' ';
					   
					spaceItems.at(i)->setXCoord(-1);
					spaceItems.at(i)->setYCoord(-1);
					
					temp = spaceItems.at(i);
					thePlayer->addItem(temp);
					
					spaceItems.erase(iter);
				}
			}
			
            thePlayer->setHasFishingPole(true);
			cout << "\nFishingPole added to items.\n";
		}
	}
	else
	{
		cout << "\nYou Found a Fishing Pole! But you cannot"
			 << " carry any more items.\nWould you "
			 << "like to drop an item to pick up the Fishing Pole? "
			 << "(y-yes, n-no): ";
		char userSelection = InputValidation::yOrNInputValidation();
		
		if (userSelection == 'Y')
		{
			Item* itemDropped = thePlayer->dropItem(userSelection);
			
			Item* temp = nullptr;
			vector<Item*>::iterator iter = spaceItems.begin();
			for (unsigned i = 0; i < spaceItems.size() && temp == nullptr; 
				 i++, iter++)
			{
				//Once the item is found based on a typeid check,
				//swap the item on the Space with the item the player
				//chose to drop.
                Item* thisItem = spaceItems.at(i);
				if (typeid(*thisItem) == typeid(FishingPole))
				{
					int xCoordinate = spaceItems.at(i)->getXCoord();
					int yCoordinate = spaceItems.at(i)->getYCoord();
					
					itemDropped->setXCoord(xCoordinate);
					itemDropped->setYCoord(yCoordinate);
					spaceItems.push_back(itemDropped);
					   
					spaceItems.at(i)->setXCoord(-1);
					spaceItems.at(i)->setYCoord(-1);
					
					temp = spaceItems.at(i);
					thePlayer->addItem(temp);
					
					spaceItems.erase(iter);
				}
			}
			
            thePlayer->setHasFishingPole(true);
			cout << "\nFishing Pole added to items.\n"
				 << itemDropped->getItemName() << " dropped.\n";
		}
	}
}
/******************************************************
			         useStoredItem	
  Function to interact with an item carried by the 
  player (as opposed to interacting with an Item found
  in a Space).
*******************************************************/
void FishingPole::useStoredItem()
{
    cout << "\nHungry? Try 'engage' when next to "
         << "a fish." << endl;
}
