#include "cstring.h"

char* cstring::append(char* secondString)
{
    int currentSize = calculate_length(this->chr);
    int newSize = calculate_length(secondString);
    char* newChr = new char[currentSize+newSize+1];
    int index = 0;
    while (index != currentSize)
    {
        newChr[index] = chr[index];
        index++;
    }
    int size = currentSize;
    while (size != currentSize+newSize)
    {
        newChr[size] = secondString[size - currentSize];
        size++;
    }
    delete[] this->chr;
    this->chr = newChr;
    this->chr[currentSize + newSize] = '\0';
    this->currentIndex = currentSize + newSize;
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