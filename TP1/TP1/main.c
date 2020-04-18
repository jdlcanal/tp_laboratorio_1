#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{   char respuesta='s';
    int num1;
    int num2;
    int flagNum1=0;
    int flagNum2=0;
    int flagOperador=0;
    int flagOperadorSuma=0;
    int flagOperadorResta=0;
    int flagOperadorDivision=0;
    int flagOperadorMultiplicacion=0;
    int flagOperadorFactorial=0;

    do{
    printf("TP1. Bienvenidos a la Calculadora!!!\n\n");
//********************************INICIO DEL MENU*************************************
    switch(MenuGeneral()){
        case 1://PRIMER NUM
            flagNum1=1;
            printf("Ingrese el 1er operando: ");
            num1=IngresoDeNumero();
            break;
        case 2://SEGUNDO NUM
            flagNum2=1;
            printf("Ingrese el 2do operando: ");
            num2=IngresoDeNumero();
            break;
        case 3://MENU DE OPERACIONES
            if(flagNum1==0 || flagNum2==0){
                printf("\nERROR!!! Debes ingresar los dos operandos antes de calcular!!!\n\n");
                break;
            }
    //************INICIO DEL SUBMENU********************************
            flagOperador=1;
            switch(MenuOperaciones()){
            case 1://SUMA
                    flagOperadorSuma=1;
                    printf("%d + %d \n\n", num1, num2);
                break;
            case 2://RESTA
                    flagOperadorResta=1;
                    printf("%d - %d \n\n", num1, num2);
                break;
            case 3://DIVISION
                if(num1==0 || num2==0){
                    flagOperador=0;
                    printf("\nERROR!! Selecciona un numero que no sea 0\n\n");
                } else{
                    flagOperadorDivision=1;
                    printf("%d / %d \n\n", num1, num2);
                }
                break;
            case 4://MULTIPLICACION
                if(num1==0 || num2==0){
                    flagOperador=0;
                    printf("\nERROR!! Selecciona un numero que no sea 0\n\n");
                } else{
                    flagOperadorMultiplicacion=1;
                    printf("%d * %d \n\n", num1, num2);
                }
                break;
            case 5://FACTORIAL
                if(num1==0 || num2==0){
                    flagOperador=0;
                    printf("\nERROR!! Selecciona un numero que no sea 0\n\n");
                } else{
                    flagOperadorFactorial=1;
                    printf("!%d y !%d \n\n", num1, num2);
                }
                break;
            default:
                printf("\nERROR!!! Selecciona una opcion valida!!!\n\n");
                break;
            }
            break;
            //************************FIN DEL SUBMENU****************************
        case 4: //RESULTADOS
            if (flagNum1==0 || flagNum2==0){
                printf("\nERROR!!! Debes ingresar los operandos antes de calcular!!!\n\n");
                break;
            } else if (flagOperador==0){
                printf("\nERROR!!! Debes seleccionar una operacion!!!\n\n");
                break;
            }
        //*******************MUESTRA DE RESULTADOS****************************************************
            if (flagOperadorSuma==1){
                printf("El resultado de %d + %d es: %d\n\n", num1, num2, Sumar(num1, num2));
            }
            if (flagOperadorResta==1){
                printf("El resultado de %d - %d es: %d\n\n", num1, num2, Restar(num1, num2));
            }
            if (flagOperadorDivision==1){
                printf("El resultado de %d / %d es: %f\n\n", num1, num2, Dividir(num1, num2));
            }
            if (flagOperadorMultiplicacion==1){
                printf("El resultado de %d * %d es: %d\n\n", num1, num2, Multiplicar(num1, num2));
            }
            if (flagOperadorFactorial==1){
                printf("El factorial de %d es: %d\nEl factorial de %d es: %d\n\n", num1, Factorial(num1), num2, Factorial(num2));
            }
        //******************FIN DE RESULTADOS***************************************************************
            break;
        case 5:
            printf("\nNos vemos!!!\n\n");//SALIR
            respuesta='n';
            break;
        default:
            printf("\nERROR!!! Selecciona una opcion valida!!!\n\n");
            break;
//*********************************FIN DEL MENU************************************************
    }
    system("pause");
    printf("\n");

    }while(respuesta=='s');
    return 0;
}

