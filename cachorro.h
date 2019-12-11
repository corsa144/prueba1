#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
  int id_cachorro;
  char nombre[128];
  int dias;
  char raza[128];
  char reservado[5];
  char genero;
}Cachorro;

//Cachorro this;

Cachorro* employee_new();
Cachorro* cachorro_nuevosParametros(char* idStr,char* nombreStr,char* diasStr,char* razaStr,char* reservadoStr, char* generoStr);
void employee_delete();

int empleado_setId(Cachorro* this,int id);
char empleado_getId(Cachorro* this,int* id);

int empleado_setNombre(Cachorro* this,char* nombre);
char* empleado_getNombre(Cachorro* this,char* nombre);

int empleado_setDias(Cachorro* this,int dias);
char empleado_getDias(Cachorro* this,int* dias);

int empleado_setRaza(Cachorro* this,char* raza);
char* empleado_getRaza(Cachorro* this,char* raza);

int empleado_setReservado(Cachorro* this,char* reservado);
char* empleado_getReservado(Cachorro* this,char* reservado);

int empleado_setGenero(Cachorro* this,char* genero);
char empleado_getGenero(Cachorro* this,char genero);

void em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED
