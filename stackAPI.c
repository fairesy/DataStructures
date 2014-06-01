// 141034 �ڽſ�
// char�� ������ �����ϴ� ���ÿ� ���� API����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* charStack;//char�� ������ �����ϴ� ������ ����Ű�� ������ ����
static int top;
static int capacity;

/*
CreateStack : ������ ����� �Լ�
���� ������ �����ϸ� 0��, �����ϸ� -1�� �����Ѵ�.
*/
static int CreateStack(int initialCapacity)//initialCapacity : ��ó���� ������ �뷮
{
	charStack = (char *)malloc(sizeof(char)*initialCapacity);
	//ó�� �뷮 (* char������)��ŭ �޸𸮸� �Ҵ����ش�.

	if (!charStack) // ������ �������� ������ ��� -1�� �����Ѵ�.
	{
		return -1; 
	}
	else 
		//������ �����ϴ� ���� �������� ���, 
		//������ capacity�� ó���� ������ initialCapacity, topIndex�� -1�� ����Ų��.
	{
		capacity = initialCapacity;
		top = -1;
	}
	return 0;
}

/*
freeStack : �޸𸮸� ȸ���ϴ� �Լ�
*/
static void freeStack(void)
{
	free(charStack);//���ÿ� �Ҵ����־��� �޸𸮸� �����Ѵ�.
}

/*
isEmpty : ������ ������� Ȯ���ϴ� �Լ�
������� 1, �ƴϸ� 0�� �����Ѵ�.
*/
static int isEmpty(void)
{
	if (top < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
isFull : ������ �� á���� Ȯ���ϴ� �Լ�
�� á���� 1, �ƴϸ� 0�� �����Ѵ�.
*/
static int isFull(void)
{
	if (top >= capacity - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
stackExtension : ������ �� á�� ��� �� �����ϱ� ���� �߰��� �޸𸮸� �Ҵ����ִ� �Լ�
*/
static void	stackExtension(void)
{
	charStack = (char *)realloc(charStack, sizeof(char)* 2 * capacity);
	//���� �Ҵ�Ǿ��ִ� ������ �ι��� ������ �ٽ� �Ҵ��Ѵ�.
	capacity *= 2;//capacity�� ���� ũ���� �ι�� ���ŵȴ�. 
}

/*
push : item�� ���ÿ� �߰��ϴ� �Լ�.
*/
static void push(char item)
{
	if (isFull())
	{
		stackExtension();
	}	//item�� �߰��Ϸ��� �ϴµ� ������ �� �� �����̸�, stackExtension�Լ��� ȣ���� �޸𸮸� Ȯ���Ѵ�.

	//top�� ����Ű�� ���� ��ĭ ���� �ű� �ڿ� item�� ����ִ´�. 
	top++;
	charStack[top] = item; 

}

/*
pop : item�� ���ÿ��� ������ �Լ�. ���߿� ���� ���� ���� ������ �Ѵ�. 
*/
static char pop(void)
{
	if (isEmpty())
	{
		printf("������ ������ϴ�!\n");
		return '\0';
		//������ ����� ��� ���� �� �ִ� ���� �����Ƿ� ������ ����ٴ� �޽��� ��� �� �Լ�����
	}
	else
	{
		return charStack[top--];
		//���ÿ� ���� ������ topIndex�� ����Ű�� �ִ� ���� ���� �ڿ� topIndex�� ��ĭ ������.
	}
}

int main(void)//���ڿ��� �������!!
{
	char str[] = "ABCD";
	int i;

	if (CreateStack(1) != 0) return;

	for (i = 0; i < strlen(str); i++)
	{
		push(str[i]);
	}
	
	while (!isEmpty())
	{
		printf("%c", pop());
	}
	freeStack();

	return 0;
}