/*
 * testTarea.c
 *
 * Conjunto de tests asociados principalmente a una tarea
 *  Created on: 26/05/2012
 *      Author: dodain
 */
#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/complejidad.h"
#include "../src/tarea.h"
#include "../src/impuesto.h"
#include "../src/proyecto.h"
#include "CuTest.h"
#include "tareaTest.h"

/********************************************************************
 *  FUNCIONES INTERNAS
 *********************************************************************/
tarea prepareDarClase(void) {
	tarea darClase;
	tarea prepararClase;
	tarea medirTiempoClase;
	darClase = Tarea_crear("Dar clase de Diseño Estructurado", 8, COMPLEJIDAD_MINIMA);
	prepararClase = Tarea_crear("Preparar clase", 5, COMPLEJIDAD_MINIMA);
	medirTiempoClase = Tarea_crear("Medir tiempo clase", 3, COMPLEJIDAD_MEDIA);
	Tarea_agregarSubtarea(darClase, prepararClase);
	Tarea_agregarSubtarea(darClase, medirTiempoClase);
	return darClase;
}

float costoTarea(char *descripcion, int tiempo, complejidad complejidad) {
	tarea tarea = Tarea_crear(descripcion, tiempo, complejidad);
	float costo = Tarea_costo(tarea);
	Tarea_destroy(tarea);
	return costo;
}

/********************************************************************
 *  TESTS
 *********************************************************************/
void TestCostoTareaSimpleComplejidadMinima(CuTest* tc) {
	tarea prepararClase;
	prepararClase = Tarea_crear("Preparar clase", 5, COMPLEJIDAD_MINIMA);
	float costoDarClase = Tarea_costo(prepararClase);

	CuAssert(tc, "costo de preparar clase", costoDarClase == 125);
}

void TestCostoTareaSimpleComplejidadMinimaConImpuestos(CuTest* tc) {
	tarea prepararClase;
	prepararClase = Tarea_crear("Preparar clase", 5, COMPLEJIDAD_MINIMA);
	impuesto impuestoA;
	impuesto impuestoB;
	impuestoA = Impuesto_crear("Impuesto A", 3.0f);
	impuestoB = Impuesto_crear("Impuesto B", 5.0f);
	Tarea_agregarImpuesto(prepararClase, impuestoA);
	Tarea_agregarImpuesto(prepararClase, impuestoB);
	float costoPrepararClase = Tarea_costo(prepararClase);
	Impuesto_destroy(impuestoA);
	Impuesto_destroy(impuestoB);
	Tarea_destroy(prepararClase);

	CuAssert(tc, "costo de preparar clase", costoPrepararClase == 135);
}

void TestCostoTareaSimpleComplejidadMedia(CuTest* tc) {
	float costoDarClase = costoTarea("Medir tiempo clase", 3, COMPLEJIDAD_MEDIA);

	CuAssert(tc, "costo de medir tiempo de clase", costoDarClase == 75);
}

void TestCostoTareaCompuestaSinImpuestos(CuTest* tc) {
	tarea darClase = prepareDarClase();
	float costoDarClase = Tarea_costo(darClase);
	Tarea_destroy(darClase);

	CuAssert(tc, "costo de dar clase", costoDarClase == 403.75);
}

void TestCostoProyecto(CuTest* tc) {
	tarea subirResumenAlSite = Tarea_crear("Subir resumen al site", 10, COMPLEJIDAD_MINIMA);
	proyecto claseDisenioEstructurado = Proyecto_crear("Disenio estructurado");
	Proyecto_agregarTarea(claseDisenioEstructurado, prepareDarClase());
	Proyecto_agregarTarea(claseDisenioEstructurado, subirResumenAlSite);
	float costoClaseDE = Proyecto_costo(claseDisenioEstructurado);
	Tarea_destroy(subirResumenAlSite);
	Proyecto_destroy(claseDisenioEstructurado);
	CuAssert(tc, "costo de proyecto", costoClaseDE == 653.75);
}

CuSuite* CuGetTareasSuite(void) {
	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestCostoTareaSimpleComplejidadMinima);
	SUITE_ADD_TEST(suite, TestCostoTareaSimpleComplejidadMinima);
	SUITE_ADD_TEST(suite, TestCostoTareaCompuestaSinImpuestos);
	SUITE_ADD_TEST(suite, TestCostoTareaSimpleComplejidadMinimaConImpuestos);
	SUITE_ADD_TEST(suite, TestCostoProyecto);
	return suite;
}

