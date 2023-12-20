#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <iostream>
#include <map>
#include <vector>

#include "DataDay19.h"

struct Product
{
    int data[4];  //x,m,a,s
};
std::vector<Product> Products;
//std::vector<Product> RejectedProducts; //needed?
std::vector<Product*> AcceptedProducts;

class IRuleEvaluator
{
public:
    IRuleEvaluator(int nextWorkflow) : m_NextWorkflow(nextWorkflow) {}
    virtual ~IRuleEvaluator() = default;
    //returns the hash of the next Workflow or -1 if rule was not met
    virtual int Eval(const Product* p_Product) const = 0;

protected:
    const int m_NextWorkflow; //if the rule is matched, this is the next workflow
};

class GreaterThanRuleEvaluator final : public IRuleEvaluator
{
public:
    GreaterThanRuleEvaluator(int nextWorkflow, int value, char valueType)
        : IRuleEvaluator(nextWorkflow), m_Value(value), m_ValueType(valueType)
    {}

    int Eval(const Product* p_Product) const override
    {
        return p_Product->data[m_ValueType] > m_Value ? m_NextWorkflow : -1;
    }

    const int m_Value;
    const char m_ValueType;
};

class SmallerThanRuleEvaluator final : public IRuleEvaluator
{
public:
    SmallerThanRuleEvaluator(int nextWorkflow, int value, char valueType)
       : IRuleEvaluator(nextWorkflow), m_Value(value), m_ValueType(valueType)
    {}

    int Eval(const Product* p_Product) const override
    {
        return p_Product->data[m_ValueType] < m_Value ? m_NextWorkflow : -1;
    }

    const int m_Value;
    const char m_ValueType;
};

class AlwaysEvalRuleEvaluator final : public IRuleEvaluator
{
    public:
    AlwaysEvalRuleEvaluator(int nextWorkflow)
        : IRuleEvaluator(nextWorkflow)
    {}

    int Eval(const Product* _) const override
    {
        return m_NextWorkflow;
    }
};

using RulesList = std::vector<std::unique_ptr<IRuleEvaluator>>;
std::map<int, RulesList> s_Workflows;
std::map<int, std::string> s_WorkflowHashes; //for debug display

int MakeWorkflowHash(const char name[4])
{
    if(name[1] == '\0')
        return name[0] << 24;
    if(name[2] == '\0')
        return name[0] << 24 | name[1] << 16 ;
    if(name[3] == '\0')
        return name[0] << 24 | name[1] << 16 | name[2] << 8;
    return name[0] << 24 | name[1] << 16 | name[2] << 8 | name[3];
}

void TrimWorkflowName(char workflowName[4], char trimChar = ',')
{
    if(workflowName[1] == trimChar)
    {
        workflowName[1] = '\0';
    }
    else if(workflowName[2] == trimChar)
    {
        workflowName[2] = '\0';
    }
    else if(workflowName[3] == trimChar)
        workflowName[3] = '\0';
}

