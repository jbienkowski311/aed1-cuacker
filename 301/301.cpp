#include <iostream>
#include <string>
#include "Command.hpp"
#include "TweetDictionary.hpp"

using namespace std;

int main() {
  string command;
  TweetDictionary* dictionary = new TweetDictionary();

  while (cin >> command && !Command::isExit(command)) {
    Command::interpret(command, dictionary);
  }

  return 0;
}
