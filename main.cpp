#include <iostream>
#include "any.h"
#include <typeinfo>
#include <any>
int main()
{
    std::cout << "hello world" << std::endl;
    const std::string qwe = "hello world";
    const mtl::any myAny = qwe;
    
    std::cout << "Value:" << mtl::any_cast<const std::string>(myAny) << std::endl;
    const int a = 2;

    const std::type_info  &info = typeid(a);

    std::cout << "Type:" << info.name() << std::endl;
    return 0;
}