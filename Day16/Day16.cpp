#include <iostream>

#include "DataDay16.h"

enum Direction : int //we will use bitflags to store the directions in the laser field
{
    Up = 1 << 0,
    Right = 1 << 1,
    Down = 1 << 2,
    Left = 1 << 3
};

int s_LaserField[NUM_ROWS][NUM_COLUMNS+1] = {{0}}; // we can pass each field in 4 directions, so we use the bitmask here

Direction CalcNewDir(Direction currentDir, char field)
{
    switch (field)
    {
        case '/':
            switch (currentDir)
            {
                case Direction::Up:
                    return Direction::Right;
                case Direction::Right:
                    return Direction::Up;
                case Direction::Down:
                    return Direction::Left;
                case Direction::Left:
                    return Direction::Down;
            }
        case '\\':
            switch (currentDir)
            {
                case Direction::Up:
                    return Direction::Left;
                case Direction::Right:
                    return Direction::Down;
                case Direction::Down:
                    return Direction::Right;
                case Direction::Left:
                    return Direction::Up;
            }
    }
    return currentDir;
}

struct Position
{
    int x;
    int y;
};

struct LaserInfo
{
    Position position;
    Direction direction;
};

char GetLaserField(int x, int y)
{
    const int storedDir = s_LaserField[y][x];
    switch (storedDir)
    {
        case 0:
            return '\0';
        case Up:
            return '^';
        case Right:
            return '>';
        case Left:
            return '<';
        case Down:
            return 'v';
        default:
            return 'X';
    }
}

bool DoesLaserFieldContainDirection(int x, int y, Direction direction)
{
    return (s_LaserField[y][x] & direction) > 0;
}

void PrintMap()
{
    static int step = 0;
    for (int y = 0; y < NUM_ROWS; ++y)
    {
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            if(GetLaserField(x,y) == '\0')
                std::cout << "\033[0m" << s_FieldData[y][x];
            else
                if(s_FieldData[y][x] != '.') // there is a mirror on this field
                    std::cout << "\033[1;32m" << s_FieldData[y][x];
                else
                    std::cout << "\033[1;31m" << GetLaserField(x,y);
        }
        std::cout << "\n";
    }
    std::cout << "Step " << ++step << " ________________________\033[0m" << std::endl;
}

void WriteLaserToLaserField(LaserInfo laserInfo)
{
    s_LaserField[laserInfo.position.y][laserInfo.position.x] |= (int)laserInfo.direction;
    //PrintMap();  //just for debugging
}

void DoLaserStep(LaserInfo laserInfo)
{
    if(DoesLaserFieldContainDirection(laserInfo.position.x, laserInfo.position.y, laserInfo.direction))
        return; //if we already have a laser in this field going in this direction, we stop here
    
    WriteLaserToLaserField(laserInfo);

    //depending on the direction and our position (borders), we will move the laser one step
    Position& newPosition = laserInfo.position;
    switch (laserInfo.direction)
    {
        case Direction::Up:
            if(newPosition.y > 0)
                newPosition.y--;
            else
                return; //we are at the top border, this laser is done
            break;
        case Direction::Down:
            if(newPosition.y < NUM_ROWS - 1)
                newPosition.y++;
            else
                return; //we are at the bottom border, this laser is done
            break;
        case Direction::Left:
            if(newPosition.x > 0)
                newPosition.x--;
            else
                return; //we are at the left border, this laser is done
            break;
        case Direction::Right:
            if(newPosition.x < NUM_COLUMNS - 1)
                newPosition.x++;
            else
                return; //we are at the right border, this laser is done
            break;
    }
    const char currentField = s_FieldData[newPosition.y][newPosition.x];
    switch (currentField)
    {
        case '.':
            break;
        case '/':
        case '\\':
            laserInfo.direction = CalcNewDir(laserInfo.direction, currentField);
            break;
        case '|':
            if(laserInfo.direction == Direction::Left || laserInfo.direction == Direction::Right)
            {
                //we have to split our laser into two and continue with both and end this one
                LaserInfo newLaserInfo = laserInfo;
                newLaserInfo.direction = Direction::Up;
                DoLaserStep(newLaserInfo);
                newLaserInfo.direction = Direction::Down;
                DoLaserStep(newLaserInfo);
                return;
            }
            break;
        case '-':
            if(laserInfo.direction == Direction::Up || laserInfo.direction == Direction::Down)
            {
                //we have to split our laser into two and continue with both and end this one
                LaserInfo newLaserInfo = laserInfo;
                newLaserInfo.direction = Direction::Left;
                DoLaserStep(newLaserInfo);
                newLaserInfo.direction = Direction::Right;
                DoLaserStep(newLaserInfo);
                return;
            }
            break;
        default:
            std::cerr << "ERROR: Unknown field type: " << currentField << std::endl;
    }
    laserInfo.position = newPosition;
    DoLaserStep(laserInfo);
}

int CountEnergizedFields()
{
    int count = 0;
    for (auto& y : s_LaserField)
        for (int x = 0; x < NUM_COLUMNS; ++x)
            if(y[x] != 0)
                count++;
    return count;
}

constexpr int Part = 2;

int main(int argc, char* argv[])
{
    std::cout << "Day 16: The Floor Will Be Lava \n";
    int highestCount = 0;

    if(Part == 1)
    {
        LaserInfo laserInfo = {{0, 0}, CalcNewDir(Direction::Right, s_FieldData[0][0])};
        DoLaserStep(laserInfo);
        PrintMap();
        highestCount = CountEnergizedFields();
    }
    else
    {
        LaserInfo startPos;
        //for part 2 we will bruteforce the laser starting position (all tiles in the first row starting downwards, then all all left tiles, then all right tiles, then bottom line)
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            startPos = {{x, 0}, CalcNewDir(Direction::Down, s_FieldData[0][x])};
            DoLaserStep(startPos);
            const int count = CountEnergizedFields();
            if(count > highestCount)
                highestCount = count;
            memset(s_LaserField, 0, sizeof(s_LaserField)); //Reset laser field
        }
        for (int y = 0; y < NUM_ROWS; ++y)
        {
            startPos = {{0, y}, CalcNewDir(Direction::Right, s_FieldData[y][0])};
            DoLaserStep(startPos);
            const int count = CountEnergizedFields();
            if(count > highestCount)
                highestCount = count;
            memset(s_LaserField, 0, sizeof(s_LaserField)); //Reset laser field
        }
        for (int y = 0; y < NUM_ROWS; ++y)
        {
            startPos = {{NUM_COLUMNS-1, y}, CalcNewDir(Direction::Left, s_FieldData[y][NUM_COLUMNS-1])};
            DoLaserStep(startPos);
            const int count = CountEnergizedFields();
            if(count > highestCount)
                highestCount = count;
            memset(s_LaserField, 0, sizeof(s_LaserField)); //Reset laser field
        }
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            startPos = {{x, NUM_ROWS-1}, CalcNewDir(Direction::Up, s_FieldData[NUM_ROWS-1][x])};
            DoLaserStep(startPos);
            const int count = CountEnergizedFields();
            if(count > highestCount)
                highestCount = count;
            memset(s_LaserField, 0, sizeof(s_LaserField)); //Reset laser field
        }
    }

    std::cout << "Energized tiles: " << highestCount << std::endl;
    return 0;
}
