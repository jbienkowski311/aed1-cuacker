#include <iostream>
#include <string>
#include "Command.hpp"
#include "Date.hpp"
#include "Messages.hpp"
#include "Tweet.hpp"

using namespace std;

int main() {
  string command;
  TweetDictionary* dictionary = new TweetDictionary();

  while (cin >> command && !Command::isExit(command)) {
    Command::interpret(command, dictionary);
  }

  return 0;
}
