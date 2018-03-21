/*************************************************************
** Program name: randomOrderUniqueElementGenerator.cpp
** Author: Ben Fridkis
** Date: 6/1/2017
** Description: Function definition to modify a vector
				parameter so as to push_back a number of 
				elements in a random order that are each
				unique between a range indicated by max and 
				min. Pushes back a number of elements equal
				to the range for a given element's value by
				default, less if indicated by the last 
				paramter.
**************************************************************/

#include <vector>
#include <cstdlib>
using std::vector;

/*************************************************
        randomOrderUniqueElementGenerator
  Uses a for loop to generate a number of integers
  according to numberOfInts parameter between max
  and min parameter and to push them into the 
  vector reference parameter.
  Reference: https://stackoverflow.com/questions/
  12657962/how-do-i-generate-a-random-number-
  between-two-variables-that-i-have-stored
 *************************************************/
 void randomOrderUniqueElementGenerator
	(vector<int>& container, int max, int min,
	 int numberOfElements)
{	
	if (numberOfElements <= max - min + 1)
	{	
		for (int i = 1; i < max; i++)
		{
			int randomInt = min + (rand() % (max - min + 1));
			bool alreadyInVector = false;
			for (unsigned j = 0; j < container.size() &&
				 alreadyInVector == false; j++)
			{
				if (randomInt == container.at(j))
				{
					alreadyInVector = true;
				}
			}
			if(!alreadyInVector)
			{
				container.push_back(randomInt);
			}
			else
			{
				i--;
			}
		}
	}
	else
	{
		throw "Storm passed with no damage.\n\n";
	}
}