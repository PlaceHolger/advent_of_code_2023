#include <assert.h>
#include <iostream>
#include "DataDay13.h"

int NUM_COLUMNS = 0;
int NUM_ROWS = 0;

int GetVerticalMirrorAxis(int pattern)
{
    bool IsNotMirrorAxis[32] = {false};

    //const auto& currentData = s_Data[pattern];

    for (int rowIndex = pattern; rowIndex < pattern + NUM_ROWS; ++rowIndex)
    {
        const auto& row = s_Data[rowIndex];
        for (int i = 0; i < NUM_COLUMNS - 1; ++i)
        {
            if(IsNotMirrorAxis[i])
                continue; //already known that this is not a mirror axis
            
            for (int offset = 0; offset < NUM_COLUMNS; ++offset)  //check in both direction is mirrored
            {
                const int leftIndex = i - offset;
                const int rightIndex = i + offset + 1;
                if(leftIndex < 0 || rightIndex >= NUM_COLUMNS)
                    break;                
                if(row[leftIndex] != row[rightIndex]) //different, so not mirrored
                {
                    IsNotMirrorAxis[i] = true;
                    break;                    
                }
            }
        }
    }

    for (int i = 0; i < NUM_COLUMNS - 1; ++i)
    {
        if(!IsNotMirrorAxis[i])
            return i + 1;
    }
    return 0;
}

int GetHorizontalMirrorAxis(int pattern)
{
    bool IsNotMirrorAxis[32] = {false};
    //const auto& currentData = s_Data[pattern];

    for (int i = 0; i < NUM_COLUMNS; ++i)
    {
        for (int j = 0; j < NUM_ROWS; ++j)
        {
            if(IsNotMirrorAxis[j])
                continue; //already known that this is not a mirror axis
            
            for (int offset = 0; offset < NUM_ROWS; ++offset)  //check in both direction is mirrored
            {
                const int topIndex = j - offset;
                const int bottomOffset = j + offset + 1;
                if(topIndex < 0 || bottomOffset >= NUM_ROWS)
                    break;                
                if(s_Data[pattern + topIndex][i] != s_Data[pattern + bottomOffset][i]) //different, so not mirrored
                {
                    IsNotMirrorAxis[j] = true;
                    break;                    
                }
            }
        }
    }

    for (int i = 0; i < NUM_ROWS - 1; ++i)
    {
        if(!IsNotMirrorAxis[i])
            return i + 1;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    //iterate over all data sets

    unsigned long long sumOfAxis = 0;
    
    for (int i = 0; i < NUM_DATA_ROWS; ++i)
    {
        NUM_ROWS = 0;
        for (int j = i+1; j < NUM_DATA_ROWS; ++j)
        {
            NUM_ROWS++;            
            if(s_Data[j] == nullptr)
                break;
        }
        NUM_COLUMNS = strlen(s_Data[i]);

        int verticalAxis = GetVerticalMirrorAxis(i);
        int horizontalAxis = GetHorizontalMirrorAxis(i);
        assert(verticalAxis + horizontalAxis != 0);
        sumOfAxis += verticalAxis;
        sumOfAxis += horizontalAxis * 100;

        //print data
        for (int y = 0; y < NUM_ROWS; ++y)
        {
            for (int x = 0; x < NUM_COLUMNS; ++x)
            {
                if(x == verticalAxis - 1)
                    printf("\x1B[33m%c", s_Data[i + y][x]);
                else if(y == horizontalAxis - 1)
                    printf("\x1B[31m%c", s_Data[i + y][x]);
                else
                    printf("\033[0m%c", s_Data[i + y][x]);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        
        i += NUM_ROWS;
    }
    std::cout << "Sum of Axis: " << sumOfAxis << std::endl;
    
    return 0;
}
