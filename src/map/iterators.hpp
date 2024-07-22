#pragma once

#include "../s21_containers.h"

namespace s21 {
template <class Key, class T>
typename RedBlackTree<typename map<Key, T>::value_type>::Iterator
map<Key, T>::begin() {
  return tree.begin();
}

template <class Key, class T>
typename RedBlackTree<typename map<Key, T>::value_type>::Iterator
map<Key, T>::end() {
  return tree.end();
}

template <class Key, class T>
typename RedBlackTree<typename map<Key, T>::value_type>::ConstIterator
map<Key, T>::cbegin() {
  return tree.cbegin();
}

template <class Key, class T>
typename RedBlackTree<typename map<Key, T>::value_type>::ConstIterator
map<Key, T>::cend() {
  return tree.cend();
}
}  // namespace s21