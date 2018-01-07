#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct sedzia
{
	char nazwisko[256];
	int id;
};
struct wezel
{
	struct sedzia * Sedzia;
	struct wezel * next;
};
void dodaj(struct wezel * head,struct wezel * element)
{
	if(element->next == NULL)
	{
		head = element;
		head->next = NULL;
	}
	else
	{
	element->next = head;
	head = element;
	}
}
void wczytaj(char nazwiskos[256], int ids, struct wezel * head)
{
	
	struct wezel * element = (struct wezel *)malloc(sizeof(struct wezel));
	strcpy(element->Sedzia->nazwisko,nazwiskos);
	element->Sedzia->id = ids;
	if(head->next == NULL)
	{
		element->next = NULL;
		head = element;
	}
	dodaj(head, element);
}
int main(int argc, char const *argv[])
{
	struct wezel lista;
	lista.Sedzia = NULL;
	lista.next = NULL;
	wczytaj("Jacek",1,&lista);
	return 0;
}
