#include "TweetDictionary.hpp"
#include <algorithm>

TweetDictionary::TweetDictionary() {
  count = 0;
  tweetsAVL = AVL<Date, Tweet*>();
}

void TweetDictionary::insert(Tweet* tweet) {
  tweetsAVL.insert(tweet->published, tweet);
  count++;
  cout << count << " cuac" << endl;
}

void TweetDictionary::last(int n) {
  int i = 0;
  list<Tweet*> lastTweets = list<Tweet*>();

  tweetsAVL.last(tweetsAVL.getRoot(), lastTweets, n);
  lastTweets.sort([](const Tweet* const& a, const Tweet* const& b) -> bool {
    return *a > *b;
  });

  cout << "last " << n << endl;
  for (Tweet* t : lastTweets) {
    cout << ++i << ". " << t << endl;
  }
  cout << "Total: " << i << " cuac" << endl;
}

void TweetDictionary::follow(string name) {
  // 200
}

void TweetDictionary::date(Date start, Date end) {
  // 301
}