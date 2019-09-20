#include "includes/filaOrdenada.h"

void initList(List *list){
	list->first = NULL;
	list->size = 0;
}

void insert(List *list, Object x){
	Pointer new;
	new = (Pointer)malloc(sizeof(Pointer));
	new->element = x;


	// TODO
	// make a search using the object x.key in the list
	// if the object is already listed, breaks the function because we dont wanna multiples equals numbers and send a msg to user warning
	if(isEmpty(list)){
		list->first = new;
		list->size++;
		printf("## Object {%i} inserted in the 1st pos\n", new->element.key);
	} else {
		Pointer aux = list->first;
		if(list->first->element.key > x.key){
			new->next = aux;
			list->first = new;
			list->size++;
			printf("## Object {%i} inserted in the 1st pos and pushed object {%i} to 2nd pos\n", new->element.key, list->first->next->element.key);
		} else {
			while(aux->next != NULL && x.key > aux->next->element.key){
				aux = aux->next;
			}
			new->next = aux->next;
			aux->next = new;
			list->size++;
			printf("## Object {%i} inserted\n", new->element.key);
		}
	}
}

void printList(List *list){
	Pointer aux = list->first;
	printf("\n{ ");
	for(aux = list->first; aux->next != NULL; aux = aux->next){
		printf("%i ", aux->element.key);
	}
	printf("%i ", aux->element.key);
	printf("}");
}

void destroyList(List *list){
	Pointer aux;
	Pointer remove;
	for(aux = list->first; aux->next != NULL; aux = aux->next){
		remove = aux;
		aux = aux->next;
		free(remove);
	}

	printf("## LIST CLEAR ##");
}

bool isEmpty(List *list){
	return (list->size==0) ? true : false;
}

bool search(List *list, int key){
	if(isEmpty(list))	return false;

	Pointer aux;
	aux = list->first;

	while( aux != NULL || key > aux->element.key){
		aux = aux->next;
	}

	return (aux == NULL || aux->element.key > key) ? false : true;
}

Object getObj(List *list, int key){
	Object obj;
	if(isEmpty(list)) {
		obj.key = 0;
		return obj;
	}

	Pointer aux;
	aux = list->first;

	while(aux != NULL || key > aux->element.key){
		aux = aux->next;
	}

	if(aux == NULL || aux->element.key > key) {
		obj.key = 0;
		return obj;
	} else {
		obj = aux->element;
		return obj;
	}
}

// bool searchFaster(List *list, int key){
//
// }

int size(List *list){
	return list->size;
}

void removeElement(List *list, int key, Object *item){
	if(isEmpty(list) || list->first->element.key > key){
		item = NULL;
		printf("## The List is Empty or the object isnt listed!!\n");
	} else {
		if(key == list->first->element.key){
			removeFirst(list, item);
		} else {
			*item = getObj(list, key);
			if(item!=NULL){
				// code here the remove function
				// using the searched object pos []
				// last Auxiliar Next receives another aux with next of the next object listed
				// lastAux = aux->next->next;
			} else {
				printf("## Object isn't listed\n");
			}
		}
	}
}

void removeFirst(List *list, Object *item){
	Pointer aux = list->first; // makes a pointer to point to the first object of the list
	*item = aux->element;	// make the object passed by parameter receive the element of aux pointer
	list->first = aux->next;	// make the first object receive next object of aux pointer
	list->size--;

	printf("## Removed 1st object with value { %i }\n", aux->element.key);

	free(aux);
}

void removeLast(List *list, Object *item){
	Pointer aux = list->first;
	while (aux->next->next != NULL) {
		aux = aux->next;
	}
	Pointer remove = aux->next;
	*item = remove->element;
	printf("## Removed last object with value { %i }\n", (*item).key);
	aux->next = NULL;
	free(remove);

	list->size--;
}

Object first(List *list){
	return list->first->element;
}

Object last(List *list){
	Pointer aux = list->first;
	while(aux->next != NULL){
		aux = aux->next;
	}
	return aux->element;
}

int main() {
	List list;
	initList(&list);
	Object ob;
	srand(time(NULL));
	for(int i=0; i<10; i++){
		ob.key = rand()%100;
		insert(&list,ob);
	}
	printList(&list);

	return 0;
}
