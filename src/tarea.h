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

// definición de estructuras
typedef struct Tarea t_tarea;
typedef struct t_tarea tad_tarea;
typedef t_tarea* tarea;

/************************************************************
* Operaciones primitivas sobre el TAD Tarea
*************************************************************/
tarea Tarea_crear(char*, int);
// TODO: Definir la asignación de una complejidad minima, media y maxima
float Tarea_costo(tarea);
float Tarea_tiempoTotal(tarea);
char* Tarea_asString(tarea);
void Tarea_agregarSubtarea(tarea, tarea);
void Tarea_agregarImpuesto(tarea, impuesto);
void Tarea_crearImpuesto(tarea tarea, char* descripcionImpuesto, float valorImpuesto);
void Tarea_destroy(tarea);
void Tarea_setComplejidadMinima(tarea);
void Tarea_setComplejidadMedia(tarea);
void Tarea_setComplejidadMaxima(tarea);

// temp
void Tarea_verSubtareas(tarea);

#endif /* TAREA_H_ */
