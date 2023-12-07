#include <algorithm>
#include <iostream>

#include "DataDay7.h"
using namespace std;

int main(int argc, char* argv[])
{
    //sort the hands reversed based on their score
    std::sort(std::begin(hands), std::end(hands), [](const Hand& a, const Hand& b) { return a.m_Score < b.m_Score; });
    
    unsigned long long totalScore = 0;
    for (size_t i = 0; i < std::size(hands); ++i)
    {
        //cout << std::dec << "Hand " << i << " has a score of " << hands[i].m_Bid * (1 + i) << " bid was " << hands[i].m_Bid << " card: " << hands[i].m_Cards << " and internal scoring: " << std::hex << hands[i].m_Score << endl;
        totalScore += hands[i].m_Bid * (1 + i);
    }

    cout << "total score: " << totalScore << endl;
    
    return 0;
}
