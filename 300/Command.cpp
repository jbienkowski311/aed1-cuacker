#include "Command.hpp"
#include <iostream>
#include "Date.hpp"
#include "Messages.hpp"

//
// Public
//
void Command::interpret(string command, TweetDictionary* dictionary) {
  if (isMcuac(command)) {
    interpretMcuac(dictionary);
  } else if (isPcuac(command)) {
    interpretPcuac(dictionary);
  } else if (isLast(command)) {
    interpretLast(dictionary);
  } else if (isFollow(command)) {
    interpretFollow(dictionary);
  } else if (isDate(command)) {
    interpretDate(dictionary);
  }
}

bool Command::isExit(string command) { return command == "exit"; }

//
// Private
//
bool Command::isMcuac(string command) { return command == "mcuac"; }

void Command::interpretMcuac(TweetDictionary* dictionary) {
  int D, M, Y, h, m, s;
  char c;
  string author, message;

  cin >> author;
  if (cin.fail()) return;
  cin >> D >> c >> M >> c >> Y >> h >> c >> m >> c >> s;
  if (cin.fail()) return;
  // fix problem with cin and getline
  // cin leaves \n character therefore the first getline()
  // grabs \n not the second line
  cin.ignore(100, '\n');
  getline(cin, message);

  Date* published = new Date(D, M, Y, h, m, s);

  Tweet* tweet = new Tweet(*published, author, message);

  dictionary->insert(tweet);
}

bool Command::isPcuac(string command) { return command == "pcuac"; }

void Command::interpretPcuac(TweetDictionary* dictionary) {
  const map<int, string> predefinedMessages = Messages::create();
  int D, M, Y, h, m, s;
  char c;
  string author, message;
  int messageNumber;

  cin >> author;
  if (cin.fail()) return;
  cin >> D >> c >> M >> c >> Y >> h >> c >> m >> c >> s;
  if (cin.fail()) return;
  // fix problem with cin and getline
  // cin leaves \n character therefore the first getline()
  // grabs \n not the second line
  cin.ignore(100, '\n');
  getline(cin, message);

  Date* published = new Date(D, M, Y, h, m, s);
  messageNumber = stoi(message);
  message = predefinedMessages.find(messageNumber)->second;

  Tweet* tweet = new Tweet(*published, author, message);

  dictionary->insert(tweet);
}

bool Command::isLast(string command) { return command == "last"; }

void Command::interpretLast(TweetDictionary* dictionary) {
  int N;
  cin >> N;

  dictionary->last(N);
}

bool Command::isFollow(string command) { return command == "follow"; }

void Command::interpretFollow(TweetDictionary* dictionary) {
  string name;
  cin >> name;

  dictionary->follow(name);
}

bool Command::isDate(string command) { return command == "date"; }

void Command::interpretDate(TweetDictionary* dictionary) {
  int D, M, Y, h, m, s;
  char c;

  cin >> D >> c >> M >> c >> Y >> h >> c >> m >> c >> s;
  Date start = Date(D, M, Y, h, m, s);
  cin >> D >> c >> M >> c >> Y >> h >> c >> m >> c >> s;
  Date end = Date(D, M, Y, h, m, s);

  dictionary->date(start, end);
}
