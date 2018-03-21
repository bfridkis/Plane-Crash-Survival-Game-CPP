/*************************************************************
** Program name: Space.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Member function definitions of the Space base
				class.
**************************************************************/

#include "Space.hpp"

const int BOARDSIZE = 25;

/*******************************************
			   Constructor
  Constructor to establish all spaces
  with a name and provide Player* to 
  access all Player public member 
  functions without needing to pass
  a Player* to functions within
  Space class that use them.
********************************************/
Space::Space(Player* player, int spaceCode,
	int difficultyLevel, bool hasRaft)
{
	thePlayer = player;
    this->spaceCode = spaceCode;
}
/*********************************************
				getSpaceBoard
  Accessor to return a double pointer to the 
  spaceBoard 2D array.
**********************************************/
char** Space::getSpaceBoard()
{
	return spaceBoard;
}
/*********************************************
				getSpacePointer
  Accessor to return one of the Space pointers
  (which point to the adjacent spaces on the
  overall game board) based on the direction
  parameter passed.
**********************************************/
Space* Space::getSpacePointer(char direction)
{
	if (direction == 'I')
	{
		return northSpace;
	}
	else if (direction == 'K')
	{
		return southSpace;
	}
	else if (direction == 'L')
	{
		return eastSpace;
	}
	else
	{
		return westSpace;
	}
}
/******************************************
		     getSpaceItems
  Accessor to return a reference to the 
  vector of Item pointers (spaceItems)
  data memeber.
*******************************************/
vector<Item*>& Space::getSpaceItems()
{
	return spaceItems;
}
/**********************************************
             setNorthSpacePointer
  Function to assign value to northSpace data
  member (which indicates the Space immediately
  above).
************************************************/
void Space::setNorthSpacePointer(Space* northSpace)
{
	this->northSpace = northSpace;
}
/**********************************************
             setSouthSpacePointer
  Function to assign value to southSpace data
  member (which indicates the Space immediately
  below).
************************************************/
void Space::setSouthSpacePointer(Space* southSpace)
{
	this->southSpace = southSpace;
}
/**********************************************
             setEastSpacePointer
  Function to assign value to eastSpace data
  member (which indicates the Space immediately
  below).
************************************************/
void Space::setEastSpacePointer(Space* eastSpace)
{
	this->eastSpace = eastSpace;
}
/**********************************************
             setWestSpacePointer
  Function to assign value to westSpace data
  member (which indicates the Space immediately
  below).
************************************************/
void Space::setWestSpacePointer(Space* westSpace)
{
	this->westSpace = westSpace;
}
/******************************************
		     getSpaceName
   Accessor to return spaceName member.
*******************************************/
string Space::getSpaceName() const
{
    return spaceName;
}
/***************************************
			  Destructor
  Destructor to destroy all dynamically 
  allocated memory items.
****************************************/
Space::~Space()
{
	//Deletes dynamically allocated Item
	//objects.
	for (unsigned i = 0; i < spaceItems.size(); i++)
	{
		delete spaceItems.at(i);
	}
	
	//Deletes 2D array for the space Board.
	for (unsigned i = 0; i < BOARDSIZE; i++)
	{
		delete[] spaceBoard[i];
	}
	
	delete[] spaceBoard;
}
