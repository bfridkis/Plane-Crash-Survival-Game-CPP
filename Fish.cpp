/*************************************************************
** Program name: Fish.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of Fish class member functions. 
				Fish is a derived class of the parent class 
				Item.
**************************************************************/

#include "Fish.hpp"

/************************************************
			       Constructor
  Fish constructor to establish an initial 
  starting coordinates for the Fish. Passes 
  xCoord and yCoord parameters to the base class 
  constructor, and establishes the Item's name 
  and character. Passes Player object pointer to 
  the base class constructor for interchange of 
  Items between the Space and Player and for 
  related Player updates.
*************************************************/
Fish::Fish(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "Fish";
	itemChar = '>';
	isPerishable = true;
}
/********************************************************
			         itemInteract	
  Function to interact with Fish (a derived Item) 
  when in a space environment (as opposed to an item 
  carried by the player).
*********************************************************/
void Fish::itemInteract()
{

    if (thePlayer->getHasFishingPole())
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
            
            cout << "\nYou Caught a Fish!\n"
                 << "e - eat now, s - save for later: ";
            char userSelection = 
                InputValidation::_1of2CharactersInputValidation
                    ('E', 'S');
            
            if (userSelection == 'E')
            {
                cout << "Fish... YUM! +25 Health Points.\n";
                thePlayer->setHealth(25);
                
                Item* temp = nullptr;
                vector<Item*>::iterator iter = spaceItems.begin();
                for (unsigned i = 0; i < spaceItems.size()
                     && temp == nullptr; i++, iter++)
                {
                    Item* thisItem = spaceItems.at(i);
                    int playerXCoord = thePlayer->getXCoord();
                    int playerYCoord = thePlayer->getYCoord();
                    int itemXCoord = thisItem->getXCoord();
                    int itemYCoord = thisItem->getYCoord();
                    if (typeid(*thisItem) == typeid(Fish) &&
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
                           [spaceItems.at(i)->getYCoord()] = 'w';
                        
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
                    if (typeid(*thisItem) == typeid(Fish) &&
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
                           [spaceItems.at(i)->getYCoord()] = 'w';
                           
                        spaceItems.at(i)->setXCoord(-1);
                        spaceItems.at(i)->setYCoord(-1);
                        
                        temp = spaceItems.at(i);
                        thePlayer->addItem(temp);
                        
                        spaceItems.erase(iter);
                    }
                }
                
                cout << "\nFish added to items.\n";
            }
        }
        else
        {
            cout << "\nYou Caught a Fish!\n"
                 << "e - eat now, s - save for later: ";
            char userSelection = InputValidation::
                _1of2CharactersInputValidation ('E', 'S');
            
            if (userSelection == 'E')
            {
                cout << "Fish Meat... YUM! +25 Health Points.\n";
                thePlayer->setHealth(25);
                
                Item* temp = nullptr;
                vector<Item*>::iterator iter = spaceItems.begin();
                for (unsigned i = 0; i < spaceItems.size()
                     && temp == nullptr; i++, iter++)
                {
                    Item* thisItem = spaceItems.at(i);
                    int playerXCoord = thePlayer->getXCoord();
                    int playerYCoord = thePlayer->getYCoord();
                    int itemXCoord = thisItem->getXCoord();
                    int itemYCoord = thisItem->getYCoord();
                    if (typeid(*thisItem) == typeid(Fish) &&
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
                        [spaceItems.at(i)->getYCoord()] = 'w';
                        
                        temp = spaceItems.at(i);
                        
                        delete temp;
                        
                        spaceItems.erase(iter);
                    }
                }

            }
            
            else
            {
                cout << "\nYou can't carry any more items.\nWould you "
                     << "like to drop an item to pick up some Fish? "
                     << "(y-yes, n-no): ";
                char userSelection = InputValidation::yOrNInputValidation();
                
                if (userSelection == 'Y')
                {
                    Item* itemDropped = thePlayer->dropItem(userSelection);
                    if (typeid(*itemDropped) == typeid(Raft))
                    {
                        cout << "You can't drop the raft when you're on water. "
                             << "You'd drown!\n";
                        thePlayer->addItem(itemDropped);
                    }
                    else
                    {
                        Item* temp = nullptr;
                        vector<Item*>::iterator iter = spaceItems.begin();
                        for (unsigned i = 0; i < spaceItems.size()
                             && temp == nullptr; i++, iter++)
                        {
                            //Once the item is found based on a typeid check,
                            //swap the item on the Space with the item the player
                            //chose to drop.
                            Item* thisItem = spaceItems.at(i);
                            int playerXCoord = thePlayer->getXCoord();
                            int playerYCoord = thePlayer->getYCoord();
                            int itemXCoord = thisItem->getXCoord();
                            int itemYCoord = thisItem->getYCoord();
                            if (typeid(*thisItem) == typeid(Fish) &&
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
                                [spaceItems.at(i)->getYCoord()] = 'w';
                                
                                spaceItems.at(i)->setXCoord(-1);
                                spaceItems.at(i)->setYCoord(-1);
                                
                                temp = spaceItems.at(i);
                                thePlayer->addItem(temp);
                                
                                spaceItems.erase(iter);
                            }
                        }
                        
                        cout << "\nFish added to items.\n"
                        << itemDropped->getItemName() << " dropped.\n";
                        delete itemDropped;
                    }
                }
            }
        }
    }
    else
    {
        cout << "\nCan't fish without a pole...\n";
    }
}
/******************************************************
			         useStoredItem	
  Function to interact with an item carried by the 
  player (as opposed to interacting with an Item found
  in a Space).
*******************************************************/
void Fish::useStoredItem()
{
    cout << "\nFish... YUM! +25 Health Points\n";
    thePlayer->setHealth(25);
}
