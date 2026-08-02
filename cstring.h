#ifndef STRING_H
#define STRING_H

#include <memory>
#include <iostream>
#include <mutex>
#include <thread>
#include <algorithm>

class cstring 
{
  protected:
  char* chr;
  int currentIndex = 0;
  std::mutex mutex;
  int MAX_LENGTH = 1024*1024;
  
  public:
  char* append(char* secondString); // length
  char at(int index); // charAt
  std::string c_str(); // 
  int calculate_length(char* len)
  {
    int count = 0;
     while (*len != '\0')
     {
       len++;
       count++;
     }
     return count;
  }
  cstring(char* t) 
  {
     chr = new char[calculate_length(t) + 1];
     while (*t != '\0')
     {
        chr[currentIndex] = *t;
        currentIndex++;
        t++;
     }
     chr[currentIndex] = '\0';
  }
  cstring(const cstring& other); // copy constructor 
  cstring(cstring&& other); // move constructor
  cstring& operator=(cstring&& other) 
  {
    if (this != &other)
    {
      chr = other.chr;
      currentIndex = other.currentIndex;
      other.chr = nullptr;
      other.currentIndex = 0;
    }
    return *this;
  }
  cstring& operator=(const cstring& other) = delete;
  virtual ~cstring() {
    delete[] chr;
  };
};

#endif
