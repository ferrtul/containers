#pragma once

#include "../RedBlackTree/rbt.hpp"
#include "../s21_containers.h"

namespace s21 {
template <typename Key>
class set : public RedBlackTree<Key> {
 private:
  RedBlackTree<Key> tree{};

 public:
  using key_type = Key;
  using value_type = key_type;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;
  using iterator = typename RedBlackTree<Key>::Iterator;
  using const_iterator = typename RedBlackTree<Key>::ConstIterator;
  using difference_type = std::ptrdiff_t;

 public:
  set() = default;
  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set(set&& s) noexcept {
    auto tmp(s);
    s.clear();
    std::swap(tree, tmp.tree);
    s.tree.setNIL();
  }
  set& operator=(set&& s) noexcept {
    std::move(this, s);
    return *this;
  }
  ~set();

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos);
  void swap(set& other);
  void merge(set& other);

  bool contains(const Key& key);
};
};  // namespace s21

#include "capacity.hpp"
#include "iterators.hpp"
#include "lookup.hpp"
#include "member_functions.hpp"
#include "modifiers.hpp"
