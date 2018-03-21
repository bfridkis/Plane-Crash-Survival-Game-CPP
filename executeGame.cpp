/*************************************************************
** Program name: executeGame.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Function definition to execute a Game after
				Space and Player object instantiation from
				within the main program for CS 162 Final 
				Project.
**************************************************************/

#include "executeGame.hpp"

/*************************************************
                   executeGame
  Function to execute the game (for final project
  cs 162) after Space and Player objects have 
  been created. Loops until Player health or
  remaining days reach 0 or Player transmits the
  distress signal to win the game. Prompts user
  with menu items for each loop iteration. Uses
  file i/o operations to retrieve and print a 
  high score if player survives. If surviving
  player is determined to have highest score
  (calculated by adding the player's remaining 
  days to remaining health at the end of a game
  won, the user is prompted to enter a name for 
  the winner which is then stored as the highest
  score. (Note: High score is also available via
  the program's main menu.)
 *************************************************/
void executeGame(Player* thisPlayer, int userSelection)
{	
	char userInput = '~';
	while (thisPlayer->getHealth() > 0 
			&& thisPlayer->getRemainingDays() > 0
			&& thisPlayer->getHasTransmitted() == false
			&& userInput != 'Q')
	{
		thisPlayer->printSpace(true);
		userInput = InputValidation::jLIKEVStarOrQInputValidation();
		if (userInput == 'I' || userInput == 'K' || userInput == 'L'
			|| userInput == 'J')
		{
			thisPlayer->movePlayer(userInput);
		}
		else if (userInput == 'E')
		{
			thisPlayer->spaceInteract();
		}
		else if (userInput == '*')
		{
			if (userSelection != 3)
			{	
				thisPlayer->printItemKey();
			}
			else
			{
				cout << "\nItem Key Not Available in Difficult Mode."
					 << endl << endl;
			}
		}
		else if (userInput == 'V')
		{
			thisPlayer->useItem();
		}
	}
	
	if (thisPlayer->getHealth() <= 0)
	{
		cout << "\nYou didn't make it. Health depleted.\n"
			 << "The world will mourn this loss.\n\n"
			 << "Number of Moves: " << thisPlayer->getMoveCount()
			 << "\n" << "Health Remaining: " 
			 << thisPlayer->getHealth() << "\n"
			 << "Number of Days Remaining: " 
			 << thisPlayer->getRemainingDays() << endl << endl;
	}
	else if (thisPlayer->getRemainingDays() <= 0)
	{
		cout << "\nUnfortunately you froze. Winter has arrived.\n"
			 << "Those holding out for your return will have to move on.\n\n"
			 << "Number of Moves: " << thisPlayer->getMoveCount()
			 << "\n" << "Health Remaining: " 
			 << thisPlayer->getHealth() << "\n"
			 << "Number of Days Remaining: " 
			 << thisPlayer->getRemainingDays() << endl << endl;
	}
	else if (userInput != 'Q')
	{
		cout << "\nYou made it!!! Distress signal sent, rescue plane dispatched.\n"
			 <<"Congratulations. You will live to see another day!\n\n"
			 << "Number of Moves: " << thisPlayer->getMoveCount()
			 << "\n" << "Health Remaining: " 
			 << thisPlayer->getHealth() << "\n"
			 << "Number of Days Remaining: " 
			 << thisPlayer->getRemainingDays() << endl << endl;
			 
		highScore(thisPlayer, userSelection);
	}
}