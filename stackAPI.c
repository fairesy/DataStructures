// 141034 박신영
// char형 변수를 저장하는 스택에 대한 API구현

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* charStack;//char형 변수를 저장하는 스택을 가리키는 포인터 선언
static int top;
static int capacity;

/*
CreateStack : 스택을 만드는 함수
스택 생성에 성공하면 0을, 실패하면 -1을 리턴한다.
*/
static int CreateStack(int initialCapacity)//initialCapacity : 맨처음에 설정된 용량
{
	charStack = (char *)malloc(sizeof(char)*initialCapacity);
	//처음 용량 (* char사이즈)만큼 메모리를 할당해준다.

	if (!charStack) // 스택을 생성하지 못했을 경우 -1을 리턴한다.
	{
		return -1; 
	}
	else 
		//스택을 생성하는 데에 성공했을 경우, 
		//스택의 capacity는 처음에 설정한 initialCapacity, topIndex는 -1을 가리킨다.
	{
		capacity = initialCapacity;
		top = -1;
	}
	return 0;
}

/*
freeStack : 메모리를 회수하는 함수
*/
static void freeStack(void)
{
	free(charStack);//스택에 할당해주었던 메모리를 해제한다.
}

/*
isEmpty : 스택이 비었는지 확인하는 함수
비었으면 1, 아니면 0을 리턴한다.
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
isFull : 스택이 꽉 찼는지 확인하는 함수
꽉 찼으면 1, 아니면 0을 리턴한다.
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
stackExtension : 스택이 꽉 찼을 경우 더 저장하기 위해 추가로 메모리를 할당해주는 함수
*/
static void	stackExtension(void)
{
	charStack = (char *)realloc(charStack, sizeof(char)* 2 * capacity);
	//원래 할당되어있던 공간에 두배의 공간을 다시 할당한다.
	capacity *= 2;//capacity가 원래 크기의 두배로 갱신된다. 
}

/*
push : item을 스택에 추가하는 함수.
*/
static void push(char item)
{
	if (isFull())
	{
		stackExtension();
	}	//item을 추가하려고 하는데 스택이 꽉 찬 상태이면, stackExtension함수를 호출해 메모리를 확장한다.

	//top이 가리키는 곳을 한칸 위로 옮긴 뒤에 item을 집어넣는다. 
	top++;
	charStack[top] = item; 

}

/*
pop : item을 스택에서 꺼내는 함수. 나중에 넣은 것을 먼저 꺼내야 한다. 
*/
static char pop(void)
{
	if (isEmpty())
	{
		printf("스택이 비었습니다!\n");
		return '\0';
		//스택이 비었을 경우 꺼낼 수 있는 것이 없으므로 스택이 비었다는 메시지 출력 후 함수종료
	}
	else
	{
		return charStack[top--];
		//스택에 뭔가 있으면 topIndex가 가리키고 있는 것을 꺼낸 뒤에 topIndex를 한칸 내린다.
	}
}

int main(void)//문자열을 뒤집어보자!!
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