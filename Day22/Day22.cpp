#include <cassert>
#include <iostream>
#include <map>
#include <unordered_set>

#include "DataDay22.h"

using BlockList = std::unordered_set<int>;
std::map<int, BlockList> blockBeneath;
std::map<int, BlockList> blockAbove;

void PrintField(const Block blocksToPrint[], int max[3])
{
    //we have 3d blocks, but we display it 2d, so we display it in z direction, z is vertical, x and y are horizontal
    //first we display from y view
    std::cout << "Y view" << std::endl;
    for (int z = 0; z <= max[2]; ++z)
    {
        const int currentHeight = max[2] - z;
        for (int x = 0; x <= max[0]; ++x)
        {
            int blockIndex = -1;
            for(int i = 0; i < NUM_BLOCKS; ++i)
            {
                const Block& block = blocksToPrint[i];
                if (block.start[0] <= x && block.end[0] >= x && block.start[2] <= currentHeight && block.end[2] >= currentHeight)
                {
                    blockIndex = i;
                    break;
                }
            }
            if (blockIndex != -1)
                printf ("%6d", blockIndex);
            else
                std::cout << "     .";
        }
        std::cout << std::endl;
    }

    //now we display from x view
    std::cout << "X view" << std::endl;
    for (int z = 0; z <= max[2]; ++z)
    {
        const int currentHeight = max[2] - z;
        for (int y = 0; y <= max[1]; ++y)
        {
            int blockIndex = -1;
            for (int i = 0; i < NUM_BLOCKS; ++i)
            {
                const Block& block = blocksToPrint[i];
                if (block.start[1] <= y && block.end[1] >= y && block.start[2] <= currentHeight && block.end[2] >= currentHeight)
                {
                    blockIndex = i;
                    break;
                }
            }
            if (blockIndex != -1)
                printf ("%6d", blockIndex);
            else
                std::cout << "     .";
        }
        std::cout << std::endl;
    }

    //now we display from z view
    std::cout << "Z view" << std::endl;
    for (int y = 0; y <= max[1]; ++y)
    {
        for (int x = 0; x <= max[0]; ++x)
        {
            int blockIndex = -1;
            for (int i = 0; i < NUM_BLOCKS; ++i)
            {
                const Block& block = blocksToPrint[i];
                if (block.start[1] <= y && block.end[1] >= y && block.start[0] <= x && block.end[0] >= x)
                {
                    blockIndex = i;
                    break;
                }
            }
            if (blockIndex != -1)
                printf ("%6d", blockIndex);
            else
                std::cout << "     .";
        }
        std::cout << std::endl;
    }
}

int field_width;
int field_depth;
int field_height;
int* field;

int GetIndex(int x, int y, int z)
{
    assert(x >= 0 && x < field_width && y >= 0 && y < field_depth && z >= 0 && z < field_height);
    return x + y * field_depth + z * field_height;
}

int& GetBlockIndex(int x, int y, int z)
{
    return field[GetIndex(x, y, z)];
}

int CountStonesThatCanBeRemoved(Block sortedBlocks[NUM_BLOCKS])
{
    int stonesToRemove = 0;
    for (int i = 0; i < NUM_BLOCKS; ++i)
    {
        bool canBeRemoved = true;
        //const Block& block = sortedBlocks[i];
        const auto it = blockAbove.find(i);
        if(it != blockAbove.end())
        {
            for (auto aboveIndex  : it->second)
            {
                const auto it2 = blockBeneath.find(aboveIndex);
                assert(it2 != blockBeneath.end());
                if(it2->second.size() <= 1) 
                {
                    canBeRemoved = false;
                    break;
                }
            }
        }
        if(canBeRemoved)
            stonesToRemove++;
    }
    return stonesToRemove;
}

void GetDependedBlocks(int index, std::unordered_set<int>& list)
{
    list.insert(index);
    const auto it = blockAbove.find(index);
    if(it != blockAbove.end())
    {
        for (auto aboveIndex  : it->second)
        {
            const auto it2 = blockBeneath.find(aboveIndex);
            bool allInclude = true;
            for (auto value : it2->second) //expensive way to check if all contained
                if(list.find(value) == list.end())
                {
                    allInclude = false;
                    break;
                }
            if(allInclude) 
            {
                GetDependedBlocks(it2->first, list);
            }
        }
    }
}

unsigned int CountChainReaction(Block sortedBlocks[NUM_BLOCKS])
{
    unsigned int chainReaction = 0;
    std::unordered_set<int> list;
    for (int i = 0; i < NUM_BLOCKS; ++i)
    {
        list.clear();
        GetDependedBlocks(i, list);
        chainReaction += list.size();
    }
    return chainReaction;
}

