#ifndef STRING_H
#define STRING_H

#include <memory>
#include <iostream>
#include <mutex>
#include <thread>

class string 
{
  protected:
  char* chr;
  int currentIndex;
  std::mutex mutex;

  private:
  int MAX_LENGTH = 1024*1024;
  
  public:
  bool compare(const string& a, const string& b);
  virtual const int getLength() = 0; // length
  virtual const char charAt(int index) = 0; // charAt
  virtual void setChr(char ch) = 0; //pure virtual 
  virtual void printAllLetters() = 0;
  string() 
  {
     chr = new char[MAX_LENGTH];
  }
  string(const string& other); // copy constructor 
  string(string&& other); // move constructor
  virtual ~string() {}; // virtual destructor
};

#endif
