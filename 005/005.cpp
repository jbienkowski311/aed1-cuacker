#include <iostream>
#include <string>
#include "Command.hpp"
#include "Date.hpp"
#include "Messages.hpp"
#include "Tweet.hpp"

using namespace std;

int main() {
  Tweet *tweet = new Tweet(Date(), "", "");
  int tweets = 0;
  string command;

  while (cin >> command && !Command::isExit(command)) {
    Command::interpret(command, tweets, *tweet);
  }

  return 0;
}
