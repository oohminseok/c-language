#include <iostream>

//�Լ�(function)
void PrintDottedLine()  //��ȯŸ�� �Լ��̸�(�Ű�����)
{
	std::cout << "---------" << std::endl; //��ü
}

void PrintNumber(int x)//ȣ����ϴ� ��(callee)
{
	std::cout << x << std::endl;
}

int Square(int x)
{
	return x * x; //������� ��ȯ���ش�.
}

//�Լ��� ����(declaration)�� ����(definition)
//���漱��(forward delcaration)
int Num(int);

//��ȯȣ��(cyclic calling)
void g();

void f()
{
	g();
}

void g()
{
	f();
}
//���漱���� ���� �ذᰡ��

//���� ����(Global Variable)
int myGlobalInteger = 5; //�ش�ҽ����� ��𿡼��� ����Ҽ� ����

//���� ����(Static Variable)
int GetOrderNumber()
{
	static int number{ 0 }; //���α׷��� ����ǰ� ����ɶ����� ��Ƴ��� ����
	return number++; 
	
	if (number == 10)
	{
		return number;
	}
}

//�Ű����� ��ġ
void WhoAmI(int value)
{
	std::cout << "���� ������ ó���մϴ�." << value << std::endl;
}
void WhoAmI(float value)
{
	std::cout << "���� �Ҽ��� ó���մϴ�." << value << std::endl;
}
void WhoAmI(float value, float value2)
{
	std::cout << "���� �Ҽ� 2���� ó���մϴ�." << value << value2 << std::endl;
}
//3���� ������ Ÿ�� �� �Լ��� �̸��� �Ű������� Ÿ�� �̸� ���� ���� �ٸ����� �Լ��� �����ε��̶� �ϸ�, 
//������ �̸��� �Լ��� ���� ó���ϱ� ����� ���� ��ȣ��(Ambiguous)��� �Ѵ�.

//�Լ� �ñ״���(function signature)
//�Լ��� �̸�, �Ű������� Ÿ��, ����, ���� �Լ��� Ư���� ��Ÿ���� �ñ״���(signature)�� ��
int Print(int i);
void Print(int i);
//�̸� �Ű������� ������ ��ȯ���� �ٸ��� �� ���� ������ ������ �߻���

//�Լ��� �۵�����


int main()
{
	PrintNumber(3); //�Լ��� ȣ���ϱ� ���� ȣ���ϴ� ��(caller) ���ڿ� ���� �ָ� ȣ����ϴ���(callee)�� �Ű������� ���� ����Ǽ� ��µȴ�. �̷��� ���� Call by Value(���� ���� ȣ��)
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