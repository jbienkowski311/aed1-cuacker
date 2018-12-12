#include "HashTable.hpp"
#include <cstdlib>
#include "Tweet.hpp"

//
// PUBLIC
//
void HashTable::insert(string key, Tweet* value) {
  int h = hash(key);

  list<Tweet*>::iterator it = table[h].begin();
  while (it != table[h].end() && (*it) > value) {
    it++;
  }
  table[h].insert(it, value);
}

void HashTable::find(string key, list<Tweet*>& values) {
  int h = hash(key);

  values = table[h];
}

//
// PRIVATE
//
int HashTable::hash(string key) {
  int h = 0;
  int i = 1;

  for (auto k : key) {
    h += 23 * int(k) + 11 * int(k) * (2 << i++);
  }

  return abs(h % HASH_TABLE);
}