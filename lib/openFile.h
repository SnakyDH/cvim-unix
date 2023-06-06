#include <fcntl.h>
#include <unistd.h>
bool openFile();
bool openFile(char *file, int pid)
{
  int fd;
  char buffer[100];
  ssize_t nr_bytes; // Numero de bytes leidos
  // ! ( WRONLY | O_APPEND)
  // O_WRONLY: Solo escritura
  // write(fd,buffer, sizeof(buffer)-1);
  // O_APPEND: Escribe al final del archivo
  // O_RDONLY: Solo lectura
  char path[] = "/home/snakydev/Projects/cvim-unix/test/";
  strcat(path, file);
  printf("%s \n", path);
  fd = open(path, O_RDONLY);
  fd; // file
  if (fd == -1)
  {
    printf("Error al abrir el archivo\n");
    return false;
  }
  else
  {
    printf("Archivo abierto correctamente\n");
    nr_bytes = read(fd, buffer, 50);
    close(fd);
    if (nr_bytes == 0)
    {
      printf("Archivo Vacio\n");
      return true;
    }
    else
    {
      printf("El numero de caracteres leidos es: %d\n, contenido: %s", (int)nr_bytes, buffer);
      return true, fd;
    }
  }
}