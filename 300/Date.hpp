#ifndef _CLASS_DATE
#define _CLASS_DATE

#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Date {
 public:
  int D, M, Y, h, m, s;

  Date();
  Date(int D, int M, int Y, int h, int m, int s);

  friend ostream &operator<<(ostream &os, const Date &d);
  Date &operator=(const Date &d);
  bool operator<(const Date &d);
  bool operator<(const Date &d) const;
  bool operator>(const Date &d);
  bool operator>(const Date &d) const;
  bool operator==(const Date &d);
  bool operator==(const Date &d) const;
  time_t toCTime() const;
};
#endif