#include "cstring.h"

int main()
{
    char* t = new char[10];
    t[0] = 'a';
    t[1] = 'b';
    t[2] = 'c';
    t[3] = 'd';
    cstring c(t);
    std::cout << c.c_str() << std::endl;
    std::cout << c.at(2) << std::endl;
    std::cout << c.append(t) << std::endl;
}