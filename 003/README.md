# 003 - Leyendo la Fecha y la Hora

## Contexto

La lectura/escritura de las horas es una necesidad básica en nuestro sistema, puesto que los mensajes vendrán ordenados por fechas y horas. Por lo tanto, necesitamos definir una clase que almacene una fecha y hora, con operaciones para leer, escribir y compararlas. A partir de ahora, cuando digamos "fecha" nos referimos a una fecha y hora.

## El Problema

Definir una clase Fecha, que será un tipo de datos para almacenar fechas. Este tipo tendrá una operación para leer una fecha en el formato definido en CUACKER, para escribirla por la salida estándar y otras para comparar dos fechas, indicando si una es menor que otra o si son iguales.

Utilizando ese tipo de datos, escribe un programa que lea fechas y las vaya comparando entre sí. En concreto, debe comparar cada fecha con la anterior y decir si es mayor, menor o igual.

## Entrada

La primera línea de la entrada contendrá un entero, N, que indica el número de casos de prueba existente.

A continuación vienen N líneas, cada una de las cuales contiene una fecha en el formato de CUACKER. Es decir, tendrán el formato:

`DD/MM/AAA HH:MM:SS`

Siendo: DD el día (de 1 a 31, según el mes); MM el mes (de 1 a 12); AAAA el año (de cuatro dígitos); HH la hora (de 00 a 23); MM los minutos (de 00 a 59); y SS los segundos (de 00 a 59). Día, mes y año no tendrán ceros a la izquierda; mientras que las horas, minutos y segundos tendrán siempre dos dígitos.

## Salida

La salida debe contener N-1 líneas, una para cada caso de prueba excepto para el primero.

Cada fecha i-ésima debes compararla con la (i-1)-ésima. Si la fecha i-ésima es menor que la fecha (i-1)-ésima, entonces debes escribir:

`DD/MM/AAA HH:MM:SS ES ANTERIOR A DD/MM/AAA HH:MM:SS`

Si es mayor, entonces debes escribir:

`DD/MM/AAA HH:MM:SS ES POSTERIOR A DD/MM/AAA HH:MM:SS`

Si es igual, entonces debes escribir:

`DD/MM/AAA HH:MM:SS ES IGUAL A DD/MM/AAA HH:MM:SS`

Donde en todos los casos anteriores, primero aparece la fecha i-ésima y luego la (i-1)-ésima.

## Ejemplo de Entrada

```
10
6/8/2002 09:32:22
6/8/2001 12:31:55
26/6/2003 13:15:01
26/6/2003 07:05:15
26/6/2003 07:05:15
23/3/2004 15:47:34
23/3/2004 15:47:35
23/3/2004 15:43:35
31/1/2004 18:37:25
3/2/2004 05:12:04
```

## Ejemplo de Salida

```
6/8/2001 12:31:55 ES ANTERIOR A 6/8/2002 09:32:22
26/6/2003 13:15:01 ES POSTERIOR A 6/8/2001 12:31:55
26/6/2003 07:05:15 ES ANTERIOR A 26/6/2003 13:15:01
26/6/2003 07:05:15 ES IGUAL A 26/6/2003 07:05:15
23/3/2004 15:47:34 ES POSTERIOR A 26/6/2003 07:05:15
23/3/2004 15:47:35 ES POSTERIOR A 23/3/2004 15:47:34
23/3/2004 15:43:35 ES ANTERIOR A 23/3/2004 15:47:35
31/1/2004 18:37:25 ES ANTERIOR A 23/3/2004 15:43:35
3/2/2004 05:12:04 ES POSTERIOR A 31/1/2004 18:37:25
```
