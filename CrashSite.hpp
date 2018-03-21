/*************************************************************
** Program name: CrashSite.hpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Declaration of CrashSite class for CS162 final
				project. This is a derived class of the Space
				base class.
**************************************************************/

#ifndef CrashSite_hpp
#define CrashSite_hpp

#include "Space.hpp"
#include "Raft.hpp"
#include "WaterJug.hpp"
#include "BackPack.hpp"
#include "FishingPole.hpp"
#include "Rifle.hpp"
#include "LockBox.hpp"
#include "HackSaw.hpp"

class CrashSite : public Space
{
public:
	CrashSite(Player* player, int spaceCode, 
		int difficultyLevel, bool hasRaft = 0);
    virtual void catastrophe() override{};
	virtual ~CrashSite(){};
};

#endif /* CrashSite_hpp */
