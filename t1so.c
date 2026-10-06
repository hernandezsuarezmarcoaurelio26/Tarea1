#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    FILE *archivo;
    int i;

    archivo = fopen("resultado.txt", "w");

    if (archivo == NULL) {
        printf("Error al crear el archivo resultado.txt\n");
        return 1;
    }

    fprintf(archivo, "========================================\n");
    fprintf(archivo, "RESULTADO DE LA EJECUCION\n");
    fprintf(archivo, "========================================\n\n");

  
    fprintf(archivo, "========== PROCESO PADRE ==========\n");

    for (i = 1; i <= 10000; i++) {
        fprintf(archivo, "%d\n", i);
    }

    fprintf(archivo, "\n========== FIN PROCESO PADRE ==========\n\n");

   
    fprintf(archivo, "========== PROCESO HIJO ==========\n");

    for (i = 10000; i >= 1; i--) {
        fprintf(archivo, "%d\n", i);
    }

    fprintf(archivo, "\n========== FIN PROCESO HIJO ==========\n");

    fclose(archivo);

    printf("Programa terminado correctamente.\n");
    printf("Los resultados se guardaron en: resultado.txt\n");

    system("pause");

    return 0;
}