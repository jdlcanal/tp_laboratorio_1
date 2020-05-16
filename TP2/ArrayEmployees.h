#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;
}eEmpleado;

typedef struct{
    int idSector;
    char descSector[20];
}eSector;

#endif // ARRAYEMPLOYEES_H_INCLUDED

void InicializarEmpleados(eEmpleado vec[], int tam);
int BuscarLibre(eEmpleado vec[], int tam);
int AltaEmpleado(int id, eEmpleado vec[], int tam, eSector sector[], int tamSec);
void MostrarEmpleados(eEmpleado vec[],int tam, eSector sector[], int tamSec, int contEmpleados);
void MostrarEmpleado(eEmpleado x, eSector sector[], int tamSec);
void ManipularCadenas(char x[]);
void MostrarSectores(eSector sector[], int tam);
void CargarDescripcionSector(char descripcion[], int id, eSector sector[], int tamSec);
void ModificarEmpleado(eEmpleado empleado[], int tam, eSector sector[], int tamSec);
int MenuModificarEmpleado();
int BuscarEmpleado(int id, eEmpleado vec[], int tam);
void ModificarEmpleadoNombre(int indice,eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void ModificarEmpleadoApellido(int indice,eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void ModificarEmpleadoSalario(int indice,eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void ModificarEmpleadoSector(int indice,eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void BajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void OrdenarEmpleados(eEmpleado vec[], int tam);
void SuperaPromedioSueldos(float promedioSueldos,eEmpleado vec[],int tam,eSector sector[],int tamSec);
