#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
/** \brief Crea memoria dinamica para un nuevo Employee* y setea la estructura en 0
 *
 */

Employee* employee_new(){
    Employee* newEmployee =(Employee*) malloc(sizeof(Employee));

    if(newEmployee != NULL)
    {
        newEmployee->id = 0;
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
        strcpy(newEmployee->nombre," ");
    }

    return newEmployee;
}
/** \brief Convierte los datos necesarios de string a enteros y crea un nuevo empleado
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadaStr
 * \param char* sueldoStr
 * \return empleado con nuevos parametros
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
    Employee* emp = employee_new();

    if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL){
        employee_setId(emp,atoi(idStr));
        employee_setNombre(emp,nombreStr);
        employee_setHorasTrabajadas(emp,atoi(horasTrabajadasStr));
        employee_setSueldo(emp,atoi(sueldoStr));
    }

    return emp;
}
/** \brief libera la memoria que estaba siendo ocupada
 *
 * \param Employee* emp
 *
 */

void employee_delete(Employee* emp){
	if(emp!=NULL){
		free(emp);
	}
}

/** \brief Settea el id a la estructura empleado
 *
 *
 */


int employee_setId(Employee* emp,int id){
    int todoOk = 0;

    if(emp != NULL && id >=0)
    {
        emp->id = id;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Copia el id de la estructura
 *
 */

int employee_getId(Employee* emp,int* id){
    int todoOk = 0;

    if(emp != NULL && id != NULL)
    {
        *id = emp->id;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief Settea el nombre a la estr empleado
 *
 */

int employee_setNombre(Employee* emp,char* nombre){
    int todoOk = 0;

    if(emp != NULL && emp != NULL && strlen(nombre) >= 3 && strlen(nombre)< 20)
    {
        strcpy(emp->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}
/** \brief copia el nombre de la estructura
 *
 */

int employee_getNombre(Employee* emp,char* nombre){
    int todoOk = 0;

    if(emp != NULL && emp != NULL && strlen(nombre) > 0 && strlen(nombre)< 20)
    {
        strcpy(nombre,emp->nombre);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Settea la cantidad de horas trabajadas a la estructura
 *
 */

int employee_setHorasTrabajadas(Employee* emp,int horasTrabajadas){
    int todoOk = 0;

    if(emp != NULL && horasTrabajadas >=0)
    {
        emp->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief copia el int de horas de la estructura
 *
 */

int employee_getHorasTrabajadas(Employee* emp,int* horasTrabajadas){
    int todoOk = 0;

    if(emp != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = emp->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief Settea el sueldo a la estructura
 *
 */

int employee_setSueldo(Employee* emp,int sueldo){
    int todoOk = 0;

    if(emp != NULL && sueldo >=0)
    {
        emp->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief Copia el int de sueldo desde la estructura
 *
 */

int employee_getSueldo(Employee* emp,int* sueldo){
    int todoOk = 0;

    if(emp != NULL && sueldo != NULL)
    {
        *sueldo = emp->sueldo;
        todoOk = 1;
    }
    return todoOk;
}
/** \brief consigue el proximo id del empleado
 *
 * \param LinkedList* lista
 * \return proximo Id
 *
 */

int proxId(LinkedList* lista){
    int id;
    int ultimo;
    static int proximo;

    Employee* emp;

    if(lista!=NULL){
        for(int i=0;i<ll_len(lista);i++){
            emp=(Employee*)ll_get(lista,i);
            employee_getId(emp,&id);

            if(i==0 && id>0){
                ultimo=id;
            } else if(id>ultimo){
                ultimo=id;
            }
        }
        if(ultimo>proximo){
            proximo=ultimo+1;
        }else{
            proximo++;
        }
    }
    return proximo;
}
/** \brief Ordena los empleados x nombre
 *
 * \param empleadoA
 * \param empleadoB
 * \return int
 *
 */

int employee_sortNombre(void* empA, void* empB){
	int todoOk=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;
	char nombre1[20];
	char nombre2[20];

	if(empA!=NULL && empB!=NULL){
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;
		employee_getNombre(emp1,nombre1);
		employee_getNombre(emp2,nombre2);
		if(stricmp(nombre1,nombre2)>0){
			todoOk=1;
		} else if(stricmp(nombre1,nombre2)<0){
			todoOk=0;
		}
    }
	return todoOk;
}

/** \brief Ordena los empleados x sueldo
 *
 * \param empleadoA
 * \param empleadoB
 * \return int
 *
 */
int employee_sortSalario(void* empA, void* empB){
	int todoOk=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;

	if(empA!=NULL && empB!=NULL){
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;
		int sueldo1,sueldo2;
		employee_getSueldo(emp1,&sueldo1);
		employee_getSueldo(emp2,&sueldo2);
		if(sueldo1 > sueldo2){
			todoOk=1;
		} else if(sueldo1 < sueldo2){
			todoOk=0;
		}
	}
	return todoOk;
}

/** \brief Ordena los empleados x cantidad de horas
 *
 * \param empleadoA
 * \param empleadoB
 * \return int
 *
 */
int employee_sortHoras(void* empA, void* empB){
	int todoOk=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;

	if(empA!=NULL && empB!=NULL){
		int hora1;
		int hora2;
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;
		employee_getHorasTrabajadas(emp1,&hora1);
		employee_getHorasTrabajadas(emp2,&hora2);
		if(hora1>hora2){
			todoOk=1;
		} else if(hora1<hora2){
			todoOk=0;
		}
    }
	return todoOk;
}

