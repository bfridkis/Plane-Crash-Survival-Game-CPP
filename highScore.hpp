/*************************************************
** Program name: highScore.hpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Function prototype for highScore.
**************************************************/

#ifndef highScore_hpp
#define highScore_hpp

#include <iostream>
#include <fstream>
#include <string>
#include "Player.hpp"
using std::cout;
using std::end;
using std::fstream;
using std::string;

void highScore(Player* thisPlayer, int difficultyLevel);

#endif /* highScore_hpp */