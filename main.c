#include <stdio.h>     // Basics C
#include <signal.h>    // Signals
#include <pthread.h>   // Hilos
#include <string.h>    // Strings
#include <unistd.h>    // Proccess and pipes
#include <semaphore.h> // Semaphores
#include <stdbool.h>   // Boolean
#include <stdlib.h>    // Exit(0)
// My libraries
#include "lib/interface.h" // Interface
#include "lib/saveFile.h"
#include "lib/openFile.h"
#include "lib/newFile.h"
#include "lib/configColors.h"
#include "lib/configAutoSave.h"
#include "lib/overflow.h"
#include "lib/exitProgram.h"
// My define
#define MAX_PWD 100
#define MAX_BUFFER 100

int main(int argc, char *argv[])
{
  // Principals Varibles
  int opc = 1;
  int fd[2]; // file descriptor pipe lines
  char buffer[MAX_BUFFER];
  ssize_t nr_bytes; // Numero de bytes leidos
  char initialPath[] = "/home/snakydev/Projects/cvim-unix/test/";
  pthread_t threadFileDescriptor;
  // Childs Varibles
  pid_t pidChildOpenFile;
  pid_t pidChildSaveFile;
  pid_t pidChildNewFile; // Save As File
  // Problematics Varibles
  pid_t pidChildConfigColors;
  pid_t pidChildConfigAutoSave;
  if (argc <= 1)
  {
    printf("****** Error: No se ingreso ningun archivo o ninguna ruta ******\n");
    return -1;
  }
  char route[MAX_PWD];
  strncpy(route, argv[1], MAX_PWD - 1);
  route[MAX_PWD] = '\0';
  strcat(initialPath, argv[1]);
  printf("El caracter que ingresaste es: %s\n", route);
  // fd = open(route, O_WRONLY | O_APPEND);
  /* while (opc == 1 || opc == 2 || opc == 3 || opc == 4 || opc == 5)
  { */
  int pidPrincipal = getpid();
  opc = interface(initialPath, pidPrincipal);
  pipe(fd);
  switch (opc)
  {
  case 1:
    pidChildOpenFile = fork();
    if (pidChildOpenFile == 0) // Hijo
    {
      char msg[] = "Hola desde OpenFile";
      close(fd[0]);                   // Lecutra
      write(fd[1], msg, sizeof(msg)); // escritura
      close(fd[1]);                   // Escritura
      printf("OpenFile PID: %d\n", getpid());
      if (openFile(initialPath, getpid()))
      {
        printf("Archivo abierto correctamente\n");
      }
      exit(0);
    }
    else if (pidChildOpenFile == -1)
    {
      printf("****** Error: No se pudo crear  proceso OPENFILE ******\n");
    }
    else
    {               // Padre
      close(fd[1]); // Escritura
      int numBytes;
      numBytes = read(fd[0], buffer, sizeof(buffer));
      close(fd[0]); // Escritura
    }
    break;
  case 2:
    pidChildSaveFile = fork();
    printf("saveFile PID: %d\n", getpid());
    if (pidChildSaveFile == 0)
    {
      saveFile();
    }
    else if (pidChildSaveFile == -1)
    {
      printf("****** Error: No se pudo crear  proceso SAVEFILE ******\n");
    }
    break;
  case 3:
    pidChildNewFile = fork();
    printf("newFile PID: %d\n", getpid());
    if (pidChildNewFile == 0)
    {
      newFile();
    }
    else if (pidChildNewFile == -1)
    {
      printf("****** Error: No se pudo crear  proceso NEWFILE ******\n");
    }
    break;
  case 4:
    pidChildConfigColors = fork();
    printf("configColors PID: %d\n", getpid());
    if (pidChildConfigColors == 0)
    {
      configColors();
    }
    break;
  case 5:
    pidChildConfigAutoSave = fork();
    printf("configAutoSave PID: %d\n", getpid());
    if (pidChildConfigAutoSave == 0)
    {
      configAutoSave();
    }
    break;
  default:
    return exitProgram();
    break;
  }
  //} while

  return 0;
}
