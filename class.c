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
	node_t * rear; //node_t* ��带 ����Ű�� ������
} queue_t;

/*
�Է� : ť, ���ο� data
��� : void
*/
void enqueue(queue_t *queue, data_t *data)
{
	node_t *newNode;

	newNode = (node_t *)malloc(sizeof(node_t));
	newNode->data = data;
	newNode->next = (node_t *) NULL;

	if (queue->rear) //ť�� rear�� NULL�� �ƴҶ�,
		queue->rear->next = newNode;
	//���� ť�� �ǳ��� ����Ű�� �ִ� ��ũ����(���� NULL����Ŵ)�� ���ο� ��带 ����Ű�� ������ ����
	
	queue->rear = newNode;//ť�� �� ���� ���ο� ��带 �߰�

	if (!queue->front) //queue�� ����־��� ���. 
		queue->front = newNode;
}


data_t * dequeue(queue_t *queue)
{
	node_t * pTmpNode;
	data_t * data;

	if (!queue->front) return (data_t *)NULL;

	data = queue->front->data; // return�� ���� front�� �ִ� element ���� 
	pTmpNode = queue->front; //���߿� free�ϱ� ���� ���� front ����
	queue->front = queue->front->next; //front�� �� ���� ��带 ����Ű���� �ٲ�
	free(pTmpNode);

	if (!queue->front) queue->rear = (node_t *) NULL; 
	//front�� �������, ť�� rear�� NULL�� ���� 
	//	: Enqueue�� �� �ùٸ� ��ġ�� �ʿ�� �ϱ� ������
	//	  ť�� �ʱ� ���¿� �����ϰ� ����� �ִ� ���� ����

	return data; //���� front�� �ִ� data�� ����
}

/*
����Ʈ �������� �����ϱ�
�Է� : ���� ��ũ�� ����Ʈ�� ���
��� : �������ĵ� ��ũ�� ����Ʈ�� ���
*/
node_t * invert_linked_list(node_t *head)
{
	node_t *newHead;
	node_t *tmpNode;

	newHead = (node_t *)NULL; //���ο� ��� ������ NULL
	while (head) { //���� ��尡 NULL�� �ɶ����� �� ����
		tmpNode = head; 
		head = head->next;
		tmpNode->next = newHead;
		newHead = tmpNode;
	}
	return newHead; //���� ����Ʈ�� ��� ��� 
}

/*
����Ʈ �ΰ� �̾� ���̱� (���� : concatenate)
�Է� : �� ����Ʈ�� ���
��� : ù��° ����Ʈ�� ���
*/
node_t * concatenate(node_t *head1, node_t *head2)
{
	node_t *tmpNode;

	if (head1 == head2) return head1;//head1 head2�� ���� ���� �ԷµǸ�(�߸��� �Է�) �׳� ���� �ϳ� ����

	if (!head1 && !head2) return (node_t *) NULL;
	else if (!head1) return head2; //head1�� NULL�̸� head2 ����
	else if (!head2) return head1;
	else {
		tmpNode = head1; 
		//ù��° ����Ʈ�� ���� ��尪�� �״�� �ΰ�, tmpNode�� ����� ���� ��带 ������ �� �װɷ� �� ��ĵ�ϴµ� ���
		
		while (tmpNode->next) //tmpNode�� next�� NULL�� �ƴѵ��� �ݺ�(ù��° ����Ʈ�� �� ��ĵ)
			tmpNode = tmpNode->next;

		tmpNode->next = head2;//tmpNode�� next�� NULL�� �Ǹ� �ű⿡ head2�� ��ġ�� �ִ´�

		return head1; 
	}
}

/* ������Ʈ

�迭
�޸𸮸� ���� �����Ѵ�.(data�� ���� : ��ũ�帮��Ʈ�� link������ ����)
���������� �����ϴ�
�߰������� ��ƴ� -> �ð����⵵�� O(n)

��ũ�帮��Ʈ
�߰������� ����
���� ���� �����Ϸ��� �ϴ� ��� ��ġ�� �־������� �� O(1)
�־������� ������ �� �� ã�ƾ��ϹǷ� worst case O(n)

���� = �迭 + topIndex
������ ������ �ι�� Ȯ��(realloc) -> O(n)�� �ð����⵵�� ����
��ҿ��� O(c)�̴ٰ� Ȯ��Ǵ� �������� O(n)

*/