#include <cassert>
#include <iostream>
#include <list>
#include <vector>

#include "DataDay17.h"
constexpr int NUM_ROWS = std::size(s_Data);

enum class Direction : char
{
    Left,
    Right,
    Up,
    Down,
    NONE,
};

constexpr int MAX_SAME_DIRECTION = 3;

struct Node
{
    int posX; //position in the array
    int posY;
    unsigned int cost = -1; //cost to get to this node
    Node* prev = nullptr; //previous node
    Direction lastDirections[MAX_SAME_DIRECTION] = { Direction::NONE, Direction::NONE, Direction::NONE }; //last 3 directions taken to get to this node
};

constexpr int NUM_DIRECTIONS = 4;

std::vector<Node> nodes[MAX_SAME_DIRECTION][NUM_DIRECTIONS]; //for our task we assume each position exist in 3 different states, depending on the last 3 directions taken to get to it.
std::vector<Node*> openList;
std::vector<Node*> closedList;

Node* GetLowestCostNode(bool pop = true)
{
    auto p_LowestCostNodeIt = openList.end();
    unsigned int lowestCost = -1;
    for (auto it = openList.begin(); it != openList.end(); ++it)
    {
        if ((*it)->cost < lowestCost)
        {
            lowestCost = (*it)->cost;
            p_LowestCostNodeIt = it;
        }
    }

    Node* p_LowestCostNode = *p_LowestCostNodeIt;
    if (pop)
        openList.erase(p_LowestCostNodeIt);

    return p_LowestCostNode;
}

// bool operator==(const Node& lhs, const Node& rhs) //REMARK: we are just comparing the position here, not the lastDirections
// {
//     return lhs.posX == rhs.posX && lhs.posY == rhs.posY;
// }

char GetCharForDirection(const Direction& dir)
{
    switch (dir)
    {
        case Direction::Left:
            return '<';
        case Direction::Right:
            return '>';
        case Direction::Up:
            return '^';
        case Direction::Down:
            return 'v';
        case Direction::NONE:
            return '!';
        default:
            return '?';
    }
}

void PrintMapWithPath(const Node* const p_TargetNode = nullptr)
{
    //first we calculate the path, because we want to print the path in red
    std::vector<const Node*> path;
    const Node* p_CurrentNode = p_TargetNode;
    while (p_CurrentNode)
    {
        path.push_back(p_CurrentNode);
        p_CurrentNode = p_CurrentNode->prev;
    }
    
    for (int y = 0; y < NUM_ROWS; ++y)
    {
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            //check if the node is part of the path (if we have a node with these x and y), than we print it red and print its direction
            const Node* p_PathNode = nullptr;
            for (const auto curNode : path)
            {
                if(curNode->posX == x && curNode->posY == y)
                {
                    p_PathNode = curNode;
                    break;
                }
            }
            
            if (p_PathNode)
            {
                std::cout << "\033[1;31m " << GetCharForDirection(p_PathNode->lastDirections[2]);
            }
            else 
                std::cout << "\033[0m " << s_Data[y][x];
        }
        std::cout << "\n";
    }
    std::cout << "__________________" << std::endl;
}

void PrintMap(int highlightX = -1, int highlightY = -1)
{
    for (int y = 0; y < NUM_ROWS; ++y)
    {
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            bool isInOpen = false;
            bool isInClosed = false;

            for(int i = 0; i < MAX_SAME_DIRECTION; ++i)
            {
                for(int j = 0; j < NUM_DIRECTIONS; ++j)
                {
                    isInOpen |= std::find(openList.begin(), openList.end(), &nodes[i][j][y * NUM_COLUMNS + x]) != openList.end();
                    isInClosed |= std::find(closedList.begin(), closedList.end(), &nodes[i][j][y * NUM_COLUMNS + x]) != closedList.end();
                }
            }

            if(x == highlightX && y == highlightY)
                std::cout << "\033[1;33m " << s_Data[y][x];
            else if (isInOpen)
                std::cout << "\033[1;32m " << s_Data[y][x];
            else if (isInClosed)
                std::cout << "\033[1;31m " << s_Data[y][x];
            else 
                std::cout << "\033[0m " << s_Data[y][x];
        }
        std::cout << "\n";
    }
    std::cout << "__________________" << std::endl;
}

