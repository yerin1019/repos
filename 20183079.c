#define _CRT_SECURE_NO_WARNIGNS_
#include<stdio.h>

/*3부터 20까지의 홀수값에 대한 fibonacci 수를 각각 계산하여 출력*/
int rfibo(int a);
int sfibo(int x);

int main()

{

	int i;


	for (i = 2; i < 46; i++)
	{

		if (i % 2 == 1)
		{
			printf("rfibo(%3d) : %5d\n",i,rfibo(i));
		
		}

	}

	printf("\n");

	for (i = 2; i < 20; i++)
	{

		if (i % 2 == 1)
		{
			printf("sfibo(%3d) : %5d\n", i, rfibo(i));

		}

	}



	return 0;

}

int rfibo(int a)
{
	if (a == 0) return 0;
	else if (a == 1) return 1;
	else return (rfibo(a - 1) + rfibo(a - 2));
}

int sfibo(int x)
{
	static int a = 1, b = 1, c;
	

		c = a + b;
		a = b;
		b = c;
	
	
	return c;

}