#define _CRT_SECURE_NO_WARNINGS_
#include<stdio.h>

void indexAddMat(int mat[][3],int result[][3]);
void ptrProdMat(int mat[][3],int result[][3]);

int main()
{
	int i, j;
	int arr[3][3] = { 0 };
	int Add[3][3] = { 0 }, Prod[3][3] = { 0 };

	/*int col = sizeof(arr[0]) / sizeof(int);  //�Ű������� �־��� ��� �� ������ ���ϱ�
	int row = sizeof(arr) / sizeof(arr[0]);*/

	printf("3X3 ����� ���� �Է��ϼ���:\n");
	
	for (i = 0; i < 3; i++)//��İ� �Է¹ޱ�
	{

		for (j = 0; j < 3; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}

	}

	printf("\n<�Է��� ���>\n");
	for (i = 0; i < 3; i++)//�⺻��� ���
	{

		for (j = 0; j < 3; j++)
		{
			printf("%3d��", arr[i][j]);
		}

		printf("\n");
	}

	indexAddMat(arr, Add);
	ptrProdMat(arr, Prod);

	
	printf("\n<���� ���>\n");
	for (i = 0; i < 3; i++) //������� ��� ���
	{

		for (j = 0; j < 3; j++)
		{
			printf("%3d��", Add[i][j]);
		}

		printf("\n");
	}

	printf("\n<���� ���>\n");
	for (i = 0; i < 3; i++)//������� ��� ���
	{

		for (j = 0; j < 3; j++)
		{
			printf("%3d��", Prod[i][j]);
		}

		printf("\n");
	}


}

void indexAddMat(int mat[][3],int result[][3])//������� by �迭
{
	
	
	for (int i =0 ; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			result[i][j] = 2 * (mat[i][j]);
		}

		
	}
	
	
}

void ptrProdMat(int (*mat)[3],int (*result)[3])//������� by ������
{

	int i, j, k;
	
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				result[i][j] += *(*(mat+i)+k) * *(*(mat+k)+j);
			}

		}
	}

	
}