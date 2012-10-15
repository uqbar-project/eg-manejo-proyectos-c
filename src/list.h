/*
 * list.h
 *
 *  Created on: 02/06/2012
 *      Author: dodain
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <windef.h>

struct node {
	void* data;
	struct node *next;
} t_node;

struct node* list_add(struct node *head, void* data);
void list_print(struct node *head);
void list_destroy(struct node *head);
void* list_get(struct node *head, int index);
int list_size(struct node *head);

#endif /* LIST_H_ */
