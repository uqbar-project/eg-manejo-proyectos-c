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

// definición de estructuras de datos
typedef struct node* list;

// operaciones de alto nivel
list list_add(list head, void* data);
void list_print(list head);
void list_destroy(list head);
void* list_get(list head, int index);
int list_size(list head);

#endif /* LIST_H_ */
