#include <string>
#include "Tweet.hpp"

using namespace std;

class Command {
 public:
  static void interpret(string command, int &tweets, Tweet &tweet);
  static bool isExit(string command);

 private:
  static bool isMcuac(string command);
  static void interpretMcuac(int &tweets, Tweet &tweet);
  static bool isPcuac(string command);
  static void interpretPcuac(int &tweets, Tweet &tweet);
  static bool isLast(string command);
  static void interpretLast(Tweet &tweet);
  static bool isFollow(string command);
  static void interpretFollow(Tweet &tweet);
  static bool isDate(string command);
  static void interpretDate(Tweet &tweet);
  static bool isTag(string command);
  static void interpretTag(Tweet &tweet);
};
