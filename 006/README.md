# 006 - Diccionario de Cuacs con Listas

## Contexto

En este ejercicio vamos a crear una primera versión funcional del CUACKER. El elemento básico será el contenedor, el diccionario de cuacs. Empezaremos con una implementación muy sencilla mediante una lista de cuacs. Crearemos una nueva clase DiccionarioCuacs que contendrá una lista donde se inserten los cuacs ordenados por fecha. Todas las operaciones de consulta obligatorias (last, follow y date) se harán mediante simples recorridos en esta lista.

## El Problema

Crear una nueva clase DiccionarioCuacs para almacenar listas de cuacs. Con ella, escribir un programa que sea capaz de procesar los comandos `mcuac`, `pcuac`, `last`, `follow` y `date`:

Los comandos `mcuac` y `pcuac` introducirán el cuac correspondiente en la lista por orden.
El comando `last N` debe listar los N últimos mensajes, es decir, los más recientes; si hay menos de N, escribirá los que haya.
El comando `follow NOMBRE` debe listar los mensajes del usuario NOMBRE.
El comando `date FECHA1 FECHA2` debe listar los mensajes que estén comprendidos entre FECHA1 y FECHA2, ambas inclusive.
Los mensajes se listarán siempre usando el orden de los cuacs definido en el ejercicio 004, es decir, desde el más reciente hasta el más antiguo, en caso de empate por orden alfabético del texto, y en caso de empate en orden alfabético del nombre de usuario.

## Entrada

La entrada contendrá una serie de comandos, que puede acabar con una línea que contiene la palabra exit; aunque puede que no aparezca esa palabra clave (en cuyo caso habrá que terminar cuando no quede más entrada).

Los comandos que pueden aparecer son:

* Comando mcuac.
* Comando pcuac.
* Comando last.
* Comando follow.
* Comando date.

El formato de estos comandos es como el explicado en el ejercicio 005. Nunca se insertarán cuacs repetidos (que contengan los mismos datos).

## Salida

Si el comando leído es de inserción de un cuac (comandos `mcuac` y `pcuac`), debes escribir el número total de cuac leídos hasta ese punto, N, de la forma:

`N cuac`

Si el comando leído es de búsqueda `last N`, debes escribir los últimos N cuacs.

Si el comando leído es de búsqueda `follow NOMBRE`, debes escribir los mensajes del usuario NOMBRE.

Si el comando leído es de búsqueda `date FECHA1 FECHA2`, debes escribir los mensajes comprendidos entre FECHA1 y FECHA2, ambas inclusive.

Los mensajes se escribirán siempre desde el más reciente hasta el más antiguo (usando el orden de la clase Cuac definido en el ejercicio 004). Y en primer lugar se escribirá la línea de búsqueda correspondiente. El formato será el siguiente:

```
LINEA_DE_BUSQUEDA
1. NOMBRE_USUARIO FECHA_HORA
   MENSAJE
2. NOMBRE_USUARIO FECHA_HORA
   MENSAJE
...
N. NOMBRE_USUARIO FECHA_HORA
   MENSAJE
Total: N cuac
```

Si no hay ningún cuac en la búsqueda, se escribirá simplemente: `Total: 0 cuac`.

## Ejemplo de Entrada

```
mcuac RafaelNaval
25/10/2011 13:45:11
¡Feliz Navidad #amigosdenaval y próspero año nuevo!
pcuac RafaelNaval
28/11/2012 11:27:08
5
last 1
last 3
follow Perico
follow RafaelNaval
mcuac GinesGM
6/5/2012 16:00:00
Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
date 28/11/2011 11:27:04 28/11/2012 11:27:08
pcuac Gutierrez
1/1/2012 00:00:00
27
last 100
pcuac GinesGM
1/1/2012 00:00:00
30
mcuac GinesGM
1/1/2012 00:00:00
Muchas gracias...
follow GinesGM
last 5
date 6/5/2012 16:00:00 1/1/2013 00:00:00
exit
```

## Ejemplo de Salida

```
1 cuac
2 cuac
last 1
1. RafaelNaval 28/11/2012 11:27:08
   Enhorabuena, campeones!
Total: 1 cuac
last 3
1. RafaelNaval 28/11/2012 11:27:08
   Enhorabuena, campeones!
2. RafaelNaval 25/10/2011 13:45:11
   ¡Feliz Navidad #amigosdenaval y próspero año nuevo!
Total: 2 cuac
follow Perico
Total: 0 cuac
follow RafaelNaval
1. RafaelNaval 28/11/2012 11:27:08
   Enhorabuena, campeones!
2. RafaelNaval 25/10/2011 13:45:11
   ¡Feliz Navidad #amigosdenaval y próspero año nuevo!
Total: 2 cuac
3 cuac
date 28/11/2011 11:27:04 28/11/2012 11:27:08
1. RafaelNaval 28/11/2012 11:27:08
   Enhorabuena, campeones!
2. GinesGM 6/5/2012 16:00:00
   Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
Total: 2 cuac
4 cuac
last 100
1. RafaelNaval 28/11/2012 11:27:08
   Enhorabuena, campeones!
2. GinesGM 6/5/2012 16:00:00
   Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
3. Gutierrez 1/1/2012 00:00:00
   Me despido hasta la proxima. Buen viaje!
4. RafaelNaval 25/10/2011 13:45:11
   ¡Feliz Navidad #amigosdenaval y próspero año nuevo!
Total: 4 cuac
5 cuac
6 cuac
follow GinesGM
1. GinesGM 6/5/2012 16:00:00
   Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
2. GinesGM 1/1/2012 00:00:00
   El que quiera saber mas, que se vaya a Salamanca.
3. GinesGM 1/1/2012 00:00:00
   Muchas gracias...
Total: 3 cuac
last 5
1. RafaelNaval 28/11/2012 11:27:08
   Enhorabuena, campeones!
2. GinesGM 6/5/2012 16:00:00
   Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
3. GinesGM 1/1/2012 00:00:00
   El que quiera saber mas, que se vaya a Salamanca.
4. Gutierrez 1/1/2012 00:00:00
   Me despido hasta la proxima. Buen viaje!
5. GinesGM 1/1/2012 00:00:00
   Muchas gracias...
Total: 5 cuac
date 6/5/2012 16:00:00 1/1/2013 00:00:00
1. RafaelNaval 28/11/2012 11:27:08
   Enhorabuena, campeones!
2. GinesGM 6/5/2012 16:00:00
   Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
Total: 2 cuac
```