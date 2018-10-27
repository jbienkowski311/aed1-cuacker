#include <iostream>
#include <string>
#include <vector>
#include "Date.hpp"
#include "Messages.hpp"
#include "Tweet.hpp"

using namespace std;

int main() {
  string type, author, date, time, message;
  vector<Tweet *> tweets;
  const map<int, string> predefinedMessages = Messages::create();
  int messageNumber;

  while (cin) {
    cin >> type >> author;
    if (cin.fail()) break;
    cin >> date >> time;
    if (cin.fail()) break;
    // fix problem with cin and getline
    // cin leaves \n character therefore the first getline()
    // grabs \n not the second line
    cin.ignore(100, '\n');
    getline(cin, message);

    Date *published = new Date();
    *published = Date::parse(date, time);

    if (Tweet::isMcuac(type)) {
      tweets.push_back(new Tweet(*published, author, message));
    }
    if (Tweet::isPcuac(type)) {
      messageNumber = stoi(message);
      message = predefinedMessages.find(messageNumber)->second;
      tweets.push_back(new Tweet(*published, author, message));
    }
  }

  for (unsigned int i = 0; i < tweets.size(); i++) {
    cout << (i + 1) << " cuac" << endl;
    cout << tweets[i] << endl;
  }

  return 0;
}
