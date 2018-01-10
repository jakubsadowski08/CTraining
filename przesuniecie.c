#include<stdio.h>

int przesuniecie(int a)
{
	int maska = 32;
	if(a > 96)
	{
		return a & (255- maska);
	}
	else
	{
		return a | maska;
	}
}
int main()
{
	char x ='A';
	printf("%c",przesuniecie((int)x));
	return 0;
}
