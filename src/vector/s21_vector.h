#ifndef CPP2_S21_CONTAINERS_1_VECTOR_H
#define CPP2_S21_CONTAINERS_1_VECTOR_H

#include "../s21_containers.h"

namespace s21 {
template <typename T>
class vector {
 public:
  // member_types
  class Iterator;
  class ConstIterator;

  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = Iterator;
  using const_iterator = ConstIterator;
  using size_type = size_t;

  class Iterator {
   public:
    explicit Iterator(T* ptr) : m_ptr(ptr) {}
    T& operator*() const { return *m_ptr; }
    T* operator->() { return m_ptr; }

    Iterator& operator++() {
      ++m_ptr;
      return *this;
    }
    Iterator operator++(int) {
      Iterator temp = *this;
      ++(*this);
      return temp;
    }
    bool operator==(const Iterator& other) const {
      return m_ptr == other.m_ptr;
    }
    bool operator!=(const Iterator& other) const {
      return m_ptr != other.m_ptr;
    }

    Iterator& operator+=(int offset) {
      m_ptr += offset;
      return *this;
    }

    Iterator operator+(int offset) const { return Iterator(m_ptr + offset); }

    Iterator& operator-=(int offset) {
      m_ptr -= offset;
      return *this;
    }

    Iterator operator-(int offset) const { return Iterator(m_ptr - offset); }

    std::ptrdiff_t operator-(const Iterator& other) const {
      return m_ptr - other.m_ptr;
    }

   private:
    T* m_ptr;
  };

  class ConstIterator {};

  // functions
  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<value_type> const& items);
  vector(const vector& v);
  vector(vector&& v) noexcept;
  ~vector();

  // operator
  vector& operator=(vector&& v) noexcept;

  // element_access
  reference operator[](size_type pos);
  reference at(size_type pos);
  const_reference front() const;
  const_reference back() const;
  iterator data();

  // capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  // iterators
  iterator begin() const;
  iterator end() const;
  const_iterator cbegin() const;
  const_iterator cend() const;

  // modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  iterator insertt(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector& other);

  // additional
  void filling();

 private:
  void resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
      new_data[i] = begin_[i];
    }
    delete[] begin_;
    begin_ = new_data;
    capacity_ = new_capacity;
  }

  T* begin_ = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;

  void reallocator();
};
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_1_VECTOR_H
