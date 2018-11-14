#define _CRT_SECURE_NO_WARNINGS_
#include<stdio.h>

void indexAddMat(int mat[][3],int result[][3]);
void ptrProdMat(int mat[][3],int result[][3]);

int main()
{
	int i, j;
	int arr[3][3] = { 0 };
	int Add[3][3] = { 0 }, Prod[3][3] = { 0 };

	/*int col = sizeof(arr[0]) / sizeof(int);  //매개변수로 넣어줄 행과 열 사이즈 구하기
	int row = sizeof(arr) / sizeof(arr[0]);*/

	printf("3X3 행렬의 값을 입력하세요:\n");
	
	for (i = 0; i < 3; i++)//행렬값 입력받기
	{

		for (j = 0; j < 3; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}

	}

	printf("\n<입력한 행렬>\n");
	for (i = 0; i < 3; i++)//기본행렬 출력
	{

		for (j = 0; j < 3; j++)
		{
			printf("%3d　", arr[i][j]);
		}

		printf("\n");
	}

	indexAddMat(arr, Add);
	ptrProdMat(arr, Prod);

	
	printf("\n<덧셈 결과>\n");
	for (i = 0; i < 3; i++) //덧셈결과 행렬 출력
	{

		for (j = 0; j < 3; j++)
		{
			printf("%3d　", Add[i][j]);
		}

		printf("\n");
	}

	printf("\n<곱셈 결과>\n");
	for (i = 0; i < 3; i++)//곱셈결과 행렬 출력
	{

		for (j = 0; j < 3; j++)
		{
			printf("%3d　", Prod[i][j]);
		}

		printf("\n");
	}


}

void indexAddMat(int mat[][3],int result[][3])//덧셈행렬 by 배열
{
	
	
	for (int i =0 ; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			result[i][j] = 2 * (mat[i][j]);
		}

		
	}
	
	
}

void ptrProdMat(int (*mat)[3],int (*result)[3])//곱셈행렬 by 포인터
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