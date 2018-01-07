#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sedzia
{
    char nazwisko[256];
    int id;
};
struct Wezel
{
    struct Sedzia * dane;
    struct Wezel * next;
};
void dodaj(struct Wezel * head, struct Wezel * nowy)
{
    struct Wezel * tmp = head;
    if (head->dane == NULL)
    {
        head->dane = nowy->dane;
        head->next = NULL;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = nowy;
        nowy->next = NULL;
    }
}
void przydziel(char nazwiskos[256],int ids,struct Wezel * head)
{
    struct Wezel * element;
    element = (struct Wezel *)malloc(sizeof(struct Wezel));
    element->dane = (struct sedzia *)malloc(sizeof(struct Sedzia));
    strcpy(element->dane->nazwisko,nazwiskos);
    element->dane->id = ids;
    dodaj(head, element);
}
void wypisz(struct Wezel head)
{
    struct Wezel * tmp = &head;
    while (tmp != NULL)
    {
        printf("%s %d\n",tmp->dane->nazwisko,tmp->dane->id);
        tmp = tmp->next;
    }
}
int main() {
    struct Wezel head;
    head.next = NULL;
    head.dane = NULL;
    przydziel("Sad",1,& head);
    przydziel("Sadowski",2,& head);
    przydziel("Sads",3,& head);
    wypisz(head);
    return 0;
}
