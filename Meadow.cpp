/*********************************************************
 ** Program name: Meadow.cpp
 ** Author: Ben Fridkis
 ** Date: 5/31/2017
 ** Description: Member function definitions for Meadow
    derived class (base class is Space).
 **********************************************************/

#include "Meadow.hpp"

const int BOARDSIZE = 25;

/*************************************************
                 Constructor
 Instantiates object. Establishes 2d dynamically
 allocated character array which is the "board"
 for the Player to move within. The game begins
 with the Player in the Meadow space. Assigns
 Items to vector data member.
 *************************************************/
Meadow::Meadow(Player* player, int spaceCode,
	int difficultyLevel, bool hasRaft) :
    Space(player, spaceCode, difficultyLevel, 
			hasRaft)
{
    spaceName = "Meadow";
    this->difficultyLevel = difficultyLevel;
	
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
                if (i == BOARDSIZE - 1)
                {
                    spaceBoard[i][j] = '#';
                }
                else if ((i % 2 == 0 && j == BOARDSIZE - 1) ||
                         (j % 2 == 0 && i == 0) ||
                         (i % 2 == 0 && j == 0) ||
                         (i == 0 && j == 0))
                {
                    spaceBoard[i][j] = 'T';
                }
                else 
				{
					spaceBoard[i][j] = ' ';
					int randomInt = 1 + rand() % 20;
					if (randomInt % 20 == 0)
					{
						spaceBoard[i][j] = 'T';
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
                if (i == 0)
                {
                    spaceBoard[i][j] = '#';
                }
                else if ((i % 2 == 0 && j == BOARDSIZE - 1) ||
                         (j % 2 == 0 && i == BOARDSIZE - 1) ||
                         (i % 2 == 0 && j == 0) ||
                         (i == BOARDSIZE - 1 && j == 0))
                {
                    spaceBoard[i][j] = 'T';
                }
                else
                {
                    spaceBoard[i][j] = ' ';
                    int randomInt = 1 + rand() % 20;
                    if (randomInt % 20 == 0)
                    {
                        spaceBoard[i][j] = 'T';
                    }
                }
            }
        }
    }
    
    //This for block generates a set of 19 random x coordinates
    //for the board, excluding the outer rows and columns. Throws
    //an exception if number of elements (parameter 4) to push
    //into vector (parameter 1) is greater than the size of the 
	//range between min and max (parameters 2 & 3).
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
    
    //This for block generates a set of 19 random y coordinates
    //for the board, excluding the outer rows and columns as well
    //as 2nd and 3rd farthest right columns (so BerryBush can take
    //up 3 adjacent spaces in a row). See comment above for details
    //concerning associated try/catch blocks.
    vector<int> uniqueRandomYCoordinates;
    try
    {
        randomOrderUniqueElementGenerator
        (uniqueRandomYCoordinates, BOARDSIZE - 4, 1, 19);
    }
    catch (string exceptionMessage)
    {
        cout << exceptionMessage;
    }
    
    //Creates 3 LargeBeasts with unique random coordinates.
    for (unsigned i = 0; i < 3; i++)
    {
        spaceItems.push_back(new LargeBeast
            (uniqueRandomXCoordinates.at(i),
             uniqueRandomYCoordinates.at(i), player));
    }
    //Creates 3 SmallBeasts with unique random coordinates.
    for (unsigned i = 3; i < 6; i++)
    {
        spaceItems.push_back(new SmallBeast
            (uniqueRandomXCoordinates.at(i),
             uniqueRandomYCoordinates.at(i), player));
    }
    //Creates 3 Snakes with unique random coordinates.
    for (unsigned i = 6; i < 9; i++)
    {
        spaceItems.push_back(new Snake
            (uniqueRandomXCoordinates.at(i),
             uniqueRandomYCoordinates.at(i), player));
    }
    //Creates 3 bunches of 3 BerryBushes with unique random
    //coordinates.
    for (unsigned i = 9; i < 12; i++)
    {
        spaceItems.push_back(new BerryBush
            (uniqueRandomXCoordinates.at(i),
             uniqueRandomYCoordinates.at(i), player));
        spaceItems.push_back(new BerryBush
            (uniqueRandomXCoordinates.at(i),
             uniqueRandomYCoordinates.at(i) + 1, player));
        spaceItems.push_back(new BerryBush
            (uniqueRandomXCoordinates.at(i),
             uniqueRandomYCoordinates.at(i) + 2, player));
    }
	if (hasRaft && (difficultyLevel == 2 ||
					difficultyLevel == 3))
	{
		spaceItems.push_back
			(new Raft(uniqueRandomXCoordinates.at(12), 
					  uniqueRandomYCoordinates.at(12), player));
	}
    
}
/*************************************************
                 catastrophe
 This virtual member function represents a storm
 hitting the meadow. It rerranges the spaces items
 and decrements 3 days and 40 health points from 
 the player.
 *************************************************/
