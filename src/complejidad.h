/*
 * complejidad.h
 *
 * Representa la complejidad inherente a una tarea
 *
 *  Created on: 26/05/2012
 *      Author: dodain
 */

#ifndef COMPLEJIDAD_H_
#define COMPLEJIDAD_H_

// definición de estructuras de datos
typedef enum COMPLEJIDAD {
	COMPLEJIDAD_MINIMA,
	COMPLEJIDAD_MEDIA,
	COMPLEJIDAD_MAXIMA
} complejidad;

// definición de operaciones de alto nivel
float Complejidad_costo(enum COMPLEJIDAD complejidad, int tiempo);

#endif /* COMPLEJIDAD_H_ */
