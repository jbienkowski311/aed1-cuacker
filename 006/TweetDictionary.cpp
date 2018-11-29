#include "TweetDictionary.hpp"

TweetDictionary::TweetDictionary() { tweets.clear(); }

int TweetDictionary::count() { return (int)tweets.size(); }

void TweetDictionary::insert(Tweet* tweet) {
  tweets.push_back(tweet);
  tweets.sort([](const Tweet* const& a, const Tweet* const& b) -> bool {
    return *a > *b;
  });
  tweets.unique();
  cout << count() << " cuac" << endl;
}

void TweetDictionary::last(int n) {
  int i = 0;
  list<Tweet*>::iterator it = tweets.begin();
  list<Tweet*>::iterator finish;
  if (n > (int)tweets.size()) {
    finish = tweets.end();
  } else {
    finish = next(it, n);
  }

  cout << "last " << n << endl;
  while (it != finish) {
    cout << ++i << ". " << (*it) << endl;
    it++;
  }
  cout << "Total: " << i << " cuac" << endl;
}

void TweetDictionary::follow(string name) {
  int i = 0;

  cout << "follow " << name << endl;
  for (Tweet* t : tweets) {
    if (t->author == name) {
      cout << ++i << ". " << t << endl;
    }
  }
  cout << "Total: " << i << " cuac" << endl;
}

void TweetDictionary::date(Date start, Date end) {
  int i = 0;

  cout << "date " << start << " " << end << endl;
  for (Tweet* t : tweets) {
    if (t->published < start || t->published > end) {
      continue;
    }
    cout << ++i << ". " << t << endl;
  }
  cout << "Total: " << i << " cuac" << endl;
}