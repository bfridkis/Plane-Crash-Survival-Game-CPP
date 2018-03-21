/*********************************************************
 ** Program name: Woods.cpp
 ** Author: Ben Fridkis
 ** Date: 5/31/2017
 ** Description: Member function definitions for Woods
    derived class (base class is Space).
 **********************************************************/

#include "Woods.hpp"

const int BOARDSIZE = 25;

/*************************************************
                 Constructor
 Instantiates object. Establishes 2d dynamically
 allocated character array which is the "board"
 for the Player to move within. Assigns
 Items to vector data member. The space code
 parameter determines the board placement and 
 appropriate borders based thereon. Places Space
 items and some of the "trees" randomly.
 *************************************************/
Woods::Woods(Player* player, int spaceCode, 
	int difficultyLevel, bool hasRaft) :
    Space(player, spaceCode, difficultyLevel)
{
    spaceName = "Woods";
    
    spaceBoard = new char*[BOARDSIZE];
    for (unsigned i = 0; i < BOARDSIZE; i++)
    {
        spaceBoard[i] = new char[BOARDSIZE];
    }
    
    if (spaceCode == 1)
    {
        for (unsigned i = 0; i < BOARDSIZE; i++)
        {
            for (unsigned j = 0; j < BOARDSIZE; j++)
            {
                if (i == 0 || j == 0)
                {
                    spaceBoard[i][j] = '#';
                }
				else if (i % 2 == 0 && j % 2 == 0 &&
                         (i == BOARDSIZE - 1 ||
                          j == BOARDSIZE - 1))
                {
                    spaceBoard[i][j] = 'T';
                }
                else 
				{
					//For all non-border spaces, there is a 2-in-three 
					//chance the space is blank and a one-in-three
					//chance the space is a tree for difficultLevel 3.
					//Else, there is a one-in-five chance the space is
					//a tree and four-in-five chance the space is blank.
					spaceBoard[i][j] = ' ';
					if (difficultyLevel != 3)
					{	
						int randomInt = 1 + rand() % 5;
						if (randomInt % 5 == 0)
						{
							spaceBoard[i][j] = 'T';
						}
					}
					else
					{
						int randomInt = 1 + rand() % 3;
						if (randomInt % 3 == 0)
						{
							spaceBoard[i][j] = 'T';
						}
					}
				}
				
            }
        }
    }
    else
    {
        for (unsigned i = 0; i < BOARDSIZE; i++)
        {
            for (unsigned j = 0; j < BOARDSIZE; j++)
            {
                if (i == BOARDSIZE - 1 ||
                    j == BOARDSIZE - 1)
                {
                    spaceBoard[i][j] = '#';
                }
                else if (i % 2 == 0 && j % 2 == 0 &&
                         (i == 0 || j == 0))
                {
                    spaceBoard[i][j] = 'T';
                }
                else 
				{
					//For all non-border spaces, there is a 2-in-three 
					//chance the space is blank and a one-in-three
					//chance the space is a tree for difficultLevel 3.
					//Else, there is a one-in-five chance the space is
					//a tree and four-in-five chance the space is blank.
					spaceBoard[i][j] = ' ';
					if (difficultyLevel != 3)
					{	
						int randomInt = 1 + rand() % 5;
						if (randomInt % 5 == 0)
						{
							spaceBoard[i][j] = 'T';
						}
					}
					else
					{
						int randomInt = 1 + rand() % 3;
						if (randomInt % 3 == 0)
						{
							spaceBoard[i][j] = 'T';
						}
					}	
				}
            }
        }
    }
	
    //Generates a set of 18 unique random x and y coordinates.
	//These will be used for random Item placement.
	//(Note these coordinates may place an Item on top of a "tree"
	//which is not itself an object but just a marker and which is
	//acceptable. Because the coordinates are unique, no two Items
	//will have the same coordinates.
    vector<int> uniqueRandomXCoordinates;
	try
	{
		randomOrderUniqueElementGenerator
		(uniqueRandomXCoordinates, BOARDSIZE - 2, 1, 19);
	}
	catch (string exceptionMessage)
	{
		cout << exceptionMessage;
	}
	
    vector<int> uniqueRandomYCoordinates;
	try
	{
		randomOrderUniqueElementGenerator
		(uniqueRandomYCoordinates, BOARDSIZE - 2, 1, 19);
	}
	catch (string exceptionMessage)
	{
		cout << exceptionMessage;
	}
	
    //Creates 9 NutGroves with unique random coordinates.
    for (unsigned i = 0; i < 9; i++)
    {
        spaceItems.push_back(new NutGrove
            (uniqueRandomXCoordinates.at(i),
             uniqueRandomYCoordinates.at(i), player));
    }
    //Creates 9 Mushroom with unique random coordinates.
    for (unsigned i = 9; i < 18; i++)
    {
        spaceItems.push_back(new Mushroom
            (uniqueRandomXCoordinates.at(i),
             uniqueRandomYCoordinates.at(i), player));
    }
	//Places Raft in Woods space based on random int
	//generator in main for difficulty levels 2 and 3.
	if (hasRaft && (difficultyLevel == 2 ||
					difficultyLevel == 3))
	{
		spaceItems.push_back
			(new Raft(uniqueRandomXCoordinates.at(18),
					  uniqueRandomYCoordinates.at(18), player));
	}
}
/*****************************************************
                     catastrophe
 This virtual member function represents a Large Beast 
 attack in the Woods. It decrements health points by 
 50 unless player has Rifle and Player's ammo member 
 is at least 2. Decrements 1 day for recovery if
 player has rifle and 2 ammo, 2 days recovery and 35 
 health points if Player had only 1 ammo at time of 
 attack, and 50 points and 3 days if player did not 
 have the rifle or had rifle but had no ammo at time of
 attack.
 ******************************************************/
void Woods::catastrophe()
{	
    int rifleAmmo;
    Item* playerRifle = nullptr;
    
	//Determines rifle Ammo, if player has rifle.
    vector<Item*>& playerItems = thePlayer->getPlayerItems();
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
    
    if (thePlayer->getHasRifle() && rifleAmmo >= 2)
    {
        cout << "\nCatastrophe has struck! Large Beast Attack!\n"
             << "Good thing you had enough ammo to fend it "
             << "off!\n\n-2 Ammo -1 Day\n";
        
        static_cast<Rifle*>(playerRifle)->setAmmo(-2);
        thePlayer->setRemainingDays();
    }
    else if (thePlayer->getHasRifle())
    {
        cout << "\nCatastrophe has struck! Large Beast Attack!\n"
             << "You didn't have enough ammo to fend it off.\n\n";
        if (rifleAmmo == 1)
        {
             cout << "-35 Health Points -2 Days -1 Ammo\n";
        
            thePlayer->setHealth(-35);
            static_cast<Rifle*>(playerRifle)->setAmmo(-1);
            thePlayer->setRemainingDays();
            thePlayer->setRemainingDays();
        }
        else
        {
            cout << "-50 Health Points -3 Days\n";
            
            thePlayer->setHealth(-50);
            thePlayer->setRemainingDays();
            thePlayer->setRemainingDays();
            thePlayer->setRemainingDays();
        }
    }
    else
    {
        cout << "\nCatastrophe has struck! Large Beast Attack!\n"
        << "You were charged and without arms!\n\n"
        << "-50 Health Points -3 Days\n";
        
        thePlayer->setHealth(-50);
        
        thePlayer->setRemainingDays();
        thePlayer->setRemainingDays();
        thePlayer->setRemainingDays();
    }
}
