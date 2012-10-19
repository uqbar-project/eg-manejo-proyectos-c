/*
 * proyecto.h
 *
 *  Created on: 19/10/2012
 *      Author: fernado
 */

#ifndef PROYECTO_H_
#define PROYECTO_H_

#include "tarea.h"

// definición de estructuras
typedef struct Proyecto t_proyecto;
typedef struct t_proyecto tad_proyecto;
typedef t_proyecto* proyecto;

/************************************************************
* Operaciones primitivas sobre el TAD Tarea
*************************************************************/
proyecto Proyecto_crear(char*);
void Proyecto_agregarTarea(proyecto, tarea);
float Proyecto_costo(proyecto);
void Proyecto_destroy(proyecto);

#endif /* PROYECTO_H_ */
