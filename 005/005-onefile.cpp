#include <ctime>
#include <iostream>
#include <map>
#include <regex>
#include <stdexcept>
#include <string>

using namespace std;

class Messages {
 public:
  static map<int, string> create();
};

map<int, string> Messages::create() {
  map<int, string> map;
  map[1] = "Afirmativo.";
  map[2] = "Negativo.";
  map[3] = "Estoy de viaje en el extranjero.";
  map[4] = "Muchas gracias a todos mis seguidores por vuestro apoyo.";
  map[5] = "Enhorabuena, campeones!";
  map[6] = "Ver las novedades en mi pagina web.";
  map[7] = "Estad atentos a la gran exclusiva del siglo.";
  map[8] = "La inteligencia me persigue pero yo soy mas rapido.";
  map[9] = "Si no puedes convencerlos, confundelos.";
  map[10] = "La politica es el arte de crear problemas.";
  map[11] = "Donde estan las llaves, matarile, rile, rile...";
  map[12] = "Si no te gustan mis principios, puedo cambiarlos por otros.";
  map[13] = "Un dia lei que fumar era malo y deje de fumar.";
  map[14] =
      "Yo si se lo que es trabajar duro, de verdad, porque lo he visto por "
      "ahi.";
  map[15] =
      "Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.";
  map[16] = "Mi vida no es tan glamurosa como mi pagina web aparenta.";
  map[17] = "Todo tiempo pasado fue anterior.";
  map[18] = "El azucar no engorda... engorda el que se la toma.";
  map[19] = "Solo los genios somos modestos.";
  map[20] = "Nadie sabe escribir tambien como yo.";
  map[21] = "Si le molesta el mas alla, pongase mas aca.";
  map[22] = "Me gustaria ser valiente. Mi dentista asegura que no lo soy.";
  map[23] = "Si el dinero pudiera hablar, me diria adios.";
  map[24] = "Hoy me ha pasado una cosa tan increible que es mentira.";
  map[25] = "Si no tienes nada que hacer, por favor no lo hagas en clase.";
  map[26] =
      "Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon "
      "y salio una calabaza.";
  map[27] = "Me despido hasta la proxima. Buen viaje!";
  map[28] = "Cualquiera se puede equivocar, inclusivo yo.";
  map[29] = "Estoy en Egipto. Nunca habia visto las piramides tan solas.";
  map[30] = "El que quiera saber mas, que se vaya a Salamanca.";
  return map;
}

class Date {
 public:
  int D, M, Y, h, m, s;

  Date();
  Date(int D, int M, int Y, int h, int m, int s);

  friend ostream &operator<<(ostream &os, const Date &d);
  Date &operator=(const Date &d);
  bool operator<(const Date &d);
  bool operator>(const Date &d);
  bool operator==(const Date &d);
  static Date parse(string date, string hour);
  static Date parse(string date);
  time_t toCTime() const;
};

Date::Date() : D(0), M(0), Y(0), h(0), m(0), s(0) {}
Date::Date(int D, int M, int Y, int h, int m, int s)
    : D(D), M(M), Y(Y), h(h), m(m), s(s) {}

Date &Date::operator=(const Date &d) {
  D = d.D;
  M = d.M;
  Y = d.Y;
  h = d.h;
  m = d.m;
  s = d.s;
  return *this;
}

bool Date::operator<(const Date &d) {
  double diff = difftime(toCTime(), d.toCTime());
  return diff < 0.0;
}

bool Date::operator>(const Date &d) {
  double diff = difftime(toCTime(), d.toCTime());
  return diff > 0.0;
}

bool Date::operator==(const Date &d) {
  double diff = difftime(toCTime(), d.toCTime());
  return diff == 0.0;
}

Date Date::parse(string date, string hour) {
  date = date + " " + hour;
  return parse(date);
}

Date Date::parse(string date) {
  regex pattern(
      "(([0-9]{1,2})/([0-9]{1,2})/([12][0-9]{3}) "
      "([01]?[0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9]))");
  smatch match;

  if (regex_search(date, match, pattern)) {
    int D, M, Y, h, m, s;
    D = stoi(match[2]);
    M = stoi(match[3]);
    Y = stoi(match[4]);
    h = stoi(match[5]);
    m = stoi(match[6]);
    s = stoi(match[7]);

    return Date(D, M, Y, h, m, s);
  }

  cout << date << endl;
  throw invalid_argument("Invalid date format: [" + date +
                         "] - expecting DD/MM/YYYY hh:mm:ss");
}

time_t Date::toCTime() const {
  struct tm _tm = {0};
  _tm.tm_year = Y - 1900;
  _tm.tm_mon = M;
  _tm.tm_mday = D;
  _tm.tm_hour = h;
  _tm.tm_min = m;
  _tm.tm_sec = s;

  return mktime(&_tm);
}

ostream &operator<<(ostream &os, const Date &d) {
  os << d.D << "/" << d.M << "/" << d.Y << " " << (d.h < 10 ? "0" : "") << d.h
     << ":" << (d.m < 10 ? "0" : "") << d.m << ":" << (d.s < 10 ? "0" : "")
     << d.s;
  return os;
}

class Tweet {
 public:
  Date published;
  string author, message;

  Tweet(const Date &published, const string &author, const string &message);

  friend ostream &operator<<(ostream &os, const Tweet &t);
  friend ostream &operator<<(ostream &os, const Tweet *t);
};

Tweet::Tweet(const Date &published, const string &author, const string &message)
    : published(published), author(author), message(message) {}

ostream &operator<<(ostream &os, const Tweet &t) {
  os << t.author << " " << t.published << endl;
  os << "   " << t.message;
  return os;
}

ostream &operator<<(ostream &os, const Tweet *t) {
  os << t->author << " " << t->published << endl;
  os << "   " << t->message;
  return os;
}

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

int main() {
  Tweet *tweet = new Tweet(Date(), "", "");
  int tweets = 0;
  string command;

  while (cin >> command && !Command::isExit(command)) {
    Command::interpret(command, tweets, *tweet);
  }

  return 0;
}
