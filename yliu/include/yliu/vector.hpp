#pragma once

#include <cstddef>
#include <stdexcept>
#include <string>

static constexpr int DEFAULT_CAP = 2;
static constexpr int INCREASE_CAP_FACTOR = 2;


namespace yliu
{

template <typename T>
class vector
{
public:
  // standard constructors
  vector()
    : buffer_(nullptr), size_(0), capacity_(0)
  {
  }

  vector(std::size_t start_size)
  {
    // ::operator new() allocates raw memory without default construction
    buffer_ = static_cast<T*>(::operator new(sizeof(T) * start_size));
    size_ = start_size;
    capacity_ = start_size;
  }

  // copy constructor
  vector(const vector<T>& other);
  // move constructor. "Steals" resources from other
  vector(vector<T>&& other);

  // destructor
  ~vector()
  {
    clear();
    ::operator delete(buffer_);
  }

  // ACCESS

  // non const gives direct reference
  T& operator[] (int index)
  {
    if (index < 0 || index >= size_) {
      throw std::out_of_range("Array index out of bounds");
    }

    return static_cast<T&>(buffer_[index]);
  }

  // const gives const reference
  const T& operator[] (int index) const
  {
    if (index < 0 || index >= size_) {
      throw std::out_of_range("Array index out of bounds");
    }

    return static_cast<const T&>(buffer_[index]);
  }


  // lvalue overload
  void push_back(const T& element)
  {
    if (size_ == capacity_) {
      increase_capacity();
    }

    // copy construction at exact memory address buffer_ + size_
    new (buffer_ + size_) T(element);
    ++size_;
  }

  // rvalue overload here
  void push_back(T&& element)
  {
    if (size_ == capacity_) {
      increase_capacity();
    }

    // move construction at exact memory address buffer_ + size_
    new (buffer_ + size_) T(std::move(element));
    ++size_;
  }

  // emplace_back
  void clear()
  {
    // don't free any memory
    for (int i = 0; i < size_; ++i) {
      buffer_[i].~T();
    }
    size_ = 0;
  }


  std::size_t size() const
  {
    return size_;
  }

  std::size_t capacity() const
  {
    return capacity_;
  }

  bool empty() const
  {
    return size_ == 0;
  }

private:
  T* buffer_; // start of vector
  std::size_t size_; // back of vector
  std::size_t capacity_; // size of allocated buffer

  // doubles the capacity and moves all elements into new buffer
  void increase_capacity()
  {
    // calculate new_cap
    std::size_t new_cap = (capacity_ == 0) ? DEFAULT_CAP : capacity_ * INCREASE_CAP_FACTOR;

    T* new_buf = static_cast<T*>(::operator new(sizeof(T) * new_cap));
    // move old into new buffer
    for (std::size_t i = 0; i < size_; ++i) {
      new_buf[i] = buffer_[i];
    }

    ::operator delete(buffer_);

    buffer_ = new_buf;
    capacity_ = new_cap;
  }
};

}  // namespace yliu
