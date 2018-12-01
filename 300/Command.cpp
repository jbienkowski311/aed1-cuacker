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
  string author, date, time, message;

  cin >> author;
  if (cin.fail()) return;
  cin >> date >> time;
  if (cin.fail()) return;
  // fix problem with cin and getline
  // cin leaves \n character therefore the first getline()
  // grabs \n not the second line
  cin.ignore(100, '\n');
  getline(cin, message);

  Date* published = new Date();
  *published = Date::parse(date, time);

  Tweet* tweet = new Tweet(*published, author, message);
  dictionary->insert(tweet);
}

bool Command::isPcuac(string command) { return command == "pcuac"; }

void Command::interpretPcuac(TweetDictionary* dictionary) {
  const map<int, string> predefinedMessages = Messages::create();
  string author, date, time, message;
  int messageNumber;

  cin >> author;
  if (cin.fail()) return;
  cin >> date >> time;
  if (cin.fail()) return;
  // fix problem with cin and getline
  // cin leaves \n character therefore the first getline()
  // grabs \n not the second line
  cin.ignore(100, '\n');
  getline(cin, message);

  Date* published = new Date();
  *published = Date::parse(date, time);
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
  string startDate, startHour, endDate, endHour;
  cin >> startDate >> startHour >> endDate >> endHour;

  Date start = Date::parse(startDate, startHour);
  Date end = Date::parse(endDate, endHour);

  dictionary->date(start, end);
}
