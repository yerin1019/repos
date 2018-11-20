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

	printf("�Է��� �ڷ��� ������ 7�� �̻� 10�� ���Ϸ� �Է��Ͻÿ�:");
	scanf_s("%d", &n);

	}while (n < 7 || n > 10);


	Student *id[10];
	for (int i = 0; i < sizeof(id) / sizeof(Student *); i++)    // ��� ������ŭ �ݺ�
	{
		id[i] = malloc(sizeof(Student));    // �� ��ҿ� ����ü ũ�⸸ŭ �޸� �Ҵ�
	}



	printf("\n�Է�: �̸�, �������, ����(��/��), ��ȭ��ȣ\n");
	printf("����:�ӿ���, 19971019, F, 1027581793\n");


	for (int i = 0; i < n; i++)//�ڷᰳ����ŭ �Է¹ޱ�
	{
		printf("\n %d��:", i + 1);
		scanf_s("%s, %s, %c, %d", &id[i]->name, &id[i]->birth, &id[i]->gender, &id[i]->phone);

	}

	printf("\n<�Է¹��� ��� ���>\n");//�Է¹������ ���

	for (int i = 0; i < n; i++)
	{
		printf("%d��:");
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
	printf("\n<�̸� ������������ ���>\n");//�Է¹������ ���

	for (int i = 0; i < n; i++)
	{
		printf("%d��:");
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
	printf("\n<������� ������������ ���>\n");//�Է¹������ ���

	for (int i = 0; i < n; i++)
	{
		printf("%d��:");
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



	for (int i = 0; i < 10; i++)    // ��� ������ŭ �ݺ�
	{
		free(id[i]);    // �� ����� ���� �޸� ����
	}
	
}

void SortbyName(Student *id, int n)//��������
{
	Student temp;
	int i = 0, j = 0;
	for (i = n; i > 1; i--)
	{
		for (j = 1; j < i; j++)
		{
			if (id[j - 1].name<id[j].name)////���� ����� �̸��� �ƽ�Ű �ڵ尪�� Ŭ ��
			{
				//�� ���� ������ ��ȯ
				temp = id[j - 1];
				id[j - 1] = id[j];
				id[j] = temp;
			}
		}
	}
}

void SortbyBirth(Student *id, int n)//��������
{
	Student temp;

	int i = 0, j = 0;
	for (i = n; i > 1; i--)
	{
		for (j = 1; j < i; j++)
		{
			if (strcmp(id[j-1].birth, id[j].birth)>0)//���ʻ��ϼ��ڰ� ������
			{
				//�� ���� ������ ��ȯ
				temp = id[j - 1];
				id[j - 1] = id[j];
				id[j] = temp;
			}
		}
	}
}
