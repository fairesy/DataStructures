//141034 �ڽſ�
//queue API ����

#include <stdio.h>
#include <stdlib.h>

static int* queue;
static int capacity;
static int front;
static int rear;

/*
createQueue : ���ο� ť�� �����
�Է� : �ʱ� ť�� �뷮
��� : �����ϸ� 0, �����ϸ� -1
*/
static int	createQueue(int	initialCapacity)
{
	queue = (int *)malloc(sizeof(int)*initialCapacity);//�ʱ� �뷮(initialCapacity)��ŭ malloc���� �޸� �Ҵ�

	if (!queue) return -1; //ť�� ����� �� �����ϸ� -1�� �����Ѵ�.

	//ť�� ���������� ��������� 0�� �����Ѵ�
	capacity = initialCapacity; //ť�� �뷮�� �Է¹��� initialCapacity�� �����Ѵ�.
	front = -1; //ť�� front �ʱⰪ�� -1
	rear = -1; //ť�� rear �ʱⰪ�� -1

	return 0;
}

/*
freeQueue : ť�� �Ҵ�� �޸𸮸� �����Ѵ�
�Է� ��� ����
*/
static void freeQueue(void)
{
	free(queue);
}

/*
queueFull : ť�� ����á���� Ȯ���Ѵ�
��� : ����á���� 1, �ƴϸ� 0
*/
static int queueFull(void)
{
	if ((rear + 1) % capacity == front)
		return 1;
	else
		return 0;
}

/*
queueEmpty : ť�� ����ִ��� Ȯ���Ѵ�
��� : ������� 1, �ƴϸ� 0
*/
static int queueEmpty(void)
{
	if (front == rear)
		return 1;
	else 
		return 0;
}

/*
enQueue : ť�� ���ο� item�� ����ִ´�
		  rear�� ����Ű�� �ִ� ���� ��ġ�� item�� ����ִ´�. 
		  ���ο� item�� ����Ǿ� �ִ� ���� rear�� ���ŵȴ�.
�Է� : item
��� : �� item�� �߰��� ť
*/
static void enQueue(int item)
{
	if (rear == capacity - 1) //rear�� ť�� �뷮���� �ϳ� ���� ���, ť�� ����á���� Ȯ���ϴ� �Լ��� ȣ���Ѵ�. [check]
		queueFull();
	
	//ť�� �� ������ ������ rear�� �ϳ� ������Ų �� ������ rear�� ����Ű�� ���� item�� ����ִ´�.
	queue[++rear] = item;
}

/*
deQueue : ť���� item�� ����.
		  front�� ����Ű�� �ִ� ���� �������� front�� ��ĭ �ڷ� �ű��.
�Է� ����
��� : ť���� ���� ��
*/
static int deQueue(void)
{
	//ť�� �������(deQueue�� ���� �ִ���) Ȯ���Ѵ�.
	if (front == rear)
		queueEmpty();

	//ť�� ������� ������ front�� ����Ű�� ���� ����, front�� ���� ��ġ�� �ű��.
	return queue[front++];
}

/*
printQueue : ť�� front���� rear���� ����Ѵ�.
			 ť�� ���µ� ������ش�(����ִ���)
*/
void printQueue(void)
{
	int curPos;

	if (queueEmpty()) //ť�� ������� ���
	{
		printf("ť�� ����ֽ��ϴ�");
		return;
	}
	//ť�� ������� ������ front���� �����ؼ� rear���� �� ����Ѵ�.
	for (curPos = front+1; curPos <= rear; curPos++)
	{
		printf("%d\n",queue[curPos]);
	}
}

/*
copyBlock : [srcBegin, srcEnd)������ ���ҵ��� dst�� ����
�Է�
srcBegin: ���� �迭�� ���� ��ġ
srcEnd: ������ �迭�� ������ ���� ��ġ + 1
dst: ���Ӱ� ������ �迭
*/
void	copyBlock(int *srcBegin, int *srcEnd, int *dst)
{
	while (srcBegin < srcEnd)//���� �迭�� ������ġ�� ������ ���� ��ġ+1���� ���� ����
	{
		*dst = *srcBegin;
		dst++;
		srcBegin++;
	}
}

/*
main : queueAPI�� ����Ȯ��
*/
int main(void)
{
	int i;

	createQueue(10);

	//Enqueue����
	printf("enqueue!\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d��°\n", i + 1);
		enQueue(i);
		printQueue();
	}
	printf("\n\n");
	//Dequeue����
	printf("dequeue!\n");
	deQueue();
	printQueue();
	
	return 0;
}