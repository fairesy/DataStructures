//141034 �ڽſ�
//Matrix �����Լ� ����

#include <stdio.h>
#include <stdlib.h>

/*
make2DArray : �������迭�� �޸𸮸� �����Ҵ��Ͽ� �����ϴ� �Լ�
�Է� : ��, ��
��� : ������ ������ �迭 ��ü�� ����Ű�� ���� �����͸� ����
*/
int** make2DArray(int row, int col)
{
	int** arr;
	int i;

	//2���� �迭�� ������ ���� �޸� �Ҵ�
	arr = (int**)malloc(sizeof(int*)*row);

	//2���� �迭��ŭ�� �޸� �Ҵ� row*col
	for (i = 0; i < row; i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*col);
	}

	return arr;
}

/*
free2Darray : �����Ҵ�� 2���� �迭�� free
�Է� : �������迭�� ����Ű�� ����������, ��
*/
void free2Darray(int** arr, int row)
{
	int i;
	for (i = 0; i < row; i++){
		free(arr[i]);//�� ���� free
	}

	if (arr){
		free(arr);//2���� �迭 ��ü�� free
		arr = NULL;
	}
}

int** matrixSum(int **result, int **A, int **B, int rowNum, int colNum)
{
	int i, j;

	for (i = 0; i < rowNum; i++){
		for (j = 0; j < colNum; j++){
			result[i][j] = A[i][j] + B[i][j];
		}
	}
	return result;
}
void print2DArray(int **arr, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int** matrixA = make2DArray(5, 5);
	int** matrixB = make2DArray(5, 5);
	int** res = make2DArray(5, 5);
	int i, j;


	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++){
			matrixA[i][j] = 1;
		}
	}

	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++){
			matrixB[i][j] = 2;
		}
	}

	matrixSum(res, matrixA, matrixB, 5, 5);
	printf("�迭1\n");
	print2DArray(matrixA, 5, 5);
	printf("\n\n");
	printf("�迭2\n");
	print2DArray(matrixB, 5, 5);
	printf("\n\n");
	printf("���� �迭\n");
	print2DArray(res, 5, 5);

	free2Darray(matrixA, 5);
	free2Darray(matrixB, 5);
	free2Darray(res, 5);

	return 0;
}