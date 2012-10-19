/*
 * complejidad.c
 *
 *  Created on: 26/05/2012
 *      Author: dodain
 */

#include <stdio.h>
#include "complejidad.h"

static const float COMPLEJIDAD_COSTO_BASE = 25.0;

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

float Complejidad_costo(enum COMPLEJIDAD complejidad, int tiempo) {
	float costoBase = internalComplejidad_costoBase(tiempo);
	switch (complejidad) {
	case COMPLEJIDAD_MINIMA:
		return costoBase;
		break;
	case COMPLEJIDAD_MEDIA:
		return costoBase * PORCENTAJE_EXTRA_COMPLEJIDAD_MEDIA
		;
		break;
	default:
		return internalComplejidad_costoBaseComplejidadMaxima(costoBase, tiempo);
		break;
	}
	// Sólo para que no tire warning el compiler
	return costoBase;
}

