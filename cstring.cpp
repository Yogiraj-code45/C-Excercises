#include "cstring.h"

char* cstring::append(char* secondString)
{
    int currentSize = calculate_length(this->chr);
    int newSize = calculate_length(secondString);
    char* newChr = new char[currentSize+newSize];
    int index = 0;
    while (index != currentSize)
    {
        newChr[index] = chr[index];
        index++;
    }
    int size = 0;
    while (size != newSize)
    {
        if (size == 0)
        {
            newChr[size] = secondString[size];
            size++;
        }
    }
    this->chr = newChr;
    return this->chr;
}

char cstring::at(int index)
{
    return chr[index];
}

std::string cstring::c_str()
{
    std::string output;
    output.append(chr);
    return output;
}