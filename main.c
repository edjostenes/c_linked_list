#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(int argc, char** argv)
{
	//Creating list
	List* list = createList();
	
	//Adding some info
	for(int i = 0; i < 5; i++)
	{
		add(list, i);
	}
	
	//Inserting at some positions
	bool inserted = insertAt(list, 0, 666);
	inserted = insertAt(list, 1, 666);
	inserted = insertAt(list, 2, 432);
	inserted = insertAt(list, 3, 654);
	inserted = insertAt(list, 4, 1958);

	//Removing a node  
	removeAt(list, 3);
	
	//Printing all list and disposing after that
	Node* aux = list->head;
	
	while(aux != NULL)
	{
		printf("%d\n", aux->info);
		aux = aux->next;
	}
	
	dispose(list);
	return 0;
}