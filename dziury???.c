#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void dynamiczna(char ** lancuch,int how_many)
{
	int i;
	int size;
	for(i=0;i<how_many;i++)
	{
		size = strlen(lancuch[i]) +1;
		lancuch[i] = (char *)realloc(lancuch[i],size * sizeof(** lancuch));
	}
}
int main()
{
	int i;
	int size = 5;
	int len = 64;
	char ** tablica;
	tablica = (char **)malloc(size * sizeof *tablica);
	for(i=0;i<size;i++)
		tablica[i] = (char *)malloc(len * sizeof(** tablica));
	printf("Napisz 5 lancuchow: ");
	for(i=0;i<size;i++)
		scanf("%s",tablica[i]);
	dynamiczna(tablica,size);
	free(tablica);
	return 0;
}
