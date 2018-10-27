# 001 - De numero a texto

## Contexto

En nuestro sistema de nano-blogging, existen los llamados pcuac, que son mensajes que se envían haciendo llamadas perdidas a un teléfono. Según el número de toques, el mensaje se interpreta como cierto texto predefinido.
En concreto, existen 30 mensajes predefinidos, que se muestran en la siguiente tabla.

| Número | Mensaje |
| 1 | Afirmativo. |
| 2 | Negativo. |
| 3 | Estoy de viaje en el extranjero. |
| 4 | Muchas gracias a todos mis seguidores por vuestro apoyo. |
| 5 | Enhorabuena, campeones! |
| 6 | Ver las novedades en mi pagina web. |
| 7 | Estad atentos a la gran exclusiva del siglo. |
| 8	|La inteligencia me persigue pero yo soy mas rapido. |
| 9	|Si no puedes convencerlos, confundelos. |
| 10 | La politica es el arte de crear problemas. |
| 11 | Donde estan las llaves, matarile, rile, rile... |
| 12 | Si no te gustan mis principios, puedo cambiarlos por otros. |
| 13 | Un dia lei que fumar era malo y deje de fumar. |
| 14 | Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi. |
| 15 | Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas. |
| 16 | Mi vida no es tan glamurosa como mi pagina web aparenta. |
| 17 | Todo tiempo pasado fue anterior. |
| 18 | El azucar no engorda... engorda el que se la toma. |
| 19 | Solo los genios somos modestos. |
| 20 | Nadie sabe escribir tambien como yo. |
| 21 | Si le molesta el mas alla, pongase mas aca. |
| 22 | Me gustaria ser valiente. Mi dentista asegura que no lo soy. |
| 23 | Si el dinero pudiera hablar, me diria adios. |
| 24 | Hoy me ha pasado una cosa tan increible que es mentira. |
| 25 | Si no tienes nada que hacer, por favor no lo hagas en clase. |
| 26 | Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza. |
| 27 | Me despido hasta la proxima. Buen viaje! |
| 28 | Cualquiera se puede equivocar, inclusivo yo. |
| 29 | Estoy en Egipto. Nunca habia visto las piramides tan solas. |
| 30 | El que quiera saber mas, que se vaya a Salamanca. |

Observar que, para evitar problemas con las codificaciones especiales, hemos quitado todas las tildes de estos mensajes.

## El Problema

Escribir un programa que, dado un número, produzca como resultado el texto correspondiente según la anterior tabla de mensajes predefinidos. 

Haz el programa de forma legible y elegante, evitando una ristra de condicionales, de manera que los textos predefinidos se puedan cambiar con facilidad. Debes usar los mecanismos propios de C++: entrada/salida con cin y cout, el tipo de datos string, las constantes const, etc.

## Entrada

La primera línea de la entrada contendrá un entero, N, que indica el número de casos de prueba existente.

A continuación vienen N líneas, cada una de las cuales contiene un número entero entre 1 y 30.

## Salida

Para cada caso de prueba, el resultado será una línea que contiene el texto predefinido correspodiente. Consejo: copia los textos de la tabla anterior, no te vayas a equivocar en alguna letra, espacio o carácter de puntuación.

## Ejemplo de Entrada

```
4
7
18
30
27
```

## Ejemplo de Salida

```
Estad atentos a la gran exclusiva del siglo.
El azucar no engorda... engorda el que se la toma.
El que quiera saber mas, que se vaya a Salamanca.
Me despido hasta la proxima. Buen viaje!
```