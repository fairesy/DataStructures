//141034 박신영
//queue API 구현

#include <stdio.h>
#include <stdlib.h>

static int* queue;
static int capacity;
static int front;
static int rear;

/*
createQueue : 새로운 큐를 만든다
입력 : 초기 큐의 용량
출력 : 성공하면 0, 실패하면 -1
*/
static int	createQueue(int	initialCapacity)
{
	queue = (int *)malloc(sizeof(int)*initialCapacity);//초기 용량(initialCapacity)만큼 malloc으로 메모리 할당

	if (!queue) return -1; //큐를 만드는 데 실패하면 -1을 리턴한다.

	//큐가 성공적으로 만들어지면 0을 리턴한다
	capacity = initialCapacity; //큐의 용량은 입력받은 initialCapacity를 대입한다.
	front = -1; //큐의 front 초기값은 -1
	rear = -1; //큐의 rear 초기값도 -1

	return 0;
}

/*
freeQueue : 큐에 할당된 메모리를 해제한다
입력 출력 없음
*/
static void freeQueue(void)
{
	free(queue);
}

/*
queueFull : 큐가 가득찼는지 확인한다
출력 : 가득찼으면 1, 아니면 0
*/
static int queueFull(void)
{
	if ((rear + 1) % capacity == front)
		return 1;
	else
		return 0;
}

/*
queueEmpty : 큐가 비어있는지 확인한다
출력 : 비었으면 1, 아니면 0
*/
static int queueEmpty(void)
{
	if (front == rear)
		return 1;
	else 
		return 0;
}

/*
enQueue : 큐에 새로운 item을 집어넣는다
		  rear가 가리키고 있는 다음 위치에 item을 집어넣는다. 
		  새로운 item이 저장되어 있는 곳이 rear로 갱신된다.
입력 : item
출력 : 새 item이 추가된 큐
*/
static void enQueue(int item)
{
	if (rear == capacity - 1) //rear가 큐의 용량보다 하나 적을 경우, 큐가 가득찼음을 확인하는 함수를 호출한다. [check]
		queueFull();
	
	//큐가 꽉 차있지 않으면 rear를 하나 증가시킨 뒤 증가된 rear가 가리키는 곳에 item을 집어넣는다.
	queue[++rear] = item;
}

/*
deQueue : 큐에서 item을 뺀다.
		  front가 가리키고 있는 것을 빼낸다음 front를 한칸 뒤로 옮긴다.
입력 없음
출력 : 큐에서 빼낸 값
*/
static int deQueue(void)
{
	//큐가 비었는지(deQueue할 값이 있는지) 확인한다.
	if (front == rear)
		queueEmpty();

	//큐가 비어있지 않으면 front가 가리키는 값을 빼고, front를 다음 위치로 옮긴다.
	return queue[front++];
}

/*
printQueue : 큐를 front부터 rear까지 출력한다.
			 큐의 상태도 출력해준다(비어있는지)
*/
void printQueue(void)
{
	int curPos;

	if (queueEmpty()) //큐가 비어있을 경우
	{
		printf("큐가 비어있습니다");
		return;
	}
	//큐가 비어있지 않으면 front부터 시작해서 rear까지 쭉 출력한다.
	for (curPos = front+1; curPos <= rear; curPos++)
	{
		printf("%d\n",queue[curPos]);
	}
}

/*
copyBlock : [srcBegin, srcEnd)까지의 원소들을 dst에 복사
입력
srcBegin: 원래 배열의 시작 위치
srcEnd: 복사할 배열의 마지막 원소 위치 + 1
dst: 새롭게 저장할 배열
*/
void	copyBlock(int *srcBegin, int *srcEnd, int *dst)
{
	while (srcBegin < srcEnd)//원래 배열의 시작위치가 마지막 원소 위치+1보다 작은 동안
	{
		*dst = *srcBegin;
		dst++;
		srcBegin++;
	}
}

/*
main : queueAPI의 동작확인
*/
int main(void)
{
	int i;

	createQueue(10);

	//Enqueue과정
	printf("enqueue!\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d번째\n", i + 1);
		enQueue(i);
		printQueue();
	}
	printf("\n\n");
	//Dequeue과정
	printf("dequeue!\n");
	deQueue();
	printQueue();
	
	return 0;
}