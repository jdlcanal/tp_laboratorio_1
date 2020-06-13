#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Listar un solo empleado
 *
 * \param Employee* emp
 *
 */
void controller_ListEmployeeUnoSolo(Employee* emp){
    if(emp!= NULL){
        printf("%4d   %15s   %3d       %6d\n", emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
    }
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* emp;

    if(pArrayListEmployee!=NULL){
        todoOk=1;
        system("cls");
        printf("   ID           NOMBRE HsTRABAJADAS SUELDO\n");
        for(int i=0; i<ll_len(pArrayListEmployee);i++){
            emp=(Employee*)ll_get(pArrayListEmployee,i);
            controller_ListEmployeeUnoSolo(emp);
        }
    }

    return todoOk;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    FILE* f;
    if(path!=NULL && pArrayListEmployee!=NULL){
        f=fopen(path,"r");
        if(f!=NULL){
            if(parser_EmployeeFromText(f,pArrayListEmployee)){
                printf("Datos cargados con Exito!!!\n\n");
                fclose(f);
                todoOk=1;
            }
            else{
                printf("Hubo un error al cargar.\n\n");
            }
        }
    }

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* f;
    if(path!=NULL && pArrayListEmployee!=NULL){
         f=fopen(path,"wb");
        if(f!=NULL){
            parser_EmployeeFromBinary(f,pArrayListEmployee);
            printf("Datos cargados con Exito!!!\n\n");
            fclose(f);
            todoOk=1;
        } else{
				printf("Hubo un error al cargar.\n\n");
        }
    }

    return todoOk;
}

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* emp=employee_new();
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int id=proxId(pArrayListEmployee);

    system("cls");
    printf("Alta de empleado\n\n");
    printf("Ingrese Nombre: ");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese Horas Trabajadas: ");
    scanf("%d",&horasTrabajadas);
    printf("Ingrese Sueldo: ");
    scanf("%d",&sueldo);

    if(employee_setId(emp,id) && employee_setNombre(emp,nombre) && employee_setHorasTrabajadas(emp,horasTrabajadas) && employee_setSueldo(emp,sueldo)){
        if(ll_add(pArrayListEmployee,emp)==0){
            printf("Empleado Cargado con Exito!\n\n");
            todoOk=1;
        }
        else{
            printf("ERROR!!! El empleado no fue cargado!\n\n");
        }
    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int id;
    char confirm;
    char opcion;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    Employee* emp;

    system("cls");
    printf("Modificar datos de empleado\n\n");
    controller_ListEmployee(pArrayListEmployee);
    printf("\nIngrese el Id del Empleado que desea modificar: ");
    scanf("%d",&id);
        for(int i=0; i<ll_len(pArrayListEmployee); i++){
        emp=(Employee*)ll_get(pArrayListEmployee,i);
            if(id==emp->id){
            controller_ListEmployeeUnoSolo(emp);
            printf("\nContinuar con la modificacion? s/n: ");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm=='s'){
                do{
                    todoOk=1;
                    printf("\nQue desea modificar?: \n\na.Nombre\nb.Horas Trabajadas\nc.Sueldo\n");
                    fflush(stdin);
                    scanf("%c",&opcion);
                    switch(opcion){
                case 'a':
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(nombre);
                    if(employee_setNombre(emp,nombre)){
                       controller_ListEmployeeUnoSolo(emp);
                    }
                    printf("Continuar modificando? s/n: ");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    break;
                case 'b':
                    printf("Ingrese nuevas horas trabajadas: ");
                    scanf("%d",&horasTrabajadas);
                    if(employee_setHorasTrabajadas(emp,horasTrabajadas)){
                       controller_ListEmployeeUnoSolo(emp);
                    }
                    printf("Continuar modificando? s/n: ");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    break;
                case 'c':
                    printf("Ingrese nuevo sueldo: ");
                    scanf("%d",&sueldo);
                    if(employee_setSueldo(emp,sueldo)){
                       controller_ListEmployeeUnoSolo(emp);
                    }
                    printf("Continuar modificando? s/n: ");
                    fflush(stdin);
                    scanf("%c",&confirm);
                    break;
                default:
                    break;
                    }
                }while(confirm=='s');
            }
        }

    }

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int id;
    char confirm;

    Employee* emp;

    system("cls");
    printf("Baja de empleado\n\n");
    controller_ListEmployee(pArrayListEmployee);
    printf("\nIngrese el Id del Empleado que desea dar de baja: ");
    scanf("%d",&id);
        for(int i=0; i<ll_len(pArrayListEmployee); i++){
            emp=(Employee*)ll_get(pArrayListEmployee,i);
            if(id==emp->id){
                controller_ListEmployeeUnoSolo(emp);
                printf("\nContinuar con la baja? s/n: ");
                fflush(stdin);
                scanf("%c",&confirm);
                if(confirm=='s'){
                    if(ll_remove(pArrayListEmployee,i)==0){
                        employee_delete(emp);
                        printf("\nBaja Exitosa!!!\n\n");
                        todoOk=1;
                    }
                }
            }
        }


    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char opcion;
    char confirm;
	if(pArrayListEmployee!=NULL){
		if(ll_len(pArrayListEmployee)>0){
			do{
                system("cls");
                printf("Ordenar Empleados\n\na.Por Nombre\nb.Por Horas Trabajadas\nc.Por Salario\n\nSelecciona una opcion: ");
                fflush(stdin);
                scanf("%c",&opcion);
				switch(opcion){
                case 'a':
						ll_sort(pArrayListEmployee,employee_sortNombre,1);
					break;

                case 'b':
						ll_sort(pArrayListEmployee,employee_sortHoras,1);
					break;

                case 'c':
						ll_sort(pArrayListEmployee,employee_sortSalario,1);
                    break;
                default:
                    break;
				}
				printf("Continua ordenando? s/n: ");
				fflush(stdin);
				scanf("%c",&confirm);


			}while(confirm=='s');
		}   todoOk=1;
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* emp;
    int len=-1;
    int id;
    int sueldo;
    int horasTrabajo;
    char nombre[20];
    int todoOk=-1;
    int i;

    if(path!=NULL && pArrayListEmployee!=NULL){
        len=ll_len(pArrayListEmployee);
        if(len>0){
            f=fopen(path,"w");
            if(f!=NULL){
                fprintf(f,"ID,NOMBRE,HsTRABAJADAS,SUELDO\n");
                for(i=0;i<len;i++){
                    emp=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(emp,&id);
                    employee_getNombre(emp,nombre);
                    employee_getHorasTrabajadas(emp,&horasTrabajo);
                    employee_getSueldo(emp,&sueldo);
                    fprintf(f,"%d,%s,%d,%d\n",id,nombre,horasTrabajo,sueldo);
                }
                fclose(f);
                if(i==len){
                    todoOk=1;
                }
            }
        }
    }
    if(todoOk == 1){
        printf("Datos guardados correctamente!!!\n\n");
    } else{
        if(len==0){
            printf("ERROR!!! No hay datos para guardar!!!\n\n");
        } else{
            printf("ERROR!!! No se pudo guardar los datos!!!\n\n");
        }
    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
	Employee* emp;
    int len=-1;
    int todoOk=-1;
    int i;

	if(path!=NULL && pArrayListEmployee!=NULL){
		len = ll_len(pArrayListEmployee);
		if(len>0){
			f=fopen(path,"wb");
			if(f!=NULL){
				for(i=0;i<len;i++){
					emp=ll_get(pArrayListEmployee,i);
					if(emp!=NULL){
						fwrite(emp,sizeof(Employee),1,f);
					}
				}
				fclose(f);

				if(i==len){
					todoOk=1;
				}
			}
		}
		printf("Datos binarios guardados correctamente!!!\n\n");
	} else{
        printf("ERROR!!! No se pudo guardar los datos!!! \n\n");
    }

    return todoOk;
}

