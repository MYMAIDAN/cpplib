#ifndef _BAD_CAST_H_
#define _BAD_CAST_H_

#include <exception>

namespace mtl
{
class bad_cast : public std::exception
{
public:
  bad_cast(){}

  bad_cast(const bad_cast&){}

  bad_cast& operator=(const bad_cast&) {}

  virtual const char* what() const _NOEXCEPT 
  {
    return "Bad Dynamic Cast";
  }
};
} // namespace mtl
#endif // _BAD_CAST_H_