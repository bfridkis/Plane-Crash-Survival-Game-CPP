/*************************************************************
** Program name: highScore.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Function definition to update highScore files
				based on difficulty level print out high 
				score for current difficulty level. Only 
				updates if current player has achieved the
				high score for the given difficulty level.
**************************************************************/

#include "highScore.hpp"

void highScore(Player* thisPlayer, int difficultyLevel)
{
	//This function will check a files "highScoreEasy.txt",
	//"highScoreNormal.txt", and "highScoreDifficult.txt" depending on 
	//difficultyLevel to compare the sum of the player's 
	//remaining health points and (days till winter x 30) and if the 
	//player's remaining values are greater than the value stored in
	//the file, the file is updated with the player's score (remaining 
	//health points + (remaining days * 30) (since 6 moves equals one 
	//day, and one move equals 5 health points) and is prompted to enter 
	//a name to associate with the high score. If the player did not score 
	//higher than the value stored in highScore.txt, The high score along 
	//with the associated name that is stored in the file is printed.
	
	if (difficultyLevel == 1)
	{	
		fstream highScoreFile;
		highScoreFile.open("highScoreEasy.txt");
		int highScore = 0;
		string highScorePlayerName;
		if (highScoreFile)
		{
			highScoreFile >> highScore;
			highScoreFile >> highScorePlayerName;
		}
		highScoreFile.close();	
		
		if (thisPlayer->getRemainingDays() + thisPlayer->getHealth()
				> highScore)
		{
			cout << "Congratulations! You Now Have the High Score!\n\n"
				 << "Please enter your name to be remembered forever\n"
				 << "(or until someone else beats your score): ";
			string playerName = InputValidation::stringSizeInputValidation(40);
			highScoreFile.open("highScoreEasy.txt");
			
			highScoreFile << thisPlayer->getHealth() + 
							 (thisPlayer->getRemainingDays() * 30);
			highScoreFile << playerName;
			
			highScoreFile.close();
		}
		else
		{
			if (!highScoreFile)
			{
				cout << "High Score Unavailable.\n\n";
			}
			else
			{	
				highScoreFile >> highScore;
				highScoreFile >> highScorePlayerName;
				
				if (highScore > 0)
				{	
					cout << "\nHigh Score (Easy): " << highScore
						 << " by " << highScorePlayerName
						 << endl << endl;
				}		 
			}
			highScoreFile.close();
		}	
	}
		
	else if (difficultyLevel == 2)
	{
		fstream highScoreFile;
		highScoreFile.open("highScoreNormal.txt");
		int highScore = 0;
		string highScorePlayerName;
		if (highScoreFile)
		{
			highScoreFile >> highScore;
			highScoreFile >> highScorePlayerName;
		}
		highScoreFile.close();	
		
		if (thisPlayer->getRemainingDays() + thisPlayer->getHealth()
				> highScore)
		{
			cout << "Congratulations! You Now Have the High Score!\n\n"
				 << "Please enter your name to be remembered forever\n"
				 << "(or until someone else beats your score): ";
			string playerName = InputValidation::stringSizeInputValidation(40);
			highScoreFile.open("highScoreNormal.txt");
			
			highScoreFile << thisPlayer->getHealth() + 
							 (thisPlayer->getRemainingDays() * 30);
			highScoreFile << playerName;
			
			highScoreFile.close();
		}
		else
		{
			if (!highScoreFile)
			{
				cout << "High Score Unavailable.\n\n";
			}
			else
			{	
				highScoreFile >> highScore;
				highScoreFile >> highScorePlayerName;
				
				if (highScore > 0)
				{	
					cout << "\nHigh Score (Normal): " << highScore
						 << " by " << highScorePlayerName
						 << endl << endl;
				}		 
			}
			highScoreFile.close();
		}
	}

	else
	{
		fstream highScoreFile;
		highScoreFile.open("highScoreDifficult.txt");
		int highScore = 0;
		string highScorePlayerName;
		if (highScoreFile)
		{
			highScoreFile >> highScore;
			highScoreFile >> highScorePlayerName;
		}
		highScoreFile.close();	
		
		if (thisPlayer->getRemainingDays() + thisPlayer->getHealth()
				> highScore)
		{
			cout << "Congratulations! You Now Have the High Score!\n\n"
				 << "Please enter your name to be remembered forever\n"
				 << "(or until someone else beats your score): ";
			string playerName = InputValidation::stringSizeInputValidation(40);
			highScoreFile.open("highScoreDifficult.txt");
			
			highScoreFile << thisPlayer->getHealth() + 
							 (thisPlayer->getRemainingDays() * 30);
			highScoreFile << playerName;
			
			highScoreFile.close();
		}
		else
		{
			if (!highScoreFile)
			{
				cout << "High Score Unavailable.\n\n";
			}
			else
			{	
				highScoreFile >> highScore;
				highScoreFile >> highScorePlayerName;
				
				if (highScore > 0)
				{	
					cout << "\nHigh Score (Difficult): " << highScore
						 << " by " << highScorePlayerName
						 << endl << endl;
				}		 
			}
			highScoreFile.close();
		}
	}
}