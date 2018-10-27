# 002 - De texto a numero

## Contexto

En este ejercicio vamos a hacer la conversión inversa a la del ejercicio anterior: dado un texto de un mensaje, encontrar el número correspondiente en CUACKER. Para ello, usaremos la misma tabla de mensajes predefinidos del anterior ejercicio.
El Problema
Escribir un programa que dada una serie de mensajes pcuac (según la tabla de mensajes predefinidos) encuentre el número equivalente a cada uno de ellos. Si un mensaje no se corresponde con ninguno de los predefinidos, entonces lo debe indicar.

Igual que antes, debes hacer el programa evitando una ristra de condicionales y permitiendo que, en el futuro, los textos predefinidos se puedan cambiar con facilidad. Recuerda usar los mecanismos propios de C++.

## Entrada

La primera línea de la entrada contendrá un entero, N, que indica el número de casos de prueba existentes.

A continuación vienen N líneas, cada una de las cuales contiene un texto arbitrario de no más de 140 caracteres.

## Salida

Para cada caso de prueba, el resultado será una línea que contiene el número correspondiente al mensaje predefinido de ese caso de prueba. Si el mensaje no corresponde con ninguno de los predefinidos, entonces debes escribir en la salida:

`ERROR. Cadena no encontrada: [X]`

Siendo X el mensaje del caso de prueba.

## Ejemplo de Entrada

```
4
Todo tiempo pasado fue anterior.
Hoy me ha pasado una cosa...
Solo los genios somos modestos.
Si el dinero pudiera hablar, me diria adios.
```

## Ejemplo de Salida

```
17
ERROR. Cadena no encontrada: [Hoy me ha pasado una cosa...]
19
23
```
