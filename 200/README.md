# 200 - Tablas de Dispersión de Cuacs

## Contexto

Ya tenemos una primera versión funcional de nuestro flamante CUACKER. Sin embargo, el problema es que admite muy pocos cuacs. Se espera que nuestro sistema pueda recibir varios millones de cuacs al día, con algunos cientos de miles de usuarios. ¿Qué ocurrirá cuando tengamos que hacer una búsqueda en toda la lista de mensajes?

Para hacerte una idea, basta que descargues y pruebes tu programa con este caso de prueba grande.

En estos ejercicios vamos a mejorar la implementación básica del sistema utilizando las estructuras de datos eficientes vistas en clase: tablas de dispersión y árboles. En primer lugar, vamos a usar tablas de dispersión para almacenar los usuarios. En segundo lugar, usaremos árboles para ordenar los cuacs por fechas.

Concretamente, en este ejercicio vamos a implementar una tabla de dispersión indexada por el nombre de los usuarios.

## El Problema

Diseñar e implementar una tabla de dispersión de cuacs indexada por los nombres de los usuarios.

En este ejercicio no existe un tope del máximo número de cuacs. Los comandos que aparecerán son mcuac, pcuac y follow:

Los comandos mcuac y pcuac introducirán el cuac en la tabla de dispersión, indexada por el nombre del usuario.
El comando follow NOMBRE debe listar los mensajes de ese usuario, ordenados con el orden definido en el ejercicio 004.

## Entrada

La entrada contendrá una serie de comandos, que puede acabar con una línea que contiene la palabra exit; aunque puede que no aparezca esa palabra clave (en cuyo caso habrá que terminar cuando no quede más entrada).

Los comandos que pueden aparecer son:

* Comando mcuac.
* Comando pcuac.
* Comando follow.

El formato de estos comandos es como el explicado en el ejercicio 005. Nunca habrá dos cuacs exactamente iguales.

## Salida

El formato de salida para cada uno de los comandos es el mismo que el explicado en el ejercicio 006.

## Ejemplo de Entrada

```
follow Pepe
pcuac David
26/11/2001 18:17:18
2
pcuac Ginés
9/4/2003 19:17:05
17
follow Ginés
pcuac David
4/5/2005 02:33:47
22
mcuac Pepa
26/2/2014 22:03:18
El volcán de #ElHierro vuelve a lanzar magma humeante a la superficie del mar.
follow David
follow Gines
pcuac Pepa
21/8/2015 10:51:45
24
mcuac Pepa
20/2/2020 21:07:48
Un nuevo experimento con #neutrinos puede explicar el misterio de la materia.
follow Pepa
follow Pepe
follow Ginés
```

## Ejemplo de Salida

```
follow Pepe
Total: 0 cuac
1 cuac
2 cuac
follow Ginés
1. Ginés 9/4/2003 19:17:05
   Todo tiempo pasado fue anterior.
Total: 1 cuac
3 cuac
4 cuac
follow David
1. David 4/5/2005 02:33:47
   Me gustaria ser valiente. Mi dentista asegura que no lo soy.
2. David 26/11/2001 18:17:18
   Negativo.
Total: 2 cuac
follow Gines
Total: 0 cuac
5 cuac
6 cuac
follow Pepa
1. Pepa 20/2/2020 21:07:48
   Un nuevo experimento con #neutrinos puede explicar el misterio de la materia.
2. Pepa 21/8/2015 10:51:45
   Hoy me ha pasado una cosa tan increible que es mentira.
3. Pepa 26/2/2014 22:03:18
   El volcán de #ElHierro vuelve a lanzar magma humeante a la superficie del mar.
Total: 3 cuac
follow Pepe
Total: 0 cuac
follow Ginés
1. Ginés 9/4/2003 19:17:05
   Todo tiempo pasado fue anterior.
Total: 1 cuac
```
