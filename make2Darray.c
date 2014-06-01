//141034 박신영
//2차원 배열의 메모리 동적할당

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

/*
print2DArray : 동적할당하여 만든 이차원 배열을 출력하는 함수
입력 : 더블포인터로 가리키는 이차원배열, 행, 열
*/
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

//make2DArray함수에 대한 Test를 main함수 내에서 시행한다.
int main(void)
{
	int ** twoDarr;
	int row, col;
	twoDarr = make2DArray(6, 10);

	//test 1 : 1X1 행렬
	/*
	twoDarr = make2DArray(1, 1);//이차원 배열 동적할당
	for (row = 0; row < 1; row++)
	{
		for (col = 0; col < 1; col++)
		{
			twoDarr[row][col] = row * 1 + 1; //할당된 배열에 원소 집어넣기
		}
	}
	print2DArray(twoDarr, 1, 1);//배열 프린트
	free2Darray(twoDarr, 1);
	*/
	/*
	//test 2 : 1X2 행렬
	twoDarr = make2DArray(1, 2);
	for (row = 0; row < 1; row++)
	{
		for (col = 0; col < 2; col++)
		{
			twoDarr[row][col] = row * 1 + 2;
		}
	}
	print2DArray(twoDarr, 1, 2);
	free(twoDarr, 1);

	//test 3 : 2X1 행렬
	twoDarr = make2DArray(2, 1);
	for (row = 0; row < 2; row++)
	{
		for (col = 0; col < 1; col++)
		{
			twoDarr[row][col] = row * 2 + 1;
		}
	}
	print2DArray(twoDarr, 2, 1);
	free(twoDarr, 2);

	//test 4 : 5X5 행렬
	twoDarr = make2DArray(5, 5);
	for (row = 0; row < 5; row++)
	{
		for (col = 0; col < 5; col++)
		{
			twoDarr[row][col] = row * 5 + 5;
		}
	}
	print2DArray(twoDarr, 5, 5);
	free(twoDarr, 5);
	*/
	//test 5 : 6X10 행렬
	for (row = 0; row < 6; row++)
	{
		for (col = 0; col < 10; col++)
		{
			twoDarr[row][col] = row * 6 + 10;
		}
	}
	print2DArray(twoDarr, 6, 10);
	free2Darray(twoDarr, 6);	
	return 0;
}
