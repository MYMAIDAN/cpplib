#include <stdint.h>
namespace mtl
{

template<class T>
struct SharedObject
{
    T* objectPtr{nullptr};
    uint64_t strongCounter{0};
    uint64_t weekCounter{0}
};

template<class T>
class shared_ptr
{
private:
    SharedObject<T>* dataPtr;
public:
    explicit shared_ptr( T* objPtr )
    {
        static_assert(objPtr != nullptr);
        dataPtr = new SharedObject<T>();
        dataPtr->objectPtr = objPtr;
    }
};
}