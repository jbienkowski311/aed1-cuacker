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

bool Date::operator<(const Date &d) { return toSeconds() < d.toSeconds(); }

bool Date::operator<(const Date &d) const {
  return toSeconds() < d.toSeconds();
}

bool Date::operator<=(const Date &d) { return toSeconds() <= d.toSeconds(); }

bool Date::operator<=(const Date &d) const {
  return toSeconds() <= d.toSeconds();
}

bool Date::operator>(const Date &d) { return toSeconds() > d.toSeconds(); }

bool Date::operator>(const Date &d) const {
  return toSeconds() > d.toSeconds();
}

bool Date::operator>=(const Date &d) { return toSeconds() >= d.toSeconds(); }

bool Date::operator>=(const Date &d) const {
  return toSeconds() >= d.toSeconds();
}

bool Date::operator==(const Date &d) { return toSeconds() == d.toSeconds(); }

bool Date::operator==(const Date &d) const {
  return toSeconds() == d.toSeconds();
}

long long int Date::toSeconds() const {
  return s + 60 * (m + 60 * (h + 24 * (D + 31 * ((long long)M + 12 * Y))));
}

ostream &operator<<(ostream &os, const Date &d) {
  os << d.D << "/" << d.M << "/" << d.Y << " " << (d.h < 10 ? "0" : "") << d.h
     << ":" << (d.m < 10 ? "0" : "") << d.m << ":" << (d.s < 10 ? "0" : "")
     << d.s;
  return os;
}
