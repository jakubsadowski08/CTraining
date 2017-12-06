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
	algebraiczna};

union postacie
{
	struct wykladnicza WYK;
	struct alg ALG;
};
struct all{
	union postacie POSTACIE;
	enum ktora POSTAC;
};
void wykladnicz(struct alg * complex, struct wykladnicza * wyk)
{
	wyk->mod = sqrt(complex->r * complex->r + complex->i*complex->i);
	wyk->arg = acos(complex->r/wyk->mod);
}
int main(void)
{
	int wybor;
	struct all ALL;
	printf("podaj liczby: ");
	scanf("%f",& ALL.POSTACIE.ALG.r);
	scanf("%f",& ALL.POSTACIE.ALG.i);
	printf("Napisz 0 jesli chcesz postac kanoniczna, 1 jesli wykladnicza: ");
	scanf("%d",&wybor);
	wykladnicz(& ALL.POSTACIE.ALG,& ALL.POSTACIE.WYK);
	switch(wybor)
	{
	case wykladnicza:
		printf("%f\n%f",ALL.POSTACIE.WYK.mod,ALL.POSTACIE.WYK.arg);
	case algebraiczna:
		printf("%f\n%f",ALL.POSTACIE.ALG.i,ALL.POSTACIE.ALG.r);
	}
	return 0;
}
	
