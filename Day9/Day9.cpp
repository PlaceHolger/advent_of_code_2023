#include <iostream>

#include "DataDay9.h"

using namespace std;

int main(int argc, char* argv[])
{
    constexpr bool IS_PART1 = true;
    
    int64_t sumPredictions = 0;

    if(IS_PART1)
    {
        for (auto& currentRow : s_Data)
        {
            unsigned int numElements = NUM_NUMBERS; //we need one element less with each level of prediction

            bool allZero = false; //if all elements are zero, we can stop
            while (!allZero)
            {
                allZero = true;
                for (unsigned int j = 0; j < numElements - 1; ++j)
                {
                    const int difference = currentRow[j+1] - currentRow[j];
                    currentRow[j] = difference; //we don't need the original numbers anymore
                    allZero = (difference == 0) && allZero;
                    // cout << difference << " ";
                }
                numElements--;
               // cout << endl;
            }
            for (const int i : currentRow)
                sumPredictions += i;
        } 
    }
    else
    {
        for (auto& currentRow : s_Data)
        {
            int startElement = 1; //we need one element less with each level of prediction

            bool allZero = false; //if all elements are zero, we can stop
            while (!allZero)
            {
                allZero = true;
                for (int j = NUM_NUMBERS - 1; j >= startElement; --j)
                {
                    const int difference = currentRow[j] - currentRow[j - 1];
                    currentRow[j] = difference; //we don't need the original numbers anymore
                    allZero = (difference == 0) && allZero;
                    //cout << difference << " ";
                }
                startElement++;
                //cout << endl;
            }

            //iterate from the back to the front and subtract the previous element
            int lastValue = 0;
            for (int i = NUM_NUMBERS - 1; i >= 0; --i)
            {
                lastValue = currentRow[i] - lastValue;
            }
            sumPredictions += lastValue;
        } 
    }
    
    std::cout << "Sum of all predictions: " << sumPredictions << std::endl;
    
    return 0;
}
