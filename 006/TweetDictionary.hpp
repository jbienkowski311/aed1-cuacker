#ifndef _CLASS_TWEET_DICTIONARY
#define _CLASS_TWEET_DICTIONARY

#include <list>
#include <string>
#include <vector>
#include "Tweet.hpp"

using namespace std;

class TweetDictionary {
 public:
  TweetDictionary();
  int count();
  void insert(Tweet* tweet);
  void last(int n);
  void follow(string name);
  void date(Date start, Date end);

 private:
  list<Tweet*> tweets;
};
#endif