#ifndef _CLASS_TWEET_DICTIONARY
#define _CLASS_TWEET_DICTIONARY

#include <list>
#include <string>
#include <vector>
#include "AVL.hpp"
#include "HashTable.hpp"
#include "Tweet.hpp"

using namespace std;

class TweetDictionary {
 public:
  TweetDictionary();
  void insert(Tweet* tweet);
  void last(int n);
  void follow(string name);
  void date(Date start, Date end);

 private:
  int count;
  HashTable<string, Tweet*> tweetsHashTable;
  AVL<Date, Tweet*> tweetsAVL;
};
#endif