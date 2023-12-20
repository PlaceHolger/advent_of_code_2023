#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <iostream>
#include <list>
#include <map>

#include "DataDay20.h"

#define IS_PART 1

class IModules
{
public:
    enum Signal
    {
        High,
        Low,
        None
    };

    virtual ~IModules() = default;
    virtual Signal OnImpulse(Signal input, IModules* p_Sender) = 0;
    void AddOutput(const std::string& p_OutputModule) { m_OutputModules.push_back(p_OutputModule); }
    
    std::list<std::string> m_OutputModules;
};

//Flip-flop modules (prefix %) are either on or off; they are initially off. If a flip-flop module receives a high pulse, it is ignored and nothing happens. However, if a flip-flop module receives a low pulse, it flips between on and off. If it was off, it turns on and sends a high pulse. If it was on, it turns off and sends a low pulse.
class FlipFlopModule : public IModules
{
    public:

    Signal OnImpulse(Signal input, IModules* p_Sender) override
    {
        if (input == Signal::Low)
        {
            m_On = !m_On;
            return m_On ? Signal::High : Signal::Low;
        }
        return Signal::None;
    }
    
private:
    bool m_On = false;
};

class BroadcastModule : public IModules
{
public:
    Signal OnImpulse(Signal input, IModules* p_Sender) override { return input; }
};

//Conjunction modules (prefix &) remember the type of the most recent pulse received from each of their connected input modules; they initially default to remembering a low pulse for each input. When a pulse is received, the conjunction module first updates its memory for that input. Then, if it remembers high pulses for all inputs, it sends a low pulse; otherwise, it sends a high pulse.
class ConjunctionModule : public IModules
{
public:
    Signal OnImpulse(Signal input, IModules* p_Sender) override
    {
        m_InputModuleState[p_Sender] = input;
        //if all inputs are high, send low pulse
        for (const auto& pair : m_InputModuleState)
        {
            if (pair.second == Signal::Low)
            {
                return Signal::High;
            }
        }
        return Signal::Low;
    }

    void AddInput(IModules* p_InputModule)
    {
        m_InputModuleState[p_InputModule] = Signal::Low;
    }
    
protected:
    std::map<IModules*, Signal> m_InputModuleState;
};

std::map<std::string, std::unique_ptr<IModules>> s_InputModules;

void ParseModules()
{
    for (const auto data : s_Data)
    {
        //%name -> name1, name2, name3

        //we first parse the input module name
        const char type = data[0]; //either % or & or nothing (for broadcaster)
        const char* outputModuleNames = strchr(data, '>') + 2;
        std::string inputModuleName = std::string(data + 1, outputModuleNames - data - 5);

        std::unique_ptr<IModules> p_InputModule = nullptr;
        switch (type)
        {
            case '%':  //flip-flop
                p_InputModule= std::make_unique<FlipFlopModule>();
                break;
            case '&': //conjuction
                p_InputModule= std::make_unique<ConjunctionModule>();
                break;
            case 'b': //broadcaster
                inputModuleName = "broadcaster";
                p_InputModule = std::make_unique<BroadcastModule>();
                break;
            default: //invalid
                assert(false && "Invalid type");
                break;
        }

        //we now parse the output module names, these are separated by commas
        while (outputModuleNames != nullptr)
        {
            const char* p_Comma = strchr(outputModuleNames, ',');
            outputModuleNames = (outputModuleNames[0] == ' ') ? outputModuleNames + 1 : outputModuleNames;
            std::string outputModuleName = std::string(outputModuleNames, (p_Comma == nullptr) ? strlen(outputModuleNames): p_Comma - outputModuleNames);
            p_InputModule->AddOutput(outputModuleName);
            outputModuleNames = p_Comma;
            if (outputModuleNames != nullptr)
                outputModuleNames++;
        }
        s_InputModules[inputModuleName] = std::move(p_InputModule);
    }

    //now we have parsed all modules, we can fix-up the Conjunction modules, these require a pointer to the input modules
    for (const auto& pair : s_InputModules)
    {
        for(const auto output : pair.second->m_OutputModules)
        {
            auto it = s_InputModules.find(output);
            if (it != s_InputModules.end())
            {
                ConjunctionModule* p_ConjunctionModule = dynamic_cast<ConjunctionModule*>(it->second.get());
                if (p_ConjunctionModule != nullptr)
                {
                    p_ConjunctionModule->AddInput(pair.second.get());
                }
            }
        }
    }
}

struct ProcessStep
{
    std::string Module;
    std::string SenderModule;
    IModules::Signal Signal;
};  

uint64_t s_NumOfLowSignals = 0;
uint64_t s_NumOfHighSignals = 0;

uint64_t s_NumOfRxHighSignals = 0;
uint64_t s_NumOfRxLowSignals = 0;

void StartSimulation()
{
    //now we can start the simulation, we start with the broadcaster module which we send a low pulse
    std::list<ProcessStep> processSteps;
    processSteps.push_back({ "broadcaster", "Button", IModules::Signal::Low });
    s_NumOfLowSignals++;

    while (!processSteps.empty())
    {
        const ProcessStep processStep = processSteps.front();
        processSteps.pop_front();

        //we first send the signal to the module
        IModules* p_Module = s_InputModules[processStep.Module].get();
        IModules* p_Sender = (processStep.SenderModule.empty()) ? nullptr : s_InputModules[processStep.SenderModule].get();
        const IModules::Signal outputSignal = p_Module->OnImpulse(processStep.Signal, p_Sender);
        if(outputSignal == IModules::Signal::None)
            continue; //nothing to do (e.g. flip-flop module received a high pulse

        for (const auto& output : p_Module->m_OutputModules)
        {
            if(outputSignal == IModules::Signal::Low)
                s_NumOfLowSignals++;
            else
                s_NumOfHighSignals++;
            
            //debug output like broadcaster -low-> a
            //std::cout << processStep.Module << " -" << ((outputSignal == IModules::Signal::High) ? "high" : "low") << "-> " << output << std::endl;
            
            auto it = s_InputModules.find(output);
            if(it == s_InputModules.end()) //e.g. "output" (rx)
            {
#if IS_PART == 2
                if(output == "rx")
                {
                    if(outputSignal == IModules::Signal::High)
                        s_NumOfRxHighSignals++;
                    else
                        s_NumOfRxLowSignals++;
                }
#endif
                //std::cout << "\nSkipped module: " << output; //e.g. "output
                continue;
            }
            processSteps.push_back({ it->first, processStep.Module, outputSignal });
        }
    }
}

int main(int argc, char* argv[])
{
    ParseModules();

    for (int i = 0; i < 1000; ++i)
    {
        StartSimulation();
    }

    const uint64_t sum = s_NumOfHighSignals * s_NumOfLowSignals;
    std::cout << "Number of low signals: " << s_NumOfLowSignals << " number of high signals: " << s_NumOfHighSignals << " Product: " << sum << std::endl;
    
    return 0;
}
