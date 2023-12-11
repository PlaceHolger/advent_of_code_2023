#include <iostream>
#include "DataDay10.h"

constexpr int MAX_Y = std::size(s_Data);
const int MAX_X = strlen(s_Data[0]);

//#define PART2 1

char* p_MapCopy = nullptr;

struct Position
{
    int x; //column
    int y; //row

    bool operator!=(const Position& other) const
    {
        return x != other.x || y != other.y;
    }
};

char GetTile(const Position& pos)
{
    return s_Data[pos.y][pos.x];
}

bool HasRightConnection(const Position& pos)
{
    if(pos.x >= MAX_X - 1)
        return false;
    const char rightTile = s_Data[pos.y][pos.x + 1];
    return (rightTile == '-' || rightTile == 'J' || rightTile == '7');
}

bool HasLeftConnection(const Position& pos)
{
    if(pos.x <= 0)
        return false;
    const char left = s_Data[pos.y][pos.x - 1];
    return (left == '-' || left == 'F' || left == 'L');
}

bool HasUpConnection(const Position& pos)
{
    if(pos.y <= 0)
        return false;
    const char up = s_Data[pos.y - 1][pos.x];
    return (up == '|' || up == '7' || up == 'F');
}

bool HasDownConnection(const Position& pos)
{
    if(pos.y >= MAX_X - 1)
        return false;
    const char down = s_Data[pos.y + 1][pos.x];
    return (down == '|' || down == 'L' || down == 'J');
}


Position FindNextFromStart(const Position& startPos)
{
    if(HasRightConnection(startPos))
        return Position{startPos.x + 1, startPos.y};
    if(HasLeftConnection(startPos))
        return Position{startPos.x - 1, startPos.y};
    if(HasUpConnection(startPos))
        return Position{startPos.x, startPos.y - 1};
    if(HasDownConnection(startPos))
        return Position{startPos.x, startPos.y + 1};
}

char FindStartTileReplacement(const Position& startPos)
{
    //we know that start has two connection, so we can find out which tile is the right to connect these two
    if(HasRightConnection(startPos) && HasLeftConnection(startPos))
        return '-';
    if(HasUpConnection(startPos) && HasDownConnection(startPos))
        return '|';
    if(HasRightConnection(startPos) && HasUpConnection(startPos))
        return 'L';
    if(HasRightConnection(startPos) && HasDownConnection(startPos))
        return 'F';
    if(HasLeftConnection(startPos) && HasUpConnection(startPos))
        return 'J';
    if(HasLeftConnection(startPos) && HasDownConnection(startPos))
        return '7';
}

Position FindStartPos()
{
    for (int y = 0; y < MAX_Y; ++y)
    {
        for (int x = 0; x < MAX_X; ++x)
        {
            if (s_Data[y][x] == 'S')
            {
                return Position{x, y};
            }
        }
    }
}

void PrintMap(const Position& startPos)
{
    std::locale::global(std::locale(""));

    for (int y = 0; y < MAX_Y; ++y)
    {
        for (int x = 0; x < MAX_X; ++x)
        {            
            const char orgTile = (p_MapCopy == nullptr) ? s_Data[y][x] : p_MapCopy[y * MAX_X + x];

            //convert to wchar_t
            wchar_t tile = orgTile;

            //some remapping for better readability
            if(orgTile == 'L')
                tile = L'└';
            else if(orgTile == 'J')
                tile = L'┘';
            else if(orgTile == '7')
                tile = L'┐';
            else if(orgTile == 'F')
                tile = L'┌';
            else if(orgTile == '-')
                tile = L'─';
            else if(orgTile == '|')
                tile = L'│';
            
            if (x == startPos.x && y == startPos.y)
            {
                printf("\x1B[31mS");
            }
            else
            {
                if(tile == '0')
                    printf("\x1B[32m%C", tile);
                else if(tile == '1')
                    printf("\x1B[33m%C", tile);
                else
                    printf("\033[0m%C", tile);
            }
        }
        printf("\033[0m\n");
    }
    std::cout << std::endl;
}

void main(int argc, char* argv[])
{
    // Find the starting point (marked with 'S') by iterating over the rows and columns
    Position StartPos = FindStartPos();
    Position CurrentPos = FindNextFromStart(StartPos);
    Position LastPos = StartPos;

    //PrintMap(CurrentPos, LastPos);

#if PART2
    const int arraySize = MAX_Y * MAX_X * sizeof(char);
    p_MapCopy = (char*)malloc(arraySize);    
    // fill with zeros
    memset(p_MapCopy, '.', arraySize);
    p_MapCopy[StartPos.y * MAX_X + StartPos.x] = FindStartTileReplacement(StartPos);  //GetTile(StartPos);
#endif
    
    unsigned int NumSteps = 1;
    while (CurrentPos != StartPos)
    {
        Position MoveDir = {CurrentPos.x - LastPos.x, CurrentPos.y - LastPos.y};
        LastPos = CurrentPos;
#if PART2
        p_MapCopy[CurrentPos.y * MAX_X + CurrentPos.x] = GetTile(CurrentPos); 
#endif

        // find the next position, depending on the tile of the current part
        switch (GetTile(CurrentPos))
        {
            case '|':
                CurrentPos.y += MoveDir.y;
                break;
            case '-':
                CurrentPos.x += MoveDir.x;
                break;
            case 'L':
                if(MoveDir.y == 0) // we came from the right
                    CurrentPos.y -= 1;
                else             // we came from the top
                    CurrentPos.x += 1;
                break;
            case 'J':
                if(MoveDir.y == 0) // we came from the left
                    CurrentPos.y -= 1;
                else             // we came from the top
                    CurrentPos.x -= 1;
                break;
            case '7':
                if(MoveDir.y == 0) // we came from the left
                    CurrentPos.y += 1;
                else             // we came from the bottom
                    CurrentPos.x -= 1;
                break;
            case 'F':
                if(MoveDir.y == 0) // we came from the right
                    CurrentPos.y += 1;
                else             // we came from the bottom
                    CurrentPos.x += 1;
                break;
            default:
                // we should never reach this point...
                break;
        }
        NumSteps++;
    }

#if PART2
    // we use Point in polygon - ray casting algorithm to find out which points are inside the loop
    // https://en.wikipedia.org/wiki/Point_in_polygon#Ray_casting_algorithm
    // for each row, we cast a ray from the left to the right and count the intersections with the loop

    int numInsides = 0;
    for (int y = 0; y < MAX_Y; ++y)
    {
        bool isInside = false;
        
        for (int x = 0; x < MAX_X; ++x)
        {
            char& tile = p_MapCopy[y * MAX_X + x];
            if(tile == '|' || tile == '7' || tile == 'F')
            {
                isInside = !isInside;
            }
            if(tile == '.')
            {                
                if(isInside)
                {
                    ++numInsides;
                    tile = '1';
                }
                else
                    tile = '0';
            }
        }
    }

    PrintMap(StartPos);
    free(p_MapCopy);

    std::cout << "Number of points inside the loop: " << numInsides << std::endl;
#else
    std::cout << "Number of steps: " << NumSteps << " furthest away therefore " << NumSteps / 2 << std::endl;
#endif
}
