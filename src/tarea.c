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
#include "impuesto.h"

#define for_each(cant, it) \
	int it; \
	for (it = 0; it < cant; it++)

/************************************************************
 * Estructura interna
 *************************************************************/
struct Tarea {
	char* descripcion;
	int tiempo;
	enum COMPLEJIDAD complejidad;
	list subtareas;
	list impuestos;
};

/************************************************************
 * Operaciones primitivas
 *************************************************************/
tarea internalTarea_crear(char* descripcion, int tiempo, complejidad complejidad) {
	tarea self = (tarea) malloc(sizeof(struct Tarea));

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

float internalTarea_costoBase(tarea tarea) {
	return Complejidad_costo(tarea->complejidad, tarea->tiempo);
}

/************************************************************
 * Operaciones de alto nivel
 *************************************************************/
tarea Tarea_crear(char* descripcion, int tiempo) {
	// por default creamos la tarea de complejidad minima
	tarea tarea = internalTarea_crear(descripcion, tiempo, COMPLEJIDAD_MINIMA);
	tarea->subtareas = NULL;
	tarea->impuestos = NULL;
	return tarea;
}

float Tarea_costo(tarea unaTarea) {
	float costoBase = internalTarea_costoBase(unaTarea);
	float costoTotal = costoBase;
	int cantidadSubtareas = list_size(unaTarea->subtareas);
	for_each(cantidadSubtareas, i) {
		tarea subtarea = list_get(unaTarea->subtareas, i);
		costoTotal = costoTotal + Tarea_costo(subtarea);
	}
	int cantidadImpuestos = list_size(unaTarea->impuestos);
	for_each(cantidadImpuestos, j) {
		impuesto unImpuesto = list_get(unaTarea->impuestos, j);
		costoTotal = costoTotal + Impuesto_monto(unImpuesto, costoBase);
	}

	return costoTotal;
}

float Tarea_tiempoTotal(tarea unaTarea) {
	return unaTarea->tiempo;
}

char* Tarea_asString(tarea unaTarea) {
	return unaTarea->descripcion;
}

void Tarea_destroy(tarea unaTarea) {
	if (unaTarea->subtareas != NULL) {
		int cantidadTareas = list_size(unaTarea->subtareas);
		for_each(cantidadTareas, i) {
			tarea subtarea = list_get(unaTarea->subtareas, i);
			Tarea_destroy(subtarea);
		}
		list_destroy(unaTarea->subtareas);
	}
	if (unaTarea->impuestos != NULL) {
		int cantidadImpuestos = list_size(unaTarea->impuestos);
		for_each(cantidadImpuestos, j) {
			impuesto unImpuesto = list_get(unaTarea->impuestos, j);
			Impuesto_destroy(unImpuesto);
		}
		list_destroy(unaTarea->impuestos);
	}

	free(unaTarea->descripcion);
	free(unaTarea);
}

void Tarea_agregarSubtarea(tarea unaTarea, tarea unaSubtarea) {
	//TODO: Modelar un TAD error
	unaTarea->subtareas = list_add(unaTarea->subtareas, unaSubtarea);
}

void Tarea_agregarImpuesto(tarea tarea, char* descripcionImpuesto, float valorImpuesto) {
	impuesto impuesto = Impuesto_crear(descripcionImpuesto, valorImpuesto);
	tarea->impuestos = list_add(tarea->impuestos, impuesto);
}

void Tarea_setComplejidadMinima(tarea unaTarea) {
	unaTarea->complejidad = COMPLEJIDAD_MINIMA;
}

void Tarea_setComplejidadMedia(tarea unaTarea) {
	unaTarea->complejidad = COMPLEJIDAD_MEDIA;
}

void Tarea_setComplejidadMaxima(tarea unaTarea) {
	unaTarea->complejidad = COMPLEJIDAD_MAXIMA;
}


