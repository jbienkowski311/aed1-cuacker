#include "Tweet.hpp"

Tweet::Tweet(const Date &published, const string &author, const string &message)
    : published(published), author(author), message(message) {}

bool Tweet::operator<(const Tweet &t) {
  if (published == t.published) {
    if (message == t.message) {
      return author > t.author;
    }

    return message > t.message;
  }

  return published < t.published;
}

bool Tweet::operator<(const Tweet &t) const {
  if (published == t.published) {
    if (message == t.message) {
      return author > t.author;
    }

    return message > t.message;
  }

  return published < t.published;
}

bool Tweet::operator>(const Tweet &t) {
  if (published == t.published) {
    if (message == t.message) {
      return author < t.author;
    }

    return message < t.message;
  }

  return published > t.published;
}

bool Tweet::operator>(const Tweet &t) const {
  if (published == t.published) {
    if (message == t.message) {
      return author < t.author;
    }

    return message < t.message;
  }

  return published > t.published;
}

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