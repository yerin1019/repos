#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Student Student;
struct Student
{

	char name[20];
	char birth[8];
	char gender;
	int phone;



};

void SortbyName(Student *id, int n);
void SortbyBirth(Student *id, int n);


void main()

{

	int n;

	
	do {

	printf("입력할 자료의 갯수를 7개 이상 10개 이하로 입력하시오:");
	scanf_s("%d", &n);

	}while (n < 7 || n > 10);


	Student *id[10];
	for (int i = 0; i < sizeof(id) / sizeof(Student *); i++)    // 요소 개수만큼 반복
	{
		id[i] = malloc(sizeof(Student));    // 각 요소에 구조체 크기만큼 메모리 할당
	}



	printf("\n입력: 이름, 생년월일, 성별(남/여), 전화번호\n");
	printf("예시:임예린, 19971019, F, 1027581793\n");


	for (int i = 0; i < n; i++)//자료개수만큼 입력받기
	{
		printf("\n %d번:", i + 1);
		scanf_s("%s, %s, %c, %d", &id[i]->name, &id[i]->birth, &id[i]->gender, &id[i]->phone);

	}

	printf("\n<입력받은 대로 출력>\n");//입력받은대로 출력

	for (int i = 0; i < n; i++)
	{
		printf("%d번:");
		printf("%c", id[i]->name);
		int j;
		for (j = 0; j < 4; j++)
			printf("%c", id[i]->birth[j]);
		printf("/");
		for (j = 4; j < 6; j++)
			printf("%c", id[i]->birth[j]);
		printf("/");
		for (j = 6; j < 8; j++)
			printf("%c", id[i]->birth[j]);
		printf("%c", id[i]->gender);
		printf("0%d", id[i]->phone);

	}

	SortbyName(id, n);
	printf("\n<이름 내림차순으로 출력>\n");//입력받은대로 출력

	for (int i = 0; i < n; i++)
	{
		printf("%d번:");
		printf("%s", id[i]->name);
		int j;
		for (j = 0; j < 4; j++)
			printf("%d", id[i]->birth[j]);
		printf("/");
		for (j = 4; j < 6; j++)
			printf("%d", id[i]->birth[j]);
		printf("/");
		for (j = 6; j < 8; j++)
			printf("%d", id[i]->birth[j]);
		printf("%c", id[i]->gender);
		printf("0%d", id[i]->phone);

	}

	SortbyBirth(id, n);
	printf("\n<생년월일 오름차순으로 출력>\n");//입력받은대로 출력

	for (int i = 0; i < n; i++)
	{
		printf("%d번:");
		printf("%s", id[i]->name);
		int j;
		for (j = 0; j < 4; j++)
			printf("%d", id[i]->birth[j]);
		printf("/");
		for (j = 4; j < 6; j++)
			printf("%d", id[i]->birth[j]);
		printf("/");
		for (j = 6; j < 8; j++)
			printf("%d", id[i]->birth[j]);
		printf("%c", id[i]->gender);
		printf("0%d", id[i]->phone);

	}



	for (int i = 0; i < 10; i++)    // 요소 개수만큼 반복
	{
		free(id[i]);    // 각 요소의 동적 메모리 해제
	}
	
}

void SortbyName(Student *id, int n)//내림차순
{
	Student temp;
	int i = 0, j = 0;
	for (i = n; i > 1; i--)
	{
		for (j = 1; j < i; j++)
		{
			if (id[j - 1].name<id[j].name)////뒤쪽 사람의 이름이 아스키 코드값이 클 때
			{
				//두 명의 데이터 교환
				temp = id[j - 1];
				id[j - 1] = id[j];
				id[j] = temp;
			}
		}
	}
}

void SortbyBirth(Student *id, int n)//오름차순
{
	Student temp;

	int i = 0, j = 0;
	for (i = n; i > 1; i--)
	{
		for (j = 1; j < i; j++)
		{
			if (strcmp(id[j-1].birth, id[j].birth)>0)//뒷쪽생일숫자가 작을때
			{
				//두 명의 데이터 교환
				temp = id[j - 1];
				id[j - 1] = id[j];
				id[j] = temp;
			}
		}
	}
}
