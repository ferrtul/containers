#pragma once

template <class T>
size_t RedBlackTree<T>::size() {
  return this->sz;
}

template <class T>
Node<T>* RedBlackTree<T>::getRoot() {
  return root;
}

template <class T>
bool RedBlackTree<T>::empty() {
  return !this->size();
}