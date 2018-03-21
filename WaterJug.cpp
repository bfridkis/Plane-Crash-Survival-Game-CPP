/***************************************************************
** Program name: WaterJug.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of WaterJug class member functions. 
				WaterJug is a derived class of the parent class 
				Item.
****************************************************************/

#include "WaterJug.hpp"

const int BOARDSIZE = 25;

/******************************************
			   Constructor
  WaterJug constructor to establish the
  initial starting coordinates for the
  WaterJug. Passes xCoord and yCoord 
  parameters to the base class constructor, 
  and establishes the Item's name and 
  board space character. Passes Player
  object pointer to the base class 
  constructor for interchange of Items
  between the Space and Player and for 
  related Player updates.
*******************************************/
WaterJug::WaterJug(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "WaterJug";
	itemChar = '+';
	isPerishable = false;
    drinkCount = 5;
	playerXCoordAtTimeOfLastDrink = -1;
	playerYCoordAtTimeOfLastDrink = -1;
	drinkCountWithoutMoving = 0;
	hasMovedSinceLastDrink = true;
}
/************************************************************
			            itemInteract	
  Function to interact with WaterJug (a derived Item) when 
  in a space environment (as opposed to the item when carried
  by the player). This is a polymorphic function, declared
  pure virtual in the Item base (abstract) class.
*************************************************************/
void WaterJug::itemInteract()
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
		
		cout << "\nYou Found a Water Jug!\n"
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
				if (typeid(*thisItem) == typeid(WaterJug))
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
			
			cout << "\nWater Jug added to items.\n";
		}
	}
	else
	{
		cout << "\nYou Found a Water Jug! But you cannot"
			 << " carry any more items.\nWould you "
			 << "like to drop an item to pick up the WaterJug? "
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
				//swap the item on the Space with the Item the Player
				//chose to drop.
                Item* thisItem = spaceItems.at(i);
				if (typeid(*thisItem) == typeid(WaterJug))
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
			
			cout << "\nWater Jug added to items.\n"
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
void WaterJug::useStoredItem()
{
	cout << "\nDrink or Fill? (d-drink, f-fill): ";
	char userSelection = 
			InputValidation::
				_1of2CharactersInputValidation('D', 'F');
	
	//If "Drink" is chosen, adds health points, 
	//decrements jug remaining drink count, and
	//adds health points to player. Prints message
	//accordingly.
	if (userSelection == 'D')
	{
		if (drinkCount > 0)
		{
			//Gets player coordinates to check if player
			//has moved since the last drink.
			int playerXCoord = thePlayer->getXCoord();
			int playerYCoord = thePlayer->getYCoord();
			
			thePlayer->setHealth(10);
			drinkCount -= 1;
            cout << "\n+10 Health Points. " << drinkCount
                 << " drinks remain.\n";
			
			//This if block penalizes the player when drinking 
			//from the jug more than 5 times in a row
			//without moving by decrementing 1 Day from remaining
			//days.
			if (playerXCoordAtTimeOfLastDrink == playerXCoord &&
					playerYCoordAtTimeOfLastDrink == playerYCoord)
				{
					hasMovedSinceLastDrink = false;
					drinkCountWithoutMoving++;
				}
				else
				{
					hasMovedSinceLastDrink = true;
					drinkCountWithoutMoving = 0;
				}
				
				if (drinkCountWithoutMoving == 5)
				{
					cout << "\nCan't just chug all day. "
						 << "Gotta keep moving!\n\n-1 Day\n";
					thePlayer->setRemainingDays();
				}
				
				playerXCoordAtTimeOfLastDrink = playerXCoord;
				playerYCoordAtTimeOfLastDrink = playerYCoord;	 
		}
		else
		{
			cout << "\nEmpty jug. Bummer.\n";
		}
	}
	//If "Fill" is chosen, checks for adjacent water space.
	//If water space is found, fills jug and prints message
	//accordingly. If not, prints message accordingly.
	else
	{
        char** spaceBoard = thePlayer->getPlayerLocation()->
            getSpaceBoard();
        int playerXCoord = thePlayer->getXCoord();
        int playerYCoord = thePlayer->getYCoord();
        if (playerXCoord == 0)
        {
			//If the player is at the top row, won't check x coord - 1
			//because attempting to access outside the bounds of the first
			//dimension of a dynamically allocated 2D array faults the 
			//program.
            if ((spaceBoard[playerXCoord + 1][playerYCoord] == 'w') ||
                (spaceBoard[playerXCoord][playerYCoord + 1] == 'w') ||
                (spaceBoard[playerXCoord][playerYCoord - 1] == 'w'))
            {
                drinkCount = 5;
                cout << "\nJug filled. 5 drinks remain.\n";
            }
            else
            {
                cout << "\nThere's no water nearby...\n";
            }
        }
		else if (playerXCoord == BOARDSIZE - 1)
        {
			//If the player is at the bottom row, won't check x coord - 1
			//because attempting to access outside the bounds of the first
			//dimension of a dynamically allocated 2D array faults the 
			//program.
            if ((spaceBoard[playerXCoord - 1][playerYCoord] == 'w') ||
                (spaceBoard[playerXCoord][playerYCoord + 1] == 'w') ||
                (spaceBoard[playerXCoord][playerYCoord - 1] == 'w'))
            {
                drinkCount = 5;
                cout << "\nJug filled. 5 drinks remain.\n";
            }
            else
            {
                cout << "\nThere's no water nearby...\n";
            }
        }
        else
        {
            if ((spaceBoard[playerXCoord + 1][playerYCoord] == 'w') ||
                (spaceBoard[playerXCoord - 1][playerYCoord] == 'w') ||
                (spaceBoard[playerXCoord][playerYCoord + 1] == 'w') ||
                (spaceBoard[playerXCoord][playerYCoord - 1] == 'w'))
            {
                drinkCount = 5;
                cout << "\nJug filled. 5 drinks remain.\n";
            }
            else
            {
                cout << "\nThere's no water nearby...\n";
            }
        }
	}
}
