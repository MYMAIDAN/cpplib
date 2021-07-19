
namespace mtl
{
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