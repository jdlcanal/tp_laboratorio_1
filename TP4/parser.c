#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Peliculas.h"

/** \brief Parsea los datos de las peliculas desde el archivo movieDataBase.csv (modo texto).
 *
 * \param FILE* pFile
 * \param pArrayListMovie LinkedList*
 * \return int
 *
 */
int parser_MovieFromText(FILE* pFile , LinkedList* pArrayListMovie)
{
    int todoOk = -1;
    int cant;
    char buff[4][20];
    Movie* nMovie=NULL;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buff[0], buff[1], buff[2], buff[3]);

    if(pFile!=NULL && pArrayListMovie!=NULL){
        while(!feof(pFile)){
            cant= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buff[0], buff[1], buff[2], buff[3]);
            nMovie=movie_newParametros(buff[0], buff[1], buff[2], buff[3]);
            if(nMovie!=NULL){
                ll_add(pArrayListMovie,nMovie);
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
