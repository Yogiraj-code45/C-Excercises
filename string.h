#ifndef STRING_H
#define STRING_H

#include <memory>
#include <iostream>
#include <mutex>
#include <thread>
#include <algorithm>

class string 
{
  protected:
  char* chr;
  int currentIndex;
  std::mutex mutex;
  int MAX_LENGTH = 1024*1024;
  
  public:
  virtual const int getLength() = 0; // length
  virtual const char charAt(int index) = 0; // charAt
  virtual void setChr(char ch) = 0; //pure virtual 
  virtual void printAllLetters() = 0; // pure virtual
  string() 
  {
     chr = new char[MAX_LENGTH];
  }
  string(const string& other); // copy constructor 
  string(string&& other); // move constructor
  string& operator=(string&& other) 
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
  string& operator=(const string& other) = delete;
  virtual ~string() {
    /// for deleting array 
    delete[] chr;
  }; // virtual destructor
};

#endif
