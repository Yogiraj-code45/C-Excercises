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

    void append(const stringimpl& append) 
    {
        if ((currentIndex + append.currentIndex) <= append.MAX_LENGTH-1)
        {
            int startAppendIndex = currentIndex+1;
            int initial = 0;
            while (startAppendIndex <= currentIndex+append.currentIndex && append.chr[initial] != '\0')
            {
                setChr(append.chr[initial]);             
                startAppendIndex++;
                initial++;
            }
        }else 
        {
            std::cout << "String overflow error !!!..." << std::endl;
        }
    }
    
};