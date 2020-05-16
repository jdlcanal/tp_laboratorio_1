#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"


void InicializarEmpleados(eEmpleado vec[], int tam){
    for(int i=0;i<tam;i++){
        vec[i].isEmpty=1;
    }

}

int BuscarLibre(eEmpleado vec[], int tam){
    int indice=-1;

    for(int i=0; i<tam; i++){
        if(vec[i].isEmpty){
            indice=i;
            break;
        }
    }
    return indice;
}

int AltaEmpleado(int id, eEmpleado vec[], int tam, eSector sector[], int tamSec){
    int todoOk=0;
    int indice=BuscarLibre(vec, tam);
    eEmpleado auxEmpleado;

    system("cls");

    printf("******* ALTA EMPLEADO *******\n\n");

    if(indice==-1){
        printf("Sistema Completo\n\n");
        } else{
            auxEmpleado.id=id;
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(auxEmpleado.nombre);
            ManipularCadenas(auxEmpleado.nombre);

            printf("Ingrese Apellido: ");
            fflush(stdin);
            gets(auxEmpleado.apellido);
            ManipularCadenas(auxEmpleado.apellido);

            printf("Ingrese Sueldo: ");
            scanf("%f", &auxEmpleado.sueldo);

            MostrarSectores(sector, tamSec);
            printf("Ingrese Sector: ");
            scanf("%d", &auxEmpleado.sector);

            printf("\n\n");

            auxEmpleado.isEmpty=0;

            //-------------------
            vec[indice]=auxEmpleado;
            todoOk=1;
            printf("Empleado Agregado con Exito!!!!\n\n");
        }
            return todoOk;

}

void MostrarEmpleado(eEmpleado x, eSector sector[], int tamSec){
    char descSector[20];
    CargarDescripcionSector(descSector,x.sector,sector,tamSec);
    printf("%4d %15s %15s    %6.2f  %10s\n",x.id,x.nombre,x.apellido,x.sueldo,descSector);
}

void MostrarEmpleados(eEmpleado vec[], int tam, eSector sector[], int tamSec, int contEmpleados){
    float totalSueldos=0;
    float promedioSueldos=0;

    system("cls");
    printf("************ Lista de Empleados ************\n");
    printf(" Id       Nombre          Apellido       Sueldo       Sector  \n");

    OrdenarEmpleados(vec, tam);

    for(int i=0; i<tam; i++){
        if(vec[i].isEmpty==0){
            MostrarEmpleado(vec[i], sector, tamSec);
            totalSueldos+=vec[i].sueldo;
        }
    }
    printf("\n\n");

    promedioSueldos=totalSueldos/contEmpleados;
    printf("El Total de los Sueldos es de: %.2f\n",totalSueldos);
    printf("El Promedio de los Sueldos es de: %.2f\n",promedioSueldos);
    SuperaPromedioSueldos(promedioSueldos, vec, tam, sector, tamSec);
}

void ManipularCadenas(char x[]){
    int indice=1;

    x[0]=toupper(x[0]);

    while(x[indice]!='\0'){
        x[indice]=tolower(x[indice]);
        if(x[indice]==' '){

            x[indice+1]=toupper(x[indice+1]);
            indice++;
        }

        indice++;
    }
}

void MostrarSectores(eSector sector[], int tam){
    printf("\n************ Sectores ************\n\n");
    printf("Id   Descripcion\n");

    for(int i=0; i<tam; i++){
    printf("%d  %10s    \n",sector[i].idSector, sector[i].descSector);

    }
    printf("\n");
}

void CargarDescripcionSector(char descripcion[], int id, eSector sector[], int tamSec){
     for(int i=0; i<tamSec; i++){
        if(sector[i].idSector==id){
            strcpy(descripcion, sector[i].descSector);
        }
    }
}

