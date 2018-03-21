/*********************************************************
** Program name: CrashSite.cpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Member function definitions for CrashSite 
				derived class (base class is Space).
**********************************************************/

#include "CrashSite.hpp"

const int BOARDSIZE = 25;

/***************************************************
			    	 Constructor
  Instantiates object. Establishes 2d dynamically
  allocated character array which is the "board"
  for the Player to move within. The game begins
  with the Player in the CrashSite space. Assigns
  Items to vector data member.
****************************************************/  
CrashSite::CrashSite(Player* player, int spaceCode,
	int difficultyLevel, bool hasRaft) :
    Space(player, spaceCode, difficultyLevel, hasRaft)
{
    spaceName = "Crash Site";
    
	spaceBoard = new char*[BOARDSIZE];
	for (unsigned i = 0; i < BOARDSIZE; i++)
	{
		spaceBoard[i] = new char[BOARDSIZE];
	}
	for (unsigned i = 0; i < BOARDSIZE; i++)
	{
		for (unsigned j = 0; j < BOARDSIZE; j++)
		{
			if (i == 0 || i == BOARDSIZE - 1 || j == 0)
			{
				spaceBoard[i][j] = '#';
			}
			else if (i % 2 == 0 && j == BOARDSIZE - 1)
			{
				spaceBoard[i][j] = 'T';
			}
            else if ((i == 6 && j >= 1 && j < 4)
                     || (i == 7 && j >= 2 && j < 7)
                     || (i == 8 && j >= 4 && j < 9)
                     || (i == 9 && j >= 6 && j < 10)
                     || (i == 10 && j >= 7 && j < 11)
                     || (i == 11 && j >= 7 && j < 11)
                     || (i == 12 && j >= 7 && j < 11)
                     || (i == 13 && j >= 6 && j < 10)
                     || (i == 14 && j >= 3 && j < 9)
                     || (i == 15 && j >= 2 && j < 7)
                     || (i == 16 && j >= 1 && j < 4))
            {
                spaceBoard[i][j] = 'w';
            }
			else {spaceBoard[i][j] = ' ';}
		}
	}
	
	//Raft is placed in the crash site if and only if the
	//difficulty level is set to 1.
	if (difficultyLevel == 1)
	{	
		spaceItems.push_back(new Raft(20, 15, player));
	}
	spaceItems.push_back(new LockBox(11, 3, player));

	spaceItems.push_back(new WaterJug(3, 3, player));

	spaceItems.push_back(new BackPack(22, 2, player));

	spaceItems.push_back(new FishingPole(16, 17, player));

	spaceItems.push_back(new Rifle(5, 11, player));
	
	spaceItems.push_back(new HackSaw(23, 10, player));
}
