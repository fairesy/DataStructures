#include <stdio.h>
#include <stdlib.h>

typedef struct data {
	int key;
	/* other fields */
} data_t;

typedef struct node {
	data_t * data;
	struct node * next;
} node_t;

typedef struct queue {
	node_t * front;
	node_t * rear; //node_t* 노드를 가리키는 포인터
} queue_t;

/*
입력 : 큐, 새로운 data
출력 : void
*/
void enqueue(queue_t *queue, data_t *data)
{
	node_t *newNode;

	newNode = (node_t *)malloc(sizeof(node_t));
	newNode->data = data;
	newNode->next = (node_t *) NULL;

	if (queue->rear) //큐의 rear가 NULL이 아닐때,
		queue->rear->next = newNode;
	//원래 큐의 맨끝이 가리키고 있는 링크정보(원래 NULL가리킴)를 새로운 노드를 가리키는 것으로 수정
	
	queue->rear = newNode;//큐의 맨 끝에 새로운 노드를 추가

	if (!queue->front) //queue가 비어있었을 경우. 
		queue->front = newNode;
}


data_t * dequeue(queue_t *queue)
{
	node_t * pTmpNode;
	data_t * data;

	if (!queue->front) return (data_t *)NULL;

	data = queue->front->data; // return할 원래 front에 있던 element 저장 
	pTmpNode = queue->front; //나중에 free하기 위해 원래 front 저장
	queue->front = queue->front->next; //front가 그 다음 노드를 가리키도록 바꿈
	free(pTmpNode);

	if (!queue->front) queue->rear = (node_t *) NULL; 
	//front가 비었으면, 큐의 rear도 NULL로 변경 
	//	: Enqueue할 때 올바른 위치를 필요로 하기 때문에
	//	  큐의 초기 상태와 동일하게 만들어 주는 것이 좋다

	return data; //원래 front에 있던 data값 리턴
}

/*
리스트 역순으로 정렬하기
입력 : 기존 링크드 리스트의 헤드
출력 : 역순정렬된 링크드 리스트의 헤드
*/
node_t * invert_linked_list(node_t *head)
{
	node_t *newHead;
	node_t *tmpNode;

	newHead = (node_t *)NULL; //새로운 헤드 시작은 NULL
	while (head) { //원래 헤드가 NULL이 될때까지 쭉 실행
		tmpNode = head; 
		head = head->next;
		tmpNode->next = newHead;
		newHead = tmpNode;
	}
	return newHead; //역순 리스트의 헤드 출력 
}

/*
리스트 두개 이어 붙이기 (연결 : concatenate)
입력 : 두 리스트의 헤드
출력 : 첫번째 리스트의 헤드
*/
node_t * concatenate(node_t *head1, node_t *head2)
{
	node_t *tmpNode;

	if (head1 == head2) return head1;//head1 head2가 같은 값이 입력되면(잘못된 입력) 그냥 둘중 하나 리턴

	if (!head1 && !head2) return (node_t *) NULL;
	else if (!head1) return head2; //head1이 NULL이면 head2 리턴
	else if (!head2) return head1;
	else {
		tmpNode = head1; 
		//첫번째 리스트의 원래 헤드값은 그대로 두고, tmpNode를 만들어 원래 헤드를 저장한 뒤 그걸로 쭉 스캔하는데 사용
		
		while (tmpNode->next) //tmpNode의 next가 NULL이 아닌동안 반복(첫번째 리스트를 쭉 스캔)
			tmpNode = tmpNode->next;

		tmpNode->next = head2;//tmpNode의 next가 NULL이 되면 거기에 head2의 위치를 넣는다

		return head1; 
	}
}

/* 수업노트

배열
메모리를 적게 차지한다.(data만 저장 : 링크드리스트는 link정보도 저장)
임의접근이 가능하다
추가삭제가 어렵다 -> 시간복잡도가 O(n)

링크드리스트
추가삭제가 쉽다
앞의 노드와 삭제하려고 하는 노드 위치가 주어져있을 때 O(1)
주어져있지 않으면 싹 다 찾아야하므로 worst case O(n)

스택 = 배열 + topIndex
스택이 꽉차면 두배로 확장(realloc) -> O(n)의 시간복잡도로 복사
평소에는 O(c)이다가 확장되는 순간에만 O(n)

*/