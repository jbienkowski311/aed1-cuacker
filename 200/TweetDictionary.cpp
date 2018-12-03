#include "TweetDictionary.hpp"
#include <algorithm>

TweetDictionary::TweetDictionary() {
  count = 0;
  tweetsHashTable = HashTable<string, Tweet*>();
  tweetsAVL = AVL<Date, Tweet*>();
}

void TweetDictionary::insert(Tweet* tweet) {
  tweetsHashTable.insert(tweet->author, tweet);
  tweetsAVL.insert(tweet->published, tweet);
  cout << ++count << " cuac" << endl;
}

void TweetDictionary::last(int n) {
  int i = 0;
  list<Tweet*> tweets = list<Tweet*>();

  tweetsAVL.last(tweetsAVL.getRoot(), tweets, n);
  tweets.sort([](const Tweet* const& a, const Tweet* const& b) -> bool {
    return *a > *b;
  });

  cout << "last " << n << endl;
  for (Tweet* t : tweets) {
    cout << ++i << ". " << t << endl;
  }
  cout << "Total: " << i << " cuac" << endl;
}

void TweetDictionary::follow(string name) {
  int i = 0;
  list<Tweet*> tweets = tweetsHashTable.find(name);
  auto it = remove_if(
      tweets.begin(), tweets.end(),
      [name](const Tweet* const& t) -> bool { return t->author != name; });
  tweets.erase(it, tweets.end());
  tweets.sort([](const Tweet* const& a, const Tweet* const& b) -> bool {
    return *a > *b;
  });

  cout << "follow " << name << endl;
  for (Tweet* t : tweets) {
    cout << ++i << ". " << t << endl;
  }
  cout << "Total: " << i << " cuac" << endl;
}

void TweetDictionary::date(Date start, Date end) {
  int i = 0;
  list<Tweet*> tweets = list<Tweet*>();

  tweetsAVL.between(tweetsAVL.getRoot(), tweets, start, end);
  tweets.sort([](const Tweet* const& a, const Tweet* const& b) -> bool {
    return *a > *b;
  });

  cout << "date " << start << " " << end << endl;
  for (Tweet* t : tweets) {
    cout << ++i << ". " << t << endl;
  }
  cout << "Total: " << i << " cuac" << endl;
}