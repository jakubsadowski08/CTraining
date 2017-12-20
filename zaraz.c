#include<stdio.h>

struct ks
{
	char *imie,*nazwisko,*tytul;
	int nr;
	int cena;
	struct ks * next;
};
struct list
{
	struct ks *head;
	int size;
};

void dopisanie(struct list * lista,struct ks * element)
{
	lista->head = element;
	lista->size=lista->size + 1;
}
void wypisz(struct list lista)
{
	int i =0;
	for(i=0;lista.size>i;i++)
	{
		printf("%s %s %s %d %d",lista.head->imie,lista.head->nazwisko,lista.head->tytul,lista.head->nr,lista.head->cena);
		lista.head=lista.head->next;
	}
}
int main(void)
{
	struct list lista;
	struct ks list_head;
	lista.head = &list_head;
	printf("Podaj imie: ");
	scanf("%s",lista.head->imie);
	printf("Podaj nazwisko: ");
	scanf("%s",lista.head->nazwisko);
	printf("Podaj tytul: ");
	scanf("%s",lista.head->tytul);
	printf("Podaj nr: ");
	scanf("%d",& lista.head->nr);
	printf("Podaj cene: ");
	scanf("%d",& lista.head->cena);
	lista.size=1;
	return 0;
}
