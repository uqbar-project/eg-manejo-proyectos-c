/*
 * tarea.h
 *
 *  Created on: 26/05/2012
 *      Author: dodain
 */

#ifndef TAREA_H_
#define TAREA_H_

#include "complejidad.h"

// definición de estructuras
typedef struct Tarea t_tarea;
typedef struct t_tarea tad_tarea;

/************************************************************
* Operaciones primitivas sobre el TAD Tarea
*************************************************************/
t_tarea* Tarea_crear(char* descripcion, int tiempo, t_complejidad complejidad);
// TODO: Definir la asignación de una complejidad minima, media y maxima
float Tarea_costo(t_tarea*);
float Tarea_tiempoTotal(t_tarea*);
char* Tarea_asString(t_tarea*);
void Tarea_agregarSubtarea(t_tarea*, t_tarea*);
void Tarea_destroy(t_tarea*);

// temp
void Tarea_verSubtareas(t_tarea* tarea);

#endif /* TAREA_H_ */
