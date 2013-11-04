/*
 * list.c
 *
 * Representa un conjunto ordenado de datos que admite duplicados
 *
 *  Created on: 02/06/2012
 *      Author: la Internet
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#ifdef _WIN32
	#include <windef.h>
#endif

/************************************************************
 * Estructura interna
 *************************************************************/
struct node {
	void* data;
	list next;
};

/************************************************************
 * Operaciones de alto nivel
 *************************************************************/
list list_createNode() {
	list newNode = (list) malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Error! memory is not available\n");
		exit(0);
	}
	return newNode;
}

list list_add(list head, void* data) {
	list tmp = list_createNode();
	tmp->data = data;
	tmp->next = head;
	return tmp;
}

void list_print(list head) {
	int actualSize = list_size(head);
	if (actualSize == 0) {
		printf("The list is empty\n");
	} else {
		int i;
		for (i = 0; i <= actualSize; i++) {
			printf(list_get(head, i), "%s");
		}
	}
}

void list_destroy(list head) {
	list current, tmp;

	current = head->next;
	while (current != NULL) {
		tmp = current->next;
		free(current);
		current = tmp;
	}

}

void* list_get(list head, int index) {
	list current = head;
	int i;
	for (i = 0; i < index; i++) {
		current = current->next;
	}
	return current->data;
}

int list_size(list head) {
	int actualSize = 0;
	list current = head;
	while (current != NULL) {
		current = current->next;
		actualSize++;
	}
	return actualSize;
}
