#include <iostream>

int main()
{
	std::cout << "���ڸ� �Է��ϰ� ���͸� ��������!" << std::endl;

	int number;

	std::cin >> number;
	std::cout << "�Է��Ͻ� ���ڴ�";
	std::cout << number;
	std::cout << "�Դϴ�!";
	std::cout << std::endl;

	int myInteger; //����(Declaration)
	myInteger = 1; //����(Assignment)

	int x;
	x = 10;

	std::cout << x << ":" << &x << std::endl; //x�� �� : x�� ���� ����� �޸� �ּ�

	//�����÷�(OverFlow)
	int overFlow = 2147483647;

	overFlow = overFlow + 1;

	std::cout << overFlow;

	//����÷�(UnderFlow)
	unsigned int underFlow = 0;

	underFlow = underFlow - 1;

	std::cout << underFlow;

	


}