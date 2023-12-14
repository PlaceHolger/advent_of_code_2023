#include <cassert>
#include <iostream>
#include <map>

#include "DataDay14.h"

void PrintData(int highlightRow = -1)
{
    //print data
    for (int y = 0; y < NUM_ROWS; ++y)
    {
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            if(highlightRow == y)
                std::cout << "\033[1;31m" << s_Data[y][x] << "\033[0m";
            else
                std::cout << s_Data[y][x] ;
        }
        std::cout << "\n";
    }
    std::cout << "________________________" << std::endl;
}

void TiltNorth()
{
    //we will start at bottom row and move up
    //for every column, we will move up until we find a '#' or we reach the top
    //we will count all the 'O' we find along the way, replace them with '.' and when we then find a '#' we will place all the 'O' we found in the column
    //we will repeat this for every column

    for (int x = 0; x < NUM_COLUMNS; ++x)
    {
        int y = NUM_ROWS - 1;
        int oCount = 0;
        while (y >= 0)
        {
            if (s_Data[y][x] == '#')
            {
                for (int i = 0; i < oCount; ++i)
                    s_Data[y + i + 1][x] = 'O';
                oCount = 0;
            }
            else if (s_Data[y][x] == 'O')
            {
                s_Data[y][x] = '.';
                oCount++;
            }
            y--;
        }
        for (int i = 0; i < oCount; ++i)
            s_Data[y + i + 1][x] = 'O';
    }
}

void TiltSouth()
{
    //we will start at top row and move down
    //for every column, we will move down until we find a '#' or we reach the bottom
    //we will count all the 'O' we find along the way, replace them with '.' and when we then find a '#' we will place all the 'O' we found in the column
    //we will repeat this for every column

    for (int x = 0; x < NUM_COLUMNS; ++x)
    {
        int y = 0;
        int oCount = 0;
        while (y < NUM_ROWS)
        {
            if (s_Data[y][x] == '#')
            {
                for (int i = 0; i < oCount; ++i)
                    s_Data[y - i - 1][x] = 'O';
                oCount = 0;
            }
            else if (s_Data[y][x] == 'O')
            {
                s_Data[y][x] = '.';
                oCount++;
            }
            y++;
        }
        for (int i = 0; i < oCount; ++i)
            s_Data[y - i - 1][x] = 'O';
    }
}

void TiltWest()
{
    //we will start at right column and move left
    //for every row, we will move left until we find a '#' or we reach the left
    //we will count all the 'O' we find along the way, replace them with '.' and when we then find a '#' we will place all the 'O' we found in the row
    //we will repeat this for every row

    for (int y = 0; y < NUM_ROWS; ++y)
    {
        int x = NUM_COLUMNS - 1;
        int oCount = 0;
        while (x >= 0)
        {
            if (s_Data[y][x] == '#')
            {
                for (int i = 0; i < oCount; ++i)
                    s_Data[y][x + i + 1] = 'O';
                oCount = 0;
            }
            else if (s_Data[y][x] == 'O')
            {
                s_Data[y][x] = '.';
                oCount++;
            }
            x--;
        }
        for (int i = 0; i < oCount; ++i)
            s_Data[y][x + i + 1] = 'O';
    }
}

void TiltEast()
{
    //we will start at left column and move right
    //for every row, we will move right until we find a '#' or we reach the right
    //we will count all the 'O' we find along the way, replace them with '.' and when we then find a '#' we will place all the 'O' we found in the row
    //we will repeat this for every row

    for (int y = 0; y < NUM_ROWS; ++y)
    {
        int x = 0;
        int oCount = 0;
        while (x < NUM_COLUMNS)
        {
            if (s_Data[y][x] == '#')
            {
                for (int i = 0; i < oCount; ++i)
                    s_Data[y][x - i - 1] = 'O';
                oCount = 0;
            }
            else if (s_Data[y][x] == 'O')
            {
                s_Data[y][x] = '.';
                oCount++;
            }
            x++;
        }
        for (int i = 0; i < oCount; ++i)
            s_Data[y][x - i - 1] = 'O';
    }
}

int CalculateWeigth()
{
    //calculate weight
    int weight = 0;
    for (int y = 0; y < NUM_ROWS; ++y)
    {
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            if (s_Data[y][x] == 'O')
            {
                weight += NUM_COLUMNS - y;
            }
        }
    }
    return weight;
}

//std::map<int, const char*> s_DataHashes;
std::map<int, int> s_StartEndMap; //here we map map-hashes to map-hashes after the tilting cycle
std::map<int, int> s_WeightMap; //here we map map-hashes to corresponding weights

int CreateMapHash()
{
    //the '#' wont move around, so these are not important for the hash
    //the 'O' will move around, so we will use the position of the 'O' to create the hash
    int hash = 0;
    for (int y = 0; y < NUM_ROWS; ++y)
        for (int x = 0; x < NUM_COLUMNS; ++x)
            if (s_Data[y][x] == 'O')
                hash += y * NUM_COLUMNS + x;
    return hash;
}

int DoTiltCycle(bool storeHash)
{
    int startHash = CreateMapHash();
    
    TiltNorth();
    TiltWest();
    TiltSouth();
    TiltEast();

    int endHash = CreateMapHash();
    if(storeHash)
    {
        s_StartEndMap[startHash] = endHash;
        s_WeightMap[endHash] = CalculateWeigth();    
    }
    return endHash;
}

int DoTiltCycleViaHash(int hash)
{
    //Sanity check if the hash is in our map
    //assert(s_StartEndMap.find(hash) != s_StartEndMap.end());
    
    //we will use the hash to find the end-hash
    return s_StartEndMap[hash];
}

int main(int argc, char* argv[])
{
    constexpr int NUM_ITERATIONS = 1000000000;
    constexpr bool IS_PART1 = false;

    if(IS_PART1)
    {
        TiltNorth();
        PrintData();
        std::cout << CalculateWeigth() << std::endl;
    }
    else
    {
        //comment: okay, this is still bruteforce... but it finishes in a few seconds (in a release build) , so I am fine with it (it`s late...). But I am quite certain there is a cycle in the tilting-results, so we can probably skip a lot of iterations, by incrementing 'i' by 'cycle-length*1000000' or something like that 
        int currentMapHash;
        for (int i = 0; i < NUM_ITERATIONS; ++i)
        {
            if(i < 1000)  //we will do 1000 iterations to fill our map
                currentMapHash = DoTiltCycle(i > 100);
            else  //after that we will start using our hashes
            {
                currentMapHash = DoTiltCycleViaHash(currentMapHash);
            }
        }
        PrintData();
        std::cout << s_WeightMap[currentMapHash] << std::endl;
    }

    return 0;
}
