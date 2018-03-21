/**********************************************************
** Program name: MenuInputValidation.cpp
** Author: Ben Fridkis
** Date: 5/3/2017
** Description: MenuInputValidation class member function 
				definitions.
***********************************************************/

#include "MenuInputValidation.hpp"

/*##################################################
####################################################
		Derivative Class Member Functions:
			  MenuInputValidation
####################################################
####################################################*/

/****************************************************
			  MenuInputValidation
  Function to check input stream for a valid menu
  selection entry. Assumes menu entry options begin
  at 1. Function is passed an int parameter to 
  establish the greatest entry value. Assumes all
  entries between 1 and numberOfSelections parameter
  are integers and valid. Base class is Menu.
 ****************************************************/ 
int MenuInputValidation::menuInputValidation
    (int numberOfSelections)
{
    int userChoice;
    cin >> userChoice;
    
    //If user input generates an error because
    //a non-int type is received by the input
    //stream, or a value is entered that is out 
	//of the established range of selections, loop 
	//as follows:
    while (!cin || userChoice < 1 || userChoice > numberOfSelections)
	   {
           cout << "\nPlease enter an integer between 1 and "
				<< numberOfSelections << " to make your "
				<< "selection.\n" << endl;
           //Clear the cin error flag.
           cin.clear();
           //Ignore the rest of the input stream, in
           //case space seperated values were provided.
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
           //Try again.
           cin >> userChoice;
       }
    
    //Ignore any remaining values in the input
    //stream, and print a new line.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    
    userSelection = userChoice;
    return userSelection;
}
/*******************************************
 		       getUserSelection
    Returns userSelection member variable.
 *******************************************/
int MenuInputValidation::getUserSelection() 
	const
{
	return userSelection;
}
/***************************************
		    setUserSelection
  Sets userSelection member variable.
 ***************************************/
void MenuInputValidation::setUserSelection
	(int userSelection)
{
	this->userSelection = userSelection;
}
