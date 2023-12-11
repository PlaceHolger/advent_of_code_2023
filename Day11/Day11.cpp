#include <iostream>
#include <vector>

#include "DataDay11.h"

struct Position
{
    long long x; //column
    long long y; //row

    bool operator!=(const Position& other) const
    {
        return x != other.x || y != other.y;
    }
};

std::vector<Position> s_Galaxies;
std::vector<int> s_EmptyRows; // we store the empty rows and columns so we can offset the galaxies, todo: would be better to store the offset for each row/column instead
std::vector<int> s_EmptyColumns;
std::vector<unsigned long long> s_DistancesBetweenGalaxies;

#define PART1 1
#if PART1
    constexpr int EMPTY_LINE_MULTIPLIER = 2; //one column/row turns into 2 columns/rows
#else
    constexpr int EMPTY_LINE_MULTIPLIER = 1000000;
#endif

void PrintMap()
{
    for (int y = 0; y < MAX_Y + (s_EmptyRows.size() * EMPTY_LINE_MULTIPLIER); ++y)
    {
        for (int x = 0; x < MAX_X + (s_EmptyColumns.size() * EMPTY_LINE_MULTIPLIER); ++x)
        {
            bool isGalaxy = false;
            for (const auto& galaxy : s_Galaxies)
            {
                if (galaxy.x == x && galaxy.y == y)
                {
                    isGalaxy = true;
                    break;
                }
            }
    
            if (isGalaxy)
                std::cout << '#';
            else
                std::cout << '.';
        }
        std::cout << std::endl;
    }
}

void FindEmptyRowsAndColumns()
{
    for (int y = 0; y < MAX_Y; ++y)
    {
        bool emptyRow = true;
        for (int x = 0; x < MAX_X; ++x)
        {
            if (s_Data[y][x] == '#')
            {
                emptyRow = false;
                break;
            }
        }

        if (emptyRow)
        {
            s_EmptyRows.push_back(y);
        }
    }

    for (int x = 0; x < MAX_X; ++x)
    {
        bool emptyColumn = true;
        for (int y = 0; y < MAX_Y; ++y)
        {
            if (s_Data[y][x] == '#')
            {
                emptyColumn = false;
                break;
            }
        }

        if (emptyColumn)
        {
            s_EmptyColumns.push_back(x);
        }
    }
}

void FindGalaxies()
{
    //find all galaxies
    for (int y = 0; y < MAX_Y; ++y)
    {
        for (int x = 0; x < MAX_X; ++x)
        {
            if (s_Data[y][x] == '#')
            {
                s_Galaxies.push_back({ x, y });
            }
        }
    }

    //offset the galaxies by the empty rows and columns
    for (auto& galaxy : s_Galaxies)
    {
        //count how many empty rows are above the galaxy
        int emptyRowsAbove = 0;
        for (const auto& emptyRow : s_EmptyRows)
        {
            if (emptyRow < galaxy.y)
                ++emptyRowsAbove;
        }
        //count how many empty columns are to the left of the galaxy
        int emptyColumnsLeft = 0;
        for (const auto& emptyColumn : s_EmptyColumns)
        {
            if (emptyColumn < galaxy.x)
                ++emptyColumnsLeft;
        }
        //offset the galaxy by the number of empty rows and columns
        galaxy.x += (emptyColumnsLeft * EMPTY_LINE_MULTIPLIER) - emptyColumnsLeft;
        galaxy.y += (emptyRowsAbove * EMPTY_LINE_MULTIPLIER) - emptyRowsAbove;
    }
}

int main(int argc, char* argv[])
{
    //find all empty rows and columns
    FindEmptyRowsAndColumns();

    FindGalaxies();

    // //PrintMap();
    
    //find the distances between all galaxies, so for 9 galaxies there are 36 distances
    const size_t numGalaxies = s_Galaxies.size();
    for (size_t i = 0; i < numGalaxies; ++i)
    {
        for (size_t j = i + 1; j < numGalaxies; ++j)
        {
            const long long distance = abs(s_Galaxies[i].x - s_Galaxies[j].x) + abs(s_Galaxies[i].y - s_Galaxies[j].y);
            s_DistancesBetweenGalaxies.push_back(distance);
        }
    }

    unsigned long long sumOfDistances = 0;
    for (const auto distance : s_DistancesBetweenGalaxies)
        sumOfDistances += distance;

    return 0;
}
