#include <iostream>

#include "DataDay5.h"

using namespace std;

int main(int argc, char* argv[])
{
    constexpr bool Part2 = false; //TODO: implement part 2 =(
    
    unsigned int lowestLocaId = -1;

    //now we iterate over all seeds and maps, and print out the values
    for (const auto& seed : seeds)
    {
        unsigned int currentId = seed;  //we start with the seedId, this will then be mapped to soil, then to fertilizer, then to water, etc..
        for (const auto& map : maps)
        {
            //const unsigned int unmappedId = currentId;
            for (auto rowIndex : map)
            {                
                const unsigned int rangeLength = rowIndex[RANGE_INDEX];
                const unsigned int destinationStart = rowIndex[DESTINATION_INDEX];
                const unsigned int sourceStart = rowIndex[SOURCE_INDEX];                
                
                //check if the currentId is in the range of the current row
                if (currentId >= destinationStart && currentId < destinationStart + rangeLength)
                {
                    //if so, then we map it to the destination start                    
                    currentId += (sourceStart - destinationStart); //add the offset between the source and destination (and yes, the offset can be negative, and we are using unsigned ints)
                    break;
                } //otherwise we do nothing, and the currentId stays the same              
            }
            //cout << "Value: " << unmappedId << " was mapped to: " << currentId << endl;
        }
        //cout << "SeedId" << seed << " map to Loca Id: " << currentId << endl;
        if(currentId < lowestLocaId)
            lowestLocaId = currentId;
    }

    cout << "Lowest Loca Id: " << lowestLocaId << endl;
    
    return 0;
}
