#define _CRT_SECURE_NO_WARNINGS

//REMARK: Part2 not working with bruteforce... we probably need to cache some results there to make it faster

#include <iostream>
#include "DataDay12.h"

static unsigned long long s_NumVariations = 0;

constexpr int LENGTH_PATTERN = 32;
constexpr int MAX_NUM_FIELDS = 8;

void FindVariations(const char* p_Pattern, int* p_Fields, int num_fields)
{
    const char* p_PatternStart = p_Pattern;
    
    //we start with the first field, and try to a position of the right length for it.
    //if we find a position for it we call the function again with the next field.
    const int sizeOfField = p_Fields[0];
    int currentBroken = 0;
    const char* firstSkippedFixedField = nullptr;
    const char* startOfThisTry = p_Pattern;
    while (*p_Pattern)
    {
        if(*(p_Pattern - sizeOfField) == '#' && (p_Pattern - p_PatternStart) >= sizeOfField)
            return; //if we have fully skipped fixed fields, we cannot continue here.
        
        if(*p_Pattern == '?') //here we go one by one
        {
            currentBroken++;
            p_Pattern++;
        }
        else if(*p_Pattern == '.') //found a working field so we stop our search here
        {
            if(firstSkippedFixedField)
                return; //we have skipped fixed fields, and now we reached a working spring, that means have to end here.
            
            currentBroken = 0;
            startOfThisTry = ++p_Pattern; //we did not find a match until this gap, so we continue after this gap.
            continue;
        }
        while (*p_Pattern == '#') //here we have to skip all
        {
            if(!firstSkippedFixedField)
                firstSkippedFixedField = p_Pattern;
            currentBroken++;
            p_Pattern++;
        }
        if(currentBroken == sizeOfField) //we found a match for the first field
        {
            //we found a match, so we can continue with the next field from this position in the pattern + 1 (because the next one cannot directly start after us).
            if(num_fields > 1)
            {
                if(!*p_Pattern)
                    return; //we reached the end of the pattern, but we still have fields to check, so we cannot continue here.
                FindVariations(p_Pattern + 1, p_Fields + 1, num_fields - 1);
                //we might find another valid position in the same pattern, so we continue searching.
                currentBroken = 0; 
                p_Pattern = ++startOfThisTry;
            }
            else
            {
                //but we need to make sure, that there are no more 'fixed' fields in the pattern.
                bool stillFixedFieldsLeft = false;
                while (*p_Pattern)
                {
                    if(*p_Pattern++ == '#')
                    {
                        stillFixedFieldsLeft = true;
                        break; //there is still a fixed field, so this is not a valid pattern.
                    }
                }
                
                //we found a match for all fields
                if(!stillFixedFieldsLeft)
                    s_NumVariations++;

                //we might find another valid position in the same pattern, so we continue searching.                
                currentBroken = 0; 
                p_Pattern = ++startOfThisTry;
            }
        }
        else if(currentBroken > sizeOfField) //to many broken fields, no match at this position
        {            
            currentBroken = 0; //too many broken fields, no match at this position
            p_Pattern = ++startOfThisTry; //we did not find a match, so we start over from here.
            if(firstSkippedFixedField < p_Pattern)
                return; //we have skipped fixed fields, so we cannot continue here.
        }
    }
}

#define PART1 1

int main(int argc, char* argv[])
{
    std::cout << "Day 12: Hot Springs\n";
    unsigned long long sumOfVariations = 0;

    char pattern[LENGTH_PATTERN];
    int fields[MAX_NUM_FIELDS];

#if defined(PART1)
    for (auto& s_data : s_Data)
    {
        //strings have a format like ".??..??...?##. 1,1,3", so we need to parse that.
        int parsedItems = sscanf(s_data, "%s %d,%d,%d,%d,%d,%d,%d,%d", pattern, &fields[0], &fields[1], &fields[2], &fields[3], &fields[4], &fields[5], &fields[6], &fields[7]);
        s_NumVariations = 0;
        FindVariations(pattern, fields, parsedItems-1);
        std::cout << "Found " << s_NumVariations << " variations" << " for string: " << s_data << std::endl;
        sumOfVariations += s_NumVariations;
    }
    
    std::cout << "Found " << sumOfVariations << " variations in total for the defect hot springs" << std::endl;

#else //PART 2
    //brutefore attempt... this is not working, because it is to slow.
    for (auto& s_data : s_Data)
    {
        //strings have a format like ".??..??...?##. 1,1,3", so we need to parse that.
        int parsedItems = sscanf(s_data, "%s %d,%d,%d,%d,%d,%d,%d,%d", pattern, &fields[0], &fields[1], &fields[2], &fields[3], &fields[4], &fields[5], &fields[6], &fields[7]);
        s_NumVariations = 0;
        //for part 2 we want to duplicate pattern and fields 5 times
        const int patternLen = strlen(pattern);
        const int numFields = parsedItems - 1;
        char pattern_5[LENGTH_PATTERN * 5];
        int fields_5[MAX_NUM_FIELDS * 5];
        for (int i = 0; i < 5; ++i)
        {
            memcpy(pattern_5 + i * patternLen + i, pattern, patternLen + 1);
            pattern_5[(i+1) * patternLen + i] = '?'; //We separate the patterns with a '?'
            memcpy(fields_5 + i * numFields, fields, numFields * sizeof(int));            
        }
        pattern_5[5 * patternLen + 4] = '\0';
        
        FindVariations(pattern_5, fields_5, 5 * numFields);
        std::cout << "Found " << s_NumVariations << " variations" << " for string: " << pattern_5 << " - " << s_data + patternLen << std::endl;
        sumOfVariations += s_NumVariations;
    }

    std::cout << "Found " << sumOfVariations << " variations in total for the defect hot springs" << std::endl;
    int notNeeded = getchar();

#endif
    
    return 0;
}
