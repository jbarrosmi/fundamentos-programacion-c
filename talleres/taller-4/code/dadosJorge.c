#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    struct Jugador
    {
        char nombre[50];
        int puntuacion;
    };

int main()
{
srand((unsigned)time(NULL));
struct Jugador jugadores[2] = {0};

printf("Nombre jugador 1: ");
scanf("%49s", jugadores[0].nombre);
jugadores[0].puntuacion = 0;

printf("Nombre jugador 2: ");
scanf("%49s", jugadores[1].nombre);
jugadores[1].puntuacion = 0;

int numJugadores = sizeof(jugadores) / sizeof(jugadores[0]); // Número de jugadores en el array
inicio:
system ("cls");
    FILE *fichero = fopen("puntuaciones.dat", "wb"); //writting binary
    if (fichero == NULL) {
        perror("Error al abrir el fichero para escritura");
        return 1;
    }
    fwrite(jugadores, sizeof(struct Jugador), numJugadores, fichero); //cuantos datos, cuantos registros y donde
    fclose(fichero);

    printf("Datos del jugador actualizados correctamente en 'jugador.txt'.\n");
    printf("\n");
    printf("1. Para jugar.\n");
    printf("2. Para ver puntuaciones.\n");
    printf("3. Para salir.\n");

    int seleccion;
    scanf("%d",&seleccion);

    if(seleccion==1){
        system("cls");
        printf("Elige el numero de caras del dado:\n");
        int caras;
        scanf("%d", &caras);
            if(caras <= 0)
                {printf("Numero de caras invalido. No se te ha ocurrido que un dado tenga cero caras, o negativas.\n");
                getchar();
                goto inicio;
                }

        int dado1 = rand() % caras +1;
        int dado2 = rand() % caras +1;
        system("cls");
        printf("Resultado de las tiradas es %d vs %d\n", dado1, dado2);
        if(dado1 > dado2)
        {
            printf("Enhorabuena, has ganado.\n");
            jugadores[0].puntuacion +=1;
            getchar();
            getchar();
            goto inicio;
        }
        else if(dado1 == dado2)
        {
            printf("Hay empate, no se actualizan puntuaciones.\n");
            getchar();
            getchar();
            goto inicio;
        }
        else if(dado1 < dado2)
        {
            printf("Has perdido.\n");
            jugadores[1].puntuacion +=1;
            getchar();
            getchar();
            goto inicio;
        }
    }
    else if(seleccion == 2)
    {
        system("cls");
        struct Jugador jugadoresLeidos[numJugadores];
        fichero = fopen("puntuaciones.dat", "rb");
        if (fichero == NULL) {
            perror("Error al abrir el fichero para lectura");
            goto inicio;
            return 1;
        }
        fread(jugadoresLeidos, sizeof(struct Jugador), numJugadores, fichero);
        fclose(fichero);
            // Mostrar los datos leídos en pantalla
        printf("Datos de los jugadores leidos desde el fichero:\n");
        for (int i = 0; i < numJugadores; i++) {
            printf("Jugador %d:\n", i + 1);
            printf("  Nombre: %s\n", jugadoresLeidos[i].nombre);
            printf("  Puntuacion: %d\n", jugadoresLeidos[i].puntuacion);
            printf("Pulse enter para volver al menu.\n");
            getchar();
        }
    }
    else if(seleccion == 3)
    {
        return 0;
    }
    goto inicio;
}