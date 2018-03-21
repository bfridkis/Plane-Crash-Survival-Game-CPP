/**********************************************************
** Program name: Player.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Player Class member function definitions.
**********************************************************/

#include "Player.hpp"

const int BOARDSIZE = 25;

/****************************************
			   Constructor
  Player constructor to establish an
  initial starting Space and coordinates
  therein. Also sets initial health
  value and hasBackPack, hasRaft, and
  hasKey flags.
****************************************/
Player::Player(int difficultyLevel)
{
	xCoord = 2;
	yCoord = 14;
	playerLocation = nullptr;
    moveCount = 0;
	playerHealth = 1500;
	if (difficultyLevel == 1)
	{
		remainingDays = 90;
	}
	else
	{
		remainingDays = 80;
	}
	hasBackPack = false;
    hasRifle= false;
    hasFishingPole = false;
	hasRaft = false;
	hasKey = false;
	hasTransmitted = false;
	previousSpaceWasWater = false;
	this->difficultyLevel = difficultyLevel;
}
/************************************
			  getXCoord
  Accessor to get xCoord data member.
*************************************/
int Player::getXCoord() const
{
	return xCoord;
}
/************************************
			  getYCoord
  Accessor to get yCoord data member.
*************************************/
int Player::getYCoord() const
{
	return yCoord;
}
/************************************
			  setXCoord
  Mutator to get xCoord data member.
*************************************/
void Player::setXCoord(int xCoord)
{
	this->xCoord = xCoord;
}
/************************************
			  setYCoord
  Mutator to get yCoord data member.
*************************************/
void Player::setYCoord(int yCoord)
{
	this->yCoord = yCoord;
}
/************************************
		  getPlayerLocation
  Accessor to return a pointer to 
  the playerLocation data member.
*************************************/
Space* Player::getPlayerLocation()
{
	return playerLocation;
}
/*************************************************
		        setPlayerLocation
  Mutator to modify the pointer playerLocation 
  data member.
**************************************************/
void Player::setPlayerLocation(Space* newLocation)
{
	playerLocation = newLocation;
}
/************************************
		  getPlayerItemCount
  Returns the size of the playerItems
  vector.
*************************************/
int Player::getPlayerItemCount() const
{
	return playerItems.size();
}
/*****************************************
		         addItem
  Adds an Item pointer to the playerItems
  vector.
******************************************/
void Player::addItem(Item* itemToAdd)
{
	playerItems.push_back(itemToAdd);
}
/***********************************************************
						  dropItem
  Drops an Item pointer from the playerItems vector. Returns
  a pointer to the dropped Item. Parameter itemNumberToDrop 
  provides identifier for which item to drop. Flags hasRaft
  false if Raft is dropped, hasFishingPole false if Fishing
  Pole is dropped, and hasRifle false if Rifle is dropped.
************************************************************/
Item* Player::dropItem(int itemNumberToDrop)
{
	cout << "\nWhich item would you like to drop?\n";
	
	printItems();
	int userSelection = InputValidation::intInputValidation
		(playerItems.size(), 1);
				
	vector<Item*>::iterator iter = playerItems.begin() 
		+ (userSelection - 1);	
	
	Item* itemToReturn = *iter;
	
	if (typeid(*itemToReturn) == typeid(Raft))
	{
		hasRaft = false;
	}
    else if (typeid(*itemToReturn) == typeid(FishingPole))
    {
        hasFishingPole = false;
    }
    else if (typeid(*itemToReturn) == typeid(Rifle))
    {
        hasRifle = false;
    }
	else if (typeid(*itemToReturn) == typeid(LargeBeast) ||
			 typeid(*itemToReturn) == typeid(SmallBeast))
	{
		cout << "\nAh! The beast came back to life!\n";
	}
	
	playerItems.erase(iter);
	
	return itemToReturn;
}
/***********************************************************
						 useItem
  Uses a Player's picked up items based on user selection.
************************************************************/
void Player::useItem()
{	
	printItems();
	if (playerItems.size() > 0)
	{	
		cout << "Enter Number of Item to Use, or 0 to cancel.\n\n";
		int userSelection = InputValidation::intInputValidation
			(playerItems.size(), 0);
			
		if (userSelection != 0)
		{	
			vector<Item*>::
				iterator iter = playerItems.begin() 
				+ (userSelection - 1);
				
			(*iter)->useStoredItem();
            
            if ((*iter)->getIsPerishable())
            {
                delete *iter;
                playerItems.erase(iter);
            }
		}	
	}
}
/***************************************************
					 printItems
  Prints the names of the Items in the playerItems 
  data member.
****************************************************/
void Player::printItems() const
{
	if (playerItems.size() > 0)
	{
		cout << endl;
		for (unsigned i = 0; i < playerItems.size(); i++)
		{
			cout << i + 1 << ".  " 
				 << playerItems.at(i)->getItemName()
				 << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "\nYou currently have no items.\n" 
			 << endl;
	}
    if (hasKey)
    {
        cout << "\n**You have the Key**\n" << endl;
    }
}
/******************************************
		     getPlayerItems
  Accessor to return a reference to the 
  vector of Item pointers (playerItems)
  data memeber.
*******************************************/
vector<Item*>& Player::getPlayerItems()
{
	return playerItems;
}
/******************************************
              getMoveCount
  Accessor to get moveCount data member.
*******************************************/
int Player::getMoveCount() const
{
	return moveCount;
}
/*********************************************
			   setMoveCount
  Mutator to set moveCount data member +1.
**********************************************/
void Player::setMoveCount()
{
	moveCount++;
}
/******************************************
		        getHealth
  Accessor to get playerHealth data member.
*******************************************/
int Player::getHealth() const
{
	return playerHealth;
}
/*********************************************
				setHealth
  Mutator to set playerHealth data member.
**********************************************/
void Player::setHealth(int healthChange)
{
	if (healthChange != 0)
	{	
		playerHealth += healthChange;
	}
	else
	{
		playerHealth = 0;
	}
}
/******************************************
		      getRemainingDays
  Accessor to get remainingDays data member.
*******************************************/
int Player::getRemainingDays() const
{
	return remainingDays;
}
/*********************************************
			 setRemainingDays
  Mutator to set remainingDays data member.
**********************************************/
void Player::setRemainingDays()
{
	remainingDays--;
}
/******************************************
		   getHasBackPack
  Accessor to get hasBackPack data member.
*******************************************/
bool Player::getHasBackPack() const
{
	return hasBackPack;
}
/************************************
				getHasKey
  Accessor to get hasKey data member.
*************************************/
bool Player::getHasKey() const
{
	return hasKey;
}
/************************************
			getHasRaft
  Accessor to get hasRaft data member.
*************************************/
bool Player::getHasRaft() const
{
	return hasRaft;
}
/************************************
         getHasFishingPole
  Accessor to get hasFishingPole data 
  member.
*************************************/
bool Player::getHasFishingPole() const
{
	return hasFishingPole;
}
/**************************************
			  getHasRifle
  Accessor to get hasRifle data member.
****************************************/
bool Player::getHasRifle() const
{
	return hasRifle;
}
/********************************************
		       getHasTransmitted
  Accessor to get hasTransmitted data member.
*********************************************/
bool Player::getHasTransmitted() const
{
	return hasTransmitted;
}
/********************************************
		    getPreviousSpaceWasWater
  Accessor to get previousSpaceWasWater 
  data member.
*********************************************/
bool Player::getPreviousSpaceWasWater() const
{
	return previousSpaceWasWater;
}
/*******************************************
		     setHasBackPack
  Mutator to set hasBackPack data member.
********************************************/
void Player::setHasBackPack(bool toggleFlag)
{
	hasBackPack = toggleFlag;
}
/*******************************************
		         setHasKey
     Mutator to set hasKey data member.
********************************************/
void Player::setHasKey()
{
	hasKey = true;
}
/*******************************************
		         setHasRaft
     Mutator to set hasRaft data member.
********************************************/
void Player::setHasRaft(bool toggleFlag)
{
	hasRaft = toggleFlag;
}
/**********************************************
           setHasFishingPole
  Mutator to set hasFishingPole data member.
***********************************************/
void Player::setHasFishingPole(bool toggleFlag)
{
	hasFishingPole = toggleFlag;
}
/*******************************************
               setHasRifle
     Mutator to set hasRifle data member.
********************************************/
void Player::setHasRifle(bool toggleFlag)
{
	hasRifle = toggleFlag;
}
/*******************************************
		     setHasTransmitted
  Mutator to set hasTransmitted data member.
********************************************/
void Player::setHasTransmitted()
{
	hasTransmitted = true;
}
/*******************************************
		  setPreviousSpaceWasWater
  Mutator to set previousSpaceWasWater data 
  member.
********************************************/
void Player::setPreviousSpaceWasWater
	(bool toggleFlag)
{
	previousSpaceWasWater = toggleFlag;
}
/*******************************************
			     movePlayer
  Moves the player within the game board
  based on character input from user.
  Player can only move to an empty space.
  If player attempts to move into a non-
  empty space, a message prints accordingly.
  If a move executes, player's health is
  decreased by 5 points, and for every 6
  moves made 1 day is decremented from 
  remaining days. Also provides a block 
  at the end of the move to call the 
  Player's current Space catastrophe 
  function at 1 to 10 odds (i.e. a random
  number is generated and if that random
  number is a factor of 10 catastrophe is
  called).
********************************************/
void Player::movePlayer(char moveDirection)
{
	char** spaceBoard = 
		playerLocation->getSpaceBoard();
		
	if (moveDirection == 'I')
	{
		//Uses variable previousSpaceWasWater to 
		//track if the Player was previously in
		//a water position. If so, the Space 
		//coordinates are returned to 'w'.
		if (previousSpaceWasWater == true)
		{	
			spaceBoard[xCoord][yCoord] = 'w';
			//Only checks all four adjacent spaces when direction
			//is up if player is not at top row (as attempting to
			//access outside the bounds of the array will result in
			//a segmentation fault.)
			if (xCoord > 0)
			{	
				if (spaceBoard[xCoord - 1][yCoord] == ' ')
				{	
					xCoord--;
                    setMoveCount();
					setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = false;
				}
				else if (spaceBoard[xCoord - 1][yCoord] == 'w')
				{
					xCoord--;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = true;
				}
				else
				{
                    if (spaceBoard[xCoord - 1][yCoord] == 'T')
                    {
                        cout << "\nJust a tree..." << endl;
                    }
                    else
                    {
                        cout << "\n\nThere's something in your way or\n"
                             << "you are trying to venture too far away!\n"
                             << endl;
                    }
				}
			}
			//Will not get x coordinate - 1 if player is at top
			//row to avoid segmentation fault caused by an
			//attempt to access outside the bounds of the spaceBoard
			//array.
			else if (xCoord == 0)
			{
				playerLocation = playerLocation->
					getSpacePointer(moveDirection);
				
				xCoord = BOARDSIZE - 1;
                setMoveCount();
                setHealth(-5);
                if (moveCount % 6 == 0){setRemainingDays();}
			}
		}
		//Same logic as above but previousSpaceWasWater is 
		//false, so Player's coordinates spaceBoard character
		//before the move is set back to a whitespace character.
		else
		{
			spaceBoard[xCoord][yCoord] = ' ';
			if (xCoord > 0)
			{	
				if (spaceBoard[xCoord - 1][yCoord] == ' ')
				{	
					xCoord--;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = false;
				}
				else if (spaceBoard[xCoord - 1][yCoord] == 'w')
				{	
					if (hasRaft)
					{	
						xCoord--;
                        setMoveCount();
                        setHealth(-5);
                        if (moveCount % 6 == 0){setRemainingDays();}
						previousSpaceWasWater = true;
					}
					else
					{
						cout << "\nYou drowned!\n"
							 << "(Next time you might want to try a raft.)"
							 << endl;
						
						setHealth(0);
					}
				}
				else
				{
                    if (spaceBoard[xCoord - 1][yCoord] == 'T')
                    {
                        cout << "\nJust a tree..." << endl;
                    }
                    else
                    {
                        cout << "\n\nThere's something in your way or\n"
                        << "you are trying to venture too far away!\n"
                        << endl;
                    }
				}
			}
			else if (xCoord == 0)
			{
				playerLocation = playerLocation->
					getSpacePointer(moveDirection);
				
				xCoord = BOARDSIZE - 1;
                setMoveCount();
                setHealth(-5);
                if (moveCount % 6 == 0){setRemainingDays();}
			}
		}
	}
	//Same logic as previous if block, but checks if player
	//is in the bottom row and if so will not attempt to access
	//x + 1 so as to avoid segmentation fault.
	else if (moveDirection == 'K')
	{
		if (previousSpaceWasWater == true)
		{	
			spaceBoard[xCoord][yCoord] = 'w';
			if (xCoord < BOARDSIZE - 1)
			{	
				if (spaceBoard[xCoord + 1][yCoord] == ' ')
				{	
					xCoord++;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = false;
				}
				else if (spaceBoard[xCoord + 1][yCoord] == 'w')
				{
					xCoord++;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = true;
				}
				else
				{
                    if (spaceBoard[xCoord + 1][yCoord] == 'T')
                    {
                        cout << "\nJust a tree...\n" << endl;
                    }
                    else
                    {
                        cout << "\n\nThere's something in your way or\n"
                        << "you are trying to venture too far away!\n"
                        << endl;
                    }
				}
			}
			else if (xCoord == BOARDSIZE - 1)
			{
				playerLocation = playerLocation->
					getSpacePointer(moveDirection);
				
				xCoord = 0;
                setMoveCount();
                setHealth(-5);
                if (moveCount % 6 == 0){setRemainingDays();}
			}
		}
		else
		{
			spaceBoard[xCoord][yCoord] = ' ';
			if (xCoord < BOARDSIZE - 1)
			{	
				if (spaceBoard[xCoord + 1][yCoord] == ' ')
				{	
					xCoord++;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = false;
				}
				else if (spaceBoard[xCoord + 1][yCoord] == 'w')
				{	
					if (hasRaft)
					{	
						xCoord++;
                        setMoveCount();
                        setHealth(-5);
                        if (moveCount % 6 == 0){setRemainingDays();}
						previousSpaceWasWater = true;
					}
					else
					{
						cout << "\nYou drowned!\n"
							 << "(Next time you might want to try a raft.)"
							 << endl;
						
						setHealth(0);
					}
				}
				else
				{
                    if (spaceBoard[xCoord + 1][yCoord] == 'T')
                    {
                        cout << "\nJust a tree..." << endl;
                    }
                    else
                    {
                        cout << "\n\nThere's something in your way or\n"
                        << "you are trying to venture too far away!\n"
                        << endl;
                    }
				}
			}
			else if (xCoord == BOARDSIZE - 1)
			{
				playerLocation = playerLocation->
					getSpacePointer(moveDirection);
				
				xCoord = 0;
                setMoveCount();
                setHealth(-5);
                if (moveCount % 6 == 0){setRemainingDays();}
			}
		}
	}
	//Same logic as previous else if block, but checks if player
	//is in the far right column and if so will not attempt to access
	//y + 1 so as to avoid segmentation fault.
	else if (moveDirection == 'L')
	{
		if (previousSpaceWasWater == true)
		{	
			spaceBoard[xCoord][yCoord] = 'w';
			if (yCoord < BOARDSIZE - 1)
			{	
				if (spaceBoard[xCoord][yCoord + 1] == ' ')
				{	
					yCoord++;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = false;
				}
				else if (spaceBoard[xCoord][yCoord + 1] == 'w')
				{
					yCoord++;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = true;
				}
				else
				{
                    if (spaceBoard[xCoord][yCoord + 1] == 'T')
                    {
                        cout << "\nJust a tree..." << endl;
                    }
                    else
                    {
                        cout << "\n\nThere's something in your way or\n"
                        << "you are trying to venture too far away!\n"
                        << endl;
                    }
				}
			}
			else if (yCoord == BOARDSIZE - 1)
			{
				playerLocation = playerLocation->
					getSpacePointer(moveDirection);
				
				yCoord = 0;
                setMoveCount();
                setHealth(-5);
                if (moveCount % 6 == 0){setRemainingDays();}
			}
		}
		else
		{
			spaceBoard[xCoord][yCoord] = ' ';
			if (yCoord < BOARDSIZE - 1)
			{	
				if (spaceBoard[xCoord][yCoord + 1] == ' ')
				{	
					yCoord++;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = false;
				}
				else if (spaceBoard[xCoord][yCoord + 1] == 'w')
				{	
					if (hasRaft)
					{	
						yCoord++;
                        setMoveCount();
                        setHealth(-5);
                        if (moveCount % 6 == 0){setRemainingDays();}
						previousSpaceWasWater = true;
					}
					else
					{
						cout << "\nYou drowned!\n"
							 << "(Next time you might want to try a raft.)"
							 << endl;
						
						setHealth(0);
					}
				}
				else
				{
                    if (spaceBoard[xCoord][yCoord + 1] == 'T')
                    {
                        cout << "\nJust a tree..." << endl;
                    }
                    else
                    {
                        cout << "\n\nThere's something in your way or\n"
                        << "you are trying to venture too far away!\n"
                        << endl;
                    }
				}
			}
			else if (yCoord == BOARDSIZE - 1)
			{
				playerLocation = playerLocation->
					getSpacePointer(moveDirection);
				
				yCoord = 0;
                setMoveCount();
                setHealth(-5);
                if (moveCount % 6 == 0){setRemainingDays();}
			}
		}
	}
	//Same logic as previous else if block, but checks if player
	//is in the far left column and if so will not attempt to access
	//y - 1 so as to avoid segmentation fault.
	else if (moveDirection == 'J')
	{
		if (previousSpaceWasWater == true)
		{	
			spaceBoard[xCoord][yCoord] = 'w';
			if (yCoord > 0)
			{	
				if (spaceBoard[xCoord][yCoord - 1] == ' ')
				{	
					yCoord--;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = false;
				}
				else if (spaceBoard[xCoord][yCoord - 1] == 'w')
				{
					yCoord--;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = true;
				}
				else
				{
                    if (spaceBoard[xCoord][yCoord - 1] == 'T')
                    {
                        cout << "\nJust a tree..." << endl;
                    }
                    else
                    {
                        cout << "\n\nThere's something in your way or\n"
                        << "you are trying to venture too far away!\n"
                        << endl;
                    }
				}
			}
			else if (yCoord == 0)
			{
				playerLocation = playerLocation->
					getSpacePointer(moveDirection);
				
				yCoord = BOARDSIZE - 1;
                setMoveCount();
                setHealth(-5);
                if (moveCount % 6 == 0){setRemainingDays();}
			}
		}
		else
		{
			spaceBoard[xCoord][yCoord] = ' ';
			if (yCoord > 0)
			{	
				if (spaceBoard[xCoord][yCoord - 1] == ' ')
				{	
					yCoord--;
                    setMoveCount();
                    setHealth(-5);
                    if (moveCount % 6 == 0){setRemainingDays();}
					previousSpaceWasWater = false;
				}
				else if (spaceBoard[xCoord][yCoord - 1] == 'w')
				{	
					if (hasRaft)
					{	
						yCoord--;
                        setMoveCount();
                        setHealth(-5);
                        if (moveCount % 6 == 0){setRemainingDays();}
						previousSpaceWasWater = true;
					}
					else
					{
						cout << "\nYou drowned!\n"
							 << "(Next time you might want to try a raft.)"
							 << endl;
						
						setHealth(0);
					}
				}
				else
				{
                    if (spaceBoard[xCoord][yCoord - 1] == 'T')
                    {
                        cout << "\n\nJust a tree..." << endl;
                    }
                    else
                    {
                        cout << "\n\nThere's something in your way or\n"
                        << "you are trying to venture too far away!\n"
                        << endl;
                    }
				}
			}
			else if (yCoord == 0)
			{
				playerLocation = playerLocation->
					getSpacePointer(moveDirection);
				
				yCoord = BOARDSIZE - 1;
                setMoveCount();
                setHealth(-5);
                if (moveCount % 6 == 0){setRemainingDays();}
			}
		}
	}
    
    //There is a 1-in-20 chance that following any given 
	//move a Space's polymorhic catastrophe function 
	//will be called for difficulty level 3, and a 1-in-30
	//chance that catastrophe will be called for levels 1 & 2.
	//(Note 1: The CrashSite space doesn't have a catastrophe
	//so this if statement prevents catastrophe and the 
	//printSpace function from being called when the Player
	//is in the CrashSite Space.)
    if (typeid(*playerLocation) != typeid(CrashSite))
	{
		if (rand() % 20 == 0 && difficultyLevel == 3)
		{	
			printSpace(false);
			playerLocation->catastrophe();
		}
		else if (rand() % 30 == 0)
		{
			printSpace(false);
			playerLocation->catastrophe();
		}
	}	
}
/*********************************************
				 printSpace
  Prints the contents of the spaceBoard 2D
  array member per Player's location. First 
  assigns coordinates with member symbols based 
  on Space Item and Player locations.
**********************************************/
void Player::printSpace(bool withMainPrompts)
{
    char** spaceBoard = playerLocation->getSpaceBoard();
    vector<Item*>& spaceItems = playerLocation->
        getSpaceItems();
	
	for (unsigned i = 0; i < spaceItems.size(); i++)
	{
		Item* currentItem = spaceItems.at(i);
		spaceBoard[currentItem->getXCoord()]
				  [currentItem->getYCoord()]
			= currentItem->getItemChar();
	}
	
	spaceBoard[xCoord][yCoord] = '@';
	
	cout << "\nPlayer Health: " << playerHealth
		 << "\nDays Till Winter: " << remainingDays
		 << endl << endl;
	
	for (unsigned i = 0; i < BOARDSIZE; i++)
	{
		for (unsigned j = 0; j < BOARDSIZE; j++)
		{
			cout << spaceBoard[i][j];
		}
		cout << endl;
	}
	
	cout << " " << playerLocation->getSpaceName()
		 << endl << endl;
	
	if (withMainPrompts)
	{	
		cout << "Commands:\n"
			 << "j-move left, l-move right "
			 << "i-move up, k-move down, e-engage, "
			 << "v-view/use items" << endl
			 << "*-view symbol key, q-quit" << endl;
	}
}
/************************************************************
			         spaceInteract	
  Function to interact with various Space Items.
  Finds item match if an item exists directly 
  adjacent to the player's coordinates (not including
  diagonally adjacent). If no item is found prints
  accordingly, otherwise uses item pointer to call
  itemInteraction function, which behaves polymorphically
  depending on the type of Item object pointed to.
************************************************************/ 
void Player::spaceInteract()
{
    char** spaceBoard = playerLocation->getSpaceBoard();
    vector<Item*> spaceItems = playerLocation->
        getSpaceItems();
	
	//Does not check x coordinate - 1 if player is at 
	//top row.
    if (xCoord == 0)
    {
        if ((spaceBoard[xCoord + 1][yCoord] == '?') ||
            (spaceBoard[xCoord][yCoord + 1] == '?') ||
            (spaceBoard[xCoord][yCoord - 1] == '?'))
        {
            cout << "\nYou Found a Key! You just may survive "
            << "after all!" << endl;
            
            hasKey = true;
        }
        //Covers all possibilities for adjacent three spaces
		//to make sure that at least one is not a blank or
		//water space.
        else if (((spaceBoard[xCoord + 1][yCoord] != ' ') &&
				 (spaceBoard[xCoord + 1][yCoord] != 'w')) ||
				 ((spaceBoard[xCoord][yCoord + 1] != ' ') &&
				 (spaceBoard[xCoord][yCoord + 1] != 'w')) ||
				 ((spaceBoard[xCoord][yCoord - 1] != ' ') &&
				 (spaceBoard[xCoord][yCoord - 1] != 'w')))
        {
            
            Item* itemToEngage = nullptr;
            
            bool itemMatch = false;
            for (unsigned i = 0; i < spaceItems.size()
                 && itemMatch == false; i++)
            {
                int itemXCoord = spaceItems.at(i)->getXCoord();
                int itemYCoord = spaceItems.at(i)->getYCoord();
                
                if ((xCoord + 1 == itemXCoord &&
                     yCoord == itemYCoord) ||
                    (xCoord == itemXCoord &&
                     yCoord + 1 == itemYCoord) ||
                    (xCoord == itemXCoord &&
                     yCoord - 1 == itemYCoord))
                {
                    itemMatch = true;
                    itemToEngage = spaceItems.at(i);
                }
            }
            if (itemToEngage != nullptr)
            {
                itemToEngage->itemInteract();
            }
            else
            {
                if ((spaceBoard[xCoord + 1][yCoord] == 'T') ||
                    (spaceBoard[xCoord][yCoord + 1] == 'T') ||
                    (spaceBoard[xCoord][yCoord - 1] == 'T'))
                    cout << "\nJust a tree..." << endl;
            }
        }
        
        else if ((spaceBoard[xCoord + 1][yCoord] == 'T') ||
                 (spaceBoard[xCoord][yCoord + 1] == 'T') ||
                 (spaceBoard[xCoord][yCoord - 1] == 'T'))
        {
            cout << "\nJust a tree..." << endl;
        }
        
        else
        {
            cout << "\nThere are no nearby items to interact with."
            << endl;
        }
    }
	
	//Does not check x coordinate + 1 if player is at bottom 
	//row.
	else if (xCoord == BOARDSIZE - 1)
    {
        if ((spaceBoard[xCoord - 1][yCoord] == '?') ||
            (spaceBoard[xCoord][yCoord + 1] == '?') ||
            (spaceBoard[xCoord][yCoord - 1] == '?'))
        {
            cout << "\nYou Found a Key! You just may survive "
                 << "after all!" << endl;
            
            hasKey = true;
        }
		
		//Deals with possibility that Player is standing on
		//the 'shore' of the Lake Space or next to water at 
		//the Crash Site space by checking to make
		//sure that non-whitespace character is also not a 
		//'w' character indicating a water space before 
		//executing the steps to engage an item.
        else if (((spaceBoard[xCoord - 1][yCoord] != ' ') &&
				 (spaceBoard[xCoord - 1][yCoord] != 'w')) ||
				 ((spaceBoard[xCoord][yCoord + 1] != ' ') &&
				 (spaceBoard[xCoord][yCoord + 1] != 'w')) ||
				 ((spaceBoard[xCoord][yCoord - 1] != ' ') &&
				 (spaceBoard[xCoord][yCoord - 1] != 'w')))
        {
            
            Item* itemToEngage = nullptr;
            
            bool itemMatch = false;
            for (unsigned i = 0; i < spaceItems.size()
                 && itemMatch == false; i++)
            {
                int itemXCoord = spaceItems.at(i)->getXCoord();
                int itemYCoord = spaceItems.at(i)->getYCoord();
                
                if ((xCoord - 1 == itemXCoord &&
                     yCoord == itemYCoord) ||
                    (xCoord == itemXCoord &&
                     yCoord + 1 == itemYCoord) ||
                    (xCoord == itemXCoord &&
                     yCoord - 1 == itemYCoord))
                {
                    itemMatch = true;
                    itemToEngage = spaceItems.at(i);
                }
            }
            if (itemToEngage != nullptr)
            {
                itemToEngage->itemInteract();
            }
            else
            {
                if ((spaceBoard[xCoord - 1][yCoord] == 'T') ||
                    (spaceBoard[xCoord][yCoord + 1] == 'T') ||
                    (spaceBoard[xCoord][yCoord - 1] == 'T'))
                cout << "\nJust a tree..." << endl;
            }
        }

        else if ((spaceBoard[xCoord - 1][yCoord] == 'T') ||
                 (spaceBoard[xCoord][yCoord + 1] == 'T') ||
                 (spaceBoard[xCoord][yCoord - 1] == 'T'))
        {
            cout << "\nJust a tree..." << endl;
        }

        else
        {
            cout << "\nThere are no nearby items to interact with."
                 << endl;
        }
    }
	
	//Does not check y coordinate + 1 if player is at 
	//far-right row.
	else if (yCoord == BOARDSIZE - 1)
    {
        if ((spaceBoard[xCoord - 1][yCoord] == '?') ||
            (spaceBoard[xCoord + 1][yCoord] == '?') ||
            (spaceBoard[xCoord][yCoord - 1] == '?'))
        {
            cout << "\nYou Found a Key! You just may survive "
                 << "after all!" << endl;
            
            hasKey = true;
        }
		
		//Deals with possibility that Player is standing on
		//the 'shore' of the Lake Space or next to water at 
		//the Crash Site space by checking to make
		//sure that non-whitespace character is also not a 
		//'w' character indicating a water space before 
		//executing the steps to engage an item.
        else if (((spaceBoard[xCoord - 1][yCoord] != ' ') &&
				 (spaceBoard[xCoord - 1][yCoord] != 'w')) ||
				 ((spaceBoard[xCoord + 1][yCoord] != ' ') &&
				 (spaceBoard[xCoord + 1][yCoord] != 'w')) ||
				 ((spaceBoard[xCoord][yCoord - 1] != ' ') &&
				 (spaceBoard[xCoord][yCoord - 1] != 'w')))
        {
            
            Item* itemToEngage = nullptr;
            
            bool itemMatch = false;
            for (unsigned i = 0; i < spaceItems.size()
                 && itemMatch == false; i++)
            {
                int itemXCoord = spaceItems.at(i)->getXCoord();
                int itemYCoord = spaceItems.at(i)->getYCoord();
                
                if ((xCoord - 1 == itemXCoord &&
                     yCoord == itemYCoord) ||
                    (xCoord + 1 == itemXCoord &&
                     yCoord == itemYCoord) ||
                    (xCoord == itemXCoord &&
                     yCoord - 1 == itemYCoord))
                {
                    itemMatch = true;
                    itemToEngage = spaceItems.at(i);
                }
            }
            if (itemToEngage != nullptr)
            {
                itemToEngage->itemInteract();
            }
            else
            {
                if ((spaceBoard[xCoord - 1][yCoord] == 'T') ||
                    (spaceBoard[xCoord + 1][yCoord] == 'T') ||
                    (spaceBoard[xCoord][yCoord - 1] == 'T'))
                cout << "\nJust a tree..." << endl;
            }
        }

        else if ((spaceBoard[xCoord - 1][yCoord] == 'T') ||
                 (spaceBoard[xCoord + 1][yCoord] == 'T') ||
                 (spaceBoard[xCoord][yCoord - 1] == 'T'))
        {
            cout << "\nJust a tree..." << endl;
        }

        else
        {
            cout << "\nThere are no nearby items to interact with."
                 << endl;
        }
    }
	
	//Does not check y coordinate - 1 if player is at 
	//far-left row.
	else if (yCoord == 0)
    {
        if ((spaceBoard[xCoord - 1][yCoord] == '?') ||
            (spaceBoard[xCoord + 1][yCoord] == '?') ||
            (spaceBoard[xCoord][yCoord + 1] == '?'))
        {
            cout << "\nYou Found a Key! You just may survive "
                 << "after all!" << endl;
            
            hasKey = true;
        }
		
		//Deals with possibility that Player is standing on
		//the 'shore' of the Lake Space or next to water at 
		//the Crash Site space by checking to make
		//sure that non-whitespace character is also not a 
		//'w' character indicating a water space before 
		//executing the steps to engage an item.
        else if (((spaceBoard[xCoord - 1][yCoord] != ' ') &&
				 (spaceBoard[xCoord - 1][yCoord] != 'w')) ||
				 ((spaceBoard[xCoord + 1][yCoord] != ' ') &&
				 (spaceBoard[xCoord + 1][yCoord] != 'w')) ||
				 ((spaceBoard[xCoord][yCoord + 1] != ' ') &&
				 (spaceBoard[xCoord][yCoord + 1] != 'w')))
        {
            
            Item* itemToEngage = nullptr;
            
            bool itemMatch = false;
            for (unsigned i = 0; i < spaceItems.size()
                 && itemMatch == false; i++)
            {
                int itemXCoord = spaceItems.at(i)->getXCoord();
                int itemYCoord = spaceItems.at(i)->getYCoord();
                
                if ((xCoord - 1 == itemXCoord &&
                     yCoord == itemYCoord) ||
                    (xCoord + 1 == itemXCoord &&
                     yCoord == itemYCoord) ||
                    (xCoord == itemXCoord &&
                     yCoord + 1 == itemYCoord))
                {
                    itemMatch = true;
                    itemToEngage = spaceItems.at(i);
                }
            }
            if (itemToEngage != nullptr)
            {
                itemToEngage->itemInteract();
            }
            else
            {
                if ((spaceBoard[xCoord - 1][yCoord] == 'T') ||
                    (spaceBoard[xCoord + 1][yCoord] == 'T') ||
                    (spaceBoard[xCoord][yCoord + 1] == 'T'))
                cout << "\nJust a tree..." << endl;
            }
        }

        else if ((spaceBoard[xCoord - 1][yCoord] == 'T') ||
                 (spaceBoard[xCoord + 1][yCoord] == 'T') ||
                 (spaceBoard[xCoord][yCoord + 1] == 'T'))
        {
            cout << "\nJust a tree..." << endl;
        }

        else
        {
            cout << "\nThere are no nearby items to interact with."
                 << endl;
        }
    }
	
	//Checks all 4 adjacent spaces if player is not at one of
	//the outer rows of the spaceBoard.
    else
    {
        if ((spaceBoard[xCoord + 1][yCoord] == '?') ||
            (spaceBoard[xCoord - 1][yCoord] == '?') ||
            (spaceBoard[xCoord][yCoord + 1] == '?') ||
            (spaceBoard[xCoord][yCoord - 1] == '?'))
        {
            cout << "\nYou Found a Key! You just may survive "
                 << "after all!" << endl;
            
            hasKey = true;
        }
		
		//Deals with possibility that Player is standing on
		//the 'shore' of the Lake Space or next to water at 
		//the Crash Site space by checking to make
		//sure that non-whitespace character is also not a 
		//'w' character indicating a water space before 
		//executing the steps to engage an item. (Uses 
		//checkForAdjacentSpaceItem function to check all 4 adjacent
		//spaces for combinations of )
        else if (((spaceBoard[xCoord - 1][yCoord] != ' ') &&
				 (spaceBoard[xCoord - 1][yCoord] != 'w')) ||
				 ((spaceBoard[xCoord + 1][yCoord] != ' ') &&
				 (spaceBoard[xCoord + 1][yCoord] != 'w')) ||
				 ((spaceBoard[xCoord][yCoord + 1] != ' ') &&
				 (spaceBoard[xCoord][yCoord + 1] != 'w')) ||
				 ((spaceBoard[xCoord][yCoord - 1] != ' ') &&
				 (spaceBoard[xCoord][yCoord - 1] != 'w')))
		
        {
            Item* itemToEngage = nullptr;
            
            bool itemMatch = false;
            for (unsigned i = 0; i < spaceItems.size()
                 && itemMatch == false; i++)
            {
                int itemXCoord = spaceItems.at(i)->getXCoord();
                int itemYCoord = spaceItems.at(i)->getYCoord();
                
                if ((xCoord + 1 == itemXCoord &&
                     yCoord == itemYCoord) ||
                    (xCoord - 1 == itemXCoord &&
                     yCoord == itemYCoord) ||
                    (xCoord == itemXCoord &&
                     yCoord + 1 == itemYCoord) ||
                    (xCoord == itemXCoord &&
                     yCoord - 1 == itemYCoord) )
                {
                    itemMatch = true;
                    itemToEngage = spaceItems.at(i);
                }
            }
            if (itemToEngage != nullptr)
            {
                itemToEngage->itemInteract();
            }
            else
            {
                if ((spaceBoard[xCoord + 1][yCoord] == 'T') ||
                    (spaceBoard[xCoord - 1][yCoord] == 'T') ||
                    (spaceBoard[xCoord][yCoord + 1] == 'T') ||
                    (spaceBoard[xCoord][yCoord - 1] == 'T'))
                cout << "\nJust a tree..." << endl;
            }
        }

        else if ((spaceBoard[xCoord + 1][yCoord] == 'T') ||
                 (spaceBoard[xCoord - 1][yCoord] == 'T') ||
                 (spaceBoard[xCoord][yCoord + 1] == 'T') ||
                 (spaceBoard[xCoord][yCoord - 1] == 'T'))
        {
            cout << "\nJust a tree..." << endl;
        }

        else
        {
            cout << "\nThere are no nearby items to interact with."
                 << endl;
        }
    }
}
/*********************************************
                printItemKey
    Prints a key of all game Item symbols.
**********************************************/
void Player::printItemKey()
{
    cout << endl
    
         << "& = BackPack\n"
         << "% = Berry Bush\n"
         << "< = Fish\n"
         << "/ = Fishing Pole\n"
         << "\\ = Hack Saw\n"
         << "# = Impassable Ridge\n"
         << "? = Key\n"
         << "B = Large Beast\n"
         << "L = LockBox\n"
         << "m = Mushroom\n"
         << "n = Nut Grove\n"
         << "@ = Player Position\n"
         << "! = Raft\n"
         << "_ = Rifle\n"
         << "b = Small Beast\n"
         << "~ = Snake\n"
         << "T = Tree\n"
         << "w = Water\n"
         << "+ = Water Jug\n"
    
         << endl;
}
/***************************************
			  Destructor
  Destructor to destroy all dynamically 
  allocated memory items.
****************************************/
Player::~Player()
{
	//Deletes dynamically allocated Item
	//objects.
	for (unsigned i = 0; i < playerItems.size(); i++)
	{
		delete playerItems.at(i);
	}
}
