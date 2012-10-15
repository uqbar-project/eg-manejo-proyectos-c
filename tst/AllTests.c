/*
 * AllTests.c
 *
 *  Created on: 15/06/2012
 *      Author: dodain
 */
#include <stdio.h>
#include <stdlib.h>
#include "CuTest.h"
#include "tareaTest.h"

void RunAllTests(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, CuGetTareasSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main(void) {
	RunAllTests();
	return EXIT_SUCCESS;
}
