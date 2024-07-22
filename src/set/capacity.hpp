#pragma once

#include "../s21_containers.h"

namespace s21 {
template <class Key>
bool s21::set<Key>::empty() {
  return tree.empty();
}

template <class Key>
std::size_t s21::set<Key>::size() {
  return tree.size();
}

template <class Key>
typename set<Key>::size_type set<Key>::max_size() {
  return set<Key>::tree.max_size();
}
}  // namespace s21