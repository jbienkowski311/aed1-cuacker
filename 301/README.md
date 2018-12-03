# Árboles de Cuacs para Date

## Contexto

Una vez que tenemos implementados los árboles de fechas, en este ejercicio se trata de resolver de forma eficiente la operación date de consulta por fechas. En principio, siempre que se haga bien, tanto los árboles trie, como los AVL y los árboles B pueden ser adecuados para este problema.

## El Problema

A partir del programa del ejercicio 300, añadir la operación para poder consultar de manera eficiente los mensajes que están en un rango de fechas, es decir, el comando date.

Los comandos que pueden aparecer en este ejercicio son mcuac, pcuac, date y exit. El número de cuacs no está limitado.
Sea cual sea el tipo de árboles utilizado, la implementación de la operación debe hacerse de manera eficiente, de forma que no se necesite recorrer todo el árbol. En otro caso, casi seguro que el programa dará un error de tiempo límite excedido.

## Entrada

La entrada contendrá una serie de comandos, que puede acabar con una línea que contiene la palabra exit; aunque puede que no aparezca esa palabra clave (en cuyo caso habrá que terminar cuando no quede más entrada).

Los comandos que pueden aparecer son:

* Comando mcuac.
* Comando pcuac.
* Comando date.

El formato de estos comandos es como el explicado en el ejercicio 005. Nunca habrá dos cuacs exactamente iguales.

## Salida

El formato de salida para cada uno de los comandos es el mismo que el explicado en el ejercicio 006. Recuerda que los cuacs se deben listar de más reciente a más antiguo, en caso de empate a fecha de menor a mayor orden alfabético de texto, y en caso de empate de menor a mayor orden alfabético de nombre de usuario.

## Ejemplo de Entrada

```
date 1/11/2001 18:17:18 31/11/2001 10:30:00
pcuac David
26/11/2001 18:17:18
2
pcuac Gines
9/4/2003 19:17:05
17
date 26/11/2001 18:17:18 26/11/2001 18:17:18
pcuac David
4/5/2005 02:33:47
22
mcuac Pepa
26/2/2014 22:03:18
El volcan de #ElHierro vuelve a lanzar magma humeante a la superficie del mar.
date 26/11/2001 18:17:20 26/2/2014 22:03:18
date 26/11/2001 18:17:18 26/2/2014 22:03:17
pcuac Pepa
21/8/2015 10:51:45
24
mcuac Pepa
20/2/2020 21:07:48
Un nuevo experimento con #neutrinos puede explicar el misterio de la materia.
date 26/11/2001 18:17:20 26/2/2020 22:03:18
date 1/1/2004 00:00:00 31/12/2020 21:07:48
date 26/2/2014 22:03:18 26/2/2014 22:03:18
date 26/2/2014 22:03:19 20/2/2020 21:07:47
```

## Ejemplo de Salida

```
date 1/11/2001 18:17:18 31/11/2001 10:30:00
Total: 0 cuac
1 cuac
2 cuac
date 26/11/2001 18:17:18 26/11/2001 18:17:18
1. David 26/11/2001 18:17:18
   Negativo.
Total: 1 cuac
3 cuac
4 cuac
date 26/11/2001 18:17:20 26/2/2014 22:03:18
1. Pepa 26/2/2014 22:03:18
   
2. David 4/5/2005 02:33:47
   Me gustaria ser valiente. Mi dentista asegura que no lo soy.
3. Gines 9/4/2003 19:17:05
   Todo tiempo pasado fue anterior.
Total: 3 cuac
date 26/11/2001 18:17:18 26/2/2014 22:03:17
1. David 4/5/2005 02:33:47
   Me gustaria ser valiente. Mi dentista asegura que no lo soy.
2. Gines 9/4/2003 19:17:05
   Todo tiempo pasado fue anterior.
3. David 26/11/2001 18:17:18
   Negativo.
Total: 3 cuac
5 cuac
6 cuac
date 26/11/2001 18:17:20 26/2/2020 22:03:18
1. Pepa 20/2/2020 21:07:48
   
2. Pepa 21/8/2015 10:51:45
   Hoy me ha pasado una cosa tan increible que es mentira.
3. Pepa 26/2/2014 22:03:18
   
4. David 4/5/2005 02:33:47
   Me gustaria ser valiente. Mi dentista asegura que no lo soy.
5. Gines 9/4/2003 19:17:05
   Todo tiempo pasado fue anterior.
Total: 5 cuac
date 1/1/2004 00:00:00 31/12/2020 21:07:48
1. Pepa 20/2/2020 21:07:48
   
2. Pepa 21/8/2015 10:51:45
   Hoy me ha pasado una cosa tan increible que es mentira.
3. Pepa 26/2/2014 22:03:18
   
4. David 4/5/2005 02:33:47
   Me gustaria ser valiente. Mi dentista asegura que no lo soy.
Total: 4 cuac
date 26/2/2014 22:03:18 26/2/2014 22:03:18
1. Pepa 26/2/2014 22:03:18
   
Total: 1 cuac
date 26/2/2014 22:03:19 20/2/2020 21:07:47
1. Pepa 21/8/2015 10:51:45
   Hoy me ha pasado una cosa tan increible que es mentira.
Total: 1 cuac
```
