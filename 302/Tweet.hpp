#ifndef _CLASS_TWEET
#define _CLASS_TWEET

#include <iostream>
#include <string>
#include "Date.hpp"

using namespace std;

class Tweet {
 public:
  Date published;
  string author, message;

  Tweet(const Date &published, const string &author, const string &message);

  bool operator<(const Tweet &t);
  bool operator<(const Tweet &t) const;
  bool operator>(const Tweet &t);
  bool operator>(const Tweet &t) const;
  bool operator==(const Tweet &t);
  bool operator==(const Tweet &t) const;
  bool operator>=(const Tweet &t);
  bool operator>=(const Tweet &t) const;
  friend ostream &operator<<(ostream &os, const Tweet &t);
  friend ostream &operator<<(ostream &os, const Tweet *t);
};
#endif