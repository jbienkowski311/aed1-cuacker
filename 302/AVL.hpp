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
};

class AVL {
 public:
  AVL() : root(NULL){};
  ~AVL() { delete root; };
  void insert(Date key, Tweet* value);
  void last(int limit, list<Tweet*>& values);
  void between(const Date& start, const Date& end, list<Tweet*>& values);

 private:
  Node* root;

  void insert(Node* n, const Date& key, Tweet* value);
  void last(Node* n, int limit, list<Tweet*>& values);
  void between(Node* n, const Date& start, const Date& end,
               list<Tweet*>& values);
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