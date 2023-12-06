#include <iostream>

#include "DataDay5.h"

using namespace std;

unsigned int lowestLocaId = -1;

void DoMapping(unsigned int seedId, unsigned int range, const int mapIndex)
{
    if(mapIndex > NUM_MAPS - 1) //if we are at the last map, we are done mapping
    {
        if(seedId < lowestLocaId)  //lets check if this is the lowest loca id (only the first one will be the lowest)
            lowestLocaId = seedId;
        return;
    }
    
    const auto& currentMap = maps[mapIndex];
    for (auto rowIndex : currentMap)
    {
        const unsigned int rangeLength = rowIndex[RANGE_INDEX];
        const unsigned int destinationStart = rowIndex[DESTINATION_INDEX];
        const unsigned int sourceStart = rowIndex[SOURCE_INDEX];

        //check if the currentId is in the range of the current row
        if (seedId >= destinationStart && seedId < destinationStart + rangeLength)
        {
            //check if the whole range is in the current row
            if (seedId + range <= destinationStart + rangeLength)
            {
                //if so, then we map it to the destination start                    
                seedId += (sourceStart - destinationStart); //add the offset between the source and destination (and yes, the offset can be negative, and we are using unsigned ints)
                return DoMapping(seedId, range, mapIndex + 1);
            }
            else
            {
                //if not, then we map the first part of the range to the destination start
                const unsigned int mappedRange = destinationStart + rangeLength - seedId; //this range can be mapped with the current row
                const unsigned int mappedId = seedId + (sourceStart - destinationStart); //add the offset between the source and destination (and yes, the offset can be negative, and we are using unsigned ints)
                //and then we map the rest of the range to the next row
                DoMapping(mappedId, mappedRange, mapIndex + 1);
                //and for the rest of the range we call this function again, with the new seedId, and the rest of the range and the same mapIndex, because we did not map the whole range yet
                return DoMapping(seedId + mappedRange, range - mappedRange, mapIndex);
            }
        } //otherwise we do nothing, and the currentId stays the same              
    }
    //no mapping found, so the id stays the same
    DoMapping(seedId, range, mapIndex + 1);
}

int main(int argc, char* argv[])
{
    constexpr bool Part2 = true; //TODO: implement part 2 =(

    if (!Part2)
    {
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
    }
    else
    {
        //now we iterate over all seeds and ranges
        for (unsigned int i = 0; i < std::size(seeds); i+=2)
        {
            DoMapping(seeds[i], seeds[i+1], 0);
        }
    }

    cout << "Lowest Loca Id: " << lowestLocaId << endl;
    
    return 0;
}
