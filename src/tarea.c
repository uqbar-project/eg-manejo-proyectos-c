/*
 *
 * DEFINICION DE TAD TAREA
 *
 * Representa una tarea dentro de un proyecto
 *
 * tarea.c
 *
 *  Created on: 26/05/2012
 *      Author: dodain
 */
#include <stdio.h>
#include <stdlib.h>
#include <windef.h>
#include "list.h"
#include "tarea.h"

/************************************************************
 * Estructura interna
 *************************************************************/
typedef struct Tarea {
	char* descripcion;
	int tiempo;
	enum COMPLEJIDAD complejidad;
	struct node* subtareas;
} t_tarea;

/************************************************************
 * Funciones privadas de acceso al TAD Tarea
 *************************************************************/
static t_tarea* internalTarea_crear(char* descripcion, int tiempo, t_complejidad complejidad) {
	t_tarea* self = (t_tarea *) malloc(sizeof(t_tarea));

	if (self == NULL) {
		perror("No se pudo crear la tarea");
		return NULL;
	}

	self->descripcion = malloc(strlen(descripcion) + 1);
	strcpy(self->descripcion, descripcion);
	self->tiempo = tiempo;
	self->complejidad = complejidad;

	return self;
}

static float internalTarea_costoBase(t_tarea* tarea) {
	return Complejidad_costo(COMPLEJIDAD_MINIMA, tarea->tiempo);
}

/************************************************************
 * Operaciones primitivas sobre el TAD Tarea
 *************************************************************/
t_tarea* Tarea_crear(char* descripcion, int tiempo, t_complejidad complejidad) {
	t_tarea* tarea = internalTarea_crear(descripcion, tiempo, complejidad);
	tarea->subtareas = NULL;
	return tarea;
}

float Tarea_costo(t_tarea* tarea) {
	float costoTotal = internalTarea_costoBase(tarea);
	int i = 0;
	int cantidadSubtareas = list_size(tarea->subtareas);
	for (i = 0; i < cantidadSubtareas; i++) {
		t_tarea* subtarea = list_get(tarea->subtareas, i);
		costoTotal = costoTotal + Tarea_costo(subtarea);
	}
	return costoTotal;
}

float Tarea_tiempoTotal(t_tarea * tarea) {
	return tarea->tiempo;
}

char* Tarea_asString(t_tarea* tarea) {
	return tarea->descripcion;
}

void Tarea_destroy(t_tarea* tarea) {
	if (tarea->subtareas != NULL) {
		int cantidadTareas = list_size(tarea->subtareas);
		int i;
		for (i = 0; i < cantidadTareas; ++i) {
			t_tarea* subtarea = list_get(tarea->subtareas, i);
			Tarea_destroy(subtarea);
		}
		list_destroy(tarea->subtareas);
	}
	free(tarea->descripcion);
	free(tarea);
}

void Tarea_agregarSubtarea(t_tarea* tarea, t_tarea* subtarea) {
	//TODO: Modelar un TAD error
	tarea->subtareas = list_add(tarea->subtareas, subtarea);
}

// temp . Es el test!!
void Tarea_verSubtareas(t_tarea* tarea) {
	int i = 0;
	int cantidadSubtareas = list_size(tarea->subtareas);
	printf("\nCantidad subtareas: %d\n", cantidadSubtareas); // esto es un test en sí mismo
	for (i = 0; i < cantidadSubtareas; i++) {
		t_tarea* subtarea = list_get(tarea->subtareas, i);
		printf("\n Subtarea %d : %s %f", i + 1, Tarea_asString(subtarea), Tarea_costo(subtarea));
	}
}
// fin temp

