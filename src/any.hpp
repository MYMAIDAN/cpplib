#include <type_traits>
#include <typeinfo>

#include "include\bad_cast.h"

namespace mtl
{
/**
 * @brieT class any is object which can hold any data type
 * 
 */
class any
{
public:
  template<class T>
  any( T val )
  {
    mStorage = new StorageIml<T>( val );
  }

private:
  class StorageBase
  {
  public:
    virtual const std::type_info& getType() = 0;
  };

  template<class U>
  class StorageIml : public StorageBase
  {
  public:
    StorageIml( U value ) : mValue( value ) {}
    U mValue;

    const std::type_info& getType() override
    {
      return typeid( mValue );
    }
  };

  StorageBase* mStorage;

  template<class T>
  friend T any_cast( any& obj );

  template<class T>
  friend T any_cast( const any& obj );

  template<class T>
  friend T any_cast( any&& obj );

  template<class T>
  friend const T* any_cast( const any* obj );

  template<class T>
  friend T* any_cast( any* obj );
};

template<class T>
T any_cast( any& obj )
{
  if( obj.mStorage->getType() == typeid( T ) )
  {
    return static_cast<any::StorageIml<T>*>( obj.mStorage )->mValue;
  }
  else
  {
    throw bad_cast();
  }
}

template<class T>
T any_cast( const any& obj )
{
  if( obj.mStorage->getType() == typeid( T ) )
  {
    return static_cast<any::StorageIml<T>*>( obj.mStorage )->mValue;
  }
  else
  {
    throw bad_cast();
  }
}

template<class T>
T any_cast( any&& obj )
{
  if( obj.mStorage->getType() == typeid( T ) )
  {
    return static_cast<any::StorageIml<T>*>( std::move( obj.mStorage ) )->mValue;
  }
  else
  {
    throw bad_cast();
  }
}

template<class T>
const T* any_cast( const any* obj )
{
  if( obj->mStorage->getType() == typeid( T ) )
  {
    return &static_cast<any::StorageIml<T>*>( obj->mStorage )->mValue;
  }
  else
  {
    return nullptr;
  }
}

template<class T>
T* any_cast( any* obj )
{
  if( obj->mStorage->getType() == typeid( T ) )
  {
    return &static_cast<any::StorageIml<T>*>( obj->mStorage )->mValue;
  }
  else
  {
    return nullptr;
  }
}
} // namespace mtl