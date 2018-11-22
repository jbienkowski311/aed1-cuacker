#include "Tweet.hpp"

Tweet::Tweet(const Date &published, const string &author, const string &message)
    : published(published), author(author), message(message) {}

ostream &operator<<(ostream &os, const Tweet &t) {
  os << t.author << " " << t.published << endl;
  os << "   " << t.message;
  return os;
}

ostream &operator<<(ostream &os, const Tweet *t) {
  os << t->author << " " << t->published << endl;
  os << "   " << t->message;
  return os;
}