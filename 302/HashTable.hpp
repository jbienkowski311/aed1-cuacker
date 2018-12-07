#ifndef _CLASS_HASH_TABLE
#define _CLASS_HASH_TABLE

#include <array>
#include <iostream>
#include <list>
#include <string>
#include "Tweet.hpp"

using namespace std;

const int HASH_TABLE = 6379;

class HashTable {
 public:
  void insert(string key, Tweet* value);
  list<Tweet*> find(string key);

 private:
  array<list<Tweet*>, HASH_TABLE> table;
  int hash(string key);
};
#endif