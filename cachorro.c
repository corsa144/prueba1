#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "cachorro.h"

Cachorro* employee_new(){
    Cachorro* perro = malloc(sizeof(Cachorro));
    return perro;
}

Cachorro* cachorro_nuevosParametros(char *var1, char *var2, char *var3, char *var4,char *var5,char *var6)
{
    int idAux,diasAux;
    Cachorro* p = employee_new();
    idAux = atoi(var1);
    diasAux = atoi(var3);
    empleado_setId(p, idAux);
    empleado_setNombre(p, var2);
    empleado_setDias(p, diasAux);
    empleado_setRaza(p, var4);
    empleado_setReservado(p, var5);
    empleado_setGenero(p, var6);
    return p;
}

/********FUNCIONES SET***********/

int empleado_setId(Cachorro* this, int id)
{
    if(id > 0){
        this->id_cachorro = id;
    }
    return 0;
}

int empleado_setNombre(Cachorro* this, char* nombre)
{
    if(nombre[0] != '\0'){
    strncpy(this->nombre, nombre, sizeof(this->nombre));
    }
    return 0;
}

int empleado_setRaza(Cachorro* this, char* raza)
{
    if(raza[0] != '\0'){
    strncpy(this->raza, raza, sizeof(this->raza));
    }
    return 0;
}

int empleado_setReservado(Cachorro* this, char* reservado)
{
    if(reservado[0] != '\0'){
    strncpy(this->reservado, reservado, sizeof(this->reservado));
    }
    return 0;
}

int empleado_setGenero(Cachorro* this, char* genero)
{
    if((*genero+0) == 'M' || (*genero+0) == 'H'){
        this->genero = (*genero+0);
    }
    return 0;
}

int empleado_setDias(Cachorro* this,int dias)
{
    if(dias > 0){
        this->dias = dias;
    }
    return 0;
}

/*********FUNCIONES GET**********/

char empleado_getId(Cachorro* this, int* id)
{

    return this->id_cachorro;

}

char* empleado_getNombre(Cachorro* this,char* nombre)
{
    return this->nombre;
}

char* empleado_getRaza(Cachorro* this,char* raza)
{
    return this->raza;
}

char empleado_getDias(Cachorro* this,int* dias)
{
    return this->dias;
}

char* empleado_getReservado(Cachorro* this,char* reservado)
{
    return this->reservado;
}

char empleado_getGenero(Cachorro* this,char genero)
{
    return this->genero;
}
/*void em_calcularSueldo(void* p)
{
	// recibo elemento empleado como void.
	// hacer calculo de sueldo y escribirlo en campo sueldo del empleado

	if(((Cachorro*)p)->dias < 120) {
        ((Cachorro*)p)->sueldo = ((Cachorro*)p)->dias * 180;
	} else if (((Cachorro*)p)->dias < 160){
        ((Cachorro*)p)->sueldo = ((Cachorro*)p)->dias * 240;
	} else {
        ((Cachorro*)p)->sueldo = ((Cachorro*)p)->dias * 350;
	}

}*/
