#include <iostream>
#include <typeinfo>
#include "optional.h"
int main()
{

    mtl::Optional<double> a = mtl::Optional<double>(5);
    int d = 3;
    auto e = Some(3.3);

    std::cout << "is some: " << e.isSome();

    std::cout << "Value : " << e.value(); 

    mtl::Optional<double> qew = e;

    e = a;

    /*std::cout << "hello world" << std::endl;
    const std::string qwe = "hello world";
    const mtl::any myAny = qwe;
    
    std::cout << "Value:" << mtl::any_cast<const std::string>(myAny) << std::endl;
    const int a = 2;

    const std::type_info  &info = typeid(a);

    std::cout << "Type:" << info.name() << std::endl;*/
    return 0;
}