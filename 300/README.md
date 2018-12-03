# Árboles de Cuacs para Last

## Contexto

Las tablas de dispersión de usuarios nos ofrecen una buena eficiencia para las operaciones follow de consulta por usuario. Pero, ¿qué pasa con las operaciones de consulta por fechas, last y date? Necesitaríamos recorrer toda la lista de cuacs, lo cual es muy ineficiente cuando el número de cuacs cree mucho.

Por ese motivo, en estos ejercicios vamos a optimizar los comandos de consulta por fecha usando árboles. En concreto, el objetivo es analizar, diseñar e implementar una estructura de datos de árboles que nos permita consultar rápidamente los últimos cuacs y los que están dentro de cierto rango de fechas. En este ejercicio se comprobará el funcionamiento correcto de la operación last, y en el siguiente el funcionamiento de date.

## El Problema

Tomando como base el programa del ejercicio 200, añadir una estructura de árboles donde las claves son las fechas y el valor asociado son los cuacs correspondientes. Por lo tanto, en los comandos mcuac y pcuac se debe insertar tanto en el árbol (por fechas) como en la tabla de dispersión (por usuarios).

En este ejercicio se pone a prueba el comando last. Los comandos que pueden aparecer en este ejercicio son mcuac, pcuac, last y exit. El número de cuacs no está limitado.
El tipo de árboles a utilizar en este ejercicio no está prefijado de antemano. Los alumnos pueden elegir entre usar árboles trie, árboles AVL o árboles B. En cualquier caso, los cuacs no deben duplicarse, sino que el árbol debe apuntar a los cuacs almacenados en la tabla de dispersión.

## Entrada

La entrada contendrá una serie de comandos, que puede acabar con una línea que contiene la palabra exit; aunque puede que no aparezca esa palabra clave (en cuyo caso habrá que terminar cuando no quede más entrada).

Los comandos que pueden aparecer son:

* Comando mcuac.
* Comando pcuac.
* Comando last.

El formato de estos comandos es como el explicado en el ejercicio 005. Nunca habrá dos cuacs exactamente iguales.

## Salida

El formato de salida para cada uno de los comandos es el mismo que el explicado en el ejercicio 006. Recuerda que los cuacs se deben listar de más reciente a más antiguo, en caso de empate a fecha de menor a mayor orden alfabético de texto, y en caso de empate de menor a mayor orden alfabético de nombre de usuario.

## Ejemplo de Entrada

```
last 4
pcuac David
26/11/2001 18:17:18
2
pcuac Ginés
9/4/2003 19:17:05
17
last 3
pcuac David
4/5/2005 02:33:47
22
mcuac Pepa
26/2/2014 22:03:18
El volcán de #ElHierro vuelve a lanzar magma humeante a la superficie del mar.
last 2
last 3
pcuac Pepa
21/8/2015 10:51:45
24
mcuac Pepa
26/2/2014 22:03:18
Un nuevo experimento con #neutrinos puede explicar el misterio de la materia.
last 1
last 5
last 0
```

## Ejemplo de Salida

```
last 4
Total: 0 cuac
1 cuac
2 cuac
last 3
1. Ginés 9/4/2003 19:17:05
   Todo tiempo pasado fue anterior.
2. David 26/11/2001 18:17:18
   Negativo.
Total: 2 cuac
3 cuac
4 cuac
last 2
1. Pepa 26/2/2014 22:03:18
   El volcán de #ElHierro vuelve a lanzar magma humeante a la superficie del mar.
2. David 4/5/2005 02:33:47
   Me gustaria ser valiente. Mi dentista asegura que no lo soy.
Total: 2 cuac
last 3
1. Pepa 26/2/2014 22:03:18
   El volcán de #ElHierro vuelve a lanzar magma humeante a la superficie del mar.
2. David 4/5/2005 02:33:47
   Me gustaria ser valiente. Mi dentista asegura que no lo soy.
3. Ginés 9/4/2003 19:17:05
   Todo tiempo pasado fue anterior.
Total: 3 cuac
5 cuac
6 cuac
last 1
1. Pepa 21/8/2015 10:51:45
   Hoy me ha pasado una cosa tan increible que es mentira.
Total: 1 cuac
last 5
1. Pepa 21/8/2015 10:51:45
   Hoy me ha pasado una cosa tan increible que es mentira.
2. Pepa 26/2/2014 22:03:18
   El volcán de #ElHierro vuelve a lanzar magma humeante a la superficie del mar.
3. Pepa 26/2/2014 22:03:18
   Un nuevo experimento con #neutrinos puede explicar el misterio de la materia.
4. David 4/5/2005 02:33:47
   Me gustaria ser valiente. Mi dentista asegura que no lo soy.
5. Ginés 9/4/2003 19:17:05
   Todo tiempo pasado fue anterior.
Total: 5 cuac
last 0
Total: 0 cuac
```
