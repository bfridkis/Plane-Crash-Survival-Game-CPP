/*************************************************************
** Program name: BerryBush.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Definition of BerryBush class member functions. 
				BerryBush is a derived class of the parent class 
				Item.
**************************************************************/

#include "BerryBush.hpp"

/************************************************
				   Constructor
  BerryBush constructor to establish an initial 
  starting coordinates for the BerryBush. 
  Passes xCoord and yCoord parameters to the 
  base class constructor, and establishes the 
  Item's name and character. Passes Player object 
  pointer to the base class constructor for 
  interchange of Items between the Space and 
  Player and for related Player updates.
*************************************************/
BerryBush::BerryBush(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "Berries";
	itemChar = '%';
	isPerishable = true;
}
/********************************************************
			         itemInteract	
  Function to interact with BerryBush (a derived Item) 
  when in a space environment (as opposed to an item 
  carried by the player).
*********************************************************/
void BerryBush::itemInteract()
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
        
        cout << "\nYou Found a BerryBush!\n"
             << "e - eat now, s - save for later: ";
        char userSelection = 
            InputValidation::_1of2CharactersInputValidation
                ('E', 'S');
        
        if (userSelection == 'E')
        {
            cout << "\nBerries... YUM! +30 Health Points.\n";
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
                if (typeid(*thisItem) == typeid(BerryBush) &&
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
                if (typeid(*thisItem) == typeid(BerryBush) &&
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
            
            cout << "\nBerries added to items.\n";
        }
    }
    else
    {
        cout << "\nYou Found a BerryBush!\n"
             << "e - eat now, s - save for later: ";
        char userSelection = InputValidation::
            _1of2CharactersInputValidation ('E', 'S');
        
        if (userSelection == 'E')
        {
            cout << "\nBerries... YUM! +30 Health Points.\n";
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
                if (typeid(*thisItem) == typeid(BerryBush) &&
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
                 << "like to drop an item to pick up some Berries? "
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
                    if (typeid(*thisItem) == typeid(BerryBush) &&
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
                
                cout << "\nBerries added to items.\n"
                     << itemDropped->getItemName() << " dropped.\n";
            }
        }
    }
}
/******************************************************
			         useStoredItem	
  Function to interact with an item carried by the 
  player (as opposed to interacting with an Item found
  in a Space).
*******************************************************/
void BerryBush::useStoredItem()
{
    cout << "\nBerries... YUM! +30 Health Points\n";
    thePlayer->setHealth(30);
}
