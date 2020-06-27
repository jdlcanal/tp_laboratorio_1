#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* nuevaLista;

    nuevaLista=(LinkedList*) malloc(sizeof(LinkedList));
    if(nuevaLista!=NULL){
        nuevaLista->size=0;
        nuevaLista->pFirstNode=NULL;
    }

    return nuevaLista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* lista)
{
    int cantidad=-1;

    if(lista!=NULL){
        cantidad=lista->size;
    }

    return cantidad;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* lista, int nodeIndex)
{
    Node* nodo=NULL;

    if(lista!=NULL && nodeIndex>-1 && nodeIndex<ll_len(lista)){
        nodo=lista->pFirstNode;

        while(nodeIndex>0){
            nodo=nodo->pNextNode;
            nodeIndex--;
        }
    }

    return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* lista, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo=NULL;
    Node* anterior=NULL;

    if(lista!=NULL && nodeIndex>-1 && nodeIndex<=ll_len(lista)){
        nuevoNodo=(Node*) malloc(sizeof(Node));

        if(nuevoNodo!=NULL){
            nuevoNodo->pElement=pElement;
            nuevoNodo->pNextNode=NULL;

            if(nodeIndex==0){
                nuevoNodo->pNextNode=lista->pFirstNode;
                lista->pFirstNode=nuevoNodo;
            }
            else{
                anterior=getNode(lista,nodeIndex-1);
                nuevoNodo->pNextNode=anterior->pNextNode;
                anterior->pNextNode=nuevoNodo;
            }
            lista->size++;
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* lista, void* pElement)
{
    int returnAux = -1;

    returnAux=addNode(lista,ll_len(lista),pElement);

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* lista, int index)
{
    void* returnAux = NULL;
    Node* nodoAux;

    nodoAux=getNode(lista, index);
    if(nodoAux!=NULL){
        returnAux=nodoAux->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* lista, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode=NULL;

    auxNode=getNode(lista,index);
    if(auxNode!=NULL){
        auxNode->pElement=pElement;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* lista,int index)
{
    int returnAux = -1;
    Node* actual;
    Node* anterior;

    if(lista!=NULL && index>-1 && index<=ll_len(lista)){
        actual=getNode(lista,index);
        if(actual!=NULL){
            if(index==0){
                lista->pFirstNode=actual->pNextNode;
                free(actual);
                lista->size--;
                returnAux=0;
            }
            else{
                anterior=getNode(lista,index-1);
                if(anterior!=NULL){
                    anterior->pNextNode=actual->pNextNode;
                    free(actual);
                    lista->size--;
                    returnAux=0;
                }
            }
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* lista)
{
    int returnAux = -1;
    if(lista!=NULL){
        while(ll_len(lista)!=0){
            ll_remove(lista,0);
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* lista)
{
    int returnAux = -1;

    if(lista!=NULL){
        if(!ll_clear(lista)){
            free(lista);
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* lista, void* pElement)
{
    int returnAux = -1;
    Node* auxNode;

    if(lista!=NULL){
        for(int i=0;i<ll_len(lista);i++){
            auxNode=getNode(lista, i);
            if(auxNode!=NULL){
                if(auxNode->pElement==pElement){
                    returnAux=i;
                    break;
                }
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* lista)
{
    int returnAux = -1;

    if(lista!=NULL){
        returnAux=1;
        if(ll_len(lista)){
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* lista, int index, void* pElement)
{
    return addNode(lista,index,pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* lista,int index)
{
    void* returnAux = NULL;

    if(lista!=NULL && index>-1 && index <= ll_len(lista)){
        returnAux=ll_get(lista,index);
        if(ll_remove(lista, index)==-1){
            returnAux=NULL;
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* lista, void* pElement)
{
    int returnAux = -1;

    if(lista!=NULL){
        if(ll_indexOf(lista,pElement)>-1){
            returnAux=1;
        }
        else{
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* lista,LinkedList* lista2)
{
    int returnAux = -1;
    int len=0;
    void* pElement=NULL;

    if(lista!=NULL && lista2!=NULL){
        returnAux=0;
        if(ll_len(lista)>=ll_len(lista2)){
            for(int i=0;i<(ll_len(lista2));i++){
                pElement=ll_get(lista2,i);
                if(ll_contains(lista,pElement)==1){
                    len++;
                }
                else{
                    break;
                }
            }
        }
        if(ll_len(lista)==len){
            returnAux=1;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* lista,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNode=NULL;

    if(lista!=NULL && from>=0 && from<=ll_len(lista) && to>=from && to<=ll_len(lista)){
        cloneArray=ll_newLinkedList();

        if(cloneArray!=NULL){
            for(int i=from;i<to;i++){
                pNode=getNode(lista,i);
                if(pNode!=NULL){
                    addNode(cloneArray,i,pNode->pElement);
                }
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* lista)
{
    LinkedList* cloneArray = NULL;
    int from=0;
    int to=ll_len(lista);

    if(lista!=NULL){
        cloneArray=ll_subList(lista,from,to);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* lista, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* auxElement;

    if(lista!=NULL && pFunc!=NULL && order>-1 && order<2){
        for(int i=0; i<ll_len(lista)-1; i++){
            for(int j=i+1;j<ll_len(lista);j++){

                if(pFunc(ll_get(lista,i),ll_get(lista,j))>0 && order==1){
                   auxElement=ll_get(lista,i);
                   ll_set(lista,i,ll_get(lista,j));
                   ll_set(lista,j,auxElement);

                } else if(pFunc(ll_get(lista,i),ll_get(lista,j))<0 && order==0){
                   auxElement=ll_get(lista,i);
                   ll_set(lista,i,ll_get(lista,j));
                   ll_set(lista,j,auxElement);
                  }
            }
        }
        returnAux=0;
    }

    return returnAux;

}