void Meadow::catastrophe()
{	
	//This for block generates a set of random x coordinates
	//per the number of space items currently on the board.
	//for the board, excluding the outer rows and columns.
	vector<int> uniqueRandomXCoordinates;
	
	try
	{
		randomOrderUniqueElementGenerator
		(uniqueRandomXCoordinates, BOARDSIZE - 2, 1,
			spaceItems.size());
	}
	catch (string exceptionMessage)
	{
		cout << exceptionMessage;
	}

	//This for block generates a set of random y coordinates
	//per the number of space items currently on the board.
	//for the board, excluding the outer rows and columns,
	//and the last 2nd and 3rd outermost columns so there is
	//room to replace full BerryBush (3 BerryBush items in 
	//a row) when necessary.
	vector<int> uniqueRandomYCoordinates;
	
	try
	{
		randomOrderUniqueElementGenerator
		(uniqueRandomYCoordinates, BOARDSIZE - 4, 1, 
			spaceItems.size());
	}
	catch (string exceptionMessage)
	{
		cout << exceptionMessage;
	}
	
	//This block is to determine the number of BerryBushes
	//so the BerryBush Items can be regrouped in clumps of
	//three in a row. All Berry Items will be moved out of 
	//spaceItems and into tempBerryVector temporarily before
	//they are then pushed back into spaceItems, to ensure
	//all Berrys are at the back of the vector.
	int numberOfBerryItems = 0;
	vector<Item*>::iterator iter = spaceItems.begin();
	int spaceItemsSizeDuringBerryRemoval = spaceItems.size();
	vector<Item*> tempBerryVector;
	for (int i = 0, j = 0; j < spaceItemsSizeDuringBerryRemoval; 
			i++, j++, iter++)
	{
		if (typeid(*spaceItems.at(i)) == typeid(BerryBush))
		{
			Item* currentItem = spaceItems.at(i);
			numberOfBerryItems++;
			spaceItems.erase(iter);
			tempBerryVector.push_back(currentItem);
			i--;
			iter--;
		}	
	}
	//Adds all Berry Items back into spaceItems.
	for (unsigned i = 0; i < tempBerryVector.size(); i++)
	{
		spaceItems.push_back(tempBerryVector.at(i));
	}
	
	cout << "\n" << numberOfBerryItems << endl;
	int numberOfBerryBushesToRelocate = numberOfBerryItems / 3;
	int numberOfBerryItemsRemainingAfterRebushingToRelocate =
		numberOfBerryItems % 3;
	
	
	for (unsigned i = 0; i < spaceItems.size(); i++)
	{
		int uniqueXCoord = uniqueRandomXCoordinates.at(i);
		int uniqueYCoord = uniqueRandomYCoordinates.at(i);
		
		//These three blocks reassign Item coordinates based on
		//type. If the Item is a BerryBush, it reassigns the
		//coordinates per the random intergers and then reassigns
		//the following 2 Items (if there are full bushes remaining)
		//with the random x coordinate + 1 and + 2 respectively. It
		//will bunch 2 BerryBushes together in like manner if there
		//are only two BerryBush Items left after all full bushes of
		//3 have been accounted for, else it relocates a last single
		//BerryBush on it's own if necessary.
		if (typeid(*spaceItems.at(i)) != typeid(BerryBush) ||
			(numberOfBerryItemsRemainingAfterRebushingToRelocate == 1 &&
			 i == spaceItems.size() - 1))
		{
			spaceBoard[spaceItems.at(i)->getXCoord()]
					  [spaceItems.at(i)->getYCoord()] = ' ';
			
			spaceItems.at(i)->setXCoord(uniqueXCoord);
			spaceItems.at(i)->setYCoord(uniqueYCoord);
		}
		else if(numberOfBerryBushesToRelocate > 0)
		{
			
			spaceBoard[spaceItems.at(i)->getXCoord()]
					  [spaceItems.at(i)->getYCoord()] = ' ';
			spaceBoard[spaceItems.at(i + 1)->getXCoord()]
					  [spaceItems.at(i + 1)->getYCoord()] = ' ';
			spaceBoard[spaceItems.at(i + 2)->getXCoord()]
					  [spaceItems.at(i + 2)->getYCoord()] = ' ';			
				
			spaceItems.at(i)->setXCoord(uniqueXCoord);
			spaceItems.at(i)->setYCoord(uniqueYCoord);
			spaceItems.at(i + 1)->setXCoord(uniqueXCoord);
			spaceItems.at(i + 1)->setYCoord(uniqueYCoord + 1);
			spaceItems.at(i + 2)->setXCoord(uniqueXCoord);
			spaceItems.at(i + 2)->setYCoord(uniqueYCoord + 2);
			
			numberOfBerryBushesToRelocate--;
			i += 2;
		}
		else if (numberOfBerryItemsRemainingAfterRebushingToRelocate
					== 2)
		{
			spaceBoard[spaceItems.at(i)->getXCoord()]
					  [spaceItems.at(i)->getYCoord()] = ' ';
			spaceBoard[spaceItems.at(i + 1)->getXCoord()]
					  [spaceItems.at(i + 1)->getYCoord()] = ' ';
					  
			spaceItems.at(i)->setXCoord(uniqueXCoord);
			spaceItems.at(i)->setYCoord(uniqueYCoord);
			spaceItems.at(i + 1)->setXCoord(uniqueXCoord);
			spaceItems.at(i + 1)->setYCoord(uniqueYCoord + 1);

			i++;
		}	
	}

	//If any Item ends up in the same position as the Player,
	//delete that Item and erase the pointer its pointer in
	//the spaceItems vector.
	iter = spaceItems.begin();
	for (unsigned i = 0; i < spaceItems.size(); i++, iter++)
	{
		if (spaceItems.at(i)->getXCoord() 
			== thePlayer->getXCoord() &&
			spaceItems.at(i)->getYCoord() 
			== thePlayer->getXCoord())
		{
			delete *iter;
			spaceItems.erase(iter);
		}
	}		
	
	cout << "\nCatastrophe has struck!\nA violent storm passed through the "
		 << "meadow.\nItems have been tossed about!\n\n-40 Health Points -3 "
		 << "days" << endl;

	thePlayer->setHealth(-40);

	thePlayer->setRemainingDays();
	thePlayer->setRemainingDays();
	thePlayer->setRemainingDays();
}