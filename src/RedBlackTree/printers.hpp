#pragma once

template <class T>
void RedBlackTree<T>::printTree(Node<T>* node, std::string indent, bool last) {
  if (node != NIL) {
    std::cout << indent;
    if (last) {
      std::cout << "R----";
      indent += "   ";
    } else {
      std::cout << "L----";
      indent += "|  ";
    }

    std::string sColor = node->color ? "BLACK" : "RED";
    std::cout << node->key << "(" << sColor << ")" << std::endl;
    printTree(node->left, indent, false);
    printTree(node->right, indent, true);
  }
}

template <class T>
void RedBlackTree<T>::printTree() {
  if (root) {
    printTree(root, "", true);
  }
}