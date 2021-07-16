#include <iostream>
#include <typeinfo>
#include "optional.h"
int main()
{

    mtl::Optional<void> a = mtl::Optional<void>();
    /*std::cout << "hello world" << std::endl;
    const std::string qwe = "hello world";
    const mtl::any myAny = qwe;
    
    std::cout << "Value:" << mtl::any_cast<const std::string>(myAny) << std::endl;
    const int a = 2;

    const std::type_info  &info = typeid(a);

    std::cout << "Type:" << info.name() << std::endl;*/
    return 0;
}