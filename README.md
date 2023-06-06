# cvim-unix
## Descripción
En esta opción se debe desarrollar un procesador de texto como “nano” o “vim” para la consola el programa debe permitir abrir archivos, guardar archivos y guardar archivos con otro nombre. El programa maneja un buffer grande en un archivo temporal de manera que no estará trabajando sobre el archivo final, sólo en las acciones de guardar y leer. Debe cumplir con las siguientes características


## Características:
- Tener, al menos, las siguientes opciones: Abrir archivo, Guardar archivo, Guardar como.., Cambiar color de la letra, Configuración y Salir (pueden agregar opciones si lo desean)
- El proceso principal maneja la interfaz gráfica y la entrada de texto así como su presentación en pantalla.
- Un proceso se llama para guardar el archivo, otro proceso para abrir un archivo y otro proceso si se desea “guardar como”
- Deberá tener un proceso que permita configurar la opción de autoguardado y el tiempo para esta herramienta, así mismo, configurar el esquema de colores de la interfaz
- Un hilo debe estar llevando el procedimiento de autoguardado de manera que cada cierto tiempo se guarde el archivo automáticamente
- Un hilo debe hilo que maneje el formato de desborde de pantalla, es decir, que cuando una línea se pase del borde horizontal, se modifiquen todas las líneas para que pase a la siguiente línea y se mueva el resto del texto.
- Se debe evidenciar el uso de tuberías internas y externas, memoria compartida,  semáforos, procesos e hilos
