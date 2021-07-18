
namespace mtl
{
template <class T>
class Optional 
{
public:
    Optional() = default;
    Optional( T data ) : mData( new T(data) ),isSome(true)
    {}

    bool isSome() const;
    {
        return isSome;
    }

    T value()
    {
        return *mData;
    }
private:
    T * mData{nullptr};
    bool isSome{false};
};
using None = Optional<void>();
}