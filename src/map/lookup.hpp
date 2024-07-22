#pragma once

#include "../s21_containers.h"

namespace s21 {
template <class Key, class T>
bool map<Key, T>::contains(const Key& key) {
  Node<typename map<Key, T>::value_type>* current = tree.getRoot();
  while (current != NIL) {
    if (key == current->key.first) {
      return true;
    } else if (key < current->key.first) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return false;
}

template <class Key, class T>
typename map<Key, T>::iterator map<Key, T>::find_map(const_reference key) {
  Node<value_type>* current = tree.getRoot();
  while (current != NIL) {
    if (key == current->key) {
      return typename RedBlackTree<value_type>::Iterator(current);
    } else if (key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return end();
}

template <class Key, class T>
typename map<Key, T>::iterator map<Key, T>::find_key(const Key& key) {
  Node<value_type>* current = tree.getRoot();
  while (current != NIL) {
    if (key == current->key.first) {
      return typename RedBlackTree<value_type>::Iterator(current);
    } else if (key < current->key.first) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return end();
}
}  // namespace s21