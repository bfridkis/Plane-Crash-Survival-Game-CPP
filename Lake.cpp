/*********************************************************
** Program name: Lake.cpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Member function definitions for Lake 
				derived class (base class is Space).
**********************************************************/

#include "Lake.hpp"

const int BOARDSIZE = 25;

/***************************************************
			    	 Constructor
  Instantiates object. Establishes 2d dynamically
  allocated character array which is the "board"
  for the Player to move within. The game begins
  with the Player in the Lake space. Assigns
  Items to vector data member.
****************************************************/  
Lake::Lake(Player* player, int spaceCode,
	int difficultyLevel, bool hasRaft) :
    Space(player, spaceCode, difficultyLevel, hasRaft)
{
	this->difficultyLevel = difficultyLevel;
	
    spaceName = "Lake";
    
	spaceBoard = new char*[BOARDSIZE];
	for (unsigned i = 0; i < BOARDSIZE; i++)
	{
		spaceBoard[i] = new char[BOARDSIZE];
	}
	for (unsigned i = 0; i < BOARDSIZE; i++)
	{
		for (unsigned j = 0; j < BOARDSIZE; j++)
		{
			if (i == 0 || i == BOARDSIZE - 1 ||
                j == BOARDSIZE - 1)
			{
				spaceBoard[i][j] = '#';
			}
            else if (i % 2 == 0 && j == 0)
            {
                spaceBoard[i][j] = 'T';
            }
			else if (j == 0 || j == 1)
			{
				spaceBoard[i][j] = ' ';
			}
			else {spaceBoard[i][j] = 'w';}
		}
	}
	
    //This for block generates a set of 8 random x coordinates
    //for the board, excluding the outer rows and columns.
    vector<int> uniqueRandomXCoordinates;
    for (unsigned i = 0; i < 8; i++)
    {
        int randomInt = 1 + rand() % (BOARDSIZE - 2);
        bool alreadyInVector = false;
        for (unsigned j = 0; j < uniqueRandomXCoordinates.size() &&
                alreadyInVector == false; j++)
        {
            if (randomInt == uniqueRandomXCoordinates.at(j))
            {
                alreadyInVector = true;
            }
        }
        if(!alreadyInVector)
        {
            uniqueRandomXCoordinates.push_back(randomInt);
        }
        else
        {
            i--;
        }
    }
    
	//This for block generates a set of 8 random y coordinates
    //for the board, excluding the outer rows and columns. Excludes
    //the 2nd, 3rd, and 4th to last columns as this is where the
    //island which has the key will be placed, and excludes the
    //first 3 columns because the first 2 will be the 'shore' of the
    //lake. Fish are not placed in the 3rd column of the lake so the
    //Player cannot drop the raft into the lake while standing on the
    //shore if trying to exchange Raft for Fish.
    vector<int> uniqueRandomYCoordinates;
    for (unsigned i = 0; i < 8; i++)
    {
        //Generates a random number between 3 and BOARDSIZE - 5
        //per formula: min + (rand() % (max - min + 1))
        //Reference: https://stackoverflow.com/questions/5008804/
        //generating-random-integer-from-a-range
        int randomInt = 3 + rand() % ((BOARDSIZE - 5) - 3 + 1);
        bool alreadyInVector = false;
        for (unsigned j = 0; j < uniqueRandomYCoordinates.size() &&
                alreadyInVector == false; j++)
        {
            if (randomInt == uniqueRandomYCoordinates.at(j))
            {
                alreadyInVector = true;
            }
        }
        if(!alreadyInVector)
        {
            uniqueRandomYCoordinates.push_back(randomInt);
        }
        else
        {
            i--;
        }
    }
    
    //Creates 8 Fish with unique random coordinates as described
	//above.
    for (unsigned i = 0; i < 8; i++)
    {
        spaceItems.push_back(new Fish
            (uniqueRandomXCoordinates.at(i),
             uniqueRandomYCoordinates.at(i), player));
    }
    
    //Space for Key Character.
    spaceBoard[(BOARDSIZE/2)+1][BOARDSIZE-2] = '?';
    //Island to hold space key.
    spaceBoard[(BOARDSIZE/2)+2][BOARDSIZE-2] = ' ';
    spaceBoard[(BOARDSIZE/2)+3][BOARDSIZE-2] = ' ';
    spaceBoard[(BOARDSIZE/2)][BOARDSIZE-2] = ' ';
    spaceBoard[(BOARDSIZE/2)-1][BOARDSIZE-2] = ' ';
    spaceBoard[(BOARDSIZE/2)+1][BOARDSIZE-3] = ' ';
    spaceBoard[(BOARDSIZE/2)+2][BOARDSIZE-3] = ' ';
    spaceBoard[(BOARDSIZE/2)+3][BOARDSIZE-3] = ' ';
    spaceBoard[(BOARDSIZE/2)][BOARDSIZE-3] = ' ';
    spaceBoard[(BOARDSIZE/2)-1][BOARDSIZE-3] = ' ';
    
    
}
/*****************************************************
                  catastrophe
 This virtual member function represents a Large Beast 
 attack in the Woods. It decrements health points by 
 50 unless player has Rifle and Player's ammo member 
 is at least 2. Decrements one day for recovery if 
 player has rifle and ammo, 3 days if player does not.
 ******************************************************/
void Lake::catastrophe()
{
	if (thePlayer->getPreviousSpaceWasWater())
	{
		cout << "\nCatastrophe has struck. A Monsoon has "
			 << "washed you to shore!\n\n-25 Health Points "
			 << "-1 Day\n";
			 
		char** spaceBoard = thePlayer->getPlayerLocation()->
			getSpaceBoard();
		
			spaceBoard[thePlayer->getXCoord()][thePlayer->getYCoord()]
				= 'w';
			thePlayer->setPreviousSpaceWasWater(false);

		thePlayer->setXCoord(13);
		thePlayer->setYCoord(1);
		thePlayer->setHealth(-25);
		thePlayer->setRemainingDays();
	}
}
