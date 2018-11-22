# 005 - Intérprete de comandos

## Contexto

Hasta ahora tenemos resuelto el problema de la lectura de los mensajes, así como la lectura de las fechas. En este ejercicio vamos a desarrollar un intérprete de comandos más completo, capaz de reconocer todos los comandos de nuestro sistema: mcuac, pcuac, last, follow, date, tag y exit.

Por el momento nuestro intérprete de comandos será solo un esqueleto, que iremos rellenando posteriormente a medida que implementemos cada una de las operaciones de inserción y búsqueda de cuac.

## El Problema

Escribir un intérprete de comandos, que vaya leyendo comandos de la entrada estándar y haciendo para cada uno lo que corresponda. Este intérprete tendrá el siguiente funcionamiento:

Deberá leer todos los comandos de la entrada, hasta encontrar el comando exit o bien llegar al final de la entrada.
Para cada comando, en primer lugar leerá el nombre del comando. Según el comando, deberá llamar a una función específica para procesar ese comando. Por ejemplo, si el comando leído es "mcuac" entonces llama a una operación: procesar_mcuac(); si es "follow", llamará a la operación: procesar_follow(), etc.
En las operaciones procesar_mcuac() y procesar_pcuac() se debe llamar a la operación de lectura correspondiente sobre la clase Cuac del ejercicio 004. Ese cuac pasa a ser "el actual". Después escribirá: N cuac, siendo N el número total de cuac leídos hasta el momento.
En las operaciones procesar_last(), procesar_follow(), procesar_date() y procesar_tag(), se deben leer los parámetros correspondientes a ese comando. En la salida se debe escribir el mismo comando de entrada y después, como si fuera el resultado, escribirá el cuac actual y el texto: Total: 1 cuac
Observar que, por ahora, solo se almacena un cuac en el sistema. Y todas las búsquedas funcionan como si el resultado fuera ese cuac (el último leído hasta ese momento).

## Entrada

La entrada contendrá una serie de comandos, que puede acabar con una línea que contiene la palabra exit; aunque puede que no aparezca esa palabra clave (en cuyo caso habrá que terminar cuando no quede más entrada).

Los comandos que pueden aparecer son los que se describen en el enunciado de la práctica, excepto el comando de búsqueda combinada (search - endsearch), que no aparecerá por el momento. El formato de los comandos será el siguiente:

**Comando mcuac**: igual que se explica en el ejercicio 004:

```
mcuac NOMBRE_USUARIO
FECHA_HORA
MENSAJE_DE_TEXTO
```

Siendo: NOMBRE_USUARIO el nombre del usuario (que no contendrá espacios en blanco); FECHA_HORA la fecha y hora del mensaje (según el formato del ejercicio 003); y MENSAJE_DE_TEXTO una cadena de no más de 140 caracteres.

**Comando pcuac**: igual que se explica en el ejercicio 004:

```
pcuac NOMBRE_USUARIO
FECHA_HORA
NUMERO
```

Siendo: NUMERO un número entero entre 1 y 30, inclusives.

**Comando last**: después de la palabra last aparecerá un número natural entre 0 y 230:

`last N`

**Comando follow**: después del comando aparecerá el nombre de un usuario, que es una cadena que no contendrá espacios en blanco:

`follow NOMBRE_USUARIO`

**Comando date**: tras la palabra clave date, aparecen dos fechas: la mínima y la máxima. El formato de las fechas es el definido en el ejercicio 003. Como ya tenemos implementada una operación para leer fechas, simplemente debemos llamarla dos veces:

`date FECHA_INICIAL FECHA_FINAL`

**Comando tag**: se indica la etiqueta a buscar, que empieza por un símbolo #. La etiqueta no contiene espacios en blanco:

`tag #ETIQUETA`

**Comando exit**: no tiene ningún parámetro:

`exit`

El primer comando de la entrada siempre será uno de inserción (mcuac o pcuac).

## Salida

Si el comando leído es de inserción de un cuac (comandos mcuac y pcuac), debes escribir el número total de cuac leídos hasta ese punto, N, de la forma:

`N cuac`

Si el comando leído es de búsqueda (comandos last, follow, date y tag), debes escribir en primer lugar una línea con el mismo comando de entrada. A continuación debes escribir "1. " seguido del último cuac leído hasta ese punto (según el formato de salida indicado en el ejercicio 004), y en la siguiente línea se escribirá: "Total: 1 cuac".

```
LINEA_DE_BUSQUEDA
1. NOMBRE_USUARIO FECHA_HORA
   MENSAJE
Total: 1 cuac
```

## Ejemplo de Entrada

```
mcuac RafaelNaval
25/10/2011 13:45:11
¡Feliz Navidad #amigosdenaval y próspero año nuevo!
pcuac RafaelNaval
28/11/2011 11:27:08
5
last 5
follow Perico
mcuac GinesGM
6/5/2012 16:00:00
Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
date 28/11/2011 11:27:04 28/11/2012 11:27:08
pcuac Gutierrez
1/1/2013 00:00:00
27
last 100
pcuac GinesGM
1/1/2013 00:00:01
30
tag #eltiempo
tag #una_nueva_etiqueta
```

Nota: los caracteres especiales (tildes, eñes, etc.) están codificados con UTF-8.

## Ejemplo de Salida

```
1 cuac
2 cuac
last 5
1. RafaelNaval 28/11/2011 11:27:08
   Enhorabuena, campeones!
Total: 1 cuac
follow Perico
1. RafaelNaval 28/11/2011 11:27:08
   Enhorabuena, campeones!
Total: 1 cuac
3 cuac
date 28/11/2011 11:27:04 28/11/2012 11:27:08
1. GinesGM 6/5/2012 16:00:00
   Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
Total: 1 cuac
4 cuac
last 100
1. Gutierrez 1/1/2013 00:00:00
   Me despido hasta la proxima. Buen viaje!
Total: 1 cuac
5 cuac
tag #eltiempo
1. GinesGM 1/1/2013 00:00:01
   El que quiera saber mas, que se vaya a Salamanca.
Total: 1 cuac
tag #una_nueva_etiqueta
1. GinesGM 1/1/2013 00:00:01
   El que quiera saber mas, que se vaya a Salamanca.
Total: 1 cuac
```
