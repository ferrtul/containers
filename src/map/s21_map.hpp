#pragma once

#include "../RedBlackTree/rbt.hpp"

namespace s21 {
template <class Key, class T>
class map : RedBlackTree<std::pair<const Key, T>> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename RedBlackTree<value_type>::Iterator;
  using const_iterator = typename RedBlackTree<value_type>::ConstIterator;
  using size_type = std::size_t;

  map() = default;
  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m) noexcept;
  ~map();
  map& operator=(map&& m) noexcept;

  mapped_type& at(const key_type& key);
  mapped_type& operator[](const key_type& key);

  iterator begin();
  iterator end();
  const_iterator cbegin();
  const_iterator cend();

  bool empty();
  size_type size();
  size_type max_size();
  bool contains(const key_type& key);

  iterator find_map(const_reference key);
  iterator find_key(const Key& key);

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj);
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);

 private:
  RedBlackTree<value_type> tree{};
};
}  // namespace s21

#include "capacity.hpp"
#include "iterators.hpp"
#include "lookup.hpp"
#include "member_functions.hpp"
#include "modifiers.hpp"