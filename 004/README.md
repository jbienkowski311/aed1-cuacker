# 004 - El tipo de datos Cuac

## Contexto

Los mensajes, llamados en nuestro sistema cuac, son el tipo de datos fundamental en nuestra aplicación. Un cuac contiene el nombre del usuario, la fecha y hora en la que ha sido enviado, y un texto que como máximo tendrá 140 caracteres. En nuestro caso, los cuac pueden ser de dos tipos:

Los pcuac, donde el mensaje es un número, que se debe traducir en un texto según la tabla prefedinida del ejercicio 001.
Los mcuac, donde el mensaje es un texto arbitrario.

## El Problema

Definir una clase para almacenar un cuac, ya sea de tipo pcuac o mcuac. Se debe intentar conseguir eficiencia en el uso de memoria. La clase debe tener operaciones para leer un cuac, escribirlo por pantalla, y comparar dos cuac.

La comparación se realizará de la siguiente manera. Como queremos que los mensajes se muestren de más a menos recientes, en primer lugar se compara por fecha. Un cuac es "anterior" a otro si su fecha es posterior; en caso de empate, se compara el texto del mensaje en orden alfabético de menor a mayor; y en caso de empate, se compara el nombre del usuario en orden alfabético de menor a mayor.

Utilizando ese tipo de datos, debes escribir un programa que lea los cuac, de ambos tipos, y los escriba por pantalla, según el formato de CUACKER.

## Entrada

La entrada contendrá varios casos de prueba y terminará cuando no quede más entrada.

Cada caso de prueba es un mensaje, que puede ser de tipo mcuac o pcuac. Los mensajes de tipo mcuac son de la forma:

```
mcuac NOMBRE_USUARIO
FECHA_HORA
MENSAJE_DE_TEXTO
```

Siendo: NOMBRE_USUARIO el nombre del usuario (que no contendrá espacios en blanco); FECHA_HORA la fecha y hora del mensaje (según el formato del ejercicio 003); y MENSAJE_DE_TEXTO una cadena de no más de 140 caracteres.

Los mensajes de tipo pcuac son de la forma:

```
pcuac NOMBRE_USUARIO
FECHA_HORA
NUMERO
```

Siendo: NUMERO un número entero entre 1 y 30, inclusives.

## Salida

Para cada caso de prueba debes escribir el número total de cuac leídos hasta este punto, N, de la forma:

`N cuac`

A continuación debes escribir el mensaje según el formato de las búsquedas. Es decir, debes escribir primero el NOMBRE_USUARIO, luego un espacio en blanco y después la FECHA_HORA. En la siguiente línea debes empezar con tres espacios en blanco y luego el mensaje. En el caso de los pcuac, el número debe ser sustituido por el texto predefinido correspondiente (ver el ejercicio 001).

```
NOMBRE_USUARIO FECHA_HORA
   MENSAJE
```

```
Ejemplo de Entrada
mcuac RafaelNaval
25/10/2011 13:45:11
¡Feliz Navidad #amigosdenaval y próspero año nuevo!
pcuac RafaelNaval
28/11/2011 11:27:08
5
mcuac GinesGM
6/5/2012 16:00:00
Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
pcuac Gutierrez
1/1/2013 00:00:00
27
pcuac GinesGM
1/1/2013 00:00:00
30
```

Nota: los caracteres especiales (tildes, eñes, etc.) están codificados con UTF-8.

## Ejemplo de Salida

```
1 cuac
RafaelNaval 25/10/2011 13:45:11
   ¡Feliz Navidad #amigosdenaval y próspero año nuevo!
2 cuac
RafaelNaval 28/11/2011 11:27:08
   Enhorabuena, campeones!
3 cuac
GinesGM 6/5/2012 16:00:00
   Dicen en #eltiempo que este lunes va a venir una tormenta muy grande...
4 cuac
Gutierrez 1/1/2013 00:00:00
   Me despido hasta la proxima. Buen viaje!
5 cuac
GinesGM 1/1/2013 00:00:00
   El que quiera saber mas, que se vaya a Salamanca.
```
