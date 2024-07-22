#pragma once

#include <iostream>
#include <limits>
#include <memory>

#define RED 0
#define BLACK 1
#define NIL nullptr

template <typename T>
class Node {
 public:
  T key;
  bool color;
  Node<T>*left, *right, *parent;

  explicit Node(T key)
      : key(key), color(RED), left(NIL), right(NIL), parent(NIL) {}
};

template <class T>
class RedBlackTree {
 private:
  Node<T>* root;
  size_t sz = 0;

 public:
  class Iterator;
  class ConstIterator;

  using key_type = T;
  using value_type = key_type;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator;
  using const_iterator = ConstIterator;
  using size_type = size_t;
  using difference_type = std::ptrdiff_t;

  class Iterator {
   public:
    Node<value_type>* current;
    explicit Iterator(Node<value_type>* root) : current(root) {
      if (current != NIL) {
        while (current->left != NIL) {
          current = current->left;
        }
      }
    }

    bool hasNext() { return current != NIL; }
    bool hasPrev() {
      return current != NIL && (current->left != NIL || current->parent != NIL);
    }
    T next() {
      if (!hasNext()) {
        throw std::out_of_range("Iterator out of range");
      }

      Node<value_type>* node = current;
      T result = node->key;

      if (current->right != NIL) {
        current = current->right;
        while (current->left != NIL) {
          current = current->left;
        }
      } else {
        Node<value_type>* parent = current->parent;
        while (parent != NIL && current == parent->right) {
          current = parent;
          parent = parent->parent;
        }
        current = parent;
      }

      return result;
    }
    T prev() {
      if (!hasPrev()) {
        throw std::out_of_range("Iterator out of range");
      }
      Node<T>* node = current;
      T result = node->key;
      decrement();

      return result;
    }

    Iterator operator++(int) {
      Iterator it = *this;
      increment();
      return it;
    }
    Iterator& operator++() {
      increment();
      return *this;
    }
    Iterator operator--(int) {
      Iterator it = *this;
      decrement();
      return it;
    }
    Iterator& operator--() {
      decrement();
      return *this;
    }
    reference operator*() {
      static value_type ans{};
      if (current == NIL) return ans;
      return current->key;
    }

    bool operator==(const Iterator& other) const {
      return current == other.current;
    }
    bool operator!=(const Iterator& other) const {
      return current != other.current;
    }

   private:
    void increment() {
      if (current->right != NIL) {
        current = current->right;
        while (current->left != NIL) {
          current = current->left;
        }
      } else {
        Node<value_type>* parent = current->parent;
        while (parent != NIL && current == parent->right) {
          current = parent;
          parent = parent->parent;
        }
        current = parent;
      }
    }
    void decrement() {
      if (current->left != NIL) {
        current = current->left;
        while (current->right != NIL) {
          current = current->right;
        }
      } else {
        Node<T>* parent = current->parent;
        while (parent != NIL && current == parent->left) {
          current = parent;
          parent = parent->parent;
        }
        current = parent;
      }
    }
  };
  class ConstIterator {
   public:
    Node<value_type>* current;
    explicit ConstIterator(Node<value_type>* root) : current(root) {
      if (current != NIL) {
        while (current->left != NIL) {
          current = current->left;
        }
      }
    }

    bool hasNext() const { return current != NIL; }
    bool hasPrev() const {
      return current != NIL && (current->left != NIL || current->parent != NIL);
    }
    T next() {
      if (!hasNext()) {
        throw std::out_of_range("Iterator out of range");
      }

      Node<value_type>* node = current;
      T result = node->key;

      if (current->right != NIL) {
        current = current->right;
        while (current->left != NIL) {
          current = current->left;
        }
      } else {
        Node<value_type>* parent = current->parent;
        while (parent != NIL && current == parent->right) {
          current = parent;
          parent = parent->parent;
        }
        current = parent;
      }

      return result;
    }
    T prev() {
      if (!hasPrev()) {
        throw std::out_of_range("Iterator out of range");
      }
      Node<T>* node = current;
      T result = node->key;
      decrement();

      return result;
    }

    ConstIterator operator++(int) {
      Iterator it = *this;
      increment();
      return it;
    }
    ConstIterator& operator++() {
      increment();
      return *this;
    }
    ConstIterator operator--(int) {
      Iterator it = *this;
      decrement();
      return it;
    }
    ConstIterator& operator--() {
      decrement();
      return *this;
    }
    const_reference operator*() const {
      if (current == NIL) throw std::out_of_range("Iterator out of range.\n");
      return current->key;
    }

    bool operator==(const ConstIterator& other) const {
      return current == other.current;
    }
    bool operator!=(const ConstIterator& other) const {
      return current != other.current;
    }

   private:
    void increment() {
      if (current->right != NIL) {
        current = current->right;
        while (current->left != NIL) {
          current = current->left;
        }
      } else {
        Node<value_type>* parent = current->parent;
        while (parent != NIL && current == parent->right) {
          current = parent;
          parent = parent->parent;
        }
        current = parent;
      }
    }
    void decrement() {
      if (current->left != NIL) {
        current = current->left;
        while (current->right != NIL) {
          current = current->right;
        }
      } else {
        Node<T>* parent = current->parent;
        while (parent != NIL && current == parent->left) {
          current = parent;
          parent = parent->parent;
        }
        current = parent;
      }
    }
  };

 public:
  RedBlackTree() : root(NIL) {}

  RedBlackTree(RedBlackTree&& other) noexcept {
    std::swap(root, other.root);
    std::swap(sz, other.sz);
    other.root = NIL;
    other.sz = 0;
  }

  ~RedBlackTree() { delete root; }

  void insert_fixup(Node<T>* node);
  virtual void insert_value(const_reference key);
  void transplant(Node<T>* u, Node<T>* v);
  void rb_delete(const_reference key);
  void rb_delete_fixup(Node<T>* node);
  void left_rotate(Node<T>* node);
  void right_rotate(Node<T>* node);

  void inorder(Node<T>* node);
  void preorder(Node<T>* node);
  void postorder(Node<T>* node);
  Node<T>* search(Node<T>* node, const_reference key);

  virtual Iterator find(const_reference key);
  Node<T>* minimum(Node<T>* node);
  Node<T>* maximum(Node<T>* node);
  Node<T>* successor(Node<T>* node);

  virtual void clear();
  virtual size_t size();
  Node<T>* getRoot();
  virtual bool empty();

  virtual Iterator begin() { return Iterator(root); }
  virtual Iterator end() { return Iterator(NIL); }
  virtual ConstIterator cbegin() const { return ConstIterator(root); }
  virtual ConstIterator cend() const { return ConstIterator(NIL); }

  size_type max_size() const {
    return std::numeric_limits<difference_type>::max() /
           sizeof(Node<value_type>);
  }

  void setNIL() {
    sz = 0;
    root = NIL;
  }
  void setSize(const size_t val) { sz = val; }

  RedBlackTree& operator=(const RedBlackTree& other) {
    if (this != &other) {
      for (auto it = other.cbegin(); it != other.cend(); ++it) {
        this->insert_value(*it);
      }
    }
    return *this;
  }

  void printTree(Node<T>* node, std::string indent, bool last);
  void printTree();
};

#include "delete.hpp"
#include "finders.hpp"
#include "getters.hpp"
#include "insert.hpp"
#include "printers.hpp"
#include "rotations.hpp"
#include "tree_walkers.hpp"