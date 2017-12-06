
#include<stdio.h>
#include<math.h>
struct alg
{
	float r;
	float i;
};
struct wykladnicza
{
	float mod;
	float arg;
};

enum ktora {
	wykladnicza,
	algebraiczna
};

union postacie
{
	struct wykladnicza WYK;
	struct alg ALG;
};
struct all {
	union postacie POSTACIE;
	enum ktora POSTAC;
};
void wykladnicz(struct wykladnicza * wyk,float r,float i )
{
	wyk->mod = (float)sqrt(r * r + i*i);
	wyk->arg = (float)acos(r / wyk->mod);
}
int main(void)
{
	int wybor;
	struct all ALL;
	printf("podaj liczby: ");
	scanf("%f", &ALL.POSTACIE.ALG.r);
	scanf("%f", &ALL.POSTACIE.ALG.i);
	printf("Napisz 0 jesli chcesz postac wykladnicza , 1 jesli algebraiczna: ");
	scanf("%d", &wybor);
	switch (wybor)
	{
	case wykladnicza:
		wykladnicz(&ALL.POSTACIE.WYK, ALL.POSTACIE.ALG.r, ALL.POSTACIE.ALG.i);
		printf("modul: %f\nargument: %f", ALL.POSTACIE.WYK.mod, ALL.POSTACIE.WYK.arg);
		break;
	case algebraiczna:
		printf("rzeczywista: %f\nurojona: %f", ALL.POSTACIE.ALG.r, ALL.POSTACIE.ALG.i);
		break;
	}
	return 0;
}
