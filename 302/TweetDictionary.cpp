#include "TweetDictionary.hpp"
#include <list>

TweetDictionary::TweetDictionary() : count(0) {}

void TweetDictionary::insert(Tweet* tweet) {
  tweetsHashTable.insert(tweet->author, tweet);
  tweetsAVL.insert(tweet->published, tweet);
  cout << ++count << " cuac" << endl;
}

void TweetDictionary::last(int n) {
  int i = 0;
  list<Tweet*> tweets;

  tweetsAVL.last(n, tweets);

  cout << "last " << n << endl;
  for (Tweet* t : tweets) {
    cout << ++i << ". " << t << endl;
  }
  cout << "Total: " << i << " cuac" << endl;
}

void TweetDictionary::follow(string name) {
  int i = 0;
  list<Tweet*> tweets;

  tweetsHashTable.find(name, tweets);

  cout << "follow " << name << endl;
  for (Tweet* t : tweets) {
    cout << ++i << ". " << t << endl;
  }
  cout << "Total: " << i << " cuac" << endl;
}

void TweetDictionary::date(const Date& start, const Date& end) {
  int i = 0;
  list<Tweet*> tweets;

  tweetsAVL.between(start, end, tweets);
  // tweets.sort([](const Tweet* const& a, const Tweet* const& b) -> bool {
  // return *a > *b;
  // });

  cout << "date " << start << " " << end << endl;
  for (Tweet* t : tweets) {
    cout << ++i << ". " << t << endl;
  }
  cout << "Total: " << i << " cuac" << endl;
}