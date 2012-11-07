/*
 * TareaTest.h
 *
 *  Created on: 15/06/2012
 *      Author: dodain
 */

#ifndef TAREATEST_H_
#define TAREATEST_H_

/*
 * Definición de tests sobre la tarea
 */
void TestCostoTareaSimpleComplejidadMinima(CuTest *);
void TestCostoTareaSimpleComplejidadMedia(CuTest *);
void TestCostoTareaCompuestaSinImpuestos(CuTest *);
void TestCostoTareaSimpleComplejidadMinimaConImpuestos(CuTest *);
void TestCostoProyecto(CuTest *);

/*
 *  Definición del suite
 */
CuSuite* CuGetTareasSuite(void);

#endif /* TAREATEST_H_ */
