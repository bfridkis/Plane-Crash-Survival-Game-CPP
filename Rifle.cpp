/***************************************************************
** Program name: Rifle.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of Rifle class member functions. 
				Rifle is a derived class of the parent class 
				Item.
****************************************************************/

#include "Rifle.hpp"

/***********************************************
			   Constructor
  Rifle constructor to establish an
  initial starting coordinates for the
  Rifle. Passes xCoord and yCoord parameters
  to the base class constructor, and 
  establishes the Item's name and character.
  Passes Player object pointer to the base class 
  constructor for interchange of Items between 
  the Space and Player and for related Player
  updates.
************************************************/
Rifle::Rifle(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "Rifle";
	itemChar = '_';
	isPerishable = false;
    ammo = 20;
}
/**********************************
              getAmmo
  Accessor to get ammo data member.
***********************************/
int Rifle::getAmmo() const
{
    return ammo;
}
/**********************************
              setAmmo
  Mutator to set ammo data member.
***********************************/
void Rifle::setAmmo(int decrement)
{
    ammo += decrement;
}
/********************************************************
			         itemInteract	
  Function to interact with Rifle (a derived Item) when 
  in a space environment (as opposed to an item carried 
  by the player).
*********************************************************/
void Rifle::itemInteract()
{
	//Gets the Player's current Space Board array and
	//Space Items vector.
	char** spaceBoard = thePlayer->getPlayerLocation()->
		getSpaceBoard();
	vector<Item*>& spaceItems = thePlayer->
		getPlayerLocation()->getSpaceItems();
	
	//Checks Player's carrying capacity. If player
	//has the Backpack, carrying capacity is 4 items,
	//else carrying capacity is 1 item. If Player is 
	//not holding the max number of Items based on
	//hasBackPack, player is prompted to pickup or 
	//ignore the Item.
	thePlayer->printSpace(false);
	
	if ((thePlayer->getHasBackPack() &&
		thePlayer->getPlayerItemCount() < 4) ||
		thePlayer->getPlayerItemCount() == 0)
	{
		
		cout << "\nYou Found a Rifle!\n"
			 << "p - pickup, i - ignore: ";
		char userSelection = 
			InputValidation::pOrIInputValidation();
		
		if (userSelection == 'P')
		{
			//If Item is picked up, it's x and y coordinates
			//are set to -1 and then it is added to the Player
			//Items. Lastly the pointer is erased from the
			//Player's Location Space Items vector.
			Item* temp = nullptr;
			vector<Item*>::iterator iter = spaceItems.begin();
			for (unsigned i = 0; i < spaceItems.size() && temp == nullptr; 
				 i++, iter++)
			{
                Item* thisItem = spaceItems.at(i);
				if (typeid(*thisItem) == typeid(Rifle))
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
			
            thePlayer->setHasRifle(true);
			cout << "\nRifle added to items.\n";
		}
	}
	else
	{
		cout << "\nYou Found a Rifle! But you cannot"
			 << " carry any more items.\nWould you "
			 << "like to drop an item to pick up the Rifle? "
			 << "(y-yes, n-no): ";
		char userSelection = InputValidation::yOrNInputValidation();
		
		//Same logic as above, but swaps an Item of the user's 
		//choice from the Player's Item with the Player's Location
		//Space so as to "drop" an item in exchange for the item
		//picked up because the Player's carrying capacity is at 
		//limit.
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
				if (typeid(*thisItem) == typeid(Rifle))
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
			
            thePlayer->setHasRifle(true);
			cout << "\nRifle added to items.\n"
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
void Rifle::useStoredItem()
{
    cout << "\nHungry? Try 'engage' when next to "
         << "a beast.\nBut be careful: Make sure you "
         << "don't run out of ammo!" << endl
         << "Current Ammo: ";
    
    vector<Item*>& playerItems = thePlayer->getPlayerItems();
        bool foundRifle = false;
        for (unsigned i = 0; i < playerItems.size() && !foundRifle; i++)
        {
            Item* thisItem = playerItems.at(i);
            if (typeid(*thisItem) == typeid(Rifle))
            {
                foundRifle = true;
                cout << static_cast<Rifle*>(thisItem)->getAmmo();
                cout << endl;
            }
        }
}
