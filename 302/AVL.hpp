#ifndef _CLASS_AVL
#define _CLASS_AVL

#include <algorithm>
#include <cstddef>
#include <list>
#include "Date.hpp"
#include "Tweet.hpp"

using namespace std;

struct Node {
  int balance;
  Date key;
  list<Tweet*> values;
  Node* left;
  Node* right;
  Node* parent;

  bool has(const Tweet* const& value) {
    return find_if(values.begin(), values.end(),
                   [value](const Tweet* const& t) { return *value == *t; }) !=
           values.end();
  }
};

class AVL {
 public:
  AVL() : root(NULL){};
  ~AVL() { delete root; };
  void insert(Date key, Tweet* value);
  void last(list<Tweet*>& values, int limit);
  void between(list<Tweet*>& values, Date start, Date end);

 private:
  Node* root;

  void insert(Node* n, Date key, Tweet* value);
  void last(Node* n, list<Tweet*>& values, int limit);
  void between(Node* n, list<Tweet*>& values, Date start, Date end);
  Node* newNode(Date key, Tweet* value);
  Node* newNode(Date key, Tweet* value, Node* parent);
  void rebalance(Node* n);
  int height(Node* n);
  void setBalance(Node* n);
  void clearNode(Node* n);
  Node* rotateLeft(Node* n);
  Node* rotateRight(Node* n);
  Node* rotateDoubleLeft(Node* n);
  Node* rotateDoubleRight(Node* n);
};
#endif