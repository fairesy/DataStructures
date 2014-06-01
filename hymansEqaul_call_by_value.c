//141034 박신영
//구조체_call by value

#include <stdio.h>
#include <string.h>
#define TRUE 1 
#define FALSE 0 

typedef struct humanBeing {
	char name[10];
	int age;
	float salary;
} humanBeing_t;//구조체 선언


int humansEqual(humanBeing_t person1, humanBeing_t person2)
{
	if (strcmp(person1.name, person2.name))//strcmp : 두 문자열을 비교하는 함수. 같으면 0 리턴
		return FALSE;
	if (person1.age != person2.age)
		return FALSE;
	if (person1.salary != person2.salary)
		return FALSE;

	return TRUE;
}

int main(void)
{
	//test data : 두 사람이 같은 사람인지 비교한다.
	humanBeing_t person1 = { "Sam", 30, 2000 };
	humanBeing_t person2 = { "Tom", 20, 1500 };

	if (humansEqual(person1, person2))
		printf("Two persons are equal\n");
	else
		printf("Two persons are different\n");

	return 0;
}