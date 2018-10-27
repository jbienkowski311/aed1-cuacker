#ifndef _CLASS_MESSAGES
#define _CLASS_MESSAGES

#include <map>
#include <string>

using namespace std;

class Messages {
 public:
  static map<int, string> create();
};
#endif