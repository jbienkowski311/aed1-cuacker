#include "HashTable.hpp"
#include <cstdlib>
#include "Tweet.hpp"

//
// PUBLIC
//
void HashTable::insert(string key, Tweet* value) {
  int h = hash(key);

  table[h].insert(value);
}

void HashTable::find(string key, set<Tweet*, TweetComp>& values) {
  int h = hash(key);

  auto it = table[h].begin();
  while (it != table[h].end()) {
    if ((*it)->author == key) {
      values.insert(*it);
    }
    it++;
  }
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