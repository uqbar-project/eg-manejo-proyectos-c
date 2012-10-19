/*
 * impuesto.c
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
typedef struct Impuesto {
	char* descripcion;
	float costo;
} t_impuesto;

/************************************************************
 * Funciones privadas de acceso al TAD Impuesto
 *************************************************************/

/************************************************************
 * Constructores
 *************************************************************/
t_impuesto* Impuesto_crear(char* descripcion, float costo) {
	t_impuesto* self = (t_impuesto *) malloc(sizeof(t_impuesto));

	if (self == NULL) {
		perror("No se pudo crear el impuesto");
		return NULL;
	}

	self->descripcion = malloc(strlen(descripcion) + 1);
	strcpy(self->descripcion, descripcion);
	self->costo = costo;

	return self;
}

/************************************************************
 * Operaciones primitivas sobre el TAD Tarea
 *************************************************************/
float Impuesto_monto(impuesto unImpuesto, float costoBase) {
	return costoBase * unImpuesto->costo / 100;
}

void Impuesto_destroy(impuesto unImpuesto) {
	free(unImpuesto->descripcion);
	//free(unImpuesto);
}
