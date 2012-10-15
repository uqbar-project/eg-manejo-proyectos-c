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
#include "../src/complejidad.h"
#include "../src/tarea.h"
//#include <cutest-1.5/CuTest.h>
#include "CuTest.h"
#include "tareaTest.h"

static float costoTarea(char *descripcion, int tiempo, t_complejidad complejidad) {
	t_tarea* tarea = Tarea_crear(descripcion, tiempo, complejidad);
	float costo = Tarea_costo(tarea);
	Tarea_destroy(tarea);
	return costo;
}

void TestCostoTareaSimpleComplejidadMinima(CuTest* tc) {
	t_tarea* prepararClase;
	prepararClase = Tarea_crear("Preparar clase", 5, COMPLEJIDAD_MINIMA);
	float costoDarClase = Tarea_costo(prepararClase);

	CuAssert(tc, "costo de preparar clase", costoDarClase == 125);
}

void TestCostoTareaSimpleComplejidadMedia(CuTest* tc) {
	float costoDarClase = costoTarea("Medir tiempo clase", 3, COMPLEJIDAD_MEDIA);
	CuAssert(tc, "costo de medir tiempo de clase", costoDarClase == 75);
}

void TestCostoTareaCompuestaSinImpuestos(CuTest* tc) {
	t_tarea* darClase;
	t_tarea* prepararClase;
	t_tarea* medirTiempoClase;

	darClase = Tarea_crear("Dar clase de Diseño Estructurado", 8, COMPLEJIDAD_MINIMA);
	prepararClase = Tarea_crear("Preparar clase", 5, COMPLEJIDAD_MINIMA);
	medirTiempoClase = Tarea_crear("Medir tiempo clase", 3, COMPLEJIDAD_MEDIA);
	Tarea_agregarSubtarea(darClase, prepararClase);
	Tarea_agregarSubtarea(darClase, medirTiempoClase);
	float costoDarClase = Tarea_costo(darClase);
	Tarea_destroy(darClase);

	//printf("\nTarea de %s \n%4.3f", Tarea_asString(darClase), costoDarClase);
	//Tarea_verSubtareas(darClase);

	CuAssert(tc, "costo de dar clase", costoDarClase == 400);
}

CuSuite* CuGetTareasSuite(void) {
	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestCostoTareaSimpleComplejidadMinima);
	SUITE_ADD_TEST(suite, TestCostoTareaSimpleComplejidadMinima);
	SUITE_ADD_TEST(suite, TestCostoTareaCompuestaSinImpuestos);
	return suite;
}
