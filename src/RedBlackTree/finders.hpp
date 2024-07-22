#pragma once

template <class T>
Node<T>* RedBlackTree<T>::search(Node<T>* node, const_reference key) {
  if (node == NIL) {
    return NIL;
  } else if (key == node->key) {
    return node;
  }
  if (key < node->key) {
    return search(node->left, key);
  } else
    return search(node->right, key);
}

template <class T>
typename RedBlackTree<T>::Iterator RedBlackTree<T>::find(const_reference key) {
  Node<T>* current = root;
  while (current != NIL) {
    if (key == current->key) {
      return Iterator(current);
    } else if (key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return end();
}

template <class T>
Node<T>* RedBlackTree<T>::minimum(Node<T>* node) {
  while (node->left != NIL) {
    node = node->left;
  }
  return node;
}

template <class T>
Node<T>* RedBlackTree<T>::maximum(Node<T>* node) {
  while (node->right != NIL) {
    node = node->right;
  }
  return node;
}

template <class T>
Node<T>* RedBlackTree<T>::successor(Node<T>* node) {
  if (node->right != NIL) {
    return minimum(node->right);
  }
  auto* y = node->parent;
  while (y != NIL && node == y->right) {
    node = y;
    y = y->parent;
  }
}
