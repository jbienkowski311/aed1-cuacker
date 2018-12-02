#include <string>
#include "TweetDictionary.hpp"

using namespace std;

const int NUM_PCUACS = 30;

class Command {
 public:
  static string messages[NUM_PCUACS];
  static void interpret(string command, TweetDictionary* dictionary);
  static bool isExit(string command);

 private:
  static bool isMcuac(string command);
  static void interpretMcuac(TweetDictionary* dictionary);
  static bool isPcuac(string command);
  static void interpretPcuac(TweetDictionary* dictionary);
  static bool isLast(string command);
  static void interpretLast(TweetDictionary* dictionary);
  static bool isFollow(string command);
  static void interpretFollow(TweetDictionary* dictionary);
  static bool isDate(string command);
  static void interpretDate(TweetDictionary* dictionary);
  static bool isTag(string command);
  static void interpretTag(TweetDictionary* dictionary);
};
