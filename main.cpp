#include "cstring.h"

int main()
{
    char* t = new char[10];
    t[0] = 'a';
    t[1] = 'b';
    t[2] = 'c';
    t[3] = 'd';
    char* tr = new char[10];
    cstring c(t);
    cstring nt(tr);
    std::cout << c.c_str() << std::endl;
    std::cout << c.at(2) << std::endl;
    std::cout << c.append(t) << std::endl;
    std::cout << "Moving the string" << std::endl;
    nt = std::move(c);
    std::cout << nt.c_str() << std::endl;
}