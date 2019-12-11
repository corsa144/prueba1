#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cachorro.h"
#include "linkedList.h"
#include "parser.h"
#include "informes.h"

/** \brief Listar cachorros
 *
 * \param path char*
 * \param lista cachorros LinkedList*
 * \return int
 *
 */
int informar_listaCachorros(LinkedList* listaCachorros)
{
    int i,cant;
    int idAux=0;
    char nombreAux[50];
    int diasAux=0;
    char razaAux[50];
    char reservadoAux[5];
    char generoAux=0;
    cant = ll_len(listaCachorros);
    Cachorro* lista;
    for (i=0;i<cant;i++){

        lista = (Cachorro*)ll_get(listaCachorros,i);
        printf("%d\t %s\t %d\t %s\t %s\t %c\n",empleado_getId(lista,&idAux),
        		empleado_getNombre(lista, nombreAux),
               empleado_getDias(lista, &diasAux),
			   empleado_getRaza(lista, razaAux),
			   empleado_getReservado(lista,reservadoAux),
			   empleado_getGenero(lista,generoAux));
    }
    return 0;
}

int cachorroMenor(void* p){
    int returnAux = 0;

    if(((Cachorro*)p)->dias >= 45){
        returnAux = 1;
    }

    return returnAux;
}

LinkedList* filtrarMenores(LinkedList* listaCachorros)
{
	LinkedList* returnAux = NULL;
	if(listaCachorros != NULL)
	{
		returnAux = ll_filter(listaCachorros,cachorroMenor);

	}
	return returnAux;
}

int cachorroHembra(void* p){
    int returnAux = 0;

    if(((Cachorro*)p)->genero == 'H'){
        returnAux = 1;
    }

    return returnAux;
}

LinkedList* filtrarMachos(LinkedList* listaCachorros)
{
	LinkedList* returnAux = NULL;
	if(listaCachorros != NULL)
	{
		returnAux = ll_filter(listaCachorros,cachorroHembra);

	}
	return returnAux;
}

int cachorroCallejero(void* p){
    int returnAux = 0;

    if(strcmp(((Cachorro*)p)->raza,"Callejero")==0){
        returnAux = 1;
    }

    return returnAux;
}

LinkedList* filtrarPorCallejero(LinkedList* listaCachorros)
{
	LinkedList* returnAux = NULL;
	if(listaCachorros != NULL)
	{
		returnAux = ll_filter(listaCachorros,cachorroCallejero);

	}
	return returnAux;
}

