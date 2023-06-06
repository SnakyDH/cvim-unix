int interface();
int interface(char route[], int pidPrincipal)
{
  printf("Archivo o Ruta: %s\n", route);
  int opc;
  printf("***** Bienvenidos a CVIM-UNIX (mi editor de texto) *****\n");
  printf("PID Principal es: %d\n", pidPrincipal);
  printf("***** Opciones *****\n");
  printf("1. Abrir archivo\n");
  printf("2. Guardar archivo\n");
  printf("3. Nuevo archivo\n");
  printf("4. Configurar colores\n");
  printf("5. Configurar autoguardado\n");
  printf("Otro boton para Salir\n");
  printf("Ingrese una opcion: ");
  scanf("%d", &opc);
  return opc;
}