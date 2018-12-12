#ifndef _CLASS_HASH_TABLE
#define _CLASS_HASH_TABLE

#include <array>
#include <iostream>
#include <set>
#include <string>
#include "Tweet.hpp"

using namespace std;

const int HASH_TABLE = 6379;

class HashTable {
 public:
  void insert(string key, Tweet* value);
  void find(string key, set<Tweet*, TweetComp>& values);

 private:
  array<set<Tweet*, TweetComp>, HASH_TABLE> table;
  int hash(string key);
};
#endif