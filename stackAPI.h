#ifndef __STACKAPI_H__
#define MAX_STACK_SIZE 50 //스택의 최대 크기를 50으로 지정

typedef struct{
	char stackArr[MAX_STACK_SIZE];//최대 크기만큼의 배열을 선언한다
	int top;
}Stack;


#endif