/*
 *
 * DEFINICION DEL TAD IMPUESTO
 *
 * impuesto.c
 *
 * Representa una carga impositiva que agrega costo a una tarea
 *
 *  Created on: 19/10/2012
 *      Author: dodain
 */
#include <stdio.h>
#include <stdlib.h>
#include <windef.h>
#include "impuesto.h"


/************************************************************
 * Estructura interna
 *************************************************************/
struct Impuesto {
	char* descripcion;
	float costo;
};

/************************************************************
 * Operaciones primitivas
 *************************************************************/

/************************************************************
 * Operaciones de alto nivel
 *************************************************************/
impuesto Impuesto_crear(char* descripcion, float costo) {
	impuesto self = (impuesto) malloc(sizeof(struct Impuesto));

	if (self == NULL) {
		perror("No se pudo crear el impuesto");
		return NULL;
	}

	self->descripcion = malloc(strlen(descripcion) + 1);
	strcpy(self->descripcion, descripcion);
	self->costo = costo;

	return self;
}

float Impuesto_monto(impuesto unImpuesto, float costoBase) {
	return costoBase * unImpuesto->costo / 100;
}

void Impuesto_destroy(impuesto unImpuesto) {
	if (unImpuesto == NULL) {
		return;
	}

	free(unImpuesto->descripcion);
	unImpuesto->descripcion = NULL;
	free(unImpuesto);
}
