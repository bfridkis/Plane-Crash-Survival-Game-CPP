/**********************************************************
** Program name: InputValidation.cpp
** Author: Ben Fridkis
** Date: 5/31/2017
** Description: InputValidation class member function 
				definitions.
***********************************************************/

#include "InputValidation.hpp"

/****************************************************
				intInputValidation
  Function to check input stream for an integer
  interger value up to the paramater max and no less
  than parameter min. Continues to prompt user until
  an input fulfilling these criteria is received.
  Default max and min are given by numeric_limits<int>
  max and min.
 ****************************************************/
int InputValidation::intInputValidation(int max, int min)
{
    int input;
    cin >> input;
	//If cin fails (i.e. the variable in the input stream
	//is not of type int) or input is less than min or
	//greater than max, notify and reprompt user, reset 
	//cin error flag ignore any remaining input in the input
    //stream up to the next newline character, and try again using
	//the user's next entry.
    if (max != numeric_limits<int>::max() &&
        min != numeric_limits<int>::min())
    {
        while (!cin || input < min || input > max)
        {
            cout << "\nInvalid input.\n"
				 << "Please enter an integer no greater than " 
				 << max << " and no less than " 
				 << min << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
    }
    else if (max != numeric_limits<int>::max())
    {
        while (!cin || input > max)
        {
            cout << "\nInvalid input. Please enter an integer "
            << "no greater than " << max << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
    }
	else if (min != numeric_limits<int>::min())
    {
        while (!cin || input < min)
        {
            cout << "\nInvalid input. Please enter an integer "
            << "no less than " << min << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
    }
    else
    {
        while (!cin)
        {
            cout << "\nInvalid input. Please enter an integer."
                 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
               
    return input;
}
/****************************************************
				 floatInputValidation
  Function to check input stream for a floating point 
  value. Reprompts the user to enter a floating point
  value within the range of max and min (default is
  given by numeric_limits<float> max and min.
 ****************************************************/
float InputValidation::floatInputValidation
    (float max, float min)
{
    float input;
    cin >> input;
	//If cin fails (i.e. the variable in the input stream
	//is not of type int) or input is less than one,
	//notify and reprompt user, reset cin error flag,
	//ignore any remaining input in the input stream up
	//to the next newline character, and try again using 
	//the user's next entry.
    if (max != numeric_limits<float>::max() &&
        min != numeric_limits<float>::lowest())
    {
        while (!cin || input < min || input > max)
        {
            cout << "\nInvalid input. Please enter a positive value "
                 << "no greater than "
                 << fixed << setprecision(1) << showpoint
                 << max << " and ."
                 << "no less than " << min << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
    }
    else if (max != numeric_limits<float>::max())
    {
        while (!cin || input > max)
        {
            cout << "\nInvalid input. Please enter a value "
                 << "no greater than "
                 << fixed << setprecision(1) << showpoint
                 << max << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
    }
	else if (min != numeric_limits<float>::min())
    {
        while (!cin || input < min)
        {
            cout << "\nInvalid input. Please enter a value "
                 << "no less than "
                 << fixed << setprecision(1) << showpoint
                 << min << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
    }
    else
    {
        while (!cin)
        {
            cout << "\nInvalid input. Please enter an integer."
                 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }
    }
        
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
               
    return input;
}
/****************************************************
			    boolInputValidation
  Function to check input stream for a boolean
  (0 or 1) entry. Used in conjunction with a prompt
  for "Yes" or "No", where 1 corresponds to yes and
  0 corresponds to no. Reprompts the user to enter a 
  1 or 0 if 1 or 0 is not entered.
 ****************************************************/ 
bool InputValidation::boolInputValidation()
{
    bool isYes;
    cin >> isYes;
	//If cin fails (i.e. the variable in the input stream
	//is not of type bool), notify and reprompt 
	//user, reset cin error flag, ignore any remaining input 
	//in the input stream up to the next newline character, 
	//and try again using the user's next entry.
    while (!cin)
    {
        cout << "\nInvalid input. Please enter 1 or 0."
             << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> isYes;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return isYes;
}
/****************************************************
			    yOrNInputValidation
  Function to check input stream for a char entry
  of 'y', 'Y', 'n', or 'N'. Reprompts the user to 
  enter 'y' or 'n' if one of these is not entered.
 ****************************************************/ 
char InputValidation::yOrNInputValidation()
{
    string yOrN;
    getline(cin, yOrN);
    
	//If input is not y, n, Y, or N, reprompt for entry
    //that is y or n.
    while (yOrN == "" ||
           (toupper(yOrN.at(0)) != 'Y'
           && toupper(yOrN.at(0)) != 'N')
           || yOrN.length() > 1 )
    {
        cout << "\nInvalid input. Please enter \'y\' for yes,"
			 << " or \'n\' for no: ";
        getline(cin, yOrN);
    }
    
    return toupper(yOrN.at(0));
}
/****************************************************
			    pOrIInputValidation
  Function to check input stream for a char entry
  of 'p', 'P', 'i', or 'I'. Reprompts the user to 
  enter 'p' or 'i' if one of these is not entered.
 ****************************************************/ 
char InputValidation::pOrIInputValidation()
{
    string pOrI;
    getline(cin, pOrI);
    
	//If input is not p, i, P, or I, reprompt for entry
    //that is p or i.
    while (pOrI == "" ||
           (toupper(pOrI.at(0)) != 'P'
           && toupper(pOrI.at(0)) != 'I')
           || pOrI.length() > 1 )
    {
        cout << "\nInvalid input. Please enter \'p\' to pickup,"
			 << " or \'i\' to ignore: ";
        getline(cin, pOrI);
    }
    
    return toupper(pOrI.at(0));
}
/****************************************************
			    oOrIInputValidation
  Function to check input stream for a char entry
  of 'o', 'O', 'i', or 'I'. Reprompts the user to 
  enter 'o' or 'i' if one of these is not entered.
 ****************************************************/ 
char InputValidation::oOrIInputValidation()
{
    string oOrI;
    getline(cin, oOrI);
    
	//If input is not o, i, O, or I, reprompt for entry
    //that is o or i.
    while (oOrI == "" ||
           (toupper(oOrI.at(0)) != 'O'
           && toupper(oOrI.at(0)) != 'I')
           || oOrI.length() > 1 )
    {
        cout << "\nInvalid input. Please enter \'o\' to open,"
			 << " or \'i\' to ignore: ";
        getline(cin, oOrI);
    }
    
    return toupper(oOrI.at(0));
}
/****************************************************
			_1of2CharactersInputValidation
  Function to check input stream for a char entry
  for one of the two character parameters (case-
  insensitive). If one of the two character parameters
  is not detected, re-prompts user accordingly.
 ****************************************************/ 
char InputValidation::_1of2CharactersInputValidation
	(char validInput1, char validInput2)
{
    string character;
    getline(cin, character);
    
	//If input is not == validInput1 or validInput2
	//re-prompt for another character that is.
    while (character == "" ||
           (toupper(character.at(0)) != validInput1
           && toupper(character.at(0)) != validInput2)
           || character.length() > 1 )
    {
        cout << "\nInvalid input. Please enter "
			 << validInput1 << " or " << validInput2
			 << " to make your selection: ";
        getline(cin, character);
    }
    
    return toupper(character.at(0));
}
/*************************************************************
			    jLIKEVStarOrQInputValidation
  Function to check input stream for a char entry or 'j', 
  'l', 'i', 'k', 'e', '*' or 'v' (case insensitive). Reprompts 
  the user to re-enter one of these characters if entry is not
  one of these seven characters.
 *************************************************************/ 
char InputValidation::jLIKEVStarOrQInputValidation()
{
    string jLIKEVStarOrQ;
    getline(cin, jLIKEVStarOrQ);
    
	//If input is not j, l, i, k, e, or v, reprompt for entry
    //that is one of these. Ignores case.
    while (jLIKEVStarOrQ == "" ||
           (toupper(jLIKEVStarOrQ.at(0)) != 'J'
           && toupper(jLIKEVStarOrQ.at(0)) != 'L'
		   && toupper(jLIKEVStarOrQ.at(0)) != 'I'
		   && toupper(jLIKEVStarOrQ.at(0)) != 'K'
		   && toupper(jLIKEVStarOrQ.at(0)) != 'E'
		   && toupper(jLIKEVStarOrQ.at(0)) != 'V'
           && jLIKEVStarOrQ.at(0) != '*'
           && toupper(jLIKEVStarOrQ.at(0)) != 'Q')
           || jLIKEVStarOrQ.length() > 1 )
    {
        cout << "\nInvalid input.\n"
			 << "Commands:\n"
			 << "j-move left, l-move right "
			 << "i-move up, k-move down, e-engage, "
			 << "v-view items\n"
             << "*-view symbol key, q-quit"
             << endl;
        getline(cin, jLIKEVStarOrQ);
    }
    
    return toupper(jLIKEVStarOrQ.at(0));
}
/*************************************************************
			      nSEorWcharQInputValidation
  Function to check input stream for a char entry or 'n', 
  's', 'e', 'w', (case insensitive). Reprompts the user to 
  re-enter one of these characters if entry is not one of 
  these four characters.
 *************************************************************/ 
char InputValidation::nSEorWcharInputValidation()
{
    string nSEorWchar;
    getline(cin, nSEorWchar);
    
	//If input is not j, l, i, k, e, or v, reprompt for entry
    //that is one of these. Ignores case.
    while (nSEorWchar == "" ||
           (toupper(nSEorWchar.at(0)) != 'N'
           && toupper(nSEorWchar.at(0)) != 'S'
		   && toupper(nSEorWchar.at(0)) != 'E'
		   && toupper(nSEorWchar.at(0)) != 'W'
		   && toupper(nSEorWchar.at(0)) != 'E')
           || nSEorWchar.length() > 1 )
    {
        cout << "\nInvalid input.\nPlease enter \'n\' for north, "
             << "\'s\' for south, \'e\' for east, or \'w\' for "
			 << "west: ";
        getline(cin, nSEorWchar);
    }
    
    return toupper(nSEorWchar.at(0));
}
/*************************************************
			    foundNonAlpha
  Function to check input stream for a non-alpha
  character. If a non-alpha character is present,
  returns true. Else, returns false.
 *************************************************/
bool InputValidation::foundNonAlpha(string input)
{
	bool notAllAlpha = false;
    for (unsigned i = 0; i < input.length() 
		&& !notAllAlpha; i++)
	{
        if (!isalpha(input.at(i)) 
			&& input.at(i) != ' ')
        {
            notAllAlpha = true;
        }
	}	
	
	return notAllAlpha;
}
/****************************************************
			 stringSizeInputValidation
  Function to check input stream for a string that
  consists of no more than max characters. Default
  is the streamsize maximum.
 ****************************************************/
string InputValidation::stringSizeInputValidation
	(unsigned long maxCharacters)
{
	string input;
	getline(cin, input);
	
    while (input.length() > maxCharacters ||
           input == "")
    {
        if (input == "")
        {
            cout << "Entry must consist of at least one"
                 << " character." << endl;
        }
        else if (input.length() > maxCharacters)
        {
            cout << "\nEntry cannon exceed " << maxCharacters
                 << " characters. Please re-type entry."
                 << endl;
        }
		getline(cin, input);
	}	
	
	return input;
}	
/****************************************************
			 alphaStringInputValidation
  Function to check input stream for a string that
  consists of only alpha characters. If a string with
  at least one non-alpha character is detected, the
  function reprompts the user to enter a string that
  consists of alpha characters only. Eliminates any
  duplicate and trailing whitespace characters.
 ****************************************************/
string InputValidation::alphaStringInputValidation
	(unsigned long maxCharacters)
{
	string input;
	getline(cin, input);
	
    while (input == "")
    {
        cout << "\nEntry must consist of at least one "
             << "alpha character. Please re-type entry."
             << "\n(Max " << maxCharacters << " characters.)"
             << endl;
        getline(cin, input);
    }
    
    while (foundNonAlpha(input) || input.length()
           > maxCharacters)
	{
		if (foundNonAlpha(input))
		{
			cout << "\nEntry must consist of alpha "
				 << "characters only. Please re-type "
				 << "entry.\n(Max " << maxCharacters
				 << " characters.)" << endl;
			getline(cin, input);	
		}	
		else if (input.length() > maxCharacters)
		{
			cout << "\nEntry cannon exceed " << maxCharacters
				 << " characters. Please re-type entry."
                 << endl;
			getline(cin, input);
		}	 
	}
    
    //Checks all characters up to (and including) the
    //second to last character of the string to see
    //if the following character is a whitespace(i.e.
	//checks if two whitespaces are found in adjacent 
	//positions or, "back-to_back". Hence, if "  " is
    //found, the at pos i is removed, and the counter
    //decrements one to check again for the same character
    //position. Stops at second to last so it will not
    //attempt to access outside the bounds of the string
    //object's char array.
    for (int i = 0; i < static_cast<int>(input.length() - 2);
            i++)
    {
        if (input.at(i) == ' ' && input.at(i + 1) == ' ')
        {
            input.erase(i, 1);
            i--;
        }
    }
    
    //Checks final character for whitespace, and if
    //a whitespace is detected, it is removed.
    if (input.at(input.length() - 1) == ' ')
    {
        input.pop_back();
    }
	
	return input;
	 
}
/****************************************************
		 atLeastOneAlphaCharacterValidation
  Function to check input stream for a string that
  contains at least one alpha character. Eliminates 
  any duplicate and trailing whitespace characters.
 ****************************************************/
string InputValidation::atLeastOneAlphaCharacterValidation
	(unsigned long maxCharacters, bool allowEntryOf0)
{
    string input;
	if (allowEntryOf0)
	{
		bool atLeastOneAlphaCharacter = false;
		getline(cin, input);
		
        while ((!atLeastOneAlphaCharacter ||
            input.length() > maxCharacters) && input != "0")
        {
            if (input.length() > maxCharacters)
            {
                cout << "Entry can not exceed " << maxCharacters
                     << " characters. Please re-type entry."
                     << endl;
                getline(cin, input);
            }
            if (input.length() <= maxCharacters)
            {	
                for (unsigned i = 0; i < input.length() && 
                    !atLeastOneAlphaCharacter; i++)
                {
                    if (isalpha(input.at(i)))
                    {
                        atLeastOneAlphaCharacter = true;
                    }
                            
                }
                if (!atLeastOneAlphaCharacter)
                {
                    cout << "\nEntry must consist of at least one alpha "
                         << "character. Please re-type "
                         << "entry.\n(Max " << maxCharacters
                         << " characters. Enter 0 for blank entry.)"
                         << endl;
                    getline(cin, input);
                }		
            }	
        }
        
        //Checks all characters up to (and including) the
        //second to last character of the string to see
        //if the following character is a whitespace(i.e.
        //checks if two whitespaces are found in adjacent 
        //positions or, "back-to_back". Hence, if "  " is
        //found, then at pos i is removed, and the counter
        //decrements one to check again for the same character
        //position. Stops at second to last so it will not
        //attempt to access outside the bounds of the string
        //object's char array.
        if (input.length() > 1)
        {
            for (int i = 0; i < static_cast<int>(input.length() - 2);
                    i++)
            {
                if (input.at(i) == ' ' && input.at(i + 1) == ' ')
                {
                    input.erase(i, 1);
                    i--;
                }
            }
        }
        //Checks final character for whitespace, and if
        //a whitespace is detected, it is removed.
        if (input.at(input.length() - 1) == ' ')
        {
            input.pop_back();
        }
    }

	else if (!allowEntryOf0)
	{
		bool atLeastOneAlphaCharacter = false;
		getline(cin, input);
		
		while (!atLeastOneAlphaCharacter || 
			input.length() > maxCharacters)
		{
			if (input.length() > maxCharacters)
			{
				cout << "\nEntry can not exceed " << maxCharacters
					 << " characters. Please re-type entry."
					 << endl;
				getline(cin, input);
			}
			if (input.length() <= maxCharacters)
			{	
				for (unsigned i = 0; i < input.length() && 
					!atLeastOneAlphaCharacter; i++)
				{
					if (isalpha(input.at(i)))
					{
						atLeastOneAlphaCharacter = true;
					}
							
				}
				if (!atLeastOneAlphaCharacter)
				{
					cout << "\nEntry must consist of at least one alpha "
						 << "character. Please re-type "
						 << "entry.\n(Max " << maxCharacters
						 << " characters.)"
						 << endl;
					getline(cin, input);
				}		
			}	
		}
		
		//Checks all characters up to (and including) the
		//second to last character of the string to see
		//if the following character is a whitespace(i.e.
		//checks if two whitespaces are found in adjacent 
		//positions or, "back-to_back". Hence, if "  " is
		//found, the at pos i is removed, and the counter
		//decrements one to check again for the same character
		//position. Stops at second to last so it will not
		//attempt to access outside the bounds of the string
		//object's char array.
		if (static_cast<int>(input.length()) > 1)
        {
            for (int i = 0;
                i < static_cast<int>(input.length()) - 2; i++)
            {
                if (input.at(i) == ' ' && input.at(i + 1) == ' ')
                {
                    input.erase(i, 1);
                    i--;
                }
            }
		}
		//Checks final character for whitespace, and if
		//a whitespace is detected, it is removed.
		if (input.at(input.length() - 1) == ' ')
		{
			input.pop_back();
        }
	}

    return input;
}
/****************************************************
					enterKeyPrompt
  Function provides a prompt to press the enter key
  that can be used as a pause between printouts. 
  Ignores any values entered before the enter key
  is pressed.
 ****************************************************/
void InputValidation::enterKeyPrompt()
 {
	char ch; 	//Used for input validation, so enter key
				//only needs to be pressed once and characters
				//entered before enter key do not remain in 
				//the input buffer.
	cout << "Press enter key to continue: ";
	cin.get(ch);
	if (ch != '\n')
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
 }
