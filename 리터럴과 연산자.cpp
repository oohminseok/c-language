#include <iostream>

int main()
{
	
	//�������
	std::cout << "Input number";
	int number{ 0 };
	std::cin >> number;
	std::cout << "number is" << number << std::endl
		<< "number+1 is" << number + 1 << std::endl
		<< "number mutiply 3 is" << number * 3 << std::endl
		<< "number's square is" << number * number << std::endl;

	//���� ǥ�� �� ��Ʈ����
	int alpha{ 255 }, red{ 255 }, green{ 0 }, blue{ 0 };
	unsigned int color;

	color = alpha << 24 | red << 16 | green << 8 | blue;

	std::cout << std::hex;
	std::cout << color << std::endl;

	alpha = color >> 24;
	red = color >> 16 & 0xFF;
	green = color >> 8 & 0xFF;
	blue = color & 0xFF;

	std::cout << alpha << ","
		<< red << ","
		<< green << ","
		<< blue << std::endl;

	//���� ����
	int a = 3;
	a = 4;
	int b = a;
	b = a + 5;
	a = a + 7;

	//��������
	//����(postfix)���� ����
	int value1 = 1;
	int value2;

	value2 = value1++;
	//����(prefix)���� ����
	int value3 = 1;
	int value4;

	value4 = ++value3;

	//�񱳿���
	bool isEqual;

	isEqual = 3 == 4;
	
	std::cout<<isEqual;

	bool isTrue;
	isTrue = isEqual==true;



	

}