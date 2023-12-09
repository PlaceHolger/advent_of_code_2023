#include <assert.h>
#include <iostream>

#include "DataDay9.h"

using namespace std;

int main(int argc, char* argv[])
{
    long long sumPredictions = 0;
    
    for (auto& currentRow : s_Data)
    {
        unsigned int numElements = NUM_NUMBERS; //we need one element less with each level of prediction

        int currentPredictionSum = 666;
        while (currentPredictionSum != 0)
        {
            currentPredictionSum = 0;
            for (unsigned int j = 0; j < numElements - 1; ++j)
            {
                const int difference = currentRow[j+1] - currentRow[j];
                currentRow[j] = difference; //we don't need the original numbers anymore
                currentPredictionSum += difference;
            }
            numElements--;
        }
        //now we have the predictions for the current line, our data already only contains the last element of each prediction-level, so we just need to add them up
        for (const int i : currentRow)
            sumPredictions += i;
    }
    
    std::cout << "Sum of all predictions: " << sumPredictions << std::endl;
    
    return 0;
}
