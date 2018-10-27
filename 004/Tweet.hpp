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

  friend ostream &operator<<(ostream &os, const Tweet &t);
  friend ostream &operator<<(ostream &os, const Tweet *t);
  static bool isMcuac(string type);
  static bool isPcuac(string type);
};
#endif