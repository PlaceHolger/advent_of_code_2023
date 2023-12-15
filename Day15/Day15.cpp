#include <iostream>
#include <cassert>
#include <list>

#include "DataDay15.h"

#define IS_PART2

int GetHash(const char* data, int numChars = -1)
{
    // Determine the ASCII code for the current character of the string.
    // Increase the current value by the ASCII code you just determined.
    // Set the current value to itself multiplied by 17.
    // Set the current value to the remainder of dividing itself by 256.
    // Repeat steps 1-4 for the entire string.

    int hash = 0;
    const int numCharsToProcess = numChars == -1 ? static_cast<int>(strlen(data)) : numChars;
    for (int i = 0; i < numCharsToProcess; ++i)
    {
        hash += data[i];
        hash *= 17;
        hash %= 256;
    }

    //std::cout << "Hash: " << hash << " string was: " << data << std::endl;
    return hash;
}

#if defined(IS_PART2)
constexpr int NUM_BOXES = 256;

    struct Lens
    {
        char lenseName[7];
        char focalStrength;
    };
    std::list<Lens> s_Boxes[NUM_BOXES];  // 256 boxes, each box contains a list of lenses

int CalculateBoxValue()
{
    int combinedValue = 0;
    // The value is calculated by:  (box number + 1) * (slot index + 1) * focal length in that slot
    int boxIndex = 0;
    for(const auto& box : s_Boxes)
    {
        boxIndex++;
        int slotIndex = 0;
        for(const auto& lens : box)
        {
            slotIndex++;
            const int value = boxIndex * slotIndex * lens.focalStrength;
            //std::cout << "Box: " << boxIndex << " Slot: " << slotIndex << " Lense: " << lens.lenseName << " FocalStrength: " << (int)lens.focalStrength << " Value: " << value << "\n";
            combinedValue += value;
        }
    }
    return combinedValue;
}
#endif

int main(int argc, char* argv[])
{
#ifndef IS_PART2
        long long sumHashes = 0;
        const char* data = s_Data;
        int numChars = strlen(s_Data);
        const char* end = s_Data + numChars;
        while (data < end)
        {
            const char* nextComma = strchr(data, ',');
            const int numChars = nextComma == nullptr ? strlen(data) : nextComma - data;
            sumHashes += GetHash(data, numChars);
            data += numChars + 1;
        }
        std::cout << "HashSum: " << sumHashes << std::endl;
#else
    //for part 2 we iterate through the data, for each entry (separated by commas) we calculate the hash for the lense and extract the operation and strength
    //there are two operations, add ('=' followed by focal strength) and remove ('-'), the input strings look like this: ql-,lrx=7

    const char* data = s_Data;
    const char* end = s_Data + strlen(s_Data);
    while (data < end)
    {
        const char* nextComma = strchr(data, ',');
        const int numChars = nextComma == nullptr ? strlen(data) : nextComma - data;

        if (data[numChars - 1] == '-') //remove lense
        {
            //remove lense
            const int boxHash = GetHash(data, numChars - 1);
            //find the lense in the box
            std::list<Lens>& box = s_Boxes[boxHash];
            for (auto itLense = box.begin(); itLense != box.end(); ++itLense)
            {
                //find the lense by name (data -1)
                if (itLense->lenseName[numChars - 1] == '\0' && strncmp(itLense->lenseName, data, numChars - 1) == 0)
                {
                    //remove the lense
                    box.erase(itLense);
                    break;
                }
            }
        }
        else //add lense
        {
            // the format is always: lenseName=focalStrength (e.g. ql=7) (focal strength is always a single digit 1-9)
            const int lenseNameLength = numChars - 2;
            const int focalStrength = *(data + lenseNameLength + 1) - '0'; //atoi(data + lenseNameLength + 1);
            const int boxHash = GetHash(data, lenseNameLength);
            //add the lense to the box:
            //1. check if the lense with that name is already in the box
            bool wasAlreadyInBox = false;
            std::list<Lens>& box = s_Boxes[boxHash];
            for (auto itLense = box.begin(); itLense != box.end(); ++itLense)
            {
                if (itLense->lenseName[lenseNameLength] == '\0' && strncmp(itLense->lenseName, data, lenseNameLength) == 0)
                {
                    //lense already in box, update the focal strength
                    itLense->focalStrength = focalStrength;
                    wasAlreadyInBox = true;
                    break;
                }
            }
            if(!wasAlreadyInBox)
            {
                assert(lenseNameLength < 7);
                Lens lense;
                strncpy_s(lense.lenseName, data, lenseNameLength);
                lense.focalStrength = focalStrength;
                s_Boxes[boxHash].push_back(lense);
            }
        }
        data += numChars + 1;
    }

    int sumBoxes = CalculateBoxValue();
    std::cout << "Sum of boxes: " << sumBoxes << std::endl;

#endif

    return 0;
}
