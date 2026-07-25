#include "string.h"

class stringimpl:public string
{
    public:
    void setChr(char ch) override
    {
        std::lock_guard<std::mutex> lock(mutex);  
        if (chr != nullptr)
        {
            chr[currentIndex] = ch;
            chr[currentIndex+1] = '\0';
            currentIndex++;
        }
    }

    const int getLength() override
    {
        std::lock_guard<std::mutex> lock(mutex);  
        int tempIndex = 0;
        while (chr[tempIndex] != '\0')
        {
            tempIndex++;
        }
        return tempIndex;
    }

    const char charAt(int index) override
    {
        return chr[index];
    }

    void printAllLetters() override
    {
        int tempIndex = 0;
        while (chr[tempIndex] != '\0')
        {
            std::cout << chr[tempIndex] << " ";
            tempIndex++;
        }
        std::cout << "\n" << std::endl;
    }
};