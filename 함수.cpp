#include <iostream>

//함수(function)
void PrintDottedLine()  //반환타입 함수이름(매개변수)
{
	std::cout << "---------" << std::endl; //본체
}

void PrintNumber(int x)//호출당하는 쪽(callee)
{
	std::cout << x << std::endl;
}

int Square(int x)
{
	return x * x; //결과값을 반환해준다.
}

//함수의 선언(declaration)과 정의(definition)
//전방선언(forward delcaration)
int Num(int);

//순환호출(cyclic calling)
void g();

void f()
{
	g();
}

void g()
{
	f();
}
//전방선언을 통해 해결가능

//전연 변수(Global Variable)
int myGlobalInteger = 5; //해당소스파일 어디에서도 사용할수 있음

//정적 변수(Static Variable)
int GetOrderNumber()
{
	static int number{ 0 }; //프로그램이 실행되고 종료될때까지 살아남는 변수
	return number++; 
	
	if (number == 10)
	{
		return number;
	}
}

//매개변수 일치
void WhoAmI(int value)
{
	std::cout << "나는 정수를 처리합니다." << value << std::endl;
}
void WhoAmI(float value)
{
	std::cout << "나는 소수를 처리합니다." << value << std::endl;
}
void WhoAmI(float value, float value2)
{
	std::cout << "나는 소수 2개를 처리합니다." << value << value2 << std::endl;
}
//3개의 동일한 타입 및 함수의 이름과 매개변수의 타입 이름 갯수 등이 다른것을 함수의 오버로딩이라 하며, 
//동일한 이름의 함수로 인해 처리하기 어려운 것을 모호성(Ambiguous)라고 한다.

//함수 시그니쳐(function signature)
//함수의 이름, 매개변수의 타입, 개수, 순서 함수의 특성을 나타내는 시그니쳐(signature)라 함
int Print(int i);
void Print(int i);
//이름 매개변수는 같지만 반환값이 다르며 이 경우는 컴파일 에러가 발생함

//함수의 작동원리


int main()
{
	PrintNumber(3); //함수를 호출하기 위해 호출하는 쪽(caller) 인자에 값을 주면 호출당하는쪽(callee)에 매개변수에 값이 복사되서 출력된다. 이러한 것을 Call by Value(값에 의한 호출)
	Square(4);

	std::cout << Num(2) << std::endl;

	int myInteger{};

	myInteger = myGlobalInteger;
	
	std::cout << myInteger << std::endl;

	
	GetOrderNumber();
	GetOrderNumber();
}

int Num(int x)
{
	return x * x;
}