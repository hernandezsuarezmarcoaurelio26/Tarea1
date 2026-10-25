
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

FILE *archivo;
pthread_mutex_t mutex;

void *imprimir_descendente(void *arg)
{
    int i;

    pthread_mutex_lock(&mutex);

    fprintf(archivo, "HILO: Numeros del 10000 al 1\n");

    for (i = 10000; i >= 1; i--)
    {
        fprintf(archivo, "%d\n", i);
    }

    fprintf(archivo, "\n");

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(void)
{
    pthread_t hilo;
    int i;

    
    archivo = fopen("resultado.txt", "w");

    if (archivo == NULL)
    {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    pthread_mutex_init(&mutex, NULL);

    
    if (pthread_create(&hilo, NULL, imprimir_descendente, NULL) != 0)
    {
        printf("Error al crear el hilo.\n");
        fclose(archivo);
        pthread_mutex_destroy(&mutex);
        return 1;
    }

    
    pthread_mutex_lock(&mutex);

    fprintf(archivo, "PROCESO PRINCIPAL: Numeros del 1 al 10000\n");

    for (i = 1; i <= 10000; i++)
    {
        fprintf(archivo, "%d\n", i);
    }

    fprintf(archivo, "\n");

    pthread_mutex_unlock(&mutex);

    
    pthread_join(hilo, NULL);

    fprintf(archivo, "Ambos recorridos han terminado.\n");

   
    fclose(archivo);

    pthread_mutex_destroy(&mutex);

    printf("Programa terminado. Revisa el archivo resultado.txt\n");

    return 0;
}
