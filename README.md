# hc11-emulator

### WORK IN PROGRESS!!
La idea es crear un "backend" que ejecute código para el Motorola M68HC11, para después correrlo tanto en PC's como en placas Raspberry Pi Pico (cada cual con su respectivo "frontend"). El formato de los archivos es *.s19*, más info en [Wikipedia](https://en.wikipedia.org/wiki/SREC_(file_format)).

Por ahora funciona la carga de archivos a la memoria. Estoy trabajando en las funciones individuales y todavía falta la búsqueda de funciones según el opcode. Voy a tener que usar algo como un árbol de búsqueda porque hay opcodes de 8 y 16 bits. No me importa ocupar mucha memoria en compu, pero hay que ver cuánto banca la Pico.

**¿Por qué en C?**

Como casi todo el código se basa en manipular memoria, el lenguaje C resulta mucho más intuitivo que otros de más alto nivel. Además, la placa RPi Pico puede ser programada en C/C++ usando el [SDK](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html), que nos da mucho mejor control de los *timers* del microcontrolador. De esta forma, se puede hacer que cada operación dure lo que duraría en un HC11 de verdad. Si bien C++ proporciona librerías con estructuras de datos y algoritmos avanzados, me interesa implementar la búsqueda en C por mi cuenta.
