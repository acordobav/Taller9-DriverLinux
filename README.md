# Biblioteca LFSR
Esta biblioteca permite la generación de números pseudo-aleatorios utilizando el algoritmo Linear-feedback shift register (LFSR) de 16 bits. Además, permite la medición de tiempo de ejecución gracias a la implementación de un driver personalizado.

## Generación de números pseudo-aleatorios
La siguiente función:

```
int lfsr_16(int seed);
```

permite la generación de números pseudo-aleatorios utilizando una semilla. Los números son generados utilizando la versión del algoritmo para números de 16 bits.

## Medición de tiempo
Para medir el tiempo con el driver, es necesario utilizar la función 

```
void init_timer();
```

para inicializar el timer. Para leer el contador, se debe utilizar la función

```
int read_timer();
```

Si se desea detener el contador, se debe utilizar la función

```
void end_timer();
```
