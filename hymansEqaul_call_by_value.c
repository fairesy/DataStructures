//141034 �ڽſ�
//����ü_call by value

#include <stdio.h>
#include <string.h>
#define TRUE 1 
#define FALSE 0 

typedef struct humanBeing {
	char name[10];
	int age;
	float salary;
} humanBeing_t;//����ü ����


int humansEqual(humanBeing_t person1, humanBeing_t person2)
{
	if (strcmp(person1.name, person2.name))//strcmp : �� ���ڿ��� ���ϴ� �Լ�. ������ 0 ����
		return FALSE;
	if (person1.age != person2.age)
		return FALSE;
	if (person1.salary != person2.salary)
		return FALSE;

	return TRUE;
}

int main(void)
{
	//test data : �� ����� ���� ������� ���Ѵ�.
	humanBeing_t person1 = { "Sam", 30, 2000 };
	humanBeing_t person2 = { "Tom", 20, 1500 };

	if (humansEqual(person1, person2))
		printf("Two persons are equal\n");
	else
		printf("Two persons are different\n");

	return 0;
}