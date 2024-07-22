#pragma once

#include "../s21_containers.h"

namespace s21 {
template <class T>
set<T>::set(
    std::initializer_list<typename s21::set<T>::value_type> const& items) {
  for (const auto& elem : items) insert(elem);
}

template <class T>
set<T>::set(const set& s) {
  tree = s.tree;
}

template <class T>
set<T>::~set() {
  clear();
}
}  // namespace s21