void ParseWorkflow(const char* line)
{
    // Workflows have a format like: "px{a<2006:qkq,m>2090:A,rfg}"
    // The first part is the workflow name, the part in {} are the rules
    char workflowName[4] = { line[0], line[1], line[2], line[3] };
    TrimWorkflowName(workflowName, '{');
    char RulesBuffer[256];
    int result = sscanf(line + strlen(workflowName), "{%255s}", RulesBuffer);
    assert(result == 1 && "Invalid workflow format");
    RulesBuffer[strlen(RulesBuffer)-1] = '\0'; //remove }
    const int workflowHash = MakeWorkflowHash(workflowName);
    assert(s_Workflows.find(workflowHash) == s_Workflows.end() && "Workflow already exists");
    s_WorkflowHashes[workflowHash] = workflowName; //for debug display
    RulesList& rules = s_Workflows[workflowHash];
    //parse the rules, Rules have a format like: "a<2006:qkq,m>2090:A,rfg"
    // The first part is the data (from the product) to check, the second part is the rule evaluator, the third part is the next workflow to execute. The blocks are separated by a comma.
    // at the end of all rules is always one workflow name, which is the workflow to execute if no rule matches
    const char* p_RuleToken = RulesBuffer;
    while (*p_RuleToken != '\0')
    {
        char dataType = p_RuleToken[0]; //xmas
        char ruleEvaluator = p_RuleToken[1]; //< > 
        int compareValue;
        char nextWorkflow[5];
        
        if (ruleEvaluator == '<' || ruleEvaluator == '>') //we have a valid rule //Format: a<2006:qkq,
        {
            result = sscanf(p_RuleToken+2, "%d:%4s,", &compareValue, nextWorkflow);
            assert(result == 2 && "Invalid rule format");

            //convert x,m,a,s to 0,1,2,3
            switch (dataType)
            {
                case 'x':
                    dataType = 0;
                break;
                case 'm':
                    dataType = 1;
                break;
                case 'a':
                    dataType = 2;
                break;
                case 's':
                    dataType = 3;
                break;
                default:
                    assert(false && "Invalid rule format");
            }
        }
        else
        {
            //we have the last workflow name
            result = sscanf(p_RuleToken, "%4s", nextWorkflow);
            assert(result == 1 && "Invalid workflow format");
            ruleEvaluator = '!';
        }

        TrimWorkflowName(nextWorkflow, ',');
        const int nextHash = MakeWorkflowHash(nextWorkflow);

        switch (ruleEvaluator)
        {
            case '>':
                rules.emplace_back(std::make_unique<GreaterThanRuleEvaluator>(nextHash, compareValue, dataType));
            break;
            case '<':
                rules.emplace_back(std::make_unique<SmallerThanRuleEvaluator>(nextHash, compareValue, dataType));
            break;
            case '!':
                rules.emplace_back(std::make_unique<AlwaysEvalRuleEvaluator>(nextHash));
            break;
            default:
                assert(false && "Invalid rule evaluator");
        }

        while(*p_RuleToken != '\0' && *p_RuleToken != ',') //skip to next rule
            ++p_RuleToken;
        if (p_RuleToken[0] == ',')
            ++p_RuleToken;
    }
}

void ParseProduct(const char* line)
{
    // products have a format like: "{x=787,m=2655,a=1222,s=2876}"
    // the order of the data is always the same (x, m, a, s), the values map to the product data[4]
    Product product;
    int result = sscanf(line, "{x=%d,m=%d,a=%d,s=%d}", &product.data[0], &product.data[1], &product.data[2], &product.data[3]);
    assert(result == 4 && "Invalid product format");
    Products.push_back(product);
}

const int s_StartWorkflow = MakeWorkflowHash("in");
const int s_AcceptWorkflow = MakeWorkflowHash("A");
const int s_RejectWorkflow = MakeWorkflowHash("R");

void ExecuteWorkflow(int currentWorkflow, const Product* p_Product)
{
    //std::string debugName = s_WorkflowHashes[currentWorkflow];
    assert(s_Workflows.find(currentWorkflow) != s_Workflows.end() && "Invalid workflow hash");
    
    //the steps are: fetch the current workflow, execute the rules, fetch the next workflow, repeat unless it is the accept or reject workflow
    auto& workflowRules = s_Workflows[currentWorkflow];
    //execute the rules (iterating over them and calling Eval, if it returns a hash, we have the next workflow otherwise we continue with the next rule in the list)
    for (auto& rule : workflowRules)
    {
        const int nextWorkflow = rule->Eval(p_Product);
        if(nextWorkflow == s_AcceptWorkflow)
            return AcceptedProducts.push_back(const_cast<Product*>(p_Product));
        if(nextWorkflow == s_RejectWorkflow)
            return;
        if (nextWorkflow != -1)
            return ExecuteWorkflow(nextWorkflow, p_Product);
        assert(nextWorkflow == -1 && "Invalid workflow hash");
    }
    AcceptedProducts.push_back(const_cast<Product*>(p_Product)); //default accept
}

int main(int argc, char* argv[])
{
    //parse the data
    bool parseProducts = false;
    for (const auto line : s_Data)
    {
        if (line == nullptr || line[0] == '\0')
            parseProducts = true; // the workflows and the products are separated by an empty line
        else if(!parseProducts)
            ParseWorkflow(line);
        else
            ParseProduct(line);
    }

    //we now iterate over all products and execute the workflows
    for (auto& product : Products)
    {
        ExecuteWorkflow(s_StartWorkflow, &product);
    }

    //we now have all accepted products in AcceptedProducts, we sum up the values
    int64_t sum = 0;
    for (auto& product : AcceptedProducts)
    {
        sum += product->data[0] + product->data[1] + product->data[2] + product->data[3];
    }
    std::cout << "Sum of all accepted products: " << sum << std::endl;  //Remark: BUGGY, the result is too high, 324360  too low, 353638 too high

    return 0;
}
