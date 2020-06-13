#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    char buff[4][20];
    Employee* nEmp=NULL;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buff[0], buff[1], buff[2], buff[3]);

    if(pFile!=NULL && pArrayListEmployee!=NULL){
        while(!feof(pFile)){
            cant= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buff[0], buff[1], buff[2], buff[3]);
            nEmp=employee_newParametros(buff[0], buff[1], buff[2], buff[3]);
            if(nEmp!=NULL){
                ll_add(pArrayListEmployee,nEmp);
                todoOk=1;
              }
            if(cant < 4){
                if(feof(pFile)){
                    break;
                }
                else{
                  todoOk=0;
                break;
                }
            }

        }
      }


    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
	int cant;
	Employee* nEmp=NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL){
        while(!feof(pFile)){
			cant=fread(nEmp,sizeof(Employee),1,pFile);
			nEmp=employee_new();

			if(nEmp!=NULL){
				ll_add(pArrayListEmployee,nEmp);
				todoOk=1;
			}

			else{
				employee_delete(nEmp);
			}


			if(cant<1){
				if(feof(pFile)){
					break;
				} else{
					todoOk=0;
					break;
				}
			}
		}
	}

    return todoOk;
}