int CalcNumSameDirections(const Node* p_CurrentNode)
{
    int numSameDirection = 0;
    for (int i = MAX_SAME_DIRECTION - 1; i >= 1; --i)
    {
        if (p_CurrentNode->lastDirections[i] != Direction::NONE && p_CurrentNode->lastDirections[i] == p_CurrentNode->lastDirections[i - 1])
            ++numSameDirection;
        else
            break;
    }
    return numSameDirection;
}

void CalculatePath(int startX, int startY, int targetX, int targetY)
{
    //add the first node to the open list
    Node* const p_FirstNode = &nodes[0][(int)Direction::Right][startY * NUM_COLUMNS + startX];
    p_FirstNode->cost = 0;
    Node* const p_FirstNode2 = &nodes[0][(int)Direction::Down][startY * NUM_COLUMNS + startX];
    p_FirstNode2->cost = 0;
    //p_FirstNode->lastDirections[2] = Direction::Right;
    openList.push_back(p_FirstNode);
    openList.push_back(p_FirstNode2);
    
    //now we are using Dijkstra's algorithm to find the shortest path, but with the added constraint that we can't go more than 3 steps in the same direction
    while (!openList.empty())
    {
        Node* p_CurrentNode = GetLowestCostNode();

        //PrintMap(p_CurrentNode->posX, p_CurrentNode->posY);

        if (p_CurrentNode->posX == targetX && p_CurrentNode->posY == targetY)
        {
            //we found the shortest path
            break;
        }

        //add the current node to the closed list
        closedList.push_back(p_CurrentNode);
        //we count how many times we went in the same direction, we do so by starting at the end of the lastDirections array and going back until we find a different direction
        const int numSameDirection = CalcNumSameDirections(p_CurrentNode);
        const int lastDir = static_cast<int>(p_CurrentNode->lastDirections[2]);

        //get the current node's neighbours
        Node* p_Neighbours[4] = { nullptr, nullptr, nullptr, nullptr };
        if (p_CurrentNode->posX > 0) //left
            p_Neighbours[0] = &nodes[numSameDirection][lastDir][(p_CurrentNode->posY) * NUM_COLUMNS + (p_CurrentNode->posX - 1)];
        if (p_CurrentNode->posX < NUM_COLUMNS - 1) //right
            p_Neighbours[1] = &nodes[numSameDirection][lastDir][(p_CurrentNode->posY) * NUM_COLUMNS + (p_CurrentNode->posX + 1)];
        if (p_CurrentNode->posY > 0) //up
            p_Neighbours[2] = &nodes[numSameDirection][lastDir][(p_CurrentNode->posY - 1) * NUM_COLUMNS + (p_CurrentNode->posX)];
        if (p_CurrentNode->posY < NUM_ROWS - 1) //down
            p_Neighbours[3] = &nodes[numSameDirection][lastDir][(p_CurrentNode->posY + 1) * NUM_COLUMNS + (p_CurrentNode->posX)];

        //we dont check the neighbour in the same direction we came from
        switch (p_CurrentNode->lastDirections[2])
        {
            case Direction::Left:
                p_Neighbours[1] = nullptr; //remove right neighbour
                break;
            case Direction::Right:
                p_Neighbours[0] = nullptr;
                break;
            case Direction::Up:
                p_Neighbours[3] = nullptr;
                break;
            case Direction::Down:
                p_Neighbours[2] = nullptr;
                break;
        }

        if(numSameDirection == MAX_SAME_DIRECTION - 1)
        {
            //we can't go in the same direction again, so we remove the neighbour in the same direction as the last 3 directions
            switch (p_CurrentNode->lastDirections[2])
            {
                case Direction::Left:
                    p_Neighbours[0] = nullptr; //remove left neighbour
                    break;
                case Direction::Right:
                    p_Neighbours[1] = nullptr;
                    break;
                case Direction::Up:
                    p_Neighbours[2] = nullptr;
                    break;
                case Direction::Down:
                    p_Neighbours[3] = nullptr;
                    break;
                default: //should never happen
                    assert(false);
            }
        }

        //for each neighbour we calculate the cost to get to it
        for (int i = 0; i < 4; ++i)
        {
            const Direction direction = static_cast<Direction>(i); //the direction we are going to take to get to the neighbour
            
            if (p_Neighbours[i] == nullptr)
                continue;

            //check if the neighbour is in the closed list
            const bool inClosedList = std::find(closedList.begin(), closedList.end(), p_Neighbours[i]) != closedList.end();

            if (inClosedList)
                continue;

            //calculate the cost to get to the neighbour
            const int enteringCost = s_Data[p_Neighbours[i]->posY][p_Neighbours[i]->posX] - '0';
            const unsigned int cost = p_CurrentNode->cost + enteringCost;
            //we remove invalid neighbours already, so this should never happen
            // if (p_CurrentNode->lastDirections[0] == p_CurrentNode->lastDirections[1] && p_CurrentNode->lastDirections[1] == p_CurrentNode->lastDirections[2] && p_CurrentNode->lastDirections[2] == direction)
            //     cost += 100000; //penalize going in the same direction 3 times in a row

            //check if the cost is lower than the existing neighbour's cost
            if (cost < p_Neighbours[i]->cost)
            {
                //update the neighbour's cost
                p_Neighbours[i]->cost = cost;
                p_Neighbours[i]->prev = p_CurrentNode;
                p_Neighbours[i]->lastDirections[0] = p_CurrentNode->lastDirections[1];
                p_Neighbours[i]->lastDirections[1] = p_CurrentNode->lastDirections[2];
                p_Neighbours[i]->lastDirections[2] = direction;

                //check if the neighbour is in the open list
                const auto openListIt = std::find(openList.begin(), openList.end(), p_Neighbours[i]);

                if (openListIt == openList.end())
                {
                    //add the neighbour to the open list
                    openList.push_back(p_Neighbours[i]);
                }
            }
        }        
    }
}

