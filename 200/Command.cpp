#include "Command.hpp"
#include <iostream>
#include "Date.hpp"

//
// Public
//
string Command::messages[NUM_PCUACS] = {
    "Afirmativo.",
    "Negativo.",
    "Estoy de viaje en el extranjero.",
    "Muchas gracias a todos mis seguidores por vuestro apoyo.",
    "Enhorabuena, campeones!",
    "Ver las novedades en mi pagina web.",
    "Estad atentos a la gran exclusiva del siglo.",
    "La inteligencia me persigue pero yo soy mas rapido.",
    "Si no puedes convencerlos, confundelos.",
    "La politica es el arte de crear problemas.",
    "Donde estan las llaves, matarile, rile, rile...",
    "Si no te gustan mis principios, puedo cambiarlos por otros.",
    "Un dia lei que fumar era malo y deje de fumar.",
    "Yo si se lo que es trabajar duro, de verdad, porque lo he visto por "
    "ahi.",
    "Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.",
    "Mi vida no es tan glamurosa como mi pagina web aparenta.",
    "Todo tiempo pasado fue anterior.",
    "El azucar no engorda... engorda el que se la toma.",
    "Solo los genios somos modestos.",
    "Nadie sabe escribir tambien como yo.",
    "Si le molesta el mas alla, pongase mas aca.",
    "Me gustaria ser valiente. Mi dentista asegura que no lo soy.",
    "Si el dinero pudiera hablar, me diria adios.",
    "Hoy me ha pasado una cosa tan increible que es mentira.",
    "Si no tienes nada que hacer, por favor no lo hagas en clase.",
    "Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon "
    "y "
    "salio una calabaza.",
    "Me despido hasta la proxima. Buen viaje!",
    "Cualquiera se puede equivocar, inclusivo yo.",
    "Estoy en Egipto. Nunca habia visto las piramides tan solas.",
    "El que quiera saber mas, que se vaya a Salamanca."};

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
  int messageNumber = stoi(message);
  message = messages[messageNumber - 1];

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
