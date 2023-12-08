#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <numeric>

#include "DataDay8.h"

#define PART2

using namespace std;

constexpr int NUM_ROWS = size(s_Data);
constexpr int NUM_DIRECTIONS = size(s_Path) - 1;

map<int, pair<int,int>> paths;

#ifdef PART2
vector<int> startPositions;
vector<int> endPositions;
bool IsEndPos(int pos)
{
    return find(endPositions.begin(), endPositions.end(), pos) != endPositions.end();
}
map<unsigned int, unsigned int> stepsToTarget;  //index of ghost, and his steps to target
#endif
map<int, const char*> debug_lookup;


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
        debug_lookup[GetHash(s_Data[i][0])] = s_Data[i][0];
        int hashPos = GetHash(s_Data[i][0]);
        int hashLeft = GetHash(s_Data[i][1]);
        int hashRight = GetHash(s_Data[i][2]);
        paths[hashPos] = make_pair(hashLeft, hashRight);

#ifdef PART2
        if(s_Data[i][0][2] == 'A')
            startPositions.push_back(hashPos);
        else if(s_Data[i][0][2] == 'Z')
            endPositions.push_back(hashPos);
#endif
    }

    unsigned int numSteps = 0;
    
#ifndef PART2
    {
        const int targetHash = GetHash("ZZZ");
        int currentPos = GetHash("AAA");
        while (currentPos != targetHash)
        {
            //int oldPos = currentPos;
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
    }
#else
    {
        //iterate over all start positions, follow the path and check if we end up at any end position
        for (size_t i = 0; i < startPositions.size(); ++i)
        {
            numSteps = 0;
            int currentPos = startPositions[i];
            while (!IsEndPos(currentPos))
            {
                char nextDir = GetNextDir();
                if (nextDir == 'L')
                {
                    currentPos = paths[currentPos].first;
                }
                else if (nextDir == 'R')
                {
                    currentPos = paths[currentPos].second;
                }
                numSteps++;
            }
            cout << "Reached end position in " << numSteps << " steps " << "startPos was " << debug_lookup[startPositions[i]] << " goal was " << debug_lookup[currentPos] << endl;
            stepsToTarget[i] = numSteps;
        }
    }
#endif

    cout << "okay, now google the answer, it is the LCM (least common multiple) of these numbers:" << endl;
    for (auto& it : stepsToTarget)
    {
        cout << it.second << ", ";
    }
    cout << endl;
    
    return 0;
}
