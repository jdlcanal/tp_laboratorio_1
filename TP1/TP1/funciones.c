#include <stdio.h>
#include <stdlib.h>

int MenuGeneral(){
    int opcion;

    printf("1. Ingrese el 1er operando: \n");
    printf("2. Ingrese el 2do operando: \n");
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n\n");
    printf("Seleccionar una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int MenuOperaciones(){
    int opcion;

    printf("\n1. Calcular la Suma \n");
    printf("2. Calcular la Resta \n");
    printf("3. Calcular la Division \n");
    printf("4. Calcular la Multiplicacion \n");
    printf("5. Calcular el Factorial(!A) \n\n");
    printf("Seleccionar una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int IngresoDeNumero(){
    int num;
    scanf("%d", &num);
    return num;
}

int Sumar(int a, int b){
    return a+b;
}
int Restar(int a, int b){
    return a-b;
}
float Dividir(float a, float b){
    return a/b;
}
int Multiplicar(int a, int b){
    return a*b;
}
int Factorial(int a){
    int fact=1;

    for(int i=1; i<=a; i++){
        fact=fact*i;
    }
    return fact;
}
