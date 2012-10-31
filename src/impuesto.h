/*
 * impuesto.h
 *
 * Representa una carga impositiva que agrega costo a una tarea
 *
 *  Created on: 19/10/2012
 *      Author: dodain
 */

#ifndef IMPUESTO_H_
#define IMPUESTO_H_

// definición de estructuras de datos
typedef struct Impuesto* impuesto;

// definición de operaciones de alto nivel
impuesto Impuesto_crear(char* descripcion, float costo);
float Impuesto_monto(impuesto, float);
void Impuesto_destroy(impuesto);

#endif /* IMPUESTO_H_ */
