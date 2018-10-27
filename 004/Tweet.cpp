#include "Tweet.hpp"

Tweet::Tweet(const Date &published, const string &author, const string &message)
    : published(published), author(author), message(message) {}

bool Tweet::isMcuac(string type) { return type == "mcuac"; }

bool Tweet::isPcuac(string type) { return type == "pcuac"; }

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