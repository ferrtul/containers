#pragma once

#include "../s21_containers.h"

namespace s21 {
template <class Key, class T>
map<Key, T>::map(std::initializer_list<value_type> const& items) {
  for (const auto& el : items) tree.insert_value(el);
}

template <class Key, class T>
map<Key, T>::map(const map& m) {
  for (auto it = m.tree.cbegin(); it != m.tree.cend(); ++it) insert(*it);
}

template <class Key, class T>
map<Key, T>::map(map&& m) noexcept {
  auto tmp(m);
  m.clear();
  std::swap(tree, tmp.tree);
  tree.setSize(tmp.tree.size());
}

template <class Key, class T>
map<Key, T>::~map() {
  clear();
}

template <class Key, class T>
map<Key, T>& map<Key, T>::operator=(map&& m) noexcept {
  std::move(this, m);
  return *this;
}

template <class Key, class T>
T& map<Key, T>::at(const Key& key) {
  auto it = find_key(key);
  if (it.current == NIL)
    throw std::out_of_range("Not found element with specified key.\n");
  return it.current->key.second;
}

template <class Key, class T>
T& map<Key, T>::operator[](const Key& key) {
  auto it = find_key(key);
  if (it.current == NIL) {
    auto pr = insert_or_assign(key, T());
    it = pr.first;
  }
  return it.current->key.second;
}
}  // namespace s21