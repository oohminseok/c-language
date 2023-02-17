#include <iostream>

int main()
{
	//동적메모리
	//c스타일
	int* buffer1, * buffer2;

	buffer1 = (int*)calloc(100, sizeof(int)); //할당할 원소의 개수, 각 원소의 크기
	buffer2 = (int*)malloc(100 * sizeof(int)); // 할당할 메모리의 크기

	if (buffer1 && buffer2)
	{
		std::cout << buffer1[2] << "," << *buffer2 << std::endl;
		free(buffer1); // 동적으로 할당된 메모리를 해제
		free(buffer2); 
	}

	//C++스타일
	int* pNew{}; 
	pNew = new int; //동적으로 할당
	*pNew = 4; // 역참조해서 값을 4로 넣어줌
	delete pNew; // 동적으로 할당된 메모리를 해제

	struct Student
	{
		int number;
		char name[16];
	};

	Student* allocated = new Student; //동적으로 할당
	allocated->number = 1; // 역참조해서 값을 1로 넣어줌
	delete allocated; // 동적으로 할당된 메모리를 해제

	Student* array = new Student[5];
	array[0].number = 1;
	array[1].number = 2;

	delete[] array;

	//주의사항
	//1.메모리 누수(Memory Leak)
	//동적으로 할당하고 해제하지 않으면 메모리 누수 발생 

	//동적 2차배열

}
