#include "Command.hpp"
#include <iostream>
#include "Date.hpp"
#include "Messages.hpp"

//
// Public
//
void Command::interpret(string command, int &tweets, Tweet &tweet) {
  if (isMcuac(command)) {
    interpretMcuac(tweets, tweet);
  } else if (isPcuac(command)) {
    interpretPcuac(tweets, tweet);
  } else if (isLast(command)) {
    interpretLast(tweet);
  } else if (isFollow(command)) {
    interpretFollow(tweet);
  } else if (isDate(command)) {
    interpretDate(tweet);
  } else if (isTag(command)) {
    interpretTag(tweet);
  }
}

bool Command::isExit(string command) { return command == "exit"; }

//
// Private
//
bool Command::isMcuac(string command) { return command == "mcuac"; }

void Command::interpretMcuac(int &tweets, Tweet &tweet) {
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

  Date *published = new Date();
  *published = Date::parse(date, time);

  tweet = Tweet(*published, author, message);
  tweets++;

  cout << tweets << " cuac" << endl;
}

bool Command::isPcuac(string command) { return command == "pcuac"; }

void Command::interpretPcuac(int &tweets, Tweet &tweet) {
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

  Date *published = new Date();
  *published = Date::parse(date, time);
  messageNumber = stoi(message);
  message = predefinedMessages.find(messageNumber)->second;
  tweet = Tweet(*published, author, message);
  tweets++;

  cout << tweets << " cuac" << endl;
}

bool Command::isLast(string command) { return command == "last"; }

void Command::interpretLast(Tweet &tweet) {
  int N;
  cin >> N;

  cout << "last " << N << endl;
  cout << "1. " << tweet << endl;
  cout << "Total: 1 cuac" << endl;
}

bool Command::isFollow(string command) { return command == "follow"; }

void Command::interpretFollow(Tweet &tweet) {
  string name;
  cin >> name;

  cout << "follow " << name << endl;
  cout << "1. " << tweet << endl;
  cout << "Total: 1 cuac" << endl;
}

bool Command::isDate(string command) { return command == "date"; }

void Command::interpretDate(Tweet &tweet) {
  string startDate, startHour, endDate, endHour;
  cin >> startDate >> startHour >> endDate >> endHour;

  Date start = Date::parse(startDate, startHour);
  Date end = Date::parse(endDate, endHour);

  cout << "date " << start << " " << end << endl;
  cout << "1. " << tweet << endl;
  cout << "Total: 1 cuac" << endl;
}

bool Command::isTag(string command) { return command == "tag"; }

void Command::interpretTag(Tweet &tweet) {
  string tag;
  cin >> tag;

  cout << "tag " << tag << endl;
  cout << "1. " << tweet << endl;
  cout << "Total: 1 cuac" << endl;
}
