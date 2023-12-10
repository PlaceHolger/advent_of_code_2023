#include <iostream>
#include "DataDay10.h"

constexpr int MAX_Y = std::size(s_Data);
const int MAX_X = strlen(s_Data[0]);

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

Position FindNextFromStart(const Position& startPos)
{
    if(startPos.x < MAX_X - 1)  //right connection?
    {
        char right = s_Data[startPos.y][startPos.x + 1];
        if(right == '-' || right == 'J' || right == '7')
            return Position{startPos.x + 1, startPos.y};
    }
    if(startPos.y < MAX_Y - 1)  //down connection?
    {
        char down = s_Data[startPos.y + 1][startPos.x];
        if(down == '|' || down == 'L' || down == 'J')
            return Position{startPos.x, startPos.y + 1};
    }
    if(startPos.x > 0)  //left connection?
    {
        char left = s_Data[startPos.y][startPos.x - 1];
        if(left == '-' || left == 'F' || left == 'L')
            return Position{startPos.x - 1, startPos.y};
    }
    if(startPos.y > 0)  //up connection?
    {
        char up = s_Data[startPos.y - 1][startPos.x];
        if(up == '|' || up == '7' || up == 'F')
            return Position{startPos.x, startPos.y - 1};
    }
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

void PrintMap(Position currentPos, Position lastPos)
{
    for (int y = 0; y < MAX_Y; ++y)
    {
        for (int x = 0; x < MAX_X; ++x)
        {
            char tile = s_Data[y][x];

            ////some remapping for better readability
            // if(tile == 'L')
            //     tile = '└';
            // else if(tile == 'J')
            //     tile = '┘';
            // else if(tile == '7')
            //     tile = '┐';
            // else if(tile == 'F')
            //     tile = '┍';    
            
            if (x == currentPos.x && y == currentPos.y)
            {
                printf("\x1B[31m%c\033[0m", tile);
            }
            else if (x == lastPos.x && y == lastPos.y)
            {
                printf("\x1B[32m%c\033[0m", tile);
            }
            else
            {
                printf("%c", tile);
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    // Find the starting point (marked with 'S') by iterating over the rows and columns
    Position StartPos = FindStartPos();
    Position CurrentPos = FindNextFromStart(StartPos);
    Position LastPos = StartPos;

    //PrintMap(CurrentPos, LastPos);
    
    unsigned int NumSteps = 1;
    while (CurrentPos != StartPos)
    {
        Position MoveDir = {CurrentPos.x - LastPos.x, CurrentPos.y - LastPos.y};
        LastPos = CurrentPos;

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

    std::cout << "Number of steps: " << NumSteps << " furthest away therefore " << NumSteps / 2 << std::endl;
    
    return 0;
}
