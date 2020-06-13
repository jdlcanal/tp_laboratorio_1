#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int menu();

int main()
{
    char seguir='s';
    char confirm;
    int primeraVez=0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL){
        printf("No se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }

    do{
        switch(menu())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                primeraVez=1;
                break;
            case 2:
                controller_loadFromBinary("data.bin",listaEmpleados);
                break;
            case 3:
                if(primeraVez==1){
                    controller_addEmployee(listaEmpleados);
                }
                else{
                    printf("Debes ingresar los datos primero!!!\n\n");
                }
                break;
            case 4:
                if(primeraVez==1){
                    controller_editEmployee(listaEmpleados);
                }
                else{
                    printf("Debes ingresar los datos primero!!!\n\n");
                }
                break;
            case 5:
                if(primeraVez==1){
                    controller_removeEmployee(listaEmpleados);
                }
                else{
                    printf("Debes ingresar los datos primero!!!\n\n");
                }
                break;
            case 6:
                if(primeraVez==1){
                    controller_ListEmployee(listaEmpleados);
                }
                else{
                    printf("Debes ingresar los datos primero!!!\n\n");
                }

                break;
            case 7:
                if(primeraVez==1){
                    controller_sortEmployee(listaEmpleados);
                }
                else{
                    printf("Debes ingresar los datos primero!!!\n\n");
                }

                break;
            case 8:
                if(primeraVez==1){
                    controller_saveAsText("data.csv",listaEmpleados);
                }
                else{
                    printf("Debes ingresar los datos primero!!!\n\n");
                }

                break;
            case 9:
                if(primeraVez==1){
                    controller_saveAsBinary("data.bin",listaEmpleados);
                }
                else{
                    printf("Debes ingresar los datos primero!!!\n\n");
                }

                break;
            case 10:
                printf("Esta seguro que desea salir? s/n: ");
                fflush(stdin);
                scanf("%c",&confirm);
                if(confirm=='s'){
                    seguir='n';
                    printf("Adios!! \n\n");
                }
                break;
            default:
                printf("ERROR!!! INGRESE UNA OPCION VALIDA!!!\n\n");
                break;
        }
        system("pause");
    }while(seguir=='s');
    return 0;
}
/** \brief Menu general del programa
 *
 * \return int
 *
 */

int menu(){
    int opcion;

    system("cls");
    printf("Bienvenido!\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10. Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
