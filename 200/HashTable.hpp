#ifndef _CLASS_HASH_TABLE
#define _CLASS_HASH_TABLE

#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

const int HASH_TABLE = 379;

template <class TK, class TV>
class HashTable {
 public:
  HashTable();
  ~HashTable();
  void insert(TK key, TV value);
  list<TV> find(TK key);

 private:
  map<int, list<TV>> table;
  int hash(TK key);
};
#endif