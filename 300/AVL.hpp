#ifndef _CLASS_AVL
#define _CLASS_AVL

#include <cstddef>
#include <list>

using namespace std;

template <class TK, class TV>
struct Node {
  int balance;
  TK key;
  list<TV> values;
  Node<TK, TV>* left;
  Node<TK, TV>* right;
  Node<TK, TV>* parent;
};

template <class TK, class TV>
class AVL {
 public:
  AVL() : root(NULL){};
  ~AVL() { delete root; };
  bool insert(TK key, TV value);
  void last(Node<TK, TV>* n, list<TV>& values, int limit);
  Node<TK, TV>* getRoot();

 private:
  Node<TK, TV>* root;

  Node<TK, TV>* newNode(TK key, TV value);
  Node<TK, TV>* newNode(TK key, TV value, Node<TK, TV>* parent);
  void rebalance(Node<TK, TV>* n);
  int height(Node<TK, TV>* n);
  void setBalance(Node<TK, TV>* n);
  void clearNode(Node<TK, TV>* n);
  Node<TK, TV>* rotateLeft(Node<TK, TV>* n);
  Node<TK, TV>* rotateRight(Node<TK, TV>* n);
  Node<TK, TV>* rotateDoubleLeft(Node<TK, TV>* n);
  Node<TK, TV>* rotateDoubleRight(Node<TK, TV>* n);
};
#endif