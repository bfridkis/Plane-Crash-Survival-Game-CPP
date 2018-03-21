/*************************************************************
** Program name: Space.hpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Declaration of Space class for CS162 final
				project. This is a pure vitual or 'abstract'
				base class.
**************************************************************/

#ifndef Space_hpp
#define Space_hpp

#include <vector>
#include <iostream>
#include <string>
#include "Item.hpp"
using std::string;
using std::cout;
using std::endl;
using std::vector;

//This forward declaration is needed to workaround a
//cyclic dependency. (https://stackoverflow.com/questions/
//2133250/does-not-name-a-type-error)
class Player;

class Space
{
protected:
	char** spaceBoard;
	vector<Item*> spaceItems;
	Space* northSpace; 
	Space* southSpace;
	Space* eastSpace;
	Space* westSpace;
	string spaceName;
    int spaceCode;
	Player* thePlayer;

public:
	Space(Player* player, int spaceCode,
          int difficultyLevel, bool hasRaft = 0);
	char** getSpaceBoard();
	Space* getSpacePointer (char direction);
	vector<Item*>& getSpaceItems();
	void setNorthSpacePointer(Space*);
    void setSouthSpacePointer(Space*);
    void setEastSpacePointer(Space*);
    void setWestSpacePointer(Space*);
	string getSpaceName() const;
    virtual void catastrophe() = 0;
	virtual ~Space();
};
	
#endif /* Space_hpp */

