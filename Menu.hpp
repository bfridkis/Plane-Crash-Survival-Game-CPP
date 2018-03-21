/**********************************************************
** Program name: Menu.hpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Header file for Menu.cpp source file.
                Declares Menu class.
***********************************************************/

#ifndef Menu_hpp
#define Menu_hpp

#include "InputValidation.hpp"
#include "MenuInputValidation.hpp"
#include <iostream>
#include <memory>
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;
using std::make_shared;

class Menu
{
protected:
    int numberOfSelections;
    int userSelection;
public:
    static int menu();
    int getNumberOfSelections() const;
    void setNumberOfSelections(int numSelections);
    int getUserSelection() const;
    void setUserSelection(int userSelection);
};

#endif /* Menu_hpp */
