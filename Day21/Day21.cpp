#include <iostream>
#include <unordered_set>

#include "DataDay21.h"

struct Position
{
    int x;
    int y;

    bool operator==(const Position& other) const
    {
        return x == other.x && y == other.y;
    }
};

struct Hash {
    size_t operator()(const Position &pos) const
    {
        return pos.x + pos.y * NUM_COLUMNS;
    }
};

std::unordered_set<Position, Hash> s_ReachablePositions;
std::unordered_set<Position, Hash> s_ReachablePositions2;

std::unordered_set<Position, Hash>& currentPositions = s_ReachablePositions;
std::unordered_set<Position, Hash>& lastStepPositions = s_ReachablePositions2;

Position FindStartPosition()
{
    for(int y = 0; y < NUM_ROWS; ++y)
    {
        for(int x = 0; x < NUM_COLUMNS; ++x)
        {
            if(s_Data[y][x] == 'S')
            {
                return {x, y};
            }
        }
    }
    return { -1, -1 };
}

void FindReachablePositions()
{
    currentPositions.swap(lastStepPositions);

    currentPositions.clear();
    for (const Position& lastStepPosition : lastStepPositions)
    {
        if (lastStepPosition.x > 0 && s_Data[lastStepPosition.y][lastStepPosition.x - 1] != '#')
        {
            currentPositions.insert({ lastStepPosition.x - 1, lastStepPosition.y });
        }
        if (lastStepPosition.x < NUM_COLUMNS - 1 && s_Data[lastStepPosition.y][lastStepPosition.x + 1] != '#')
        {
            currentPositions.insert({ lastStepPosition.x + 1, lastStepPosition.y });
        }
        if (lastStepPosition.y > 0 && s_Data[lastStepPosition.y - 1][lastStepPosition.x] != '#')
        {
            currentPositions.insert({ lastStepPosition.x, lastStepPosition.y - 1 });
        }
        if (lastStepPosition.y < NUM_ROWS - 1 && s_Data[lastStepPosition.y + 1][lastStepPosition.x] != '#')
        {
            currentPositions.insert({ lastStepPosition.x, lastStepPosition.y + 1 });
        }
    }
}

void PrintMap(int step)
{
    //print s_Data
    for (int y = 0; y < NUM_ROWS; ++y)
    {
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            const bool isCurrentPosition = std::find(currentPositions.begin(), currentPositions.end(), Position{ x, y }) != currentPositions.end();
            const bool isLastPosition = std::find(lastStepPositions.begin(), lastStepPositions.end(), Position{ x, y }) != lastStepPositions.end();
            if (isCurrentPosition)
                std::cout << "\033[1;31m" << '0' << "\033[0m";
            else if (isLastPosition)
                std::cout << "\033[1;33m" << s_Data[y][x] << "\033[0m";
            else
                std::cout << "\033[1;32m" << s_Data[y][x] << "\033[0m";
        }
        std::cout << "\n";
    }
    std::cout << "Step " << step << ": NumPositions: " << currentPositions.size() << std::endl;
}

int main(int argc, char* argv[])
{
    const Position startPosition = FindStartPosition();
    currentPositions.insert(startPosition);

    constexpr int NUM_STEPS = 64;
    for (int step = 0; step < NUM_STEPS; ++step)
    {
        FindReachablePositions();
        PrintMap(step);
    }

    std::cout << "After " << NUM_STEPS+1 << "steps: NumPositions: " << currentPositions.size() << std::endl;
    
    return 0;
}
