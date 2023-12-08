#include <iostream>
#include <map>

#include "DataDay8.h"

using namespace std;

constexpr int NUM_ROWS = size(s_Data);
constexpr int NUM_DIRECTIONS = size(s_Path) - 1;

map<int, pair<int,int>> paths;
//map<int, const char*> debug_lookup;

int GetHash(const char* path)
{
    int hashPos = (path[0] << 16) + (path[1] << 8) + path[2];
    return hashPos;
}

static unsigned int currentDir = 0;

char GetNextDir()
{
    return s_Path[currentDir++ % NUM_DIRECTIONS];
}

int main(int argc, char* argv[])
{
    //create a map with data
    for (int i = 0; i < NUM_ROWS; ++i)
    {
        //debug_lookup[GetHash(s_Data[i][0])] = s_Data[i][0];
        int hashPos = GetHash(s_Data[i][0]);
        int hashLeft = GetHash(s_Data[i][1]);
        int hashRight = GetHash(s_Data[i][2]);
        paths[hashPos] = make_pair(hashLeft, hashRight);        
    }

    unsigned int numSteps = 0;
    const int targetHash = GetHash("ZZZ");
    int currentPos = GetHash("AAA");
    while (currentPos != targetHash)
    {
        int oldPos = currentPos;
        char nextDir = GetNextDir();
        if (nextDir == 'L')
        {
            currentPos = paths[currentPos].first;
        }
        else if (nextDir == 'R')
        {
            currentPos = paths[currentPos].second;
        }
        //cout << "From: " << debug_lookup[oldPos] << " to: " << debug_lookup[currentPos] << endl;
        numSteps++;
    }

    cout << numSteps;
    return 0;
}
