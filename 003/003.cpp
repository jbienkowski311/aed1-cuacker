#include <ctime>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Date
{
  public:
    int D,
        M,
        Y,
        h,
        m,
        s;

    Date() : D(0), M(0), Y(0), h(0), m(0), s(0) {}
    Date(int D, int M, int Y, int h, int m, int s) : D(D), M(M), Y(Y), h(h), m(m), s(s) {}

    friend ostream &operator<<(ostream &os, const Date &d);

    Date &operator=(const Date &d)
    {
        D = d.D;
        M = d.M;
        Y = d.Y;
        h = d.h;
        m = d.m;
        s = d.s;
        return *this;
    }

    bool operator<(const Date &d)
    {
        double diff = difftime(toCTime(), d.toCTime());
        return diff < 0.0;
    }

    bool operator>(const Date &d)
    {
        double diff = difftime(toCTime(), d.toCTime());
        return diff > 0.0;
    }

    bool operator==(const Date &d)
    {
        double diff = difftime(toCTime(), d.toCTime());
        return diff == 0.0;
    }

    static Date parse(string date, string hour)
    {
        date = date + " " + hour;
        return parse(date);
    }

    static Date parse(string date)
    {
        regex pattern("(([0-9]{1,2})/([0-9]{1,2})/([12][0-9]{3}) ([01]?[0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9]))");
        smatch match;

        if (regex_search(date, match, pattern))
        {
            int D, M, Y, h, m, s;
            D = stoi(match[2]);
            M = stoi(match[3]);
            Y = stoi(match[4]);
            h = stoi(match[5]);
            m = stoi(match[6]);
            s = stoi(match[7]);

            return Date(D, M, Y, h, m, s);
        }

        throw "Invalid date format - expecting DD/MM/YYYY hh:mm:ss";
    }

    time_t toCTime() const
    {
        struct tm _tm = {0};
        _tm.tm_year = Y - 1900;
        _tm.tm_mon = M;
        _tm.tm_mday = D;
        _tm.tm_hour = h;
        _tm.tm_min = m;
        _tm.tm_sec = s;

        return mktime(&_tm);
    }
};

ostream &operator<<(ostream &os, const Date &d)
{
    os << d.D << "/" << d.M << "/" << d.Y << " " << (d.h < 10 ? "0" : "") << d.h << ":" << (d.m < 10 ? "0" : "") << d.m << ":" << (d.s < 10 ? "0" : "") << d.s;
    return os;
}

int main()
{
    int N;
    string date, hour;
    Date prev, curr;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> date >> hour;
        prev = curr;
        curr = Date::parse(date, hour);
        if (i == 0)
        {
            continue;
        }
        if (curr > prev)
        {
            cout << curr << " ES POSTERIOR A " << prev << endl;
            continue;
        }
        if (curr == prev)
        {
            cout << curr << " ES IGUAL A " << prev << endl;
            continue;
        }
        if (curr < prev)
        {
            cout << curr << " ES ANTERIOR A " << prev << endl;
            continue;
        }
    }
    return 0;
}
