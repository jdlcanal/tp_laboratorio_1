#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#define TAM 1000
#define TAMSEC 5

int Menu();

int main()
{
    char seguir='s';
    char confirm;
    int primeraVez=0;
    int proxId=1000;

    eEmpleado empleado[TAM];
    eSector sector[TAMSEC]={{1, "Sistemas"},{2, "RRHH"},{3,"Ventas"},{4, "Compras"},{5, "Contable"}};
    InicializarEmpleados(empleado, TAM);

    do{
        switch(Menu()){
        case 1:
            if(AltaEmpleado(proxId, empleado, TAM, sector, TAMSEC)){
                primeraVez++;
                proxId++;
            }
            break;
        case 2:
            if(primeraVez==0){
                printf("\nERROR!!! Primero debe ingresar un empleado!\n\n");
                break;
            }
            ModificarEmpleado(empleado, TAM, sector, TAMSEC);
            break;
        case 3:
            if(primeraVez==0){
                printf("\nERROR!!! Primero debe ingresar un empleado!\n\n");
                break;
            }
            BajaEmpleado(empleado, TAM, sector, TAMSEC);
            break;
        case 4:
            if(primeraVez==0){
                printf("\nERROR!!! Primero debe ingresar un empleado!\n\n");
                break;
            }
            MostrarEmpleados(empleado, TAM, sector, TAMSEC, primeraVez);
            break;
        case 5:
            printf("Confirma Salir? s/n: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm=='s'){
                seguir='n';
            }
            break;
        }
    system("pause");
    }while(seguir=='s');



    return 0;
}

int Menu(){
    int opcion;
    system("cls");
    printf("Bienvenido!!\nSeleccione una opcion, por favor: \n\n");
    printf("1. Altas\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informar\n");
    printf("5. Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
