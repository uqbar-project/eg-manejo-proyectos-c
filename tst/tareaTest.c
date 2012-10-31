/*
 * testTarea.c
 *
 *  Created on: 26/05/2012
 *      Author: dodain
 */
#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/tarea.h"
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
	darClase = Tarea_crear("Dar clase de Diseño Estructurado", 8);
	Tarea_setComplejidadMinima(darClase);
	prepararClase = Tarea_crear("Preparar clase", 5);
	medirTiempoClase = Tarea_crear("Medir tiempo clase", 3);
	Tarea_setComplejidadMedia(medirTiempoClase);
	Tarea_agregarSubtarea(darClase, prepararClase);
	Tarea_agregarSubtarea(darClase, medirTiempoClase);
	return darClase;
}

float costoTarea(char *descripcion, int tiempo) {
	tarea tarea = Tarea_crear(descripcion, tiempo);
	float costo = Tarea_costo(tarea);
	Tarea_destroy(tarea);
	return costo;
}

/********************************************************************
 *  TESTS
 *********************************************************************/
void TestCostoTareaSimpleComplejidadMinima(CuTest* tc) {
	float costoDarClase = costoTarea("Preparar clase", 5);

	CuAssert(tc, "costo de preparar clase", costoDarClase == 125);
}

void TestCostoTareaSimpleComplejidadMinimaConImpuestos(CuTest* tc) {
	tarea prepararClase;
	prepararClase = Tarea_crear("Preparar clase", 5);
	Tarea_agregarImpuesto(prepararClase, "Impuesto A", 3.0f);
	Tarea_agregarImpuesto(prepararClase, "Impuesto B", 5.0f);
	float costoPrepararClase = Tarea_costo(prepararClase);
	Tarea_destroy(prepararClase);

	CuAssert(tc, "costo de preparar clase", costoPrepararClase == 135);
}

void TestCostoTareaSimpleComplejidadMedia(CuTest* tc) {
	tarea medirTiempoClase = Tarea_crear("Medir tiempo clase", 3);
	float costoDarClase = Tarea_costo(medirTiempoClase);
	Tarea_setComplejidadMedia(medirTiempoClase);
	Tarea_destroy(medirTiempoClase);

	CuAssert(tc, "costo de medir tiempo de clase", costoDarClase == 75);
}

void TestCostoTareaCompuestaSinImpuestos(CuTest* tc) {
	tarea darClase = prepareDarClase();
	float costoDarClase = Tarea_costo(darClase);
	Tarea_destroy(darClase);

	CuAssert(tc, "costo de dar clase", costoDarClase == 400);
}

void TestCostoProyecto(CuTest* tc) {
	tarea subirResumenAlSite = Tarea_crear("Subir resumen al site", 10);
	proyecto claseDisenioEstructurado = Proyecto_crear("Disenio estructurado");
	Proyecto_agregarTarea(claseDisenioEstructurado, prepareDarClase());
	Proyecto_agregarTarea(claseDisenioEstructurado, subirResumenAlSite);
	float costoClaseDE = Proyecto_costo(claseDisenioEstructurado);
	Tarea_destroy(subirResumenAlSite);
	Proyecto_destroy(claseDisenioEstructurado);

	CuAssert(tc, "costo de proyecto", costoClaseDE == 650);
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

