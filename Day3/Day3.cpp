#include <iostream>
#include <cstring>
#include "DataDay3.h"

//auto& data = s_TestData;
auto& data = s_Data;

bool IsSpecialCharacter(char c)
{
    return c != '.' && !isdigit(c);
}

int SumOfDigitsAroundPos(int posX, int posY)
{
    int sum = 0;
    for (int y = posY - 1; y <= posY + 1; y++)
    {
        for (int x = posX - 1; x <= posX + 1; x++)
        {
            //check if at this position is a digit
            if (isdigit(data[y][x]))
            {
                //find the start of the number
                int start = x;
                while (start > 0 && isdigit(data[y][start - 1]))
                {
                    start--;
                }
                sum += std::atoi(&data[y][start]);
                //we used the number, now we remove it
                while (isdigit(data[y][start]))
                {
                    data[y][start] = '.';
                    start++;
                }
            }
        }
    }
    return sum;
}

int ProductOfGear(int posX, int posY)
{
    //exactly the same as SumOfDigitsAroundPos, but we need to find 2 numbers and multiply them. so we keep track of how many numbers we found
    int numNumbers = 0;
    int product = 1;
    for (int y = posY - 1; y <= posY + 1; y++)
    {
        for (int x = posX - 1; x <= posX + 1; x++)
        {
            //check if at this position is a digit
            if (isdigit(data[y][x]))
            {
                if(numNumbers >= 2)
                    return 0; //we already have 2 numbers, so we can't use this one

                //find the start of the number
                int start = x;
                while (start > 0 && isdigit(data[y][start - 1]))
                {
                    start--;
                }
                product *= std::atoi(&data[y][start]);
                //we used the number, now we remove it
                while (isdigit(data[y][start]))
                {
                    data[y][start] = '.';
                    start++;
                }
                numNumbers++;
            }
        }
    }
    if(numNumbers != 2)
        return 0; //we didn't find 2 numbers, so we can't use this gear
    return product;
}

int main()
{
    constexpr bool isPart2 = true;

    int numElements = std::size(data);
    int lengthElement = std::strlen((char*)data);

    if (!isPart2)
    {
        int totalSum = 0;

        //iterate over the array and find all non-digit non '.' characters
        for (int y = 0; y < numElements; y++)
        {
            for (int x = 0; x < lengthElement; x++)
            {
                if (IsSpecialCharacter(data[y][x]))
                {
                    std::cout << "part character found: " << data[y][x] << std::endl;
                    totalSum += SumOfDigitsAroundPos(x, y);
                }
            }
        }
        std::cout << "Sum of parts: " << totalSum;
    }
    else
    {
        int totalProduct = 0;

        //iterate over the array and find all non-digit non '.' characters
        for (int y = 0; y < numElements; y++)
        {
            for (int x = 0; x < lengthElement; x++)
            {
                if (data[y][x] == '*')
                {
                    std::cout << "gear character found: " << data[y][x] << std::endl;
                    totalProduct += ProductOfGear(x, y);
                }
            }
        }

        std::cout << "totalProduct of gears: " << totalProduct;
    }

    return 0;
}
