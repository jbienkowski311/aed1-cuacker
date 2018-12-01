#include "AVL.hpp"
#include <algorithm>
#include "Date.hpp"
#include "Tweet.hpp"

//
// PUBLIC
//
template <class TK, class TV>
bool AVL<TK, TV>::insert(TK key, TV value) {
  if (root == NULL) {
    root = new Node<TK, TV>();
    root->key = key;
    root->values.clear();
    root->values.push_back(value);
    root->values.sort([](const TV &a, const TV &b) -> bool { return a > b; });
  } else {
    bool goLeft;
    Node<TK, TV> *n = root, *parent;

    while (n != NULL) {
      if (n->key == key && (find(n->values.begin(), n->values.end(), value) !=
                            n->values.end())) {
        return false;
      }

      parent = n;

      goLeft = n->key > key;
      n = goLeft ? n->left : n->right;
    }

    if (goLeft) {
      parent->left = new Node<TK, TV>();
      parent->left->key = key;
      parent->left->parent = parent;
      parent->left->values.clear();
      parent->left->values.push_back(value);
      parent->left->values.sort(
          [](const TV &a, const TV &b) -> bool { return a > b; });
    } else {
      parent->right = new Node<TK, TV>();
      parent->right->key = key;
      parent->right->parent = parent;
      parent->right->values.clear();
      parent->right->values.push_back(value);
      parent->right->values.sort(
          [](const TV &a, const TV &b) -> bool { return a > b; });
    }

    rebalance(parent);
  }

  return true;
}

template <class TK, class TV>
void AVL<TK, TV>::last(Node<TK, TV> *n, list<TV> &values, int limit) {
  if ((int)values.size() == limit) {
    return;
  }
  if (n == NULL) {
    return;
  }

  last(n->right, values, limit);

  typename list<TV>::iterator it = n->values.begin();
  while (it != n->values.end() && (int)values.size() < limit) {
    values.push_back(*it);
    it++;
  }

  last(n->left, values, limit);
}

template <class TK, class TV>
Node<TK, TV> *AVL<TK, TV>::getRoot() {
  return root;
}

//
// PRIVATE
//
template <class TK, class TV>
void AVL<TK, TV>::rebalance(Node<TK, TV> *n) {
  setBalance(n);

  if (n->balance == -2) {
    if (height(n->left->left) >= height(n->left->right)) {
      n = rotateRight(n);
    } else {
      n = rotateDoubleLeft(n);
    }
  } else if (n->balance == 2) {
    if (height(n->right->right) >= height(n->right->left)) {
      n = rotateLeft(n);
    } else {
      n = rotateDoubleRight(n);
    }
  }

  if (n->parent != NULL) {
    rebalance(n->parent);
  } else {
    root = n;
  }
}

template <class TK, class TV>
Node<TK, TV> *AVL<TK, TV>::rotateLeft(Node<TK, TV> *a) {
  Node<TK, TV> *b = a->right;
  b->parent = a->parent;
  a->right = b->left;

  if (a->right != NULL) a->right->parent = a;

  b->left = a;
  a->parent = b;

  if (b->parent != NULL) {
    if (b->parent->right == a) {
      b->parent->right = b;
    } else {
      b->parent->left = b;
    }
  }

  setBalance(a);
  setBalance(b);
  return b;
}

template <class TK, class TV>
Node<TK, TV> *AVL<TK, TV>::rotateRight(Node<TK, TV> *a) {
  Node<TK, TV> *b = a->left;
  b->parent = a->parent;
  a->left = b->right;

  if (a->left != NULL) a->left->parent = a;

  b->right = a;
  a->parent = b;

  if (b->parent != NULL) {
    if (b->parent->right == a) {
      b->parent->right = b;
    } else {
      b->parent->left = b;
    }
  }

  setBalance(a);
  setBalance(b);
  return b;
}

template <class TK, class TV>
Node<TK, TV> *AVL<TK, TV>::rotateDoubleLeft(Node<TK, TV> *n) {
  n->left = rotateLeft(n->left);
  return rotateRight(n);
}

template <class TK, class TV>
Node<TK, TV> *AVL<TK, TV>::rotateDoubleRight(Node<TK, TV> *n) {
  n->right = rotateRight(n->right);
  return rotateLeft(n);
}

template <class TK, class TV>
int AVL<TK, TV>::height(Node<TK, TV> *n) {
  if (n == NULL) return -1;
  return 1 + max(height(n->left), height(n->right));
}

template <class TK, class TV>
void AVL<TK, TV>::setBalance(Node<TK, TV> *n) {
  n->balance = height(n->right) - height(n->left);
}

template class AVL<Date, Tweet *>;