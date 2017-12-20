
#include<stdio.h>
#define max_n 50
struct ks
{
	char imie[50];
	char nazwisko[50];
	char tytul[50];
	int nr;
	int cena;
	struct ks * next;
};
struct list
{
	struct ks *head;
	int size;
};
void dopisanie(struct list * lista, struct ks * element)
{
	element->next = lista->head;
	lista->head = element;
	lista->size = lista->size + 1;
}
void wypisz(struct list lista)
{
	int i = 0;
	for (i = 0; lista.size>i; i++)
	{
		printf("Ksiazka nr: %d \n%s\n%s\n%s\n%d\n%d\n", i+1,lista.head->imie, lista.head->nazwisko, lista.head->tytul, lista.head->nr, lista.head->cena);
		lista.head = lista.head->next;
	}
}
int main(void)
{
	struct list lista;
	struct ks list_head;
	lista.head = &list_head;
	printf("Podaj imie: ");
	fgets(lista.head->imie, max_n, stdin);
	printf("Podaj nazwisko: ");
	fgets(lista.head->nazwisko, max_n, stdin);
	printf("Podaj tytul: ");
	fgets(lista.head->tytul, max_n, stdin);
	printf("Podaj nr: ");
	scanf("%d", &lista.head->nr);
	printf("Podaj cene: ");
	scanf("%d", &lista.head->cena);
	lista.size = 1;
	struct ks druga ={"asdf","asdfg","asdfgh",33,50,NULL};
	dopisanie(&lista,&druga);
	wypisz(lista);
	return 0;
}


