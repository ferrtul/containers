#pragma once

#include "../s21_containers.h"

namespace s21 {

template <class Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const_reference value) {
  bool answer = false;
  if (tree.search(tree.getRoot(), value)) {
    return {tree.find(value), answer};
  }
  tree.insert_value(value);
  answer = true;
  return {tree.find(value), answer};
}

template <class Key>
void set<Key>::clear() {
  if (!tree.empty()) tree.clear();
}

template <class Key>
void set<Key>::erase(set<Key>::iterator pos) {
  if (pos != end()) tree.rb_delete(pos.current->key);
}

template <class Key>
void set<Key>::swap(set& other) {
  std::swap(tree, other.tree);
}

template <class Key>
void set<Key>::merge(set& other) {
  for (auto it = other.begin(); it != other.end(); ++it) insert(*it);
  other.clear();
}

}  // namespace s21