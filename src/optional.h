#include <typeinfo>
#include <string_view>

namespace mtl
{

#define Some(val) mtl::Optional<decltype(val)>(val)
template <class T>
class Optional 
{
public:
    Optional() = default;
    Optional( T data ) : mData( data ),isValuePresent(true)
    {}

    template<class U>
    explicit Optional(const Optional<U>& other)
    {
        this->mData = other.mData;
    }

    template<class U>
    Optional& operator=(const Optional<U>& other)
    {
        return this->mData = other.mData;
    }

    bool operator<(const Optional<T>& other)
    {
        return this->mData < other.mData;
    }

    bool operator>(const Optional<T>& other)
    {
        return this->mData > other.mData;
    }

    bool operator==(const Optional<T>& other)
    {
        return this->mData == other.mData;
    }

    bool operator!=(const Optional<T>& other)
    {
        return this->mData != other.mData;
    }

    bool isSome() const
    {
        return isValuePresent;
    }

    bool isNone() const
    {
        return isValuePresent;
    }

    T value() const
    {
        return mData;
    }

    std::string_view type() const
    {
        return typeid(mData).name();
    }
private:
    T mData;
    bool isValuePresent{false};
};
using None = Optional<void>();
}