#include <iostream>
#include "DataDay4.h"

constexpr auto& data = s_Data;
constexpr int numCards = std::size(data);

int s_WinNumbers[numCards][NUM_WIN_NUMBERS] = { 0 };
int s_CardNumbers[numCards][NUM_CARD_NUMBERS] = { 0 };

int main()
{
    //1. convert the data to numbers
    for (int i = 0; i < numCards; ++i)
    {
        const char* currentDataPos = data[i];

        //sscanf_s(currentDataPos, "%d %d %d %d %d", &s_WinNumbers[i][0], &s_WinNumbers[i][1], &s_WinNumbers[i][2], &s_WinNumbers[i][3], &s_WinNumbers[i][4]); okay, that is a lot of typing...
        
        for(int j = 0; j < NUM_WIN_NUMBERS; ++j)
        {
            s_WinNumbers[i][j] = atoi(currentDataPos);
            currentDataPos += 3; //all numbers are 2 digits + 1 space
        }

        currentDataPos += 2; //skip the pipe and the space

        for(int j = 0; j < NUM_CARD_NUMBERS; ++j)
        {
            s_CardNumbers[i][j] = atoi(currentDataPos);
            currentDataPos += 3; //all numbers are 2 digits + 1 space
        }
    }

    constexpr bool isPart1 = false;

    if (isPart1)
    {
        //now iteratate over the numbers and check if they are in the win numbers
        int totalScore = 0;
        for (int i = 0; i < numCards; ++i)
        {
            int numCorrect = 0;
            for (int j = 0; j < NUM_CARD_NUMBERS; ++j)
            {
                for (int k = 0; k < NUM_WIN_NUMBERS; ++k)
                {
                    if (s_WinNumbers[i][k] == s_CardNumbers[i][j])
                    {
                        ++numCorrect;
                        break;
                    }
                }
            }
            int score = (numCorrect == 0) ? 0 : pow(2, numCorrect - 1);
            totalScore += score;
        }

        std::cout << "Total score: " << totalScore << std::endl;
    }
    else
    {
        //part 2 does not calculate the score, but the number of cards at the end. for each winning number we get a copy of the next card(s)
        unsigned int s_AmountOfCards[numCards] = {0};
        unsigned int s_CardWinningNumbers[numCards];

        //first we calculate the amount of winning numbers for each card
        for (int i = 0; i < numCards; ++i)
        {
            int numCorrect = 0;
            for (int j = 0; j < NUM_CARD_NUMBERS; ++j)
            {
                for (int k = 0; k < NUM_WIN_NUMBERS; ++k)
                {
                    if (s_WinNumbers[i][k] == s_CardNumbers[i][j])
                    {
                        ++numCorrect;
                        break;
                    }
                }
            }
            s_CardWinningNumbers[i] = numCorrect;
        }

        //now we iterate again over all cards and add the cards to the total amount
        for (unsigned int i = 0; i < numCards; ++i)
        {
            s_AmountOfCards[i] += 1; //we always get a copy of the card
            const unsigned int amountOfCardsToAdd = s_AmountOfCards[i]; //we get one for each copy of this winning card
            for(unsigned int j = 1; j <= s_CardWinningNumbers[i]; ++j) //for each correct number we get a copy of the next cards
            {
                s_AmountOfCards[i + j] += amountOfCardsToAdd;
            }            
        }

        //now we have the amount of cards, we can calculate the score
        unsigned int sumOfAllCards = 0;
        for (const unsigned int s_AmountOfCard : s_AmountOfCards)
            sumOfAllCards += s_AmountOfCard;
        std::cout << "Total amount of cards: " << sumOfAllCards << std::endl;
    }


}
