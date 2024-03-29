#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

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

#endif // LINKEDLIST_H_INCLUDED

 Node* getNode(LinkedList* this, int nodeIndex);
 int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
LinkedList* ll_map(LinkedList* this, void (*pFunc)(void*));
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*));
