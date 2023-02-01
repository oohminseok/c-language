#include <iostream>

int main()
{
	std::cout << "숫자를 입력하고 엔터를 누르세요!" << std::endl;

	int number;

	std::cin >> number;
	std::cout << "입력하신 숫자는";
	std::cout << number;
	std::cout << "입니다!";
	std::cout << std::endl;

	int myInteger; //선언(Declaration)
	myInteger = 1; //대입(Assignment)

	int x;
	x = 10;

	std::cout << x << ":" << &x << std::endl; //x의 값 : x의 값이 저장된 메모리 주소

	//오버플로(OverFlow)
	int overFlow = 2147483647;

	overFlow = overFlow + 1;

	std::cout << overFlow;

	//언더플로(UnderFlow)
	unsigned int underFlow = 0;

	underFlow = underFlow - 1;

	std::cout << underFlow;

	


}