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
#include "tarea.h"
#include "proyecto.h"
#include "tareaTest.h"

/********************************************************************
 *  FUNCIONES INTERNAS
 *********************************************************************/
tarea prepareDarClase() {
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
int inicializar() {
	return 0;
}

int limpiar() {
	return 0;
}
/********************************************************************
 *  TESTS
 *********************************************************************/
void TestCostoTareaSimpleComplejidadMinima() {
	float costoDarClase = costoTarea("Preparar clase", 5);

	CU_ASSERT_EQUAL(125, costoDarClase);
}

void TestCostoTareaSimpleComplejidadMinimaConImpuestos() {
	tarea prepararClase;
	prepararClase = Tarea_crear("Preparar clase", 5);
	Tarea_agregarImpuesto(prepararClase, "Impuesto A", 3.0f);
	Tarea_agregarImpuesto(prepararClase, "Impuesto B", 5.0f);
	float costoPrepararClase = Tarea_costo(prepararClase);
	Tarea_destroy(prepararClase);

	CU_ASSERT_EQUAL(135, costoPrepararClase);
}

void TestCostoTareaSimpleComplejidadMedia() {
	tarea medirTiempoClase = Tarea_crear("Medir tiempo clase", 3);
	float costoDarClase = Tarea_costo(medirTiempoClase);
	Tarea_setComplejidadMedia(medirTiempoClase);
	Tarea_destroy(medirTiempoClase);

	CU_ASSERT_EQUAL(75, costoDarClase);
}

void TestCostoTareaCompuestaSinImpuestos() {
	tarea darClase = prepareDarClase();
	float costoDarClase = Tarea_costo(darClase);
	Tarea_destroy(darClase);

	CU_ASSERT_EQUAL(403.75,costoDarClase);
}

void TestCostoProyecto() {
	tarea subirResumenAlSite = Tarea_crear("Subir resumen al site", 10);
	proyecto claseDisenioEstructurado = Proyecto_crear("Disenio estructurado");
	Proyecto_agregarTarea(claseDisenioEstructurado, prepareDarClase());
	Proyecto_agregarTarea(claseDisenioEstructurado, subirResumenAlSite);
	float costoClaseDE = Proyecto_costo(claseDisenioEstructurado);
	// El destroy de tareas es Por las dudas, debemos tener cuidado
	// de no eliminar la tarea antes del proyecto porque queda mal la referencia
	Proyecto_destroy(claseDisenioEstructurado);
	Tarea_destroy(subirResumenAlSite);

	CU_ASSERT_EQUAL(653.75,costoClaseDE);
}

void CrearTareasSuite() {
	CU_pSuite suite = CU_add_suite("suite", inicializar, limpiar);
	CU_add_test(suite, "TestCostoTareaSimpleComplejidadMinima", TestCostoTareaSimpleComplejidadMinima);
	CU_add_test(suite, "TestCostoTareaSimpleComplejidadMinima",TestCostoTareaSimpleComplejidadMinima);
	CU_add_test(suite, "TestCostoTareaSimpleComplejidadMinima", TestCostoTareaCompuestaSinImpuestos);
	CU_add_test(suite, "TestCostoTareaSimpleComplejidadMinima", TestCostoTareaSimpleComplejidadMinimaConImpuestos);
	CU_add_test(suite, "TestCostoTareaSimpleComplejidadMinima",TestCostoProyecto);
}

