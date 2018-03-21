/***********************************************************************
** Program name: Player.hpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Player Class declaration. The Player class tracks the
				position of the player within the game map and provides
				a data member (vector) to store Player Items and 
				modify this container accordingly.
************************************************************************/

#ifndef Player_hpp
#define Player_hpp

#include <vector>
#include <iostream>
#include <vector>
#include "Item.hpp"
#include "Raft.hpp"
#include "WaterJug.hpp"
#include "BackPack.hpp"
#include "FishingPole.hpp"
#include "Rifle.hpp"
#include "LockBox.hpp"
#include "LargeBeast.hpp"
#include "SmallBeast.hpp"
#include "Space.hpp"
#include "CrashSite.hpp"
using std::cout;
using std::endl;
using std::vector;


class Player
{
private:
	int xCoord;
	int yCoord;
	Space* playerLocation;
	vector<Item*> playerItems;
    int moveCount;
	int playerHealth;
	int remainingDays;
	bool hasBackPack;
	bool hasKey;
	bool hasRaft;
    bool hasFishingPole;
    bool hasRifle;
	bool hasTransmitted;
	bool previousSpaceWasWater;
	int difficultyLevel;
	
public:
	Player(int difficultyLevel);
	int getXCoord() const;
	int getYCoord() const;
	void setXCoord(int xCoord);
	void setYCoord(int yCoord);
	Space* getPlayerLocation();
	void setPlayerLocation(Space* newLocation);
	int getPlayerItemCount() const;
	void addItem(Item*);
	Item* dropItem(int itemNumberToDrop);
	void useItem();
	void printItems() const;
	vector<Item*>& getPlayerItems();
    int getMoveCount() const;
    void setMoveCount();
	int getHealth() const;
	void setHealth(int healthChange);
	int getRemainingDays() const;
	void setRemainingDays();
	bool getHasBackPack() const;
	bool getHasKey() const;
	bool getHasRaft() const;
    bool getHasFishingPole() const;
    bool getHasRifle() const;
	bool getHasTransmitted() const;
	bool getPreviousSpaceWasWater () const;
	void setHasBackPack(bool);
    void setHasKey();
	void setHasRaft(bool);
    void setHasFishingPole(bool);
    void setHasRifle(bool);
	void setHasTransmitted();
	void setPreviousSpaceWasWater(bool);
	void movePlayer(char moveDirection);
    void printSpace(bool withMainPrompts);
    void printItemKey();
    void spaceInteract();
	~Player();
};

#endif /* Player_hpp */
