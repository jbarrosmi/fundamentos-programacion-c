#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generarNumeros(int numeros[]) //aleatoriedad en numeros
{
    srand(time(NULL)); //semilla aleatoria
    for (int i = 0; i < 100; i++)
        {numeros[i] = rand() % 100+1;}
}
int encontrarmayor(int numeros[]){
    int mayor = numeros[0]; //esto elige el valor de índice 0 (el primero)
    for (int i = 1; i < 20; i++) //esto desplaza los indices para encontrar el valor más alto
    {
        if (numeros[i] > mayor) //cuando encuentre el mayor
        {
            mayor = numeros[i]; //lo guarda como mayor
        }
    }
    return mayor; //y lo devuelve
}
int encontrarmenor(int numeros[]){
    int menor = numeros[0];
    for (int i = 1; i < 20; i++)
    {
        if(numeros[i] < menor)
        {
            menor = numeros[i];
        }
    }
    return menor;
}
int main(){
inicio:
    int numeros[20];
    generarNumeros(numeros);
    printf("Se han generado 20 numeros aleatorios.\n");
    printf("Tienes 10 intentos. Adivina el número mayor:\n");
    int eleccion;
    int intentos = 0;
    do{
    scanf("%d", &eleccion);
    int salidamayor = encontrarmayor(numeros);
    if(eleccion == salidamayor){
        printf("Correcto, el numero mayor es %d", salidamayor);
        goto continuar;
    }
    else{
        intentos ++; //tambien podría ser intentos=intentos+1
        if(intentos == 10){
            printf("Se acabaron los %d intentos\n", intentos);
            system("cls");
            goto inicio;
        }
        else
        {
            printf("Intento n:%d \n", intentos);
            printf("Vuelve a intentarlo:\n");
        }
    }
    }while (intentos < 10);
    continuar:
    printf("\nEnhorabuena. Te quedan %d intentos. Ahora adivina el menor:\n", &intentos);
    int salidamenor = encontrarmenor(numeros);
    do{
    scanf("%d", &eleccion);
        if(eleccion == salidamenor){
        printf("Correcto, el numero menor es %d", salidamenor);
    }
    else{
        intentos ++; //tambien podría ser intentos=intentos+1
        if(intentos == 10){
            printf("Se acabaron los %d intentos\n", intentos);
            system("cls");
            goto inicio;
        }
        else
        {
            printf("Intento n:%d \n", intentos);
            printf("Vuelve a intentarlo:\n");
        }
    }
    }while (intentos < 10);

}