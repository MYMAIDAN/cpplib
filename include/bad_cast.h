#ifndef _BAD_CAST_H_
#define _BAD_CAST_H_

#include <exception>

namespace mtl
{
class bad_cast : public std::exception
{
public:
  bad_cast() noexcept {}

  bad_cast(const bad_cast&)noexcept{}

  bad_cast& operator=(const bad_cast&)noexcept{}

  virtual const char* what() const noexcept 
  {
    return "Bad Dynamic Cast";
  }
};
} // namespace mtl
#endif // _BAD_CAST_H_