//typedef struct list List;
//typedef struct node Node;

typedef struct node
{
	int info;
	struct node *next;
}Node;

typedef struct list
{
	Node* head;
	int length;
}List;

List* createList();
bool add(List* list, int info);
bool insertAt(List* list, int index, int info);
bool removeAt(List* list, int index);
void printList(List* list);
void dispose(List* list);