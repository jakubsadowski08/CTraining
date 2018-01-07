#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
int czyBylaWylosowana( int iLiczba, int tab[], int ile )
{
    if( ile <= 0 )
        return 0;

    int i = 0;
    do
    {
        if( tab[ i ] == iLiczba )
            return 1;
        i++;
    } while( i < ile );

    return 0;
}
int losuj(int ile)
{
    return 1+ rand()%(ile*(ile-1)/2+1);
}
struct  Sedzia losowy(struct Wezel head, int los)
{
    int i;
    struct Wezel * tmp = &head;
    for(i=1;i<los;i++)
    {
        tmp = tmp->next;
    }
    return * tmp->dane;
}
void wypisz(struct Wezel * head,int nd)
{
    int i;
    struct Sedzia sendzia;
    int wylosowane[ nd*(nd-1)/2 ];
    int wylosowanych = 0;
    do
    {
        int liczba = losuj(nd);
        if( czyBylaWylosowana( liczba, wylosowane, wylosowanych ) == 0)
        {
            wylosowane[ wylosowanych ] = liczba;
            wylosowanych++;
        }
    } while( wylosowanych <= nd*(nd-1)/2 );
    for(i=0;i<=nd*(nd-1)/2;i++)
    {
        sendzia = losowy(*head,wylosowane[i]);
        printf("Gra nr %d - Sedzia %s o id %d \n",i+1,sendzia.nazwisko,sendzia.id);
    }


}
int main() {
    time_t tt;
    int zarodek = time(&tt);
    srand(zarodek);
    struct Wezel * head;
    int nd, i, id;
    char nazwisko[256];
    head->next = NULL;
    head->dane = NULL;
    printf("Podaj liczbe druzyn ");
    scanf("%d",&nd);
    for(i=0;i<=nd*(nd-1)/2;i++)
    {
        printf("Podaj nazwisko sedziego: ");
        scanf("%s",nazwisko);
        printf("Podaj id sedziego: ");
        scanf("%d", &id);
        przydziel(nazwisko,id,head);
    }
    wypisz(head,nd);
    return 0;
}
