/*
 * TareaTest.h
 *
 *  Created on: 15/06/2012
 *      Author: dodain
 */

#ifndef TAREATEST_H_
#define TAREATEST_H_

#include <CUnit/Basic.h>
int inicializar();
int limpiar();
/*
 * Definición de tests sobre la tarea
 */
void TestCostoTareaSimpleComplejidadMinima();
void TestCostoTareaSimpleComplejidadMinima();
void TestCostoTareaCompuestaSinImpuestos();
void TestCostoTareaSimpleComplejidadMinimaConImpuestos();
void TestCostoProyecto();

/*
 *  Definición del suite
 */
void CrearTareasSuite(void);

#endif /* TAREATEST_H_ */
