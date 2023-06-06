#include "saveFile.h"
#include "openFile.h"
#include "newFile.h"
#include "configColors.h"
#include "configAutoSave.h"
#include "overflow.h"

void interface();
void interface()
{
  int opc;
  printf("***** Bienvenidos a CVIM-UNIX (mi editor de texto) *****\n");
  printf("1. Abrir archivo\n");
  printf("2. Guardar archivo\n");
  printf("3. Nuevo archivo\n");
  printf("4. Configurar colores\n");
  printf("5. Configurar autoguardado\n");
  printf("Otro boton para Salir\n");
  printf("Ingrese una opcion: ");
  scanf("%d", &opc);
  printf("El número que ingresaste es: %d\n", opc);
  switch (opc)
  {
  case 1:
    openFile();
    break;
  /* case 2:
    saveFile();
    break;
  case 3:
    newFile();
    break;
  case 4:
    configColors();
    break;
  case 5:
    configAutoSave();
    break; */
  default:
    // exit();
    break;
  }
}