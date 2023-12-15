#include <iostream>
#include <assert.h>

#include "DataDay15.h"

int GetHash(const char* data, int numChars = -1)
{
    // Determine the ASCII code for the current character of the string.
    // Increase the current value by the ASCII code you just determined.
    // Set the current value to itself multiplied by 17.
    // Set the current value to the remainder of dividing itself by 256.
    // Repeat steps 1-4 for the entire string.

    int hash = 0;
    const int numCharsToProcess = numChars == -1 ? strlen(data) : numChars;
    for (int i = 0; i < numCharsToProcess; ++i)
    {
        hash += data[i];
        hash *= 17;
        hash %= 256;
    }

    //std::cout << "Hash: " << hash << " string was: " << data << std::endl;
    return hash;
}


int main(int argc, char* argv[])
{
    const int hashTest = GetHash("HASH");
    assert(hashTest == 52);

//Part1
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
    std::cout << "Hash: " << sumHashes << std::endl;
    
    return 0;
}
