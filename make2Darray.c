//141034 �ڽſ�
//2���� �迭�� �޸� �����Ҵ�

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

/*
print2DArray : �����Ҵ��Ͽ� ���� ������ �迭�� ����ϴ� �Լ�
�Է� : ���������ͷ� ����Ű�� �������迭, ��, ��
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

//make2DArray�Լ��� ���� Test�� main�Լ� ������ �����Ѵ�.
int main(void)
{
	int ** twoDarr;
	int row, col;
	twoDarr = make2DArray(6, 10);

	//test 1 : 1X1 ���
	/*
	twoDarr = make2DArray(1, 1);//������ �迭 �����Ҵ�
	for (row = 0; row < 1; row++)
	{
		for (col = 0; col < 1; col++)
		{
			twoDarr[row][col] = row * 1 + 1; //�Ҵ�� �迭�� ���� ����ֱ�
		}
	}
	print2DArray(twoDarr, 1, 1);//�迭 ����Ʈ
	free2Darray(twoDarr, 1);
	*/
	/*
	//test 2 : 1X2 ���
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

	//test 3 : 2X1 ���
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

	//test 4 : 5X5 ���
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
	//test 5 : 6X10 ���
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
