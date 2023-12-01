// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Data.h"

using namespace std;

//https://adventofcode.com/2023/day/1

//constexpr std::size_t constexpr_strlen(const char* s)
//{
//    return (s && s[0]) ? (constexpr_strlen(&s[1]) + 1) : 0;
//}

constexpr bool isPartTwo = true;

int GetNumber(const char* str)
{
	if (str[0] >= '0' && str[0] <= '9') //its a digit
		return str[0] - '0';

	if(isPartTwo)
	{
		//we else check if its a written digit
		if (strncmp(str, "one", 3) == 0)
			return 1;
		if (strncmp(str, "two", 3) == 0)
			return 2;
		if (strncmp(str, "three", 5) == 0)
			return 3;
		if (strncmp(str, "four", 4) == 0)
			return 4;
		if (strncmp(str, "five", 4) == 0)
			return 5;
		if (strncmp(str, "six", 3) == 0)
			return 6;
		if (strncmp(str, "seven", 5) == 0)
			return 7;
		if (strncmp(str, "eight", 5) == 0)
			return 8;
		if (strncmp(str, "nine", 4) == 0)
			return 9;
	}

	return -1;	
}

int main()
{
	constexpr int numDataElements = std::size(s_Data);

	//iterate over the array find the first and the last digit in it and add them to the sum
	unsigned int sum = 0;
	for (const auto curElement : s_Data)
	{
		//cout << curElement << endl;
		const int elementLength = strlen(curElement);
		//Find first digit
		for (int j = 0; j < elementLength; j++)  
		{
			const int num = GetNumber(curElement + j);
			if (num >= 0) //its a digit
			{
				//cout << "first:" << num;
				sum += num * 10;
				break;
			}
		}
		//Find last digit
		for (int j = elementLength - 1; j >= 0; j--)
		{
			const int num = GetNumber(curElement + j);
			if (num >= 0) //its a digit
			{
				//cout << " last:" << num << endl;
				sum += num;
				break;
			}
		}		
	}
    cout << sum;
}