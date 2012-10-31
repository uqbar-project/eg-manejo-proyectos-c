/*
 *
 * ENUM COMPLEJIDAD
 *
 * complejidad.c
 *
 * Representa la complejidad inherente a una tarea
 *
 *  Created on: 26/05/2012
 *      Author: dodain
 */

#include <stdio.h>
#include "complejidad.h"

#define PORCENTAJE_EXTRA_COMPLEJIDAD_MEDIA    		1.05;

#define PORCENTAJE_EXTRA_COMPLEJIDAD_MAXIMA   		1.07;
#define MAXIMO_DIAS_COMPLEJIDAD_MAXIMA    		    10;
#define COSTO_EXTRA_COMPLEJIDAD_MAXIMA 				10;

static const float COMPLEJIDAD_COSTO_BASE = 25.0;

/************************************************************
 * Operaciones primitivas
 *************************************************************/
float internalComplejidad_costoBase(int tiempo) {
	return tiempo * COMPLEJIDAD_COSTO_BASE;
}

float internalComplejidad_costoBaseComplejidadMaxima(float costoBase, int tiempo) {
	float result = costoBase * PORCENTAJE_EXTRA_COMPLEJIDAD_MAXIMA;
	int delayExtra = tiempo - MAXIMO_DIAS_COMPLEJIDAD_MAXIMA;
	if (delayExtra > 0) {
		float costoExtra = delayExtra * COSTO_EXTRA_COMPLEJIDAD_MAXIMA;
		result = result + costoExtra;
	}
	return result;
}

/************************************************************
 * Operaciones de alto nivel
 *************************************************************/
float Complejidad_costo(enum COMPLEJIDAD complejidad, int tiempo) {
	float costoBase = internalComplejidad_costoBase(tiempo);
	switch (complejidad) {
	case COMPLEJIDAD_MINIMA:
		return costoBase;
		break;
	case COMPLEJIDAD_MEDIA:
		return costoBase * PORCENTAJE_EXTRA_COMPLEJIDAD_MEDIA;
		break;
	default:
		return internalComplejidad_costoBaseComplejidadMaxima(costoBase, tiempo);
		break;
	}
	// Sólo para que no tire warning el compiler
	return costoBase;
}

