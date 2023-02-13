#include <iostream>

int main()
{
	//포인터(Pointer)
	//포인터(Pointer)는 컴퓨터 메모리의 어딘가를 가르키고 있다는 의미
	//주소연산자 &, 포인터연산자*

	int x{ 0 };
	int* p; //p는 포인터이며 int타입을 가르킨다.
	p = &x; //x의 주소를 가르킨다.
	std::cout << &x; //x의 주소가 나온다.
	std::cout << p; //똑같이 x의 주소가 나온다.
	std::cout << &p; //p의 주소가 나온다.

	int a{ 1 }, b{ 2 };
	p = &a;
	p = &b;
	std::cout << *p << std::endl; //b의 주소를 가르키고 있으므로 b의 값에 접근할수 있다.
	*p = 3; //b의 값에 접근해서 3이란 값으로 바꾼다.

	//포인터 연산

	std::cout << p << std::endl; //가령 b의 주소가 2000일시 2000의 주소가 출력된다.
	std::cout << p + 1 << std::endl; //타입이 int타입이며 4바이트 증가한 2004의 주소가 출력된다. p=p+sizeof(int)*1가 동일
	std::cout << p + 2 << std::endl;//타입이 int타입이며 8바이트 증가한 2008주소가 출력된다.  p=p+sizeof(int)*2가 동일

	//타입이 없는 포인터(Void Pointer)
	//Void Pointer의 경우 타입이 없으므로 아무 타입이나 가르킬수 있지만 값에 접근은 불가능하다.

	int n{ 10 };
	char c{ 'a' };
	void* pointer;
	pointer = &n; //n의 주소를 가르킴
	pointer = &c; //c의 주소를 가르킴
	std::cout << *n; // n의 값에 접근 불가
	pointer = pointer + 1; //타입이 없으므로 연산이 불가하다.
	std::cout << *(char*)p; //명시적으로 형변환을 시켜 P가 C의 값에 접근할수 있게 해줌
	

		int m{ 1025 };
		int* pa = &m; //a의 주소를 가르킨다. 
		char* p0 = (char*)pa; //명시적 형변환으로 p0가 pa의 주소를 가르킬수 있게 해줌

		for (int i = 0; i < 4; ++i)
		{
			std::cout << (void*)p0 << ":" << (int)*p0 << std::endl; //  m의 주소 출력 및 m의 값은 int->char으로 형변환 되서 1025의 값이 1출력후 그다음 주소로 넘어가므로 4가 출력된다. 
			p0++; //p0는 char타입 1바이트므로 주소가 1씩증가
		}
		 // 메모리 주소      : 값 : BIN(8bit) : HEX(1bye)
		 // 000000B2A911FAF4 : 1  : 0000 0001 : 01
		 //	000000B2A911FAF5 : 4  : 0000 0100 : 04
		 //	000000B2A911FAF6 : 0  : 0000 0000 : 00
		 //	000000B2A911FAF7 : 0  : 0000 0000 : 00
		 
		 //1025 = 00000000 00000000 00000100 00000001(2진수)
		     // =    00       00       04       01
		 //Endian 이라는 특성으로 값이 메모리에 거꾸로 저장됨

		//포인터의 포인터
		int q{ 10 };
		int* w = &q;
		int** r = &w; //q를 가르키는 w의 주소를 가르킨다.

		std::cout << q << std::endl; //q의 값이 출력
		std::cout << *w << std::endl; //w가 가르키는 q의 주소 출력
		std::cout << *(*r) << std::endl; //r이 가르키는 w의 주소 메모리에 저장된 q의 주소안에 값이 출력

		//구조체와 포인터

		struct Status
		{
			int HP;
			int MP;
		};
		Status myStatus{ 100,10 };
		Status* pStatus = &myStatus;
		std::cout << pStatus->HP << std::endl; //구조체의 포인터가 가르키는 값에 접근할 ->표시

		//const와 포인터
		const int myPrecious = 10;
		int* ptr = &myPrecious; //const int 타입을 가르켜야 하나 int타입의 포인터 이므로 컴파일 오류가 난다.

		const int x{ 10 }, y{ 20 };
		const int* tr;
		tr = &x;
		tr = &y;
		*tr = 1; //상수이므로 값 변경 불가하다.

		int n{ 10 }, m{ 20 };
		int* const tr2{ &n };
		tr = &y;//상수 포인터이므로 가르키는 대상을 수정할수 없다.
		*tr2 = 20; //int가 상수가 아니므로 값을 수정할수 있다.

		const int* const tr3 = &x; //tr3 상수 포인터이며 const int타입을 가르킨다.
		tr3 = &y; // 상수 포인터이므로 다른 주소를 가르킬수 없다.
		*tr3 = 25; // tr3이 상수를 가르키므로 값을 수정할수 없다.
}
