#include<stdio.h>
#include<math.h>
void dodawanie(float * wek,float * wek_2,float * wek_3,int size)
{
	int i;
	for(i=0;i<size;i++)
		wek_3[i] = wek_2[i] + wek[i];
	for(i=0;i<size;i++)
		{
		printf("%f %f %f \n",wek[i],wek_2[i],wek_3[i]);
		}

}
int main(void)
{
	float wektor[] ={1,5,3,5};
	float wektor_2[] ={3,4,3,5};
	int size =sizeof(wektor) / sizeof(float);
	float wektor_3[size];
	dodawanie(wektor,wektor_2,wektor_3,size);
	return 0;
}
	
