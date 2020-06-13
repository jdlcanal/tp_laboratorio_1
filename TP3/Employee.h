#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* emp);

int employee_setId(Employee* emp,int id);
int employee_getId(Employee* emp,int* id);

int employee_setNombre(Employee* emp,char* nombre);
int employee_getNombre(Employee* emp,char* nombre);

int employee_setHorasTrabajadas(Employee* emp,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* emp,int* horasTrabajadas);

int employee_setSueldo(Employee* emp,int sueldo);
int employee_getSueldo(Employee* emp,int* sueldo);

int proxId(LinkedList* lista);

int employee_sortNombre(void* empA, void* empB);
int employee_sortSalario(void* empA, void* empB);
int employee_sortHoras(void* empA, void* empB);

#endif // employee_H_INCLUDED
