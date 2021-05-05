#include <iostream>
#include "any.hpp"
int main()
{
    std::cout << "hello world" << std::endl;
    mtl::any myAny = std::string("Hello value");
    
    std::cout << "Value:" << mtl::any_cast<std::string>(myAny);
    return 0;
}