/*
 * AllTests.c
 *
 *  Created on: 15/06/2012
 *      Author: dodain
 */
#include <stdlib.h>
#include <unistd.h>
#include "tareaTest.h"

int main(void) {
	CU_initialize_registry();

	CrearTareasSuite();

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
	return EXIT_SUCCESS;
}