int main(int argc, char* argv[])
{
    //First we create nodes for each position in the array
    for(int j = 0; j < NUM_DIRECTIONS; ++j)
        for(int i = 0; i < MAX_SAME_DIRECTION; ++i)
        {
            nodes[i][j].resize(NUM_ROWS * NUM_COLUMNS);
            for (int y = 0; y < NUM_ROWS; ++y)
            {
                for (int x = 0; x < NUM_COLUMNS; ++x)
                {
                    nodes[i][j][y * NUM_COLUMNS + x].posX = x;
                    nodes[i][j][y * NUM_COLUMNS + x].posY = y;

                }
            }
        }

    const int targetX = NUM_COLUMNS - 1;
    const int targetY = NUM_ROWS - 1;
    
    CalculatePath(0, 0, targetX, targetY);

    //Find the target node with the lowest cost
    const Node* p_BestTargetNode = nullptr;
    for(int j = 0; j < NUM_DIRECTIONS; ++j)
        for(int i = 0; i < MAX_SAME_DIRECTION; ++i)
        {
            const Node* p_TargetNode = &nodes[i][j][targetY * NUM_COLUMNS + targetX];
            if (!p_BestTargetNode || p_TargetNode->cost < p_BestTargetNode->cost)
                p_BestTargetNode = p_TargetNode;
        }

    // //now we have the shortest path, we can print the cost for the last node
    std::cout << "Shortest path cost: " << p_BestTargetNode->cost << std::endl;
    //
    PrintMapWithPath(p_BestTargetNode);
    
    return 0;
}
