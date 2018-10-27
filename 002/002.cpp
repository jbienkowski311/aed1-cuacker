#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, string> createMap() {
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
  map[14] = "Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.";
  map[15] = "Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.";
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
  map[26] = "Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.";
  map[27] = "Me despido hasta la proxima. Buen viaje!";
  map[28] = "Cualquiera se puede equivocar, inclusivo yo.";
  map[29] = "Estoy en Egipto. Nunca habia visto las piramides tan solas.";
  map[30] = "El que quiera saber mas, que se vaya a Salamanca.";
  return map;
}

string texto(map<int, string> map, int n) {
  return map.find(n)->second;
}

int numero(map<int, string> map, string texto) {
  for (auto it = map.begin(); it != map.end(); ++it) {
    if (it->second == texto) return it->first;
  }

  return 0;
}

int main() {
  int no_casos, result;
  string input;
  // Lookup table
  map<int, string> lut = createMap();

  cin >> no_casos;
  // fix problem with cin and getline
  // cin leaves \n character therefore the first getline() grabs \n not the second line
  cin.ignore(100, '\n');
  for (int i = 0; i < no_casos; i++) {
    getline(cin, input);
    result = numero(lut, input);
    if (result == 0) {
      cout << "ERROR. Cadena no encontrada: [" << input << "]" << endl;
    } else {
      cout << result << endl;
    }
  }

  return 0;
}

