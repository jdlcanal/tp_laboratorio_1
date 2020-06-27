#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);//UTILIZADA
int ll_len(LinkedList* lista);//UTILIZADA
Node* test_getNode(LinkedList* lista, int nodeIndex);
int test_addNode(LinkedList* lista, int nodeIndex,void* pElement);
int ll_add(LinkedList* lista, void* pElement);//UTILIZADA
void* ll_get(LinkedList* lista, int index);//UTILIZADA
int ll_set(LinkedList* lista, int index,void* pElement);//UTILIZADA
int ll_remove(LinkedList* lista,int index);//UTILIZADA
int ll_clear(LinkedList* lista);//UTILIZADA
int ll_deleteLinkedList(LinkedList* lista);//UTILIZADA
int ll_indexOf(LinkedList* lista, void* pElement);//UTILIZADA
int ll_isEmpty(LinkedList* lista);//UTILIZADA
int ll_push(LinkedList* lista, int index, void* pElement);//UTILIZADA
void* ll_pop(LinkedList* lista,int index);//UTILIZADA                           //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
int ll_contains(LinkedList* lista, void* pElement);//UTILIZADA
int ll_containsAll(LinkedList* lista,LinkedList* this2);//UTILIZADA
LinkedList* ll_subList(LinkedList* lista,int from,int to);//UTILIZADA
LinkedList* ll_clone(LinkedList* lista);//UTILIZADA
int ll_sort(LinkedList* lista, int (*pFunc)(void* ,void*), int order);//UTILIZADA
