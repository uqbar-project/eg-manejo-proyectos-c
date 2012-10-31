/*
 * tarea.h
 *
 *  Created on: 26/05/2012
 *      Author: dodain
 */

#ifndef TAREA_H_
#define TAREA_H_

#include "complejidad.h"
#include "impuesto.h"

// definición de estructuras de daots
typedef struct Tarea* tarea;

// operaciones de alto nivel
tarea Tarea_crear(char*, int, complejidad);
float Tarea_costo(tarea);
float Tarea_tiempoTotal(tarea);
char* Tarea_asString(tarea);
void Tarea_agregarSubtarea(tarea, tarea);
void Tarea_agregarImpuesto(tarea, impuesto);
void Tarea_destroy(tarea);

#endif /* TAREA_H_ */
