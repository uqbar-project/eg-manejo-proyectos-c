/*
 * proyecto.h
 *
 * Representa un proyecto que se desarrolla en un lugar
 *
 *  Created on: 19/10/2012
 *      Author: dodain
 */

#ifndef PROYECTO_H_
#define PROYECTO_H_

#include "tarea.h"

// definición de estructuras de datos
typedef struct Proyecto* proyecto;

// operaciones de alto nivel
proyecto Proyecto_crear(char*);
void Proyecto_agregarTarea(proyecto, tarea);
float Proyecto_costo(proyecto);
void Proyecto_destroy(proyecto);

#endif /* PROYECTO_H_ */
