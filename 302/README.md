# El Motor de CUACKER

![Cuacker](../cuacker.png)

## Contexto

Si has llegado hasta este punto resolviendo los ejercicios previos, ya tienes una versión funcional y eficiente del sistema gestor CUACKER. ¡Enhorabuena!

En este ejercicio se comprobará que todos los comandos obligatorios funcionan eficientemente de forma conjunta: la inserción de mensajes con mcuac y pcuac; la búsqueda con last usando el árbol; la búsqueda de usuarios con follow usando las tablas de dispersión; y la búsqueda por fechas con date usando el árbol de fechas.

Pero, ojo, tu programa debe estar preparado para manejar con rapidez (y sin perder memoria) unas cuantas decenas o cientos de miles de cuacs.

## El Problema

Escribir un programa capaz de procesar de manera eficiente todos los comandos obligatorios del sistema gestor CUACKER. Como mínimo, el programa debe implementar tablas de dispersión para los usuarios y árboles para las fechas.

Por lo tanto, los comandos que pueden aparecer en este ejercicio son mcuac, pcuac, last, follow, date y exit. El número de cuacs no está limitado.
Puesto que este ejercicio contiene todos los comandos obligatorios, puedes usar los casos de prueba de los anteriores ejercicios para probar este.

Entrada
La entrada contendrá una serie de comandos, que puede acabar con una línea que contiene la palabra exit; aunque puede que no aparezca esa palabra clave (en cuyo caso habrá que terminar cuando no quede más entrada).

Los comandos que pueden aparecer son:

* Comando mcuac.
* Comando pcuac.
* Comando last.
* Comando follow.
* Comando date.

El formato de estos comandos es como el explicado en el ejercicio 005.

## Salida

El formato de salida para cada uno de los comandos es el mismo que el explicado en el ejercicio 006.

## Ejemplo de Entrada

```
mcuac RafaelNaval
25/10/2011 13:45:11
¡Feliz Navidad #amigosdenaval y próspero año nuevo!
pcuac RafaelNaval
28/11/2011 11:27:08
5
last 1
follow Perico
follow RafaelNaval
mcuac GinesGM
6/5/2012 16:00:00
Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
date 28/11/2011 11:27:04 28/11/2012 11:27:08
pcuac Gutierrez
1/1/2013 00:00:00
27
last 100
```

## Ejemplo de Salida

```
1 cuac
2 cuac
last 1
1. RafaelNaval 28/11/2011 11:27:08
   Enhorabuena, campeones!
Total: 1 cuac
follow Perico
Total: 0 cuac
follow RafaelNaval
1. RafaelNaval 28/11/2011 11:27:08
   Enhorabuena, campeones!
2. RafaelNaval 25/10/2011 13:45:11
   ¡Feliz Navidad #amigosdenaval y próspero año nuevo!
Total: 2 cuac
3 cuac
date 28/11/2011 11:27:04 28/11/2012 11:27:08
1. GinesGM 6/5/2012 16:00:00
   Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
2. RafaelNaval 28/11/2011 11:27:08
   Enhorabuena, campeones!
Total: 2 cuac
4 cuac
last 100
1. Gutierrez 1/1/2013 00:00:00
   Me despido hasta la proxima. Buen viaje!
2. GinesGM 6/5/2012 16:00:00
   Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
3. RafaelNaval 28/11/2011 11:27:08
   Enhorabuena, campeones!
4. RafaelNaval 25/10/2011 13:45:11
   ¡Feliz Navidad #amigosdenaval y próspero año nuevo!
Total: 4 cuac
```
