#ifndef _CLASS_TWEET_DICTIONARY
#define _CLASS_TWEET_DICTIONARY

#include <string>
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
  void date(const Date& start, const Date& end);

 private:
  int count;
  HashTable tweetsHashTable;
  AVL tweetsAVL;
};
#endif