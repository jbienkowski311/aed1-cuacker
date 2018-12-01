#include "Date.hpp"

Date::Date() : D(0), M(0), Y(0), h(0), m(0), s(0) {}
Date::Date(int D, int M, int Y, int h, int m, int s)
    : D(D), M(M), Y(Y), h(h), m(m), s(s) {}

Date &Date::operator=(const Date &d) {
  D = d.D;
  M = d.M;
  Y = d.Y;
  h = d.h;
  m = d.m;
  s = d.s;
  return *this;
}

bool Date::operator<(const Date &d) {
  double diff = difftime(toCTime(), d.toCTime());
  return diff < 0.0;
}

bool Date::operator<(const Date &d) const {
  double diff = difftime(toCTime(), d.toCTime());
  return diff < 0.0;
}

bool Date::operator>(const Date &d) {
  double diff = difftime(toCTime(), d.toCTime());
  return diff > 0.0;
}

bool Date::operator>(const Date &d) const {
  double diff = difftime(toCTime(), d.toCTime());
  return diff > 0.0;
}

bool Date::operator==(const Date &d) {
  double diff = difftime(toCTime(), d.toCTime());
  return diff == 0.0;
}

bool Date::operator==(const Date &d) const {
  double diff = difftime(toCTime(), d.toCTime());
  return diff == 0.0;
}

time_t Date::toCTime() const {
  struct tm _tm = {0};
  _tm.tm_year = Y - 1900;
  _tm.tm_mon = M;
  _tm.tm_mday = D;
  _tm.tm_hour = h;
  _tm.tm_min = m;
  _tm.tm_sec = s;

  return mktime(&_tm);
}

ostream &operator<<(ostream &os, const Date &d) {
  os << d.D << "/" << d.M << "/" << d.Y << " " << (d.h < 10 ? "0" : "") << d.h
     << ":" << (d.m < 10 ? "0" : "") << d.m << ":" << (d.s < 10 ? "0" : "")
     << d.s;
  return os;
}
