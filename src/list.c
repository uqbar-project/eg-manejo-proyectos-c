/*
 * list.c
 *
 *  Created on: 02/06/2012
 *      Author: la Internet
 */
#include <stdio.h>
#include <stdlib.h>
#include <windef.h>
#include "list.h"

struct node* list_createNode() {
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Error! memory is not available\n");
		exit(0);
	}
	return newNode;
}

/** El original de internet hacía **/
//struct node* list_add(struct node *head, void* data) {
//	struct node *tmp;
//	if (head == NULL) {
//		head = (struct node *) malloc(sizeof(struct node));
//		if (head == NULL) {
//			printf("Error! memory is not available\n");
//			exit(0);
//		}
//		head->data = data;
//		head->next = NULL;
//	} else {
//		tmp = head;
//
//		while (tmp->next != head)
//			tmp = tmp->next;
//		tmp->next = (struct node *) malloc(sizeof(struct node));
//		if (tmp->next == NULL) {
//			printf("Error! memory is not available\n");
//			exit(0);
//		}
//		tmp = tmp->next;
//		tmp->data = data;
//		tmp->next = head;
//	}
//	return head;
//}

/** Refactorizada**/
struct node* list_add(struct node *head, void* data) {
	struct node *tmp = list_createNode();
	tmp->data = data;
	tmp->next = head;
	return tmp;
}

void list_print(struct node *head) {
	int actualSize = list_size(head);
	if (actualSize == 0) {
		printf("The list is empty\n");
	} else {
		int i;
		for (i = 0; i <= actualSize; i++) {
			printf(list_get(head, i));
		}
	}
// Versión anterior
//	struct node *current;
//	current = head;
//	if (current != NULL) {
//		do {
//			printf(current->data);
//			current = current->next;
//		} while (current != head);
//		printf("\n");
//	} else {
//		printf("The list is empty\n");
//	}
}

void list_destroy(struct node *head) {
	struct node *current, *tmp;

	current = head->next;
	while (current != NULL) {
		tmp = current->next;
		free(current);
		current = tmp;
	}

}

void* list_get(struct node *head, int index) {
	struct node* current = head;
	int i;
	for (i = 0; i < index; i++) {
		current = current->next;
	}
	return current->data;
}

int list_size(struct node *head) {
	int actualSize = 0;
	struct node* current = head;
	while (current != NULL) {
		current = current->next;  // qué pasa si hago head->next
		actualSize++;
	}
	return actualSize;
}
