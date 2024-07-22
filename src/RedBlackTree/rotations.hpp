#pragma once

template <class T>
void RedBlackTree<T>::left_rotate(Node<T>* node) {
  Node<T>* y = node->right;
  node->right = y->left;

  if (y->left != NIL) {
    y->left->parent = node;
  }
  y->parent = node->parent;
  if (node->parent == NIL) {
    this->root = y;
  } else if (node == node->parent->left) {
    node->parent->left = y;
  } else {
    node->parent->right = y;
  }
  y->left = node;
  node->parent = y;
}

template <class T>
void RedBlackTree<T>::right_rotate(Node<T>* node) {
  Node<T>* y = node->left;
  node->left = y->right;

  if (y->right != NIL) {
    y->right->parent = node;
  }
  y->parent = node->parent;
  if (node->parent == NIL) {
    this->root = y;
  } else if (node == node->parent->right) {
    node->parent->right = y;
  } else {
    node->parent->left = y;
  }
  y->right = node;
  node->parent = y;
}