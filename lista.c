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
	int i;
	struct list lista;
	struct ks list_head ={"asdf","asdfg","asdfgh",33,50,NULL};
	lista.head = &list_head;
	lista.size = 1;
	struct ks ksiazki[50];
	for(i=0;i<5;i++)
	{
		printf("Podaj imie: ");
		scanf("%s",ksiazki[i].imie);
		printf("Podaj nazwisko: ");
		scanf("%s",ksiazki[i].nazwisko);
		printf("Podaj tytul: ");
		scanf("%s", ksiazki[i].tytul);
		printf("Podaj nr: ");
		scanf("%d", &ksiazki[i].nr);
		printf("Podaj cene: ");
		scanf("%d", &ksiazki[i].cena);
		dopisanie(& lista, &ksiazki[i]);
	}
	wypisz(lista);
	return 0;
}
