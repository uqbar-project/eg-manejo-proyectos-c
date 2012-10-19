/*
 * impuesto.h
 *
 *  Created on: 19/10/2012
 *      Author: dodain
 */

#ifndef IMPUESTO_H_
#define IMPUESTO_H_

// definición de estructuras
typedef struct Impuesto t_impuesto;
typedef struct t_impuesto tad_impuesto;
typedef t_impuesto* impuesto;

t_impuesto* Impuesto_crear(char* descripcion, float costo);
float Impuesto_monto(impuesto, float);
void Impuesto_destroy(impuesto);

#endif /* IMPUESTO_H_ */

