/*
 ============================================================================
 Name        : utn_segundo_parcial.c
 Author      : Cristian 1E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cachorro.h"
#include "linkedList.h"
#include "parser.h"
#include "informes.h"
#include "utn_validar.h"


/****************************************************
    Menu:
     1. Cargar archivo.
     2. Imprimir lista.
     3. filtrar menores de 45 dias
     4. filtrar machos
     5. generar lista de callejeros
    6. Salir
*****************************************************/


int main()
{
    int opcion = 0;
    int bandera = 0;
    LinkedList* listaCachorros = ll_newLinkedList();
    LinkedList* listaFiltradaPorDias = ll_newLinkedList();
    LinkedList* listaFiltradaPorGenero = ll_newLinkedList();
    LinkedList* listaFiltradaPorCallejeros = ll_newLinkedList();
    do{
    	utn_getUnsignedInt("\nMenu segundo parcial\n"
"Seleccione 1- Para cargar el archivo\n"
"Seleccione 2- Para imprimir lista\n"
"Seleccione 3- Para filtrar menores de 45 dias\n"
"Seleccione 4- Para filtrar cachorros machos\n"
"Seleccione 5- Para generar lista de callejeros\n"
"Seleccione 6- Para salir del programa\n"
"Opcion elegida: ","Error\n",0,sizeof(int),1,sizeof(opcion),2,&opcion);
        switch(opcion)
        {
            case 1:
                if (bandera == 1){
                    printf ("\n\nSolo se puede cargar una vez\n\n");
                }else{
                	parser_parseCachorros(fopen("../src/cachorros.csv", "r+"), listaCachorros);
                }
                bandera = 1;
                break;
            case 2:

                if (bandera == 1){

                    informar_listaCachorros(listaCachorros);
                }
                bandera = 1;

                break;
           case 3:
                if (bandera == 1){
                	listaFiltradaPorDias=filtrarMenores(listaCachorros);
                	informar_listaCachorros(listaFiltradaPorDias);
                }
                break;
            case 4:
                if (bandera == 1){

                	listaFiltradaPorGenero=filtrarMachos(listaCachorros);
                	informar_listaCachorros(listaFiltradaPorGenero);
                }
                break;
           case 5:
                if (bandera == 1){
                	listaFiltradaPorCallejeros = filtrarPorCallejero(listaCachorros);
                	informar_listaCachorros(listaFiltradaPorCallejeros);
                }
                break;
            case 6:
                break;
        }
    }while(opcion != 6);
    return 0;
}