int main(int argc, char* argv[])
{
    //find min&max x, y, z
    int max[3] = { 0, 0, 0 };
    int min[3] = { 9999, 9999, 9999 };
    for (const Block& block : s_Blocks)
    {
        for(int i = 0; i < 3; ++i)
        {
            if (block.start[i] < min[i])
                min[i] = block.start[i];
            if (block.end[i] > max[i])
                max[i] = block.end[i];
        }
    }

    //we create an 3d array holding the block index for each position, so that we can easily check if a position is occupied
    field_width = max[0] + 12;
    field_depth = max[1] + 12;
    field_height = max[2] + 12;
    field = new int[field_width * field_depth * field_height];
    memset(field, -1, sizeof(int) * field_width * field_depth * field_height);
    //add blocks to field
    for (int i = 0; i < NUM_BLOCKS; ++i)
    {
        const Block& block = s_Blocks[i];
        for (int z = block.start[2]; z <= block.end[2]; ++z)
        {
            for (int y = block.start[1]; y <= block.end[1]; ++y)
            {
                for (int x = block.start[0]; x <= block.end[0]; ++x)
                {
                    field[GetIndex(x,y,z)] = i;
                }
            }
        }
    }

    //first we create a sorted (by z) list of all blocks
    Block sortedBlocks[NUM_BLOCKS];
    for (int i = 0; i < NUM_BLOCKS; ++i)
    {
        sortedBlocks[i] = s_Blocks[i];
    }
    for (int i = 0; i < NUM_BLOCKS; ++i)
    {
        for (int j = i + 1; j < NUM_BLOCKS; ++j)
        {
            if (sortedBlocks[j].start[2] < sortedBlocks[i].start[2] || sortedBlocks[j].end[2] < sortedBlocks[i].end[2])
            {
                std::swap(sortedBlocks[i], sortedBlocks[j]);
            }
        }
    }

    PrintField(sortedBlocks, max);
    
    //now we iterate through the sorted list and move each block down until it hits another block
    bool brickMoved = true;
    while (brickMoved)
    {
        brickMoved = false;

        for (int i = 0; i < NUM_BLOCKS; ++i)
        {
            Block& block = sortedBlocks[i];
            int startMinZ = std::min(block.start[2], block.end[2]);
            int newMinZ = startMinZ;
            while (newMinZ > 1)
            {
                bool canMove = true;
                for (int x = block.start[0]; x <= block.end[0]; ++x)
                {
                    for (int y = block.start[1]; y <= block.end[1]; ++y)
                    {
                        if (GetBlockIndex(x,y,newMinZ-1) != -1)
                        {
                            canMove = false;
                            break;
                        }
                    }
                    if (!canMove)
                        break;
                }
                if (!canMove)
                    break;
                --newMinZ;
            }
            const int heightDiff = startMinZ - newMinZ;
            if(heightDiff > 0)
            {
                //now we found the new height, so we move the block
                for (int x = block.start[0]; x <= block.end[0]; ++x)
                {
                    for (int y = block.start[1]; y <= block.end[1]; ++y)
                    {
                        for (int z = startMinZ; z <= block.end[2]; ++z)
                        {
                            GetBlockIndex(x, y, z - heightDiff) = i; //beware: this is not the initial index, but the index in the sorted list
                            GetBlockIndex(x, y, z) = -1;
                        }
                    }
                }
                block.start[2] -= heightDiff;
                block.end[2] -= heightDiff;
                brickMoved = true;
            }
        }
    }

    PrintField(sortedBlocks, max);

    //now we create a map of all blocks that are beneath a specific block
    for (int i = 0; i < NUM_BLOCKS; ++i)
    {
        const Block& block = sortedBlocks[i];
        const int lowestZ = std::min(block.start[2], block.end[2]);
        for (int x = block.start[0]; x <= block.end[0]; ++x)
        {
            for (int y = block.start[1]; y <= block.end[1]; ++y)
            {
                const int blockIndex = GetBlockIndex(x, y, lowestZ-1);
                if (blockIndex != -1)
                {
                    blockBeneath[i].insert(blockIndex);
                 }
            }
        }
    }

    //now we do it again, but this time we want to find above each block
    for (int i = 0; i < NUM_BLOCKS; ++i)
    {
        const Block& block = sortedBlocks[i];
        const int highestZ = std::max(block.start[2], block.end[2]);
        for (int x = block.start[0]; x <= block.end[0]; ++x)
        {
            for (int y = block.start[1]; y <= block.end[1]; ++y)
            {
                const int blockIndex = GetBlockIndex(x, y, highestZ + 1);
                if (blockIndex != -1)
                {
                    blockAbove[i].insert(blockIndex);
                }
            }
        }
    }
    
    int stonesToRemove = CountStonesThatCanBeRemoved(sortedBlocks);
    std::cout << "Stones that can be removed: " << stonesToRemove << std::endl;

    unsigned int chainReaction = CountChainReaction(sortedBlocks);
    std::cout << "Chain Reaction: " << chainReaction << std::endl;

    return 0;
}
