#pragma once

template <class T>
void RedBlackTree<T>::inorder(Node<T>* node) {
  if (node != NIL) {
    inorder(node->left);
    std::cout << node->key << std::endl;
    inorder(node->right);
  }
}

template <class T>
void RedBlackTree<T>::preorder(Node<T>* node) {
  if (node != NIL) {
    std::cout << node->key << std::endl;
    inorder(node->left);
    inorder(node->right);
  }
}

template <class T>
void RedBlackTree<T>::postorder(Node<T>* node) {
  if (node != NIL) {
    inorder(node->left);
    inorder(node->right);
    std::cout << node->key << std::endl;
  }
}