void ModificarEmpleado(eEmpleado empleado[], int tam, eSector sector[], int tamSec){
    char seguir='s';
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("******* Modificar *******\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice=BuscarEmpleado(id,empleado,tam);

    if(indice==-1){
       printf("El id (%d) que ingreso no existe\n",id);
    }
    else{
        MostrarEmpleado(empleado[indice], sector, tamSec);

        printf("\nContinua con la Modificacion? s/n: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma!='s'){
            printf("Se ha Cancelado la Modificacion\n\n");
        }
        else{
            do{
                switch(MenuModificarEmpleado()){
                case 'a':
                    ModificarEmpleadoNombre(indice,empleado, tam, sector, tamSec);
                    break;
                case 'b':
                    ModificarEmpleadoApellido(indice,empleado, tam, sector, tamSec);
                    break;
                case 'c':
                    ModificarEmpleadoSalario(indice,empleado, tam, sector, tamSec);
                    break;
                case 'd':
                    ModificarEmpleadoSector(indice,empleado, tam, sector, tamSec);
                    break;
                case 'e':
                    seguir='n';
                    break;
                }
            system("pause");
            }while(seguir=='s');
        }
    }
}

int MenuModificarEmpleado(){
    char opcion;
    system("cls");
    printf("******* Modificar *******\nSeleccione La Opcion Que Desea Modificar: \n\n");
    printf("a. Nombre\n");
    printf("b. Apellido\n");
    printf("c. Salario\n");
    printf("d. Sector\n");
    printf("e. Volver\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

int BuscarEmpleado(int id, eEmpleado vec[], int tam){
    int indice=-1;
    for(int i=0; i<tam; i++){
        if(vec[i].id==id && vec[i].isEmpty==0){
            indice=i;
            break;
        }
    }
    return indice;
}

void ModificarEmpleadoNombre(int indice,eEmpleado vec[], int tam, eSector sectores[], int tamSec){
    char nuevoNombre[51];
    MostrarEmpleado(vec[indice], sectores, tamSec);
    printf("Ingrese Nuevo Nombre: ");
    fflush(stdin);
    gets(nuevoNombre);
    ManipularCadenas(nuevoNombre);
    strcpy(vec[indice].nombre, nuevoNombre);
    MostrarEmpleado(vec[indice], sectores, tamSec);
    printf("\n\nEmpleado Modificado con Exito!!!!\n\n");
}

void ModificarEmpleadoApellido(int indice,eEmpleado vec[], int tam, eSector sectores[], int tamSec){
    char nuevoApellido[51];
    MostrarEmpleado(vec[indice], sectores, tamSec);
    printf("Ingrese Nuevo Apellido: ");
    fflush(stdin);
    gets(nuevoApellido);
    ManipularCadenas(nuevoApellido);
    strcpy(vec[indice].apellido, nuevoApellido);
    MostrarEmpleado(vec[indice], sectores, tamSec);
    printf("\n\nEmpleado Modificado con Exito!!!!\n\n");
}

void ModificarEmpleadoSalario(int indice,eEmpleado vec[], int tam, eSector sectores[], int tamSec){
    float nuevoSueldo;
    MostrarEmpleado(vec[indice], sectores, tamSec);
    printf("Ingrese Nuevo Sueldo: ");
    scanf("%f", &nuevoSueldo);
    vec[indice].sueldo=nuevoSueldo;
    MostrarEmpleado(vec[indice], sectores, tamSec);
    printf("\n\nEmpleado Modificado con Exito!!!!\n\n");
}

void ModificarEmpleadoSector(int indice,eEmpleado vec[], int tam, eSector sectores[], int tamSec){
    int nuevoSector;
    MostrarEmpleado(vec[indice], sectores, tamSec);
    MostrarSectores(sectores, tamSec);
    printf("Ingrese Nuevo Sector: ");
    scanf("%d", &nuevoSector);
    vec[indice].sector=nuevoSector;
    MostrarEmpleado(vec[indice], sectores, tamSec);
    printf("Empleado Modificado con Exito!!!!\n\n");
}

void BajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec){
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("******* Baja Empleado *******\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice=BuscarEmpleado(id,vec,tam);

    if(indice==-1){
       printf("El id (%d) que ingreso no existe\n",id);
    }else{
        MostrarEmpleado(vec[indice], sectores, tamSec);
        printf("\nConfirma Baja? s/n: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s'){
            vec[indice].isEmpty=1;
            printf("Empleado Dado de Baja con Exito!!!!\n\n");
        } else{
            printf("Se ha Cancelado la Baja\n\n");
        }
    }
}

void OrdenarEmpleados(eEmpleado vec[], int tam){
eEmpleado auxEmpleado;

    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){
            if(vec[i].sector>vec[j].sector){
                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j]=auxEmpleado;
            }
            else if(vec[i].sector==vec[j].sector && strcmp(vec[i].apellido, vec[j].apellido)>0){
                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j]=auxEmpleado;
            }
        }
    }
}

void SuperaPromedioSueldos(float promedioSueldos,eEmpleado vec[],int tam,eSector sector[],int tamSec){
    int flag=0;

    printf("Empleado/s que supera/n el Promedio de Sueldos: \n");

    for(int i=0; i<tam; i++){
        if(vec[i].isEmpty==0 && vec[i].sueldo>promedioSueldos){
            MostrarEmpleado(vec[i], sector, tamSec);
            flag=1;
        }
    }
    if(flag==0){
        printf("No hay Empleado que supere el Promedio de Sueldos\n\n");
    }
}

