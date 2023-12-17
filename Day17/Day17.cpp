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
    NONE
};

struct Node
{
    int posX; //position in the array
    int posY;
    unsigned int cost = -1; //cost to get to this node
    Node* prev = nullptr; //previous node
    Direction lastDirections[3] = { Direction::NONE, Direction::NONE, Direction::NONE}; //last 3 directions taken to get to this node
};

std::vector<Node> nodes;
std::list<Node*> openList;
std::list<Node*> closedList;

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
        default:
            return '?';
    }
}

void PrintMapWithPath(const Node* const p_FirstNode = nullptr, const Node* const p_TargetNode = nullptr)
{
    //first we calculate the path, because we want to print the path in red
    std::vector<const Node*> path;
    const Node* p_CurrentNode = p_TargetNode;
    while (p_CurrentNode != p_FirstNode)
    {
        path.push_back(p_CurrentNode);
        p_CurrentNode = p_CurrentNode->prev;
    }
    path.push_back(p_FirstNode);

    for (int y = 0; y < NUM_ROWS; ++y)
    {
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            //check if the node is part of the path, than we print it red and print its direction
            const auto pathIt = std::find(path.begin(), path.end(), &nodes[y * NUM_COLUMNS + x]);
            if (pathIt != path.end())
            {
                std::cout << "\033[1;31m " << GetCharForDirection((*pathIt)->lastDirections[2]);
            }
            else 
                std::cout << "\033[0m " << s_Data[y][x];
        }
        std::cout << "\n";
    }
    std::cout << "__________________" << std::endl;
}

void PrintMap()
{
    for (int y = 0; y < NUM_ROWS; ++y)
    {
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            //check if the node is in the open list, than we print it green
            const bool isInOpen = std::find(openList.begin(), openList.end(), &nodes[y * NUM_COLUMNS + x]) != openList.end();
            //check if the node is in the closed list, than we print it red
            const auto closeListIt = std::find(closedList.begin(), closedList.end(), &nodes[y * NUM_COLUMNS + x]);
            
            if (isInOpen)
                std::cout << "\033[1;32m " << s_Data[y][x];
            else if (closeListIt != closedList.end())
                std::cout << "\033[1;31m " << GetCharForDirection((*closeListIt)->lastDirections[2]);
            else 
                std::cout << "\033[0m " << s_Data[y][x];
        }
        std::cout << "\n";
    }
    std::cout << "__________________" << std::endl;
}

void CalculatePath(const Node* const p_TargetNode)
{
    //now we are using Dijkstra's algorithm to find the shortest path, but with the added constraint that we can't go more than 3 steps in the same direction
    while (!openList.empty())
    {
        PrintMap();
        
        Node* p_CurrentNode = GetLowestCostNode();

        if (p_CurrentNode == p_TargetNode)
        {
            //we found the shortest path
            break;
        }

        //add the current node to the closed list
        closedList.push_back(p_CurrentNode);

        //get the current node's neighbours
        Node* p_Neighbours[4] = { nullptr, nullptr, nullptr, nullptr };
        if (p_CurrentNode->posX > 0) //left
            p_Neighbours[0] = &nodes[(p_CurrentNode->posY) * NUM_COLUMNS + (p_CurrentNode->posX - 1)];
        if (p_CurrentNode->posX < NUM_COLUMNS - 1) //right
            p_Neighbours[1] = &nodes[(p_CurrentNode->posY) * NUM_COLUMNS + (p_CurrentNode->posX + 1)];
        if (p_CurrentNode->posY > 0) //up
            p_Neighbours[2] = &nodes[(p_CurrentNode->posY - 1) * NUM_COLUMNS + (p_CurrentNode->posX)];
        if (p_CurrentNode->posY < NUM_ROWS - 1) //down
            p_Neighbours[3] = &nodes[(p_CurrentNode->posY + 1) * NUM_COLUMNS + (p_CurrentNode->posX)];

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
            unsigned int cost = p_CurrentNode->cost + enteringCost;
            if (p_CurrentNode->lastDirections[0] == p_CurrentNode->lastDirections[1] && p_CurrentNode->lastDirections[1] == p_CurrentNode->lastDirections[2] && p_CurrentNode->lastDirections[2] == direction)
                cost += 100000; //penalize going in the same direction 3 times in a row

            //check if the cost is lower than the neighbour's cost
            if (cost < p_Neighbours[i]->cost || (cost <= p_Neighbours[i]->cost && p_CurrentNode->lastDirections[2] != direction))  //if the cost are the same, we prefer to not go in the same direction as the last node
            {
                //update the neighbour's cost
                p_Neighbours[i]->cost = cost;
                p_Neighbours[i]->prev = p_CurrentNode;
                p_Neighbours[i]->lastDirections[0] = p_CurrentNode->lastDirections[1];
                p_Neighbours[i]->lastDirections[1] = p_CurrentNode->lastDirections[2];
                p_Neighbours[i]->lastDirections[2] = direction;

                //check if the neighbour is in the open list
                const bool inOpenList = std::find(openList.begin(), openList.end(), p_Neighbours[i]) != openList.end();

                if (!inOpenList)
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
    nodes.resize(NUM_ROWS * NUM_COLUMNS);
    for (int y = 0; y < NUM_ROWS; ++y)
    {
        for (int x = 0; x < NUM_COLUMNS; ++x)
        {
            nodes[y * NUM_COLUMNS + x].posX = x;
            nodes[y * NUM_COLUMNS + x].posY = y;
        }
    }

    //add the first node to the open list
    Node* const p_FirstNode = nodes.data();
    p_FirstNode->cost = 0;
    openList.push_back(p_FirstNode);

    const Node* const p_TargetNode = &nodes[NUM_ROWS * NUM_COLUMNS - 1];

    CalculatePath(p_TargetNode);

    //now we have the shortest path, we can print the cost for the last node
    std::cout << "Shortest path cost: " << p_TargetNode->cost << std::endl;

    PrintMapWithPath(p_FirstNode, p_TargetNode);
    
    return 0;
}
