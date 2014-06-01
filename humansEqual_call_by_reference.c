//141034 박신영
//구조체_call_by_reference

#include <stdio.h>
#include <string.h>
#define TRUE 1 
#define FALSE 0 

typedef struct humanBeing {
	char name[10];
	int age;
	float salary;
} humanBeing_t;//구조체 선언

int humansEqualReference(humanBeing_t * person1, humanBeing_t * person2)//포인터로 접근:call by reference
{
	if (strcmp(person1->name, person2->name))
		return FALSE;
	if (person1->age != person2->age)
		return FALSE;
	if (person1->salary != person2->salary)
		return FALSE;

	return TRUE;
}

int main(void)
{
	humanBeing_t person1 = { "Sam", 30, 2000 };
	humanBeing_t person2 = { "Tom", 20, 1500 };

	if (humansEqualReference(&person1, &person2))
		printf("Two persons are equal\n");
	else
		printf("Two persons are different\n");
}