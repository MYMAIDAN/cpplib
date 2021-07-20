
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

    bool isSome() const
    {
        return isValuePresent;
    }

    bool isNone() const
    {
        return isValuePresent;
    }

    T value()
    {
        return mData;
    }
private:
    T mData;
    bool isValuePresent{false};
};
using None = Optional<void>();
}