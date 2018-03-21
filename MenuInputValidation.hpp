/*****************************************************************
** Program name: lab5RecursiveFunctions.cpp
** Author: Ben Fridkis
** Date: 5/3/2017
** Description: Derived class MenuInputValidation declaration.
				(Base class is InputValidation).
******************************************************************/

#ifndef MenuInputValidation_hpp
#define MenuInputValidation_hpp

#include "InputValidation.hpp"

using std::cout;
using std::cin;

class MenuInputValidation: public InputValidation
{
private:
    int userSelection;
public:
    int menuInputValidation(int numberOfSelections);
	int getUserSelection() const;
	void setUserSelection(int userSelection);
};

#endif /* MenuInputValidation_hpp */