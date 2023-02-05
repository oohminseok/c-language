#include <iostream>

int main()
{
	//변수의 범위(Scope)
	  /*{
		  int i = 1;
	  }

	  std::cout << i;*/
	  //변수 i의 범위는 블록 안으로 한정되 있어 컴파일이 안되며
	  //중괄호 안에서 사용된 것은 지역변수(Local value)이라고 부름


	  //반복(Repetition 또는 Loop)
	  //do~while(조건식)구문
	int i = 1;
	do
	{
		std::cout << i << std::endl;
		++i;
	} while (i <= 10);

	//while(조건식)
	int j = 1;
	while (j <= 10)
	{
		std::cout << ++j << std::endl;
	}

	////for(초기화;조건식; 연산)
	for (int i = 1; i <= 10; ++i)
	{
		std::cout << i << std::endl;
	}

	////for문 고급
	for (int i = 0, int j = 1; i < 10; i += 2, j = i + 1)
	{
		std::cout << i << "," << j << std::endl;
	}
	

	//연습문제
	/*1. 다음과 같이 화면에 출력합시다.
		1
		2
		3
		4
		5*/
	for (int i = 1; i <= 5; ++i)
	{
		std::cout << i << std::endl;
	}

	/*2. 다음과 같이 화면에 출력합시다.
		1
		3
		5
		7
		9*/

	for (int i = 1; i <= 9; i += 2)
	{
		std::cout << i << std::endl;
	}

	/*3. 1에서 10까지의 합을 출력합시다.*/

	int sum = 0;
	for (int i = 1; i <= 10; ++i)
	{
		sum += i;
	}
	std::cout << sum;


	/*	4. 다음과 같이 숫자를 출력해 보세요.
		1 1
		1 2
		1 3
		2 1
		2 2
		2 3*/

	for (int i = 1; i <= 2; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			std::cout << i << ":" << j << std::endl;
		}
	}

	/*5. 화면에 a부터 z까지 출력합시다.
		힌트 : char 타입은 ASCII 코드를 사용해서 글자를 표현*/

	for (char ascii = 97; ascii <= 122; ++ascii)
	{
		std::cout << ascii << std::endl;
	}

	/*6. 화면에 구구단 2단을 출력해 봅시다.
		2 x 1 = 2
		2 x 2 = 4
		2 x 3 = 6
		.
		.
		2 x 9 = 18*/

	for (int i = 2; i < 3; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			std::cout << i << "x" << j << std::endl;
		}
	}

	/*7. 출력할 구구단을 입력받고, 해당 구구단을 출력해 봅시다.
		몇 단을 출력할까요 : 3
		3 x 1 = 3
		3 x 2 = 6
		.
		.
		3 x 9 = 27*/

	int gugudan;
	std::cin >> gugudan;

	for (int i = 1; i <= 9; ++i)
	{
		std::cout << gugudan << "x" << i << std::endl;

	/*8. 모든 구구단을 화면에 출력해 봅시다.
		---- 2단----
		2 x 1 = 2
		.
		.
		---- 3단----
		3 x 1 = 3
		.
		.
		---- 9단----
		9 x 1 = 9
		.
		.*/

		for (int i = 2; i <= 9; ++i)
		{
			std::cout << "-----" << i << "단-----" << std::endl;
			for (int j = 1; j <= 9; ++j)
			{
				std::cout << i << "x" << j << "=" << i * j << std::endl;
			}
		}

		/*9. 두 개의 주사위를 던졌을 때 두 눈의 합이 6이 되는 모든 경우의 수를 구하세요.
		1 5
		2 4
		3 3
		4 2
		5 1*/

		for (int i = 1; i <= 5; ++i)
		{
			for (int j = 5; j >= 1; --j)
			{
				std::cout << i << ":" << j << std::endl;
			}
		}

		/*10. 정답이 6으로 정해진 Up & Down 게임을 만들어 봅시다.
			입력 : 4
			UP
			입력 : 9
			DOWN
			입력 : 7
			DOWN
			입력 : 6
			정답입니다.
			-- - 프로그램 종료-- - */


		while (true)
		{
			int input;
			std::cout << "숫자를 입력하세요";
			std::cin >> input;

			if (input < 6)
			{
				std::cout << "입력" << ":" << input << std::endl;
				std::cout << "UP" << std::endl;
			}
			if (input > 6)
			{
				std::cout << "입력" << ":" << input << std::endl;
				std::cout << "DOWN" << std::endl;
			}
			if (input == 6)
			{
				std::cout << "정답입니다" << std::endl;
				std::cout << "----프로그램 종료----" << std::endl;
				break;
			}
		}



}

