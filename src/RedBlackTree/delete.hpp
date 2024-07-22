#pragma once

template <class T>
void RedBlackTree<T>::transplant(Node<T>* u, Node<T>* v) {
  if (u->parent == NIL) {
    root = v;
  } else if (u == u->parent->left) {
    u->parent->left = v;
  } else {
    u->parent->right = v;
  }
  if (v != NIL) v->parent = u->parent;
}

template <class T>
void RedBlackTree<T>::rb_delete(const_reference key) {
  auto* node = search(root, key);
  auto lol = node->key;
  if (node == NIL) return;
  auto* y = node;
  bool y_orig_color = y->color;
  Node<T>* x = NIL;
  if (node->left == NIL) {
    x = node->right;
    transplant(node, node->right);
  } else if (node->right == NIL) {
    x = node->left;
    transplant(node, node->left);
  } else {
    y = minimum(node->right);
    y_orig_color = y->color;
    x = y->right;
    if (y->parent == node) {
      x->parent = y;
    } else {
      if (x != nullptr) x->parent = y->parent;
      transplant(y, y->right);
      if (y->right != nullptr) y->right->parent = y;
      y->right = node->right;
      if (y->right != nullptr) y->right->parent = y;
    }
    transplant(node, y);
    y->left = node->left;
    if (y->left != NIL) y->left->parent = y;
    y->color = node->color;
  }

  if (y_orig_color == BLACK && x != NIL) {
    rb_delete_fixup(x);
  }

  delete node;
  --this->sz;
}

template <class T>
void RedBlackTree<T>::rb_delete_fixup(Node<T>* node) {
  while (node != root && node != NIL && node->color == BLACK) {
    if (node == node->parent->left) {
      auto* w = node->parent->right;
      if (w->color == RED) {
        w->color = BLACK;
        node->parent->color = RED;
        left_rotate(node->parent);
        w = node->parent->right;
      }
      if ((w->left == NIL || w->left->color == BLACK) &&
          (w->left == NIL || w->right->color == BLACK)) {
        w->color = RED;
        node = node->parent;
      } else {
        if (w->right == NIL || w->right->color == BLACK) {
          if (w->left != NIL) w->left->color = BLACK;
          w->color = RED;
          right_rotate(w);
          w = node->parent->right;
        }
        w->color = node->parent->color;
        node->parent->color = BLACK;
        if (w->right != NIL) w->right->color = BLACK;
        left_rotate(node->parent);
        node = root;
      }
    } else {
      auto* w = node->parent->left;
      if (w->color == RED) {
        w->color = BLACK;
        node->parent->color = RED;
        left_rotate(node->parent);
        w = node->parent->left;
      }
      if ((w->right == NIL || w->right->color == BLACK) &&
          (w->left == NIL || w->left->color == BLACK)) {
        w->color = RED;
        node = node->parent;
      } else {
        if (w->left == nullptr || w->left->color == BLACK) {
          if (w->right != nullptr) w->right->color = BLACK;
          w->color = RED;
          left_rotate(w);
          w = node->parent->left;
        }
        w->color = node->parent->color;
        node->parent->color = BLACK;
        if (w->left != nullptr) w->left->color = BLACK;
        right_rotate(node->parent);
        node = root;
      }
    }
  }
  if (node != NIL) node->color = BLACK;
}

template <class T>
void RedBlackTree<T>::clear() {
  while (this->root) {
    auto rm = minimum(this->root)->key;
    rb_delete(rm);
  }
}
