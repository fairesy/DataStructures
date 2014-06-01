//141034 박신영
//Matrix 덧셈함수 구현

#include <stdio.h>
#include <stdlib.h>

/*
make2DArray : 이차원배열을 메모리를 동적할당하여 구현하는 함수
입력 : 행, 열
출력 : 생성된 이차원 배열 자체를 가리키는 더블 포인터를 리턴
*/
int** make2DArray(int row, int col)
{
	int** arr;
	int i;

	//2차원 배열을 선언할 곳의 메모리 할당
	arr = (int**)malloc(sizeof(int*)*row);

	//2차원 배열만큼의 메모리 할당 row*col
	for (i = 0; i < row; i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*col);
	}

	return arr;
}

/*
free2Darray : 동적할당된 2차원 배열을 free
입력 : 이차원배열을 가리키는 더블포인터, 행
*/
void free2Darray(int** arr, int row)
{
	int i;
	for (i = 0; i < row; i++){
		free(arr[i]);//각 행을 free
	}

	if (arr){
		free(arr);//2차원 배열 자체를 free
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
	printf("배열1\n");
	print2DArray(matrixA, 5, 5);
	printf("\n\n");
	printf("배열2\n");
	print2DArray(matrixB, 5, 5);
	printf("\n\n");
	printf("합한 배열\n");
	print2DArray(res, 5, 5);

	free2Darray(matrixA, 5);
	free2Darray(matrixB, 5);
	free2Darray(res, 5);

	return 0;
}