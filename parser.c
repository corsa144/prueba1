#include <stdio.h>
#include <stdlib.h>
#include "cachorro.h"
#include "linkedList.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_parseCachorros(FILE* fileName, LinkedList* listaEmpleados)
{
    int r,i=0;
    Cachorro* this;
    if (fileName == NULL){
        printf ("Error al leer el archivo txt");
    }
    else{
        char var1[150],var3[150],var2[150],var4[150], var5[150],var6[150];

        do{
            r = fscanf(fileName,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);

            if(r==6){

                this = cachorro_nuevosParametros(var1, var2, var3, var4,var5 ,var6);
                i++;
                if(i==1) {
                	continue;
                }
                ll_add(listaEmpleados,this);
            }
            else{
                break;
            }
        }while( !feof(fileName));
    }
    return i;
}
