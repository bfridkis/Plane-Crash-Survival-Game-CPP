/*************************************************************
** Program name: NutGrove.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Defintion of NutGrove class member functions. 
				NutGrove is a derived class of the parent class 
				Item.
**************************************************************/

#include "NutGrove.hpp"

/**********************************************
			   Constructor
  NutGrove constructor to establish an
  initial starting coordinates for the
  NutGrove. Passes xCoord and yCoord parameters
  to the base class constructor, and 
  establishes the Item's name and character.
  Passes Player object pointer to the base 
  class constructor for interchange of Items
  between the Space and Player and for related
  Player updates.
***********************************************/
NutGrove::NutGrove(int xCoord, int yCoord,
	Player* player) : 
	Item(xCoord, yCoord, player)
{
	itemName = "Nuts";
	itemChar = 'n';
	isPerishable = true;
}
/********************************************************
			         itemInteract	
  Function to interact with NutGrove (a derived Item) 
  when in a space environment (as opposed to an item 
  carried by the player).
*********************************************************/
void NutGrove::itemInteract()
{
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
        
        cout << "\nYou Found a NutGrove!\n"
             << "e - eat now, s - save for later: ";
        char userSelection = 
            InputValidation::_1of2CharactersInputValidation
                ('E', 'S');
        
        if (userSelection == 'E')
        {
            cout << "\nNuts... YUM! +25 Health Points.\n";
            thePlayer->setHealth(25);
            
			//If Item is consumed up, Player's health is
			//incremented. For loop finds the item match
			//based on player coordinates and item coordinates,
			//then sets the spaceBoard occupied by the Item to
			//a whitespace character. The item is then deleted
			//and erased from the Player location spaceItems 
			//vector.
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
                if (typeid(*thisItem) == typeid(NutGrove) &&
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
				//Similar logic to above but Item is added to
				//playerItems vector rather than being deleted
				//if user prompt dictates save instead of eat.
                Item* thisItem = spaceItems.at(i);
                int playerXCoord = thePlayer->getXCoord();
                int playerYCoord = thePlayer->getYCoord();
                int itemXCoord = thisItem->getXCoord();
                int itemYCoord = thisItem->getYCoord();
                if (typeid(*thisItem) == typeid(NutGrove) &&
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
            
            cout << "\nNuts added to items.\n";
        }
    }
	//Same as previous if block but informs user of max
	//carrying capacity if user prompt dictates saving
	//Item. User is given the option of dropping an existing
	//Item to save this Item.
    else
    {
        cout << "\nYou Found a NutGrove!\n"
             << "e - eat now, s - save for later: ";
        char userSelection = InputValidation::
            _1of2CharactersInputValidation ('E', 'S');
        
        if (userSelection == 'E')
        {
            cout << "\nNuts... YUM! +25 Health Points.\n";
            thePlayer->setHealth(25);
            
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
                if (typeid(*thisItem) == typeid(NutGrove) &&
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
                 << "like to drop an item to pick up some Nuts? "
                 << "(y-yes, n-no): ";
            char userSelection = InputValidation::yOrNInputValidation();
            
            if (userSelection == 'Y')
            {
                Item* itemDropped = thePlayer->dropItem(userSelection);
                
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
                    if (typeid(*thisItem) == typeid(NutGrove) &&
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
                
                cout << "\nNuts added to items.\n"
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
void NutGrove::useStoredItem()
{
    cout << "\nNuts... YUM! +25 Health Points\n";
    thePlayer->setHealth(25);
}

