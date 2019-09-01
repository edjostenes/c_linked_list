#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* createNode()
{
	return (Node*)malloc(sizeof(Node));
}

List* createList()
{
	List* list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->length = 0;
	return list;
}

/*
	Adding to the end of list
*/
bool add(List* list, int info)
{
	if (list->head == NULL)
	{
		list->head = createNode();
		
		if (list->head == NULL)
		{
			printf("Out of memory\n");
			return false;
		}

		if (list->head == NULL)
		{
			return false;
		}

		list->head->info = info;
		list->head->next = NULL;
		list->length++;
		return true;
	}

	Node *aux = list->head;

	while(aux->next != NULL)
	{
		aux = aux->next;
	}

	Node* newNode = createNode();

	if (newNode == NULL)
	{
		printf("Out of memory\n");
		return false;
	}

	newNode->info = info;
	newNode->next = NULL;
	aux->next = newNode;
	list->length++;
	return true;
}

/*
	Inserting at position INDEX
*/
bool insertAt(List* list, int index, int info)
{
	if (index > list->length)
	{
		printf("Out of bounds\n");
		return false;
	}

	Node* newNode = createNode();

	if (newNode == NULL)
	{
		printf("Out of memory\n");
		return false;
	}

	if (index == 0)
	{
		newNode->info = info;
		newNode->next = list->head;
		list->head = newNode;
	}
	else
	{
		Node* aux = list->head;
		int i = 0;

		while (i < (index - 1))
		{
			aux = aux->next;
			i++;
		}

		newNode->info = info;
		newNode->next = aux->next;
		aux->next = newNode;
	}

	list->length++;
	return true;
}

/*
	Removing from any position
*/
bool removeAt(List* list, int index)
{
	if (index < 0 || index > list->length)
	{
		printf("Out of bounds\n");
		return false;
	}
	
	Node* aux = list->head;
	
	if (index == 0)
	{
		list->head = list->head->next;
		free(aux);
	}
	else
	{
		int i = 0;

		while (i < (index - 1))
		{
			aux = aux->next;
			i++;
		}

		Node* toBeDeleted = aux->next;
		aux->next = toBeDeleted->next;
		free(toBeDeleted);
	}

	list->length--;
	return true;
}

void printList(List* list)
{
	Node* aux = list->head;
	while(aux != NULL)
	{
		printf("Info: %d\n", aux->info);
		aux = aux->next;
	}
	printf("Lenght: %d\n", list->length);
}

/*
	Releasing memory.
	READ ABOUT MEMORY LEAK
*/
void dispose(List* list)
{
	Node* aux = NULL;

	while (list->head != NULL)
	{
		aux = list->head;
		list->head = list->head->next;
		free(aux);
	}
	
	free(list);
}
















