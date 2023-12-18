#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <iostream>

#include "DataDay18.h"

#define PART 2

struct Point
{
    int64_t x;
    int64_t y;
};

struct DigInstructions
{
    char direction;
    int64_t distance;
    //uint8_t color[3]; //RGB
};
DigInstructions s_DigInstructions[NUM_ROWS];

void PrintMap(const Point* p_DigLinePoints)
{
    //now we want to print the field by showing # for the digged area and . for the undigged area
    //this is just debugging code, so we can ignore the performance
    for (int y = -350; y < NUM_ROWS + 30; ++y)
    {
        for (int x = -10; x < NUM_COLUMNS + 450; ++x)
        {
            bool isDigged = false;
            for (int i = 0; i < NUM_ROWS; ++i)
            {
                const Point& p1 = p_DigLinePoints[i];
                const Point& p2 = p_DigLinePoints[i+1];
                if (p1.y == p2.y)
                {
                    if (p1.y == y && p1.x <= x && x <= p2.x || p1.y == y && p2.x <= x && x <= p1.x)
                    {
                        isDigged = true;
                        break;
                    }
                }
                else
                {
                    if (p1.x == x && p1.y <= y && y <= p2.y || p1.x == x && p2.y <= y && y <= p1.y)
                    {
                        isDigged = true;
                        break;
                    }
                }
            }
            std::cout << (isDigged ? "#" : ".");
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[])
{
    std::cout << "-- Day 18: Lavaduct Lagoon -- \n";

    //first we need to parse the data
    //we iterate through the data and scanf the data into a struct "R 6 (#70c710)"
    for (int y = 0; y < NUM_ROWS; ++y)
    {
        DigInstructions& info = s_DigInstructions[y];
        //int numParsed = sscanf(s_Data[y], "%c %d (#%02x%02x%02x))", &info.direction, &info.distance, info.color, info.color+1, info.color+2);
#if PART != 2
        int numParsed = sscanf(s_Data[y], "%c %d ", &info.direction, &info.distance);
#else "R 6 (#70c710)"
        char unused; int unused2;
        int numParsed = sscanf(s_Data[y], "%c %d (#%05x%01x)", &unused, &unused2, &info.distance, &info.direction);
        assert(numParsed == 4);
#endif
    }

    //okay now we have the data, we need to dig the field
    //first we add all lines that we need to dig into an array
    Point DigLinePoints[NUM_ROWS+1];
    DigLinePoints[0] = { 0, 0 };
    Point LastPos = DigLinePoints[0];
    int boundaryPoints = 0;
    for (int y = 0; y < NUM_ROWS; ++y)
    {
        const DigInstructions& info = s_DigInstructions[y];
        Point direction;
#if PART != 2
        switch (info.direction)
        {
            case 'U': direction = { 0, -1 }; break;
            case 'D': direction = { 0, 1 }; break;
            case 'R': direction = { 1, 0 }; break;
            case 'L': direction = { -1, 0 }; break;
        }
#else//  //0 means R, 1 means D, 2 means L, and 3 means U
        switch (info.direction)
        {
            case 0: direction = { 1, 0 }; break;
            case 1: direction = { 0, 1 }; break;
            case 2: direction = { -1, 0 }; break;
            case 3: direction = { 0, -1 }; break;
        }
#endif
        LastPos.x += direction.x * info.distance;
        LastPos.y += direction.y * info.distance;
        boundaryPoints += info.distance;
        DigLinePoints[y+1] = LastPos;
    }

    //okay, now we calculate the area of the field by using the shoelace formula
    //https://en.wikipedia.org/wiki/Shoelace_formula
    
    int64_t area = 0;
    for (int i = 0; i < NUM_ROWS; ++i)
    {
        const Point& p1 = DigLinePoints[i];
        const Point& p2 = DigLinePoints[i+1];
        area += p1.x * p2.y - p2.x * p1.y;
    }
    area = abs(area) / 2;

    // Pick's theorem states that A = i + b/2 - 1
    // where A is the area of the polygon, i is the number of interior points and b is the number of boundary points
    // so we can calculate the number of interior points by i = A - b/2 + 1 because we know A and b
    const uint64_t innerPoints = area - boundaryPoints / 2 + 1;
    
    std::cout << "Area: " << boundaryPoints + innerPoints << std::endl;
    //PrintMap(DigLinePoints);

    return 0;
}
