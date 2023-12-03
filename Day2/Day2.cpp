// Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Data.h"

using namespace std;

int main()
{
	//stopped with this approach, and moved to C#... (Day2_CS)

	constexpr int numDataElements = std::size(s_games);
	constexpr int numSets = MAX_SETS;

	//iterate over the array find the first and the last digit in it and add them to the sum
	unsigned int sum = 0;
	for(int i = 0; i < numDataElements; ++i)
	{
		for(int j = 0; j < numDataElements; ++j)
		{
			auto curElement = s_games[i][j];
			cout << curElement.m_Amount << " - " << curElement.m_Color << " , ";
		}
		cout << endl;
	}
}
