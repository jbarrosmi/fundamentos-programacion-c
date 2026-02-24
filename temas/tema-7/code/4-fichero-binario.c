#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del jugador
struct Jugador { //struct es un tipo de dato definido por el usuario o personalizado
    char nombre[50]; //la primera letra se suele poner en mayus Jugador en este caso (de 0 a 49 posiciones de caracteres)
    int nivel; //esta estructura es similar al array, pero en este caso se guardan diferentes tipos de datos
    int puntos; //en este caso char e int
};

int main() {
    struct Jugador jugador;

    // Solicitar los datos del jugador
    printf("Introduce el nombre del jugador: ");
    scanf("%49s", jugador.nombre); // Limitar la entrada a 49 caracteres para evitar cosumir el ultimo dato al pulsar enter
    printf("Introduce el nivel del juego: ");
    scanf("%d", &jugador.nivel);
    printf("Introduce los puntos del jugador: ");
    scanf("%d", &jugador.puntos);

    // Guardar los datos en un fichero binario
    FILE *fichero = fopen("ficheros\\jugador.dat", "wb"); //writting binary
    if (fichero == NULL) {
        perror("Error al abrir el fichero para escritura");
        return 1;
    }
    fwrite(&jugador, sizeof(struct Jugador), 1, fichero); //cuantos datos, cuantos registros y donde
    fclose(fichero);
    printf("Datos del jugador guardados correctamente en 'jugador.dat'.\n");

    // Leer los datos desde el fichero binario
    struct Jugador jugadorLeido;
    fichero = fopen("ficheros\\jugador.dat", "rb"); //read binary
    if (fichero == NULL) {
        perror("Error al abrir el fichero para lectura");
        return 1;
    }
    fread(&jugadorLeido, sizeof(struct Jugador), 1, fichero);
    fclose(fichero);

    // Mostrar los datos leídos en pantalla
    printf("\nDatos del jugador leídos desde el fichero:\n");
    printf("Nombre: %s\n", jugadorLeido.nombre);
    printf("Nivel: %d\n", jugadorLeido.nivel);
    printf("Puntos: %d\n", jugadorLeido.puntos);

    return 0;
}
