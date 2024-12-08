# hc11-emulator

### WORK IN PROGRESS!!
La idea es crear un "backend" que ejecute código para el Motorola M68HC11, para después correrlo tanto en PC's como en placas Raspberry Pi Pico (cada cual con su respectivo "frontend"). El formato de los archivos es *.s19*, más info en [Wikipedia](https://en.wikipedia.org/wiki/SREC_(file_format)).

Por ahora funciona la carga de archivos a la memoria y la búsqueda por opcode (falta testear bien). Queda escribir las funciones de cada opcode individualmente, que es la parte más tediosa.

**¿Por qué en C?**

Como casi todo el código se basa en manipular memoria, el lenguaje C resulta mucho más intuitivo que otros de más alto nivel. Además, la placa RPi Pico puede ser programada en C/C++ usando el [SDK](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html), que nos da mucho mejor control de los *timers* del microcontrolador. De esta forma, se puede hacer que cada operación dure lo que duraría en un HC11 de verdad. Si bien C++ proporciona librerías con estructuras de datos y algoritmos avanzados, no es muy complejo escribir el algoritmo de búsqueda que necesito. Por último pero no menos importante, aguante C (soy de Ing. Electrónica).

**Código Python**

El script en Python está para generar el arreglo de ```inst_t``` y el boilerplate de las funciones para la parte de *instrucciones*. La idea es que sea relativamente simple adaptar el código a otro procesador. Queda hacer que el script genere el texto completo, pero es úitl tenerlo así como está.