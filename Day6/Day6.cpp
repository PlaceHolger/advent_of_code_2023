#include <iostream>

#include "DataDay6.h"

using namespace std;
int main(int argc, char* argv[])
{
    constexpr int numRaces = std::size(s_TimeData);

    unsigned long long totalNumberOfWaysToWin = 1;
    
    for (int i = 0; i < numRaces; ++i)
    {
        unsigned long long numberOfWaysToWin = 0;
        const auto AvailableTime = s_TimeData[i];
        const auto DistanceToBeat = s_DistanceData[i];

        //now we test all possible outcomes, j means how long we keep our accelaration button pressed before releasing it. The longer we press it, the faster we go, but the more time we waste. j is therefor directly our speed.
        for (unsigned long long j = 1; j < AvailableTime; ++j)
        {
            unsigned long long resultingDistance = j * (AvailableTime - j); 
            //cout << "Hold the button for " << j << " millisecond at the start of the race. Then, the boat will travel at a speed of " << j << " millimeter per millisecond for " << AvailableTime - j << " milliseconds, reaching a total distance traveled of " << resultingDistance << " millimeters." << endl;
            if(resultingDistance > DistanceToBeat)
                ++numberOfWaysToWin;
        }

        totalNumberOfWaysToWin *= numberOfWaysToWin;        
    }

    cout << "Total number of ways to win: " << totalNumberOfWaysToWin << endl;
    return 0;
}
