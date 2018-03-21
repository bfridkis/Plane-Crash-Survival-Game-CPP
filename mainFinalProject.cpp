/*************************************************************
** Program name: mainFinalProject.cpp
** Author: Ben Fridkis
** Date: 6/2/2017
** Description: Main program to execute final project "Plane
				Crash Survivial" game.
**************************************************************/

#include "Item.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include "CrashSite.hpp"
#include "Meadow.hpp"
#include "Woods.hpp"
#include "Lake.hpp"
#include "InputValidation.hpp"
#include "MenuInputValidation.hpp"
#include "Menu.hpp"
#include "setSpacePointers.hpp"
#include "executeGame.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>
using std::fstream;

int main()
{
    //Seed declaration for random interger generator.
    unsigned seed = time(0);
    srand(seed);
    
    cout << "\n\nCS 162 FINAL PROJECT" << endl;
    
	int userSelection = Menu::menu();
    
	while (userSelection != 5)
	{
		if (userSelection != 4)
		{	
			cout << "\n\nYOUR PLANE HAS CRASHED IN THE REMOTE WILDERNESS!\n\n";
			
			if (userSelection == 1)
			{
				cout << "You have 90 days till winter.\n\n";
			}
			else
			{
				cout << "You have 80 days till winter.\n\n";
			}
			
			cout << "Stay alive and transmit the distress signal "
				 << "before it's too late!!!\n\n";
			
			Player* thisPlayer = new Player(userSelection);
			
			Space* theCrashSite = new CrashSite(thisPlayer, 0, 
				userSelection);
			Space* Meadow1 = new Meadow(thisPlayer, 1, 
				0);
				
			int randomInt = 1 + rand() % 3;	
			
			if (randomInt == 1)
			{
				Space* Meadow2 = new Meadow(thisPlayer, 2, userSelection, 1);
				Space* Woods1 = new Woods(thisPlayer, 1, userSelection);
				Space* Woods2 = new Woods(thisPlayer, 2, userSelection);
				Space* theLake = new Lake(thisPlayer, 0, userSelection);
				
				setSpacePointers(theCrashSite, Meadow1, Meadow2, Woods1,
								 Woods2, theLake);
								 
				thisPlayer->setPlayerLocation(theCrashSite);
				
				executeGame(thisPlayer, userSelection);
				
				delete thisPlayer;
				delete theCrashSite;
				delete Meadow1;
				delete Meadow2;
				delete Woods1;
				delete Woods2;
				delete theLake;
			}
			else if (randomInt == 2)
			{
				Space* Meadow2 = new Meadow(thisPlayer, 2, userSelection);
				Space* Woods1 = new Woods(thisPlayer, 1, userSelection, 1);
				Space* Woods2 = new Woods(thisPlayer, 2, userSelection);
				Space* theLake = new Lake(thisPlayer, 0, userSelection);
				
				setSpacePointers(theCrashSite, Meadow1, Meadow2, Woods1,
							 Woods2, theLake);
				
				thisPlayer->setPlayerLocation(theCrashSite);

				executeGame(thisPlayer, userSelection);
				
				delete thisPlayer;
				delete theCrashSite;
				delete Meadow1;
				delete Meadow2;
				delete Woods1;
				delete Woods2;
				delete theLake;
			}
			else
			{
				Space* Meadow2 = new Meadow(thisPlayer, 2, userSelection);
				Space* Woods1 = new Woods(thisPlayer, 1, userSelection);
				Space* Woods2 = new Woods(thisPlayer, 2, userSelection, 1);
				Space* theLake = new Lake(thisPlayer, 0, userSelection);
				setSpacePointers(theCrashSite, Meadow1, Meadow2, Woods1,
							 Woods2, theLake);
							 
				thisPlayer->setPlayerLocation(theCrashSite);
				
				executeGame(thisPlayer, userSelection);
				
				delete thisPlayer;
				delete theCrashSite;
				delete Meadow1;
				delete Meadow2;
				delete Woods1;
				delete Woods2;
				delete theLake;
			}
		}
		
        else
		{	
	
			fstream highScoreFile;
			highScoreFile.open("highScoreEasy.txt");
			int highScore = 0;
			string highScorePlayerName;
			if (!highScoreFile)
			{
				cout << "Easy Mode High Score Unavailable.\n\n";
			}
			else
			{	
				highScoreFile >> highScore;
				highScoreFile >> highScorePlayerName;
				
				if (highScore > 0)
				{	
					cout << "Easy:      " << highScore
						 << " by " << highScorePlayerName
						 << endl;
							 
				}
				else
				{
					cout << "Easy:      None "
						 << "(No one has survived easy mode yet.)"
						 << endl;
				}		 
			}
			highScoreFile.close();
		

			highScoreFile.open("highScoreNormal.txt");
			if (!highScoreFile)
			{
				cout << "Normal Mode High Score Unavailable.\n\n";
			}
			else
			{	
				highScoreFile >> highScore;
				highScoreFile >> highScorePlayerName;
				
				if (highScore > 0)
				{	
					cout << "Normal:    " << highScore
						 << " by " << highScorePlayerName
						 << endl;
						  
				}
				else
				{
					cout << "Normal:    None "
						 << "(No one has survived normal mode yet.)"
						 << endl;		 
				}	
			}
			highScoreFile.close();
		
			highScoreFile.open("highScoreDifficult.txt");
			if (!highScoreFile)
			{
				cout << "Difficult Mode High Score Unavailable.\n\n";
			}
			else
			{	
				highScoreFile >> highScore;
				highScoreFile >> highScorePlayerName;
				
				if (highScore > 0)
				{	
					cout << "Difficult: " << highScore
						 << " by " << highScorePlayerName
						 << endl << endl;
						  
				}
				else
				{
					cout << "Difficult: None "
						 << "(No one has survived difficult mode yet.)"
						 << endl;
				}		 
			}
			highScoreFile.close();
			
	
			cout << "\n(High score is highest remaining health + (days\n"
				 << "remaining x 30) after transmitting the distress signal.\n"
				 << "Tying the high score does not quailify for update.)"
				 << endl << endl;

		}
		userSelection = Menu::menu();
	}
	
	return 0;
}
