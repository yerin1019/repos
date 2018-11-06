#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*개인명세서 구조체 정의
구조체 배열 10개 선언
5-10개(7개) 입력받고
1.그대로 출력
2,이름순 출력
3.나이순 출력

sorting 해야함....ㅇ어어ㅓ
올림차순 내림차순에서는 부등호만 딱 바꿔주면 된다..?


구조체는 비교는 멤버차원에서만 가능, 대입은 같은 구조인 구조체끼리는 가능함*/


struct id
{

	char name[20];
	struct birth
	{
		int year;
		int month;
		int date;

	}num;
	char sex;
	char address[50];
	int phone;



};



void sortbyname(struct id** ARR, int size);
void sortbybirth(struct id** ARR, int size);

int main()

{

	struct id** arr;
	int n;
	int i, j;




	printf("입력할 자료의 수:");
	scanf_s("%d", &n);
	arr = (struct id**)malloc(sizeof(struct id*)*n);
	for (i = 0; i<n; i++)
	{
		arr[i] = (struct id*)malloc(sizeof(struct id));
	}


	for (i = 0; i < n; i++)
	{
		printf("\n이름,생년월일,성별(F/M),주소,전화번호를 입력하시오\n");
		scanf_s(" %s", &arr[i]->name); //이름입력받기
		scanf_s(" %d %d %d", &arr[i]->num.year, &arr[i]->num.month, &arr[i]->num.date);//생년월일
		scanf_s(" %c", &arr[i]->sex);		//성별
		scanf_s(" %s", &arr[i]->address); //주소
		scanf_s(" %s", &arr[i]->phone);//전화번호
	}






	/*
	for i=[1,n)
	for(j=k;j>0&&x[j=1]>x[j];j--)
	*/

	printf("<입력받은 대로 출력>\n");



	printf("　　이름　　　　생년월일　　　　　성별　　　　　　　주소　　　　　　　　전화번호\n");

	for (int i = 0; i < 10; i++)
	{

		printf(" 　%s　　%d년 %d월 %d일　　　%c　　%s　%011d\n", arr[i]->name, arr[i]->num.year, arr[i]->num.month, arr[i]->num.date, arr[i]->sex, arr[i]->address, arr[i]->phone);

	}

	/*
	레이아웃 박제
	　　이름　　　　생년월일　　　　　성별　　　　　　　주소　　　　　　　　전화번호\n
	  　%s　　%d년 %d월 %d일　　　%c　　%s　%011d\n
	   */

	sortbyname(arr, n);
	printf("<이름 가나다순으로 출력>\n");
	printf("　　이름　　　　생년월일　　　　　성별　　　　　　　주소　　　　　　　　전화번호\n");

	for (int i = 0; i < 10; i++)
	{

		printf(" 　%s　　%d년 %d월 %d일　　　%c　　%s　%011d\n", arr[i]->name, arr[i]->num.year, arr[i]->num.month, arr[i]->num.date, arr[i]->sex, arr[i]->address, arr[i]->phone);

	}

	sortbybirth(arr, n);
	printf("<빠른생일순으로 출력>");
	for (int i = 0; i < 10; i++)
	{

		printf(" 　%s　　%d년 %d월 %d일　　　%c　　%s　%011d\n", arr[i]->name, arr[i]->num.year, arr[i]->num.month, arr[i]->num.date, arr[i]->sex, arr[i]->address, arr[i]->phone);

	}

	free(arr);


	return 0;

}

void sortbyname(struct id** ARR, int size)
{
	int i, j;
	struct id* p;

	for (i = 0; i<size - 1; i++)
	{
		for (j = 0; j<(size - i) - 1; j++)
		{
			if (ARR[j]->name > ARR[j + 1]->name)
			{
				p = ARR[j];
				ARR[j] = ARR[j + 1];
				ARR[j + 1] = p;
			}
		}
	}
	return;
}

void sortbybirth(struct id** ARR, int size)
{


	int i, j;
	struct id* p;


	for (i = 0; i<size - 1; i++)
	{
		for (j = 0; j<(size - i) - 1; j++)
		{
			if (ARR[j]->num.year < ARR[j + 1]->num.year)
			{
				p = ARR[j];
				ARR[j] = ARR[j + 1];
				ARR[j + 1] = p;
			}

			else if (ARR[j]->num.year == ARR[j + 1]->num.year)
			{
				if (ARR[j]->num.month < ARR[j + 1]->num.month)
				{
					p = ARR[j];
					ARR[j] = ARR[j + 1];
					ARR[j + 1] = p;
				}
				else if (ARR[j]->num.month == ARR[j + 1]->num.month)
				{
					if (ARR[j]->num.date < ARR[j + 1]->num.date)
					{
						p = ARR[j];
						ARR[j] = ARR[j + 1];
						ARR[j + 1] = p;
					}

				}
			}
		}
	}
	return;
}




