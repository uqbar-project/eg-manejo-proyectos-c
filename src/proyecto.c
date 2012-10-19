/*
 * proyecto.c
 *
 *  Created on: 19/10/2012
 *      Author: fernado
 */
#include <stdio.h>
#include <stdlib.h>
#include <windef.h>
#include "list.h"
#include "tarea.h"
#include "proyecto.h"

/************************************************************
 * Estructura interna
 *************************************************************/
typedef struct Proyecto {
	char* descripcion;
	list tareas;
} t_proyecto;

/************************************************************
 * Funciones privadas de acceso al TAD Tarea
 *************************************************************/
proyecto Proyecto_crear(char* descripcion) {
	proyecto self = (t_proyecto*) malloc(sizeof(t_proyecto));

	if (self == NULL) {
		perror("No se pudo crear el proyecto");
		return NULL;
	}

	self->descripcion = malloc(strlen(descripcion) + 1);
	strcpy(self->descripcion, descripcion);
	self->tareas = NULL;

	return self;
}

float Proyecto_costo(proyecto unProyecto) {
	float costoTotal = 0.0;
	int i;
	int cantidadTareas = list_size(unProyecto->tareas);
	for (i = 0; i < cantidadTareas; i++) {
		tarea unaTarea = list_get(unProyecto->tareas, i);
		costoTotal = costoTotal + Tarea_costo(unaTarea);
	}
	return costoTotal;
}

void Proyecto_agregarTarea(proyecto unProyecto, tarea unaTarea) {
	unProyecto->tareas = list_add(unProyecto->tareas, unaTarea);
}

void Proyecto_destroy(proyecto unProyecto) {
	if (unProyecto->tareas != NULL) {
		int cantidadTareas = list_size(unProyecto->tareas);
		int i;
		for (i = 0; i < cantidadTareas; ++i) {
			tarea unaTarea = list_get(unProyecto->tareas, i);
			Tarea_destroy(unaTarea);
		}
		list_destroy(unProyecto->tareas);
	}
	free(unProyecto->descripcion);
	free(unProyecto);
}
