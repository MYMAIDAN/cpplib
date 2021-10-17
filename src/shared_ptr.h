#include <stdint.h>
namespace mtl
{

template<class T>
struct SharedObject
{
    T* objectPtr{nullptr};
    uint64_t strongCounter{0};
    uint64_t weekCounter{0};
};

template<class T>
class shared_ptr
{
private:
    SharedObject<T>* dataPtr;

    template<typename U, typename ...Args>
    friend shared_ptr<U> make_shared(Args ... args);
public:
    shared_ptr() = default;

    explicit shared_ptr( T* objPtr )
    {
        static_assert(objPtr != nullptr);
        dataPtr = new SharedObject<T>();
        dataPtr->objectPtr = objPtr;
    }

    shared_ptr(const shared_ptr<T>& obj)
    {
        //static_assert(obj.dataPtr == nullptr);
        dataPtr = obj.dataPtr;
        obj.dataPtr->strongCounter++;
        
    }
    shared_ptr<T>& operator=(const shared_ptr<T>& obj)
    {
        static_assert(obj.dataPtr != nullptr);
        dataPtr = obj.dataPtr;
        obj.dataPtr->strongCounter++;
    }

};

template <typename U, typename ... Args>
shared_ptr<U> make_shared(Args ... args)
{
    char* memory = new char[sizeof(U) + sizeof(SharedObject<U>)];
    U* obj = new (memory) U(std::forward<Args>(args)...);
    SharedObject<U> *e = new(memory)(SharedObject<U>);
    
    shared_ptr<U> temp;
    temp.dataPtr = e;
    temp.dataPtr->objectPtr = obj;
    temp.dataPtr->strongCounter = 0;
    temp.dataPtr->weekCounter = 0;
    return temp;
}
}