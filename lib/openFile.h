#include <fcntl.h>
#include <unistd.h>
void openFile();
void openFile()
{
  int fd;
  char buffer[100];
  ssize_t nr_bytes; // Numero de bytes leidos
  // ! ( WRONLY | O_APPEND)
  // O_WRONLY: Solo escritura
  // write(fd,buffer, sizeof(buffer)-1);
  // O_APPEND: Escribe al final del archivo
  fd = open("/home/snakydev/Projects/cvim-unix/test/openFile.txt", O_RDONLY);
  if (fd == -1)
  {
    printf("Error al abrir el archivo\n");
  }
  else
  {
    printf("Archivo abierto correctamente\n");
    nr_bytes = read(fd, buffer, 50);
    close(fd);
    if (nr_bytes == 0)
    {
      printf("Archivo Vacio\n");
    }
    else
    {
      printf("El numero de caracteres leidos es: %d\n, contenido: %s", (int)nr_bytes, buffer);
    }
  }
}