// basic of C
#include <stdio.h>
// strings
#include <string.h>
// lib de hilos
#include <pthread.h>
// mi library
#include "lib/interface.h"

#define MAX_PWD 100
int main(int argc, char *argv[])
{
  // ! Obtener datos de argumentos
  /* if (argc > 2)
  {
    char route[MAX_PWD];
    strncpy(route, argv[1], MAX_PWD - 1);
    route[MAX_PWD] = '\0';
    printf("El caracter que ingresaste es: %s\n", route);
  }
  else
  {
    printf("No ingresaste ningun argumento al programa :C\n");
  } */
  // ! Semaforos
  /*
  <semaphore.h>
  inicializar
  value =
   int sem_init (sem_t, *sem, int pshared, unsigned int value)
  decrementar una unidad al semaforo, o bloquear acceso al recurso compartido
   int sem_wait (sem_t *sem)
  incrementar una unidad al semaforo, o desbloquear acceso al recurso compartido

   int sem_post (sem_t *sem)
  */
  // ! signals (señales)
  /*
  <signal.h>
  kill -l
  SIGKILL -> terminar un proceso
  SIGSTOP -> pausar un proceso
  SIGCONT -> reanudar un proceso

  signum -> numero de señal, de la lista de kill -l
  handler -> funcion que se ejecutara cuando se reciba la señal
    signal(int signum, &handlerFuntion)
  handlerFuntion (int signal ){
    printf("Se recibio la señal: %d\n", signal);
  }
  */
  // ! Flork procesos
  /*
  #include <unistd.h>
  pid_t pidChild;
  printf("El id del proceso actual es: %d\n", getpid());
  getpid() -> id del proceso actual
  fork() -> crea un proceso hijo
  pidChild = fork();
  printf("Proc PID : %d, pidC= %d ejecutandose \n", getpid(), pidChild);

  if(pidChild>0){
    printf("Soy el proceso padre, mi id es: %d\n", getpid());
  }else if(pidChild==0)){
    printf("Soy el proceso hijo, mi id es: %d\n", getpid());
  }  else{
    printf("Error al crear el proceso hijo\n");
  }
  */

  // ! Hilos
  /*
  <pthread.h>

    pthread_t thread; // id Hilo
    interface = rutine, funtion
    if (pthread_create(&thread, NULL, *interface, NULL) != 0)
    {
      return -1;
    }
    esperar a que terminen
    pthread_join(thread, NULL);
    interface(); */
  return 0;
}
