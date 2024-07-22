#pragma once

template <class T>
void RedBlackTree<T>::insert_fixup(Node<T>* node) {
  while (node != root && node->parent->color == RED) {
    if (node->parent == node->parent->parent->left) {
      Node<T>* y = node->parent->parent->right;
      if (y != nullptr && y->color == RED) {
        node->parent->color = BLACK;
        y->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      } else {
        if (node == node->parent->right) {
          node = node->parent;
          left_rotate(node);
        }
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        right_rotate(node->parent->parent);
      }
    } else {
      Node<T>* y = node->parent->parent->left;
      if (y != nullptr && y->color == RED) {
        node->parent->color = BLACK;
        y->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      } else {
        if (node == node->parent->left) {
          node = node->parent;
          right_rotate(node);
        }
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        left_rotate(node->parent->parent);
      }
    }
  }
  root->color = BLACK;
}

template <class T>
void RedBlackTree<T>::insert_value(const_reference key) {
  auto* node = new Node<T>(key);

  if (root == NIL) {
    root = node;
    node->color = BLACK;
  } else {
    Node<T>* current = root;
    Node<T>* parent = NIL;

    while (current != NIL) {
      parent = current;
      if (node->key < current->key) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    node->parent = parent;
    if (node->key < parent->key) {
      parent->left = node;
    } else {
      parent->right = node;
    }

    insert_fixup(node);
  }
  this->sz += 1;
}