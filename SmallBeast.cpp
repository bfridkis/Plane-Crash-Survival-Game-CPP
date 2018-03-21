/*************************************************************
** Program name: SmallBeast.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of SmallBeast class member functions. 
				SmallBeast is a derived class of the parent class 
				Item.
**************************************************************/

#include "SmallBeast.hpp"

/**********************************************
			   Constructor
  SmallBeast constructor to establish an
  initial starting coordinates for the
  SmallBeast. Passes xCoord and yCoord 
  parametersto the base class constructor, and 
  establishes the Item's name and character.
  Passes Player object pointer to the base 
  class constructor for interchange of Items
  between the Space and Player.
************************************************/
SmallBeast::SmallBeast(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "Small Beast Meat";
	itemChar = 'b';
	isPerishable = true;
}
/********************************************************
			         itemInteract	
  Function to interact with SmallBeast (a derived Item) 
  when in a space environment (as opposed to an item 
  carried by the player).
*********************************************************/
void SmallBeast::itemInteract()
{
	//Gets the Player's Space Items vector.
    vector<Item*>& playerItems = thePlayer->getPlayerItems();
    
	//A temporary pointer is used to manage the Rifle 
	//(if found). Variables to flag if Player has the rifle
	//and to track rifle ammo are declared.
	Item* playerRifle;
    int rifleAmmo;
    bool foundRifle = false;
	
	//Loops through playerItems to determine if Player has Rifle.
    for (unsigned i = 0; i < playerItems.size() && !foundRifle; i++)
    {
        playerRifle = playerItems.at(i);
        if (typeid(*playerRifle) == typeid(Rifle))
        {
            rifleAmmo = static_cast<Rifle*>(playerRifle)->getAmmo();
            foundRifle = true;
        }
    }
    
	//If Player has Rifle and has ammo > 0, kills the beast,
	//decrements 1 ammo, and prompts Player to either save 
	//beast for later or eat now. Adds health points or adds
	//beast item to playerItems according to user input.
    if (foundRifle && rifleAmmo > 0)
    {
        char** spaceBoard = thePlayer->getPlayerLocation()->
            getSpaceBoard();
        vector<Item*>& spaceItems = thePlayer->
            getPlayerLocation()->getSpaceItems();
        
        static_cast<Rifle*>(playerRifle)->setAmmo(-1);
        thePlayer->printSpace(false);
		
		//If player has capacity to carry item, print 
		//messages to user accordingly.
        if ((thePlayer->getHasBackPack() &&
            thePlayer->getPlayerItemCount() < 4) ||
            thePlayer->getPlayerItemCount() == 0)
        {
            cout << "\nYou Killed a SmallBeast! -1 Ammo\n"
                 << "e - eat now, s - save for later: ";
            char userSelection = 
                InputValidation::_1of2CharactersInputValidation
                    ('E', 'S');
            
            if (userSelection == 'E')
            {
                cout << "\nSmall Beast Meat... YUM! +30 Health Points.\n";
                thePlayer->setHealth(30);
                
                Item* temp = nullptr;
                vector<Item*>::iterator iter = spaceItems.begin();
                for (unsigned i = 0; i < spaceItems.size()
                     && temp == nullptr;
                     i++, iter++)
                {
                    Item* thisItem = spaceItems.at(i);
                    int playerXCoord = thePlayer->getXCoord();
                    int playerYCoord = thePlayer->getYCoord();
                    int itemXCoord = thisItem->getXCoord();
                    int itemYCoord = thisItem->getYCoord();
                    if (typeid(*thisItem) == typeid(SmallBeast) &&
                        ((playerXCoord + 1 == itemXCoord &&
                          playerYCoord == itemYCoord) ||
                         (playerXCoord - 1 == itemXCoord &&
                          playerYCoord == itemYCoord) ||
                         (playerXCoord == itemXCoord &&
                          playerYCoord + 1 == itemYCoord) ||
                         (playerXCoord == itemXCoord &&
                          playerYCoord - 1 == itemYCoord)))
                    {
                        spaceBoard[spaceItems.at(i)->getXCoord()]
                           [spaceItems.at(i)->getYCoord()] = ' ';
                        
                        temp = spaceItems.at(i);
                        
                        delete temp;
                        
                        spaceItems.erase(iter);
                    }
                }
            }
            
            else
            {
                Item* temp = nullptr;
                vector<Item*>::iterator iter = spaceItems.begin();
                for (unsigned i = 0; i < spaceItems.size() && temp == nullptr; 
                     i++, iter++)
                {
                    Item* thisItem = spaceItems.at(i);
                    int playerXCoord = thePlayer->getXCoord();
                    int playerYCoord = thePlayer->getYCoord();
                    int itemXCoord = thisItem->getXCoord();
                    int itemYCoord = thisItem->getYCoord();
                    if (typeid(*thisItem) == typeid(SmallBeast) &&
                        ((playerXCoord + 1 == itemXCoord &&
                          playerYCoord == itemYCoord) ||
                         (playerXCoord - 1 == itemXCoord &&
                          playerYCoord == itemYCoord) ||
                         (playerXCoord == itemXCoord &&
                          playerYCoord + 1 == itemYCoord) ||
                         (playerXCoord == itemXCoord &&
                          playerYCoord - 1 == itemYCoord)))
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
                
                cout << "\nSmall Beast Meat added to items.\n";
            }
        }
		
		//Else if player doesn't have carrying capacity
		//to add another item without dropping a current 
		//item, print prompts accordingly.
        else
        {
            cout << "\nYou Killed a SmallBeast! -1 Ammo\n"
                 << "e - eat now, s - save for later: ";
            char userSelection = InputValidation::
                _1of2CharactersInputValidation ('E', 'S');
            
            if (userSelection == 'E')
            {
                cout << "\nSmall Beast Meat... YUM! +30 Health Points.\n";
                thePlayer->setHealth(30);
                
                Item* temp = nullptr;
                vector<Item*>::iterator iter = spaceItems.begin();
                for (unsigned i = 0; i < spaceItems.size() && temp == nullptr;
                     i++, iter++)
                {
                    Item* thisItem = spaceItems.at(i);
                    int playerXCoord = thePlayer->getXCoord();
                    int playerYCoord = thePlayer->getYCoord();
                    int itemXCoord = thisItem->getXCoord();
                    int itemYCoord = thisItem->getYCoord();
                    if (typeid(*thisItem) == typeid(SmallBeast) &&
                        ((playerXCoord + 1 == itemXCoord &&
                          playerYCoord == itemYCoord) ||
                         (playerXCoord - 1 == itemXCoord &&
                          playerYCoord == itemYCoord) ||
                         (playerXCoord == itemXCoord &&
                          playerYCoord + 1 == itemYCoord) ||
                         (playerXCoord == itemXCoord &&
                          playerYCoord - 1 == itemYCoord)))
                    {
                        spaceBoard[spaceItems.at(i)->getXCoord()]
                        [spaceItems.at(i)->getYCoord()] = ' ';
                        
                        temp = spaceItems.at(i);
                        
                        delete temp;
                        
                        spaceItems.erase(iter);
                    }
                }
            }
            
            else
            {
                cout << "\nYou can't carry any more items.\nWould you "
                     << "like to drop an item to pick up the SmallBeast? "
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
                        int playerXCoord = thePlayer->getXCoord();
                        int playerYCoord = thePlayer->getYCoord();
                        int itemXCoord = thisItem->getXCoord();
                        int itemYCoord = thisItem->getYCoord();
                        if (typeid(*thisItem) == typeid(SmallBeast) &&
                            ((playerXCoord + 1 == itemXCoord &&
                              playerYCoord == itemYCoord) ||
                             (playerXCoord - 1 == itemXCoord &&
                              playerYCoord == itemYCoord) ||
                             (playerXCoord == itemXCoord &&
                              playerYCoord + 1 == itemYCoord) ||
                             (playerXCoord == itemXCoord &&
                              playerYCoord - 1 == itemYCoord)))
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
                    
                    cout << "\nSmallBeast added to items.\n"
                         << itemDropped->getItemName() << " dropped.\n";
                }
            }
        }
    }
	//If player has Rifle but no ammo, print message accordingly
	//and decrement health points. If Player doesn't have the
	//Rifle, print message and decrement health points accordingly.
    else
    {
        if (thePlayer->getHasRifle())
        {
            cout << "\nYou didn't have enough ammo to kill the Small Beast.\n"
                 << "Small Beast has attacked!\n\n-30 Health Points -1 Day\n";
            
            thePlayer->setHealth(-30);
            thePlayer->setRemainingDays();
        }
        else
        {
            cout << "\nYou attacked a Small Beast unarmed!\n"
                 << "Small Beast has attacked back!\n\n-30 Health Points"
                 << " -1 Day\n";
            
            thePlayer->setHealth(-30);
            thePlayer->setRemainingDays();
        }
    }
}
/******************************************************
			         useStoredItem	
  Function to interact with an item carried by the 
  player (as opposed to interacting with an Item found
  in a Space).
*******************************************************/
void SmallBeast::useStoredItem()
{
    cout << "\nSmall Beast Meat... YUM! +30 Health Points\n";
    thePlayer->setHealth(30);
}
