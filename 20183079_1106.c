#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*���θ��� ����ü ����
����ü �迭 10�� ����
5-10��(7��) �Է¹ް�
1.�״�� ���
2,�̸��� ���
3.���̼� ���

sorting �ؾ���....������
�ø����� �������������� �ε�ȣ�� �� �ٲ��ָ� �ȴ�..?


����ü�� �񱳴� ������������� ����, ������ ���� ������ ����ü������ ������*/


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




	printf("�Է��� �ڷ��� ��:");
	scanf_s("%d", &n);
	arr = (struct id**)malloc(sizeof(struct id*)*n);
	for (i = 0; i<n; i++)
	{
		arr[i] = (struct id*)malloc(sizeof(struct id));
	}


	for (i = 0; i < n; i++)
	{
		printf("\n�̸�,�������,����(F/M),�ּ�,��ȭ��ȣ�� �Է��Ͻÿ�\n");
		scanf_s(" %s", &arr[i]->name); //�̸��Է¹ޱ�
		scanf_s(" %d %d %d", &arr[i]->num.year, &arr[i]->num.month, &arr[i]->num.date);//�������
		scanf_s(" %c", &arr[i]->sex);		//����
		scanf_s(" %s", &arr[i]->address); //�ּ�
		scanf_s(" %s", &arr[i]->phone);//��ȭ��ȣ
	}






	/*
	for i=[1,n)
	for(j=k;j>0&&x[j=1]>x[j];j--)
	*/

	printf("<�Է¹��� ��� ���>\n");



	printf("�����̸���������������ϡ����������������������������ּҡ�����������������ȭ��ȣ\n");

	for (int i = 0; i < 10; i++)
	{

		printf(" ��%s����%d�� %d�� %d�ϡ�����%c����%s��%011d\n", arr[i]->name, arr[i]->num.year, arr[i]->num.month, arr[i]->num.date, arr[i]->sex, arr[i]->address, arr[i]->phone);

	}

	/*
	���̾ƿ� ����
	�����̸���������������ϡ����������������������������ּҡ�����������������ȭ��ȣ\n
	  ��%s����%d�� %d�� %d�ϡ�����%c����%s��%011d\n
	   */

	sortbyname(arr, n);
	printf("<�̸� �����ټ����� ���>\n");
	printf("�����̸���������������ϡ����������������������������ּҡ�����������������ȭ��ȣ\n");

	for (int i = 0; i < 10; i++)
	{

		printf(" ��%s����%d�� %d�� %d�ϡ�����%c����%s��%011d\n", arr[i]->name, arr[i]->num.year, arr[i]->num.month, arr[i]->num.date, arr[i]->sex, arr[i]->address, arr[i]->phone);

	}

	sortbybirth(arr, n);
	printf("<�������ϼ����� ���>");
	for (int i = 0; i < 10; i++)
	{

		printf(" ��%s����%d�� %d�� %d�ϡ�����%c����%s��%011d\n", arr[i]->name, arr[i]->num.year, arr[i]->num.month, arr[i]->num.date, arr[i]->sex, arr[i]->address, arr[i]->phone);

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




