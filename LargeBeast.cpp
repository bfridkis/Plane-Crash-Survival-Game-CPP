/*************************************************************
** Program name: LargeBeast.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of LargeBeast class member functions. 
				LargeBeast is a derived class of the parent class 
				Item.
**************************************************************/

#include "LargeBeast.hpp"

/***********************************************
			   Constructor
  LargeBeast constructor to establish an
  initial starting coordinates for the
  LargeBeast. Passes xCoord and yCoord 
  parameters to the base class constructor, 
  and establishes the Item's name and character.
  Passes Player object pointer to the base class 
  constructor for interchange of Items between 
  the Space and Player and for related Player
  updates.
*************************************************/
LargeBeast::LargeBeast(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "Large Beast Meat";
	itemChar = 'B';
	isPerishable = true;
}
/********************************************************
			         itemInteract	
  Function to interact with LargeBeast (a derived Item) 
  when in a space environment (as opposed to an item 
  carried by the player).
*********************************************************/
void LargeBeast::itemInteract()
{
    vector<Item*>& playerItems = thePlayer->getPlayerItems();
    Item* playerRifle = nullptr;
    int rifleAmmo;
    bool foundRifle = false;
    for (unsigned i = 0; i < playerItems.size() && !foundRifle; i++)
    {
        playerRifle = playerItems.at(i);
        if (typeid(*playerRifle) == typeid(Rifle))
        {
            foundRifle = true;
            rifleAmmo = static_cast<Rifle*>(playerRifle)->getAmmo();
        }
    }
    
    if (foundRifle && rifleAmmo >= 2)
    {
        char** spaceBoard = thePlayer->getPlayerLocation()->
            getSpaceBoard();
        vector<Item*>& spaceItems = thePlayer->
            getPlayerLocation()->getSpaceItems();
        
        static_cast<Rifle*>(playerRifle)->setAmmo(-2);
        thePlayer->printSpace(false);

        if ((thePlayer->getHasBackPack() &&
            thePlayer->getPlayerItemCount() < 4) ||
            thePlayer->getPlayerItemCount() == 0)
        {
            
            cout << "\nYou Killed a LargeBeast! -2 Ammo\n"
                 << "e - eat now, s - save for later: ";
            char userSelection = 
                InputValidation::_1of2CharactersInputValidation
                    ('E', 'S');
            
            if (userSelection == 'E')
            {
                cout << "\nLarge Beast Meat... YUM! +50 Health Points.\n";
                thePlayer->setHealth(50);
                
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
                    if (typeid(*thisItem) == typeid(LargeBeast) &&
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
            
            if (userSelection == 'S')
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
                    if (typeid(*thisItem) == typeid(LargeBeast) &&
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
                
                cout << "\nLarge Beast Meat added to items.\n";
            }
        }
        else
        {
            cout << "\nYou Killed a LargeBeast! -2 Ammo\n"
                 << "e - eat now, s - save for later: ";
            char userSelection = InputValidation::
                _1of2CharactersInputValidation ('E', 'S');
            
            if (userSelection == 'E')
            {
                cout << "\nLarge Beast Meat... YUM! +50 Health Points.\n";
                thePlayer->setHealth(50);
                
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
                    if (typeid(*thisItem) == typeid(LargeBeast) &&
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
                     << "like to drop an item to pick up the LargeBeast? "
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
                        if (typeid(*thisItem) == typeid(LargeBeast) &&
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
                    
                    cout << "\nLargeBeast added to items.\n"
                         << itemDropped->getItemName() << " dropped.\n";
                }
            }
        }
    }
    else if (foundRifle)
    {
        if (rifleAmmo == 1)
        {
            static_cast<Rifle*>(playerRifle)->setAmmo(-1);
            thePlayer->printSpace(false);
            
            cout << "\nYou didn't have enough ammo to kill the Large Beast.\n"
                 << "Large Beast has attacked back!\n\n-35 Health Points -1 Ammo "
                 << "-1 Day\n";
            
            thePlayer->setHealth(-35);
            thePlayer->setRemainingDays();
        }
        else
        {
            thePlayer->printSpace(false);
            cout << "\nYou didn't have enough ammo to kill the Large Beast.\n"
                 << "Large Beast has attacked back!\n\n-50 Health Points "
                 << "-2 Days\n";
            
            thePlayer->setHealth(-50);
            thePlayer->setRemainingDays();
            thePlayer->setRemainingDays();
        }
    }
    else
    {
        thePlayer->printSpace(false);
        cout << "\nYou attacked a Large Beast unarmed!\n"
             << "Large Beast has attacked back!\n\n-50 Health Points"
             << " -2 Days\n";
            
            thePlayer->setHealth(-50);
            thePlayer->setRemainingDays();
            thePlayer->setRemainingDays();
    }
}
/******************************************************
			         useStoredItem	
  Function to interact with an item carried by the 
  player (as opposed to interacting with an Item found
  in a Space).
*******************************************************/
void LargeBeast::useStoredItem()
{
    cout << "\nLarge Beast Meat... YUM! +50 Health Points\n";
    thePlayer->setHealth(50);
}
