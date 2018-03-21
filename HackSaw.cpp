/***************************************************************
** Program name: HackSaw.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of HackSaw class member functions. 
				HackSaw is a derived class of the parent class 
				Item.
****************************************************************/

#include "HackSaw.hpp"

int const BOARDSIZE = 25;

/******************************************
			   Constructor
  HackSaw constructor to establish an
  initial starting coordinates for the
  HackSaw. Passes xCoord and yCoord 
  parameters to the base class constructor, 
  and establishes the Item's name and 
  board space character. Passes Player object 
  pointer to the base class constructor for 
  interchange of Items between the Space and 
  Player and for related Player updates.
********************************************/
HackSaw::HackSaw(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "Hack Saw";
	itemChar = '\\';
	isPerishable = false;
	isTreeToNorth = false; 
	isTreeToSouth = false; 
	isTreeToEast = false; 
	isTreeToWest = false;
}
/************************************************************
			            itemInteract	
  Function to interact with HackSaw (a derived Item) when 
  in a space environment (as opposed to the item when carried
  by the player). This is a polymorphic function, declared
  pure virtual in the Item base (abstract) class.
*************************************************************/
void HackSaw::itemInteract()
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
		
		cout << "\nYou Found a Hack Saw!\n"
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
				if (typeid(*thisItem) == typeid(HackSaw))
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
			
			cout << "\nHackSaw added to items.\n";
		}
	}
	else
	{
		cout << "\nYou Found a Hack Saw! But you cannot"
			 << " carry any more items.\nWould you "
			 << "like to drop an item to pick up the Hack Saw? "
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
				if (typeid(*thisItem) == typeid(HackSaw))
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
			
			cout << "\nHack Saw added to items.\n"
				 << itemDropped->getItemName() << " dropped.\n";
		}
	}
}
/******************************************************
			         useStoredItem	
  Function to interact with an item carried by the 
  player (as opposed to interacting with an Item found
  in a Space). This is a polymorphic function, declared
  pure virtual in the Item base (abstract) class.
*******************************************************/
void HackSaw::useStoredItem()
{
	//Gets the Player's current Space Board array and
	//coordinates.
	char** spaceBoard = thePlayer->getPlayerLocation()->
		getSpaceBoard();
	int xCoord = thePlayer->getXCoord();
	int yCoord = thePlayer->getYCoord();
    
	int numberOfSurroundingTrees = 0;
		 
	if (xCoord > 0 && xCoord < BOARDSIZE - 1)
	{	
		if (spaceBoard[xCoord + 1][yCoord] == 'T')
		{
			numberOfSurroundingTrees++;
			isTreeToSouth = true;
		}
		if (spaceBoard[xCoord - 1][yCoord] == 'T')
		{
			numberOfSurroundingTrees++;
			isTreeToNorth = true;
		}
		if (spaceBoard[xCoord][yCoord + 1] == 'T')
		{
			numberOfSurroundingTrees++;
			isTreeToEast = true;
		}
		if (spaceBoard[xCoord][yCoord - 1] == 'T')
		{
			numberOfSurroundingTrees++;
			isTreeToWest = true;
		}
	}
	else if (xCoord == 0)
	{
		if (spaceBoard[xCoord + 1][yCoord] == 'T')
		{
			numberOfSurroundingTrees++;
			isTreeToSouth = true;
		}
		if (spaceBoard[xCoord][yCoord + 1] == 'T')
		{
			numberOfSurroundingTrees++;
			isTreeToEast = true;
		}
		if (spaceBoard[xCoord][yCoord - 1] == 'T')
		{
			numberOfSurroundingTrees++;
			isTreeToWest = true;
		}
	}
	else
	{
		if (spaceBoard[xCoord - 1][yCoord] == 'T')
		{
			numberOfSurroundingTrees++;
			isTreeToNorth = true;
		}
		if (spaceBoard[xCoord][yCoord + 1] == 'T')
		{
			numberOfSurroundingTrees++;
			isTreeToEast = true;
		}
		if (spaceBoard[xCoord][yCoord - 1] == 'T')
		{
			numberOfSurroundingTrees++;
			isTreeToWest = true;
		}
	}
	if (numberOfSurroundingTrees > 0)
	{
		if (numberOfSurroundingTrees > 1)
		{
			cout << "\nWhich tree do you want to cut down?\n"
				 << "(n-north, s-south, e-east, w-west): ";
			char treeChoice = InputValidation::nSEorWcharInputValidation();
			
			if (treeChoice == 'N')
			{
				if (isTreeToNorth)
				{
					spaceBoard[xCoord - 1][yCoord] = ' ';
				}
				else
				{
					cout << "\nKind sir or good lady: There is no tree "
						 << "there.\n";
                    InputValidation::enterKeyPrompt();
				}
			}
			else if (treeChoice == 'S')
			{
				if (isTreeToSouth)
				{
					spaceBoard[xCoord + 1][yCoord] = ' ';
				}
				else
				{
					cout << "\nKind sir or good lady: There is no tree "
						 << "there.\n";
                    InputValidation::enterKeyPrompt();
				}
			}
			else if (treeChoice == 'E')
			{
				if (isTreeToEast)
				{
					spaceBoard[xCoord][yCoord + 1] = ' ';
				}
				else
				{
					cout << "\nKind sir or good lady: There is no tree "
						 << "there.\n";
                    InputValidation::enterKeyPrompt();
				}
			}
			else if (treeChoice == 'W')
			{
				if (isTreeToWest)
				{
					spaceBoard[xCoord][yCoord - 1] = ' ';
				}
				else
				{
					cout << "\nKind sir or good lady: There is no tree "
						 << "there.\n";
                    InputValidation::enterKeyPrompt();
                    
				}
			}
		}
		else
		{
			if (isTreeToNorth)
			{
				spaceBoard[xCoord - 1][yCoord] = ' ';
			}
			else if (isTreeToSouth)
			{
				spaceBoard[xCoord + 1][yCoord] = ' ';
			}
			else if (isTreeToEast)
			{
				spaceBoard[xCoord][yCoord + 1] = ' ';
			}
			else
			{
				spaceBoard[xCoord][yCoord - 1] = ' ';
			}
		}
        if (isTreeToNorth || isTreeToSouth ||
            isTreeToEast || isTreeToWest)
        {
            cout << "\nTree Felled. -0.5 Days\n";
			
            //Because 6 moves equals 1 day, incrementing
			//move count by 3 is equivalent to the
			//passage of 0.5 days.
			thePlayer->setMoveCount();
			thePlayer->setMoveCount();
			thePlayer->setMoveCount();
        }
	}
	else
	{
		cout << "\nThere are no trees nearby to cut down.\n";
	}
    isTreeToNorth = false;
    isTreeToSouth = false;
    isTreeToEast = false;
    isTreeToWest = false;
}
