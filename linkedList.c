#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"



 Node* getNode(LinkedList* this, int nodeIndex);
 int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode=NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if (this == NULL){
        returnAux = -1;
    }else{

    returnAux = this->size;

    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
 Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo;
    int i;
    nodo = NULL;
    if(this!= NULL && nodeIndex >= 0 && nodeIndex <= (this->size)-1)
    {
        nodo = this->pFirstNode;
        if( nodeIndex >0 && this->size > nodeIndex)
        {
            for(i=0;i<nodeIndex;i++)
            {
                nodo = nodo->pNextNode;
            }
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
 int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    if(ll_len(this) != -1 && nodeIndex >= 0 && nodeIndex <= (this->size) )
    {
        returnAux = ll_push(this,nodeIndex,pElement);
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
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodoActual;
    Node* nodoAnterior;
    if(this != NULL )
    {
        if(ll_len(this)>0){
            nodoAnterior = getNode(this,ll_len(this)-1);
            nodoActual = (Node*)malloc(sizeof(Node));
            nodoActual->pElement=pElement;
            nodoActual->pNextNode=NULL;
            nodoAnterior->pNextNode=nodoActual;
            this->size+=1;
            returnAux = 0;
        }else{
            this->pFirstNode = (Node*)malloc(sizeof(Node));
            this->pFirstNode->pElement = pElement;
            this->pFirstNode->pNextNode=NULL;
            this->size+=1;
            returnAux = 0;
        }

    }
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
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoActual;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
        nodoActual=getNode(this,index);
        returnAux=nodoActual->pElement;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoAux;
    if(this != NULL && index>=0 && index < ll_len(this))
    {
        nodoAux = getNode(this,index);
        nodoAux->pElement = pElement;
        returnAux = 0;
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
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAnterior;
    Node* nodoActual;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        returnAux = 0;
        nodoActual=getNode(this, index);
        if(index == 0)
        {
            this->pFirstNode = nodoActual->pNextNode;
        }else{
            nodoAnterior = getNode(this, index-1);
            nodoAnterior->pNextNode = nodoActual->pNextNode;
        }
        this->size--;
        free(nodoActual);
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
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        this->pFirstNode = NULL;
        this->size=0;
        returnAux = 0;
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
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if( this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
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
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodoActual;

    if(this != NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            if(i==0)
            {
                nodoActual = this->pFirstNode;
            }
            if(nodoActual->pElement == pElement)
            {
                returnAux = i;
                break;
            }
            nodoActual = nodoActual->pNextNode;
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
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
        if(ll_len(this)==0)
        {
            returnAux = 1;
        }else{
            returnAux = 0;
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
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* nodoActual;
    Node* nodoAnterior;

    if(this != NULL && index >= 0 && index <= ll_len(this) )
    {
        if ( ll_len(this) == 0 || index == ll_len(this))
        {
            returnAux = ll_add(this,pElement);
        }else{
            nodoAnterior = getNode(this,index);
            nodoActual = (Node*)malloc(sizeof(Node));
            nodoActual ->pElement=nodoAnterior->pElement;
            nodoActual->pNextNode=nodoAnterior->pNextNode;
            nodoAnterior->pElement=pElement;
            nodoAnterior->pNextNode=nodoActual;
            this->size+=1;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodoActual;
    Node* nodoAnterior;

    if( this != NULL && index >= 0 && index < ll_len(this))
    {
        nodoActual = getNode(this,index);
        if( index != 0)
        {
            nodoAnterior = getNode(this,index-1);
            nodoAnterior->pNextNode = nodoActual->pNextNode;
        }else{
            this->pFirstNode = nodoActual->pNextNode;
        }
        returnAux = nodoActual->pElement;
        this->size--;
        free(nodoActual);
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
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_indexOf(this,pElement) == -1)
        {
            returnAux = 0;
        }else{
            returnAux = 1;
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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    Node* nodoDos;
    if(this != NULL && this2 != NULL)
    {
        nodoDos = this2->pFirstNode;
        for(i=0;i<ll_len(this2);i++)
        {
            if(ll_contains(this,nodoDos->pElement) == 0)
            {
                returnAux = 0;
                break;
            }
            nodoDos = nodoDos->pNextNode;
        }
        if( returnAux == -1)
        {
            returnAux = 1;
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
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* nodo;
    int i;

    if(this != NULL)
    {
       if(from >= 0 && from <=ll_len(this))
       {
           if(to > from && to <=ll_len(this) )
           {
               nodo = this->pFirstNode;
                for(i=0;i<ll_len(this);i++)
                {
                    if(i >= from && i <= to)
                    {
                        if(cloneArray == NULL)
                        {
                            cloneArray = ll_newLinkedList();
                        }
                        addNode(cloneArray,ll_len(cloneArray),nodo->pElement);
                    }
                    nodo=nodo->pNextNode;
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
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    Node* nodo;
    int i;

    if(this != NULL)
    {
       nodo = this->pFirstNode;
        for(i=0;i<ll_len(this);i++)
        {
            if(cloneArray == NULL)
            {
                cloneArray = ll_newLinkedList();
            }
            addNode(cloneArray,ll_len(cloneArray),nodo->pElement);

            nodo=nodo->pNextNode;
        }
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int j;
    void* el1;
    void* el2;
    int flagNoEstaOrdenado = 1;
    int ordenamiento = 1;

    if(order == 0){
        ordenamiento = -1;
    }

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        returnAux = 0;

        while(flagNoEstaOrdenado == 1)
        {
            flagNoEstaOrdenado = 0;
            for(j = 1;j < ll_len(this);j++)
            {
                el1 = ll_get(this,j-1);
                el2 = ll_get(this,j);
                if(pFunc(el1,el2)== ordenamiento)
                {
                    ll_set(this,j,el1);
                    ll_set(this,j-1,el2);
                    flagNoEstaOrdenado = 1;
                }
            }
        }
    }

    return returnAux;

}

LinkedList* ll_map(LinkedList* this, void (*pFunc)(void*)){
    LinkedList* newList = NULL;
    Node* nodo;
    //void* nuevoElemento;
    int i;

    if(this != NULL && pFunc != NULL){
        newList = ll_newLinkedList();

        nodo = this->pFirstNode;

        for(i=0; i<ll_len(this); i++){
            pFunc(nodo->pElement);
            ll_add(newList, nodo);

            nodo = nodo->pNextNode;
        }
    }

    return newList;

}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*)){
    LinkedList* listaFiltrada = NULL;
    void* el;
    int i;

    listaFiltrada = ll_newLinkedList();

    for(i=0; i<ll_len(this); i++){
        el = ll_get(this, i);
        if(pFunc(el) == 1){
            ll_add(listaFiltrada, el);
        }
    }
    return listaFiltrada;
}
