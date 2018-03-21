/*************************************************************
** Program name: setSpacePointers.cpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Member function definition to set each Space
				pointer's adjacent Spaces at beginning of each
				game.
**************************************************************/

#include "Space.hpp"

/*********************************************************
                    setSpacePointers
 This function sets all the Space pointers for each Space 
 after the Spaces have been assigned their place within 
 the game map. (Meadows and Woods are assigned randomly.)
**********************************************************/
void setSpacePointers(Space* theCrashSite, Space* Meadow1,
                      Space* Meadow2, Space* Woods1,
                      Space* Woods2, Space* theLake)
{
    theCrashSite->setNorthSpacePointer(nullptr);
	theCrashSite->setSouthSpacePointer(nullptr);
	theCrashSite->setEastSpacePointer(Meadow1);
	theCrashSite->setWestSpacePointer(nullptr);
	
	Meadow1->setNorthSpacePointer(Woods1);
	Meadow1->setSouthSpacePointer(nullptr);
	Meadow1->setEastSpacePointer(Woods2);
	Meadow1->setWestSpacePointer(theCrashSite);
	
	Meadow2->setNorthSpacePointer(nullptr);
	Meadow2->setSouthSpacePointer(Woods2);
	Meadow2->setEastSpacePointer(theLake);
	Meadow2->setWestSpacePointer(Woods1);
	
	Woods1->setNorthSpacePointer(nullptr);
	Woods1->setSouthSpacePointer(Meadow1);
	Woods1->setEastSpacePointer(Meadow2);
	Woods1->setWestSpacePointer(nullptr);
	
	Woods2->setNorthSpacePointer(Meadow2);
	Woods2->setSouthSpacePointer(nullptr);
	Woods2->setEastSpacePointer(nullptr);
	Woods2->setWestSpacePointer(Meadow1);
	
	theLake->setNorthSpacePointer(nullptr);
	theLake->setSouthSpacePointer(nullptr);
	theLake->setEastSpacePointer(nullptr);
	theLake->setWestSpacePointer(Meadow2);
}	