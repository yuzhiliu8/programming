#pragma once

namespace yliu
{

template <typename T>
class vector
{
public:
  vector();

private:
  T* buffer_;
};

}  // namespace yliu
