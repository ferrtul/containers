#pragma once

#include "../s21_containers.h"

namespace s21 {

template <class Key, class T>
void map<Key, T>::clear() {
  tree.clear();
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    map<Key, T>::const_reference value) {
  if (contains(value.first)) return std::make_pair(find_map(value), false);
  tree.insert_value(value);
  auto k = find_map(value);
  return {find_map(value), true};
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  if (contains(key) &&
      find_map(std::make_pair(key, obj)).current->key.second == obj)
    return std::make_pair(find_map(std::make_pair(key, obj)), false);
  return insert(std::make_pair(key, obj));
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  auto tmp = find_key(key);
  tmp.current->key.second = obj;
  return {tmp, true};
}

template <class Key, class T>
void map<Key, T>::erase(typename map<Key, T>::iterator pos) {
  tree.rb_delete(*pos);
}

template <class Key, class T>
void map<Key, T>::swap(map& other) {
  auto tsz = tree.size();
  auto osz = other.tree.size();
  std::swap(tree, other.tree);
  other.tree.setSize(tsz);
  tree.setSize(osz);
}

template <class Key, class T>
void map<Key, T>::merge(map& other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    auto res = insert(*it);
    if (res.second == true) other.erase(it);
  }
}

}  // namespace s21