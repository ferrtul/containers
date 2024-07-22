#pragma once

#include "../s21_containers.h"

namespace s21 {
template <class Key>
typename s21::set<Key>::iterator s21::set<Key>::begin() {
  return tree.RedBlackTree<Key>::begin();
}

template <class Key>
typename s21::set<Key>::iterator s21::set<Key>::end() {
  return tree.RedBlackTree<Key>::end();
}

template <class Key>
typename s21::set<Key>::const_iterator s21::set<Key>::cbegin() const {
  return tree.RedBlackTree<Key>::cbegin();
}

template <class Key>
typename s21::set<Key>::const_iterator s21::set<Key>::cend() const {
  return tree.RedBlackTree<Key>::cend();
}
}  // namespace s21