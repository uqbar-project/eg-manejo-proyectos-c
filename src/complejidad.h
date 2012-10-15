/*
 * complejidad.h
 *
 *  Created on: 26/05/2012
 *      Author: dodain
 */

#ifndef COMPLEJIDAD_H_
#define COMPLEJIDAD_H_

#define PORCENTAJE_EXTRA_COMPLEJIDAD_MEDIA    		1.05;

#define PORCENTAJE_EXTRA_COMPLEJIDAD_MAXIMA   		1.07;
#define MAXIMO_DIAS_COMPLEJIDAD_MAXIMA    		    10;
#define COSTO_EXTRA_COMPLEJIDAD_MAXIMA 				10;

typedef enum COMPLEJIDAD {
	COMPLEJIDAD_MINIMA,
	COMPLEJIDAD_MEDIA,
	COMPLEJIDAD_MAXIMA
} t_complejidad;

float Complejidad_costo(enum COMPLEJIDAD complejidad, int tiempo);

#endif /* COMPLEJIDAD_H_ */
