#include "AVL.hpp"

//
// PUBLIC
//
void AVL::insert(const Date &key, Tweet *value) {
  if (root == NULL) {
    root = newNode(key, value);
    return;
  }

  insert(root, key, value);
}

void AVL::last(int limit, set<Tweet *, TweetComp> &values) {
  if (root == NULL) {
    return;
  }

  last(root, limit, values);
}

void AVL::between(const Date &start, const Date &end,
                  set<Tweet *, TweetComp> &values) {
  if (root == NULL) {
    return;
  }

  between(root, start, end, values);
}

//
// PRIVATE
//
void AVL::insert(Node *n, const Date &key, Tweet *value) {
  if (n->key > key) {
    if (n->left != NULL) {
      insert(n->left, key, value);
    } else {
      n->left = newNode(key, value, n);
      rebalance(n);
    }
  } else if (n->key == key) {
    n->values.insert(value);
  } else {
    if (n->right != NULL) {
      insert(n->right, key, value);
    } else {
      n->right = newNode(key, value, n);
      rebalance(n);
    }
  }
}

void AVL::last(Node *n, int limit, set<Tweet *, TweetComp> &values) {
  if ((int)values.size() == limit) {
    return;
  }

  if (n->right != NULL) {
    last(n->right, limit, values);
  }

  auto it = n->values.begin();
  while (it != n->values.end() && (int)values.size() < limit) {
    values.insert(*it);
    it++;
  }

  if (n->left != NULL) {
    last(n->left, limit, values);
  }
}

void AVL::between(Node *n, const Date &start, const Date &end,
                  set<Tweet *, TweetComp> &values) {
  if (n->right != NULL) {
    between(n->right, start, end, values);
  }

  if (n->key >= start && n->key <= end) {
    auto it = n->values.begin();
    while (it != n->values.end()) {
      values.insert(*it);
      it++;
    }
  }

  if (n->left != NULL) {
    between(n->left, start, end, values);
  }
}

Node *AVL::newNode(const Date &key, Tweet *value) {
  Node *node = new Node();
  node->key = key;
  node->values.insert(value);
  return node;
}

Node *AVL::newNode(const Date &key, Tweet *value, Node *parent) {
  Node *node = newNode(key, value);
  node->parent = parent;
  return node;
}

void AVL::rebalance(Node *n) {
  setBalance(n);

  switch (n->balance) {
    case 0:
      if (n->parent == NULL) {
        root = n;
      }
      return;
    case -2:
      if (height(n->left->left) >= height(n->left->right)) {
        n = rotateRight(n);
      } else {
        n = rotateDoubleLeft(n);
      }
      break;
    case 2:
      if (height(n->right->right) >= height(n->right->left)) {
        n = rotateLeft(n);
      } else {
        n = rotateDoubleRight(n);
      }
      break;
    case 1:
    case -1:
      if (n->parent != NULL) {
        rebalance(n->parent);
      }
      break;
  }

  if (n->parent == NULL) {
    root = n;
  }
}

Node *AVL::rotateLeft(Node *a) {
  Node *b = a->right;
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

Node *AVL::rotateRight(Node *a) {
  Node *b = a->left;
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

Node *AVL::rotateDoubleLeft(Node *n) {
  n->left = rotateLeft(n->left);
  return rotateRight(n);
}

Node *AVL::rotateDoubleRight(Node *n) {
  n->right = rotateRight(n->right);
  return rotateLeft(n);
}

int AVL::height(Node *n) {
  if (n == NULL) return -1;
  return 1 + max(height(n->left), height(n->right));
}

void AVL::setBalance(Node *n) {
  n->balance = height(n->right) - height(n->left);
}
