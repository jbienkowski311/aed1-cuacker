#include "HashTable.hpp"
#include <cmath>
#include "Tweet.hpp"

//
// PUBLIC
//
template <class TK, class TV>
HashTable<TK, TV>::HashTable() {
  table.clear();
}

template <class TK, class TV>
HashTable<TK, TV>::~HashTable() {}

template <class TK, class TV>
void HashTable<TK, TV>::insert(TK key, TV value) {
  int h = hash(key);
  // TK h = key;

  typename list<TV>::iterator it = table[h].begin();
  while (it != table[h].end() && (*it) < value) {
    it++;
  }
  table[h].insert(it, value);
}

template <class TK, class TV>
list<TV> HashTable<TK, TV>::find(TK key) {
  int h = hash(key);
  // TK h = key;

  return table[h];
}

//
// PRIVATE
//
template <class TK, class TV>
int HashTable<TK, TV>::hash(TK key) {
  int h = 0;
  int i = 4;

  for (auto k : key) {
    h += 61 * int(k) + 37 * int(k) * (2 << i++);
  }

  return h % HASH_TABLE;
}

template class HashTable<string, Tweet *>;