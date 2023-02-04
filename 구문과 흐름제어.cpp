#include <iostream>

int main()
{
    //표현식(expression)
	int length{ 20 }; 
	int width{ 40 };  
	int area = length * width; //<표현식>* 연산자의 계산식 피연산자 length,width의 값을 곱한다.

	int inputNumber;
	std::cout << "숫자를 입력하세요:";
	std::cin >> inputNumber;

	int biggerNumber;
	std::cout << "더 큰 숫자를 입력하세요:";
	std::cin >> biggerNumber;

	if (inputNumber > biggerNumber)
	{
		std::cout << "잘못 입력하셨습니다.";
	}
	else
	{
		std::cout << "잘하셨습니다.";
	}

	//1.사용자에게 숫자를 입력받고 해당 숫자가 짝수인지 홀수인지 출력해봅시다.
	int number;

	std::cout << "숫자를 입력하세요";
	std::cin >> number;

	if (number % 2 == 1)
	{
		std::cout << "입력하신 숫자는" << number << "이며 홀수입니다";
	}
	else
	{
		std::cout << "입력하신 숫자는" << number << "이며 짝수입니다.";
	}

	//2.입력받은 달러와 엔화를 KRW(원)으로 변환하는 프로그램을 작성해 봅시다.
	const int USDTOWN{ 1090 };
	const float YENTOWON = 9.7f;
	int money;
	char kind;

	std::cout << "달러(s)와 혹은 엔(y)를 입력하세요:";
	std::cin >> money >> kind;

	if (kind == 's')
	{
		std::cout << money << "usd는";
		std::cout << money * USDTOWN << "원 입니다" << std::endl;
	}
	if (kind == 'y')
	{
		std::cout << money << "JPY는";
		std::cout << money * YENTOWON << "원 입니다";
	}
	
	//3.BMI를 구하는 프로그램을 작성해 봅시다.

	double height;
	double weight;
	double bmi;

	std::cout << "키(cm)를 입력하세요:";
	std::cin >> height;
	std::cout << "체중(kg)을 입력하세요:";
	std::cin >> weight;

	//bmi=몸무게(kg)/(키(m)*키(m)
	height /= 100;
	bmi = weight / (height * height);

	//std::cout << "키 :" << height << ",몸무게:" << weight << "에 대한 bmi:" << bmi << std::endl;

	if (bmi <= 18.5)
	{
		std::cout << "저체중입니다." << std::endl;
	}
	else if (bmi < 25)
	{
		std::cout << "정상입니다." << std::endl;
	}
	else if (bmi < 30)
	{
		std::cout << "과체중입니다." << std::endl;
	}
	else
	{
		std::cout << "비정상입니다." << std::endl;
	}

	//switch 구문
	std::cout << "C++의 비트 연산자를 입력하세요.";
	char inputOperator;
	std::cin >> inputOperator;

	switch (inputOperator)
	{
	case '!':
		std::cout << "단항 연산자";
		break;

	case'&':
	case'|':
	case'^':
		std::cout << "이항 연산자";
		break;

	default:
		std::cout << "비트 연산자가 아닙니다.";
	}
}
