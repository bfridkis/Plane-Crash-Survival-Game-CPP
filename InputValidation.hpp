/**********************************************************
** Program name: InputValidation.hpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: Header file for InputValidation.cpp source 
				file.
***********************************************************/

#ifndef InputValidation_hpp
#define InputValidation_hpp

#include <string>
#include <iostream>
#include <limits>
#include <memory>
#include <algorithm>
#include <cctype>
#include <iomanip>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::streamsize;
using std::isalpha;
using std::find_if;
using std::numeric_limits;
using std::setprecision;
using std::fixed;
using std::showpoint;

class InputValidation
{
private:
	static bool foundNonAlpha(string input);
public:
    static int intInputValidation
        (int max = numeric_limits<int>::max(),
         int min = numeric_limits<int>::min());
	static float floatInputValidation
		(float max = numeric_limits<float>::max(),
         float min = numeric_limits<float>::min());
    
    static bool boolInputValidation();
	static char yOrNInputValidation();
	static char pOrIInputValidation();
	static char oOrIInputValidation();
	static char _1of2CharactersInputValidation(char, char);
	static char jLIKEVStarOrQInputValidation();
	static char nSEorWcharInputValidation();
	
	static string stringSizeInputValidation
		(unsigned long max = 
		 numeric_limits<streamsize>::max());
	static string alphaStringInputValidation
		(unsigned long max = 
		 numeric_limits<streamsize>::max());
	static string atLeastOneAlphaCharacterValidation
        (unsigned long max = 
		 numeric_limits<streamsize>::max(),
		 bool allowEntryOf0 = false);
	static void enterKeyPrompt();	 
};

#endif /* InputValidation_hpp */
