#pragma once

#include "../s21_containers.h"

namespace s21 {
template <class Key>
bool s21::set<Key>::contains(const Key &key) {
  if (tree.search(tree.getRoot(), key) != NIL) return true;
  return false;
}
}  // namespace s21