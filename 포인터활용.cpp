#include <iostream>

//값에 의한 호출(call by value)
void swap1(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

//참조에 의한 호출(call by reference)
void swap2(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap3(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

//함수와 포인터
int Sigma(int(*f)(int x), int m, int n)
{
    int sum = 0;
    for (int k = m; k <= n; ++k)
    {
        sum += f(k);
    }
}

int NormalFunction(int x)
{
    return x;
}

int SquareFunction(int x)
{
    return x * x;
}

using Comparison = bool(*)(int x, int y);

bool Asscending(int x, int y)
{
    return x > y;
}

bool Desecndeing(int x, int y)
{
    return x < y;
}

void Sort(int numbers[], int count, Comparison f)
{
    int temp{};

    for (int i = 0; i < count; ++i)
    {
        for (int j = i + 1; j < count; ++j)
        {
            if (f(numbers[i], numbers[j]))
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int main()
{
    //포인터의 활용 
    //값에 의한 호출(call by value)
    int x{ 10 }, y{ 20 };

    swap1(x, y);

    //참조에 의한 호출(call by reference)
    swap2(&x, &y);

    //참조(Reference)
    int a{ 1 };
    int& ref = a; //참조형의 선언 및 정의
    ref = 3; //참조형 변수의 값을 3으로 변경
    //1. 선언과 동시에 반드시 초기화 해야한다.
    //2. 초기화 이후에 다른 변수를 참조하도록 변경 불가

    swap3(x, y);

    //참조와 상수
    const int x{ 10 };
    const int& re = x; // 상수 참조 타입 
    re = 1; //참조가 상수 타입이므로 값 변경 불가

    int y{ 20 };
    const int& re2 = y; //상수 포인터와 동일하게 일반 변수를 참조 할수 있다.
    re2 = 2; //참조하고 있는 변수가 상수가 아니더라도 re2가 상수 타입이므로 값 변경 불가

    const int& re3 = 10 + 20; //우측값 참조(r-value reference)


    //함수 포인터
    std::cout << Sigma(NormalFunction, 1, 10) << std::endl;
    std::cout << Sigma(SquareFunction, 1, 10) << std::endl;

    const int NumArray = 10;
    int scores[NumArray]{ 20,10,40,15,30 };

    Sort(scores, NumArray, Asscending);
    Sort(scores, NumArray, Desecndeing);

    for (int i = 0; i < NumArray; ++i)
    {
        std::cout << scores[i] << ",";
    }


    //배열과 포인터
    int array[10]{ 1,2,3,4,5,6,7,8,9,10 };
    int sum = 0;

    for (int i = 0; i < 10; ++i)
    {
        std::cout << &array[i]<< " " << std::endl; //주소 출력
    }

    for (int i = 0; i < 10; ++i)
    {
        sum += *(array + i); //각 주소에 들어있는 값을 역참조 해서 더함
    }

    //2차배열
    int arrays[2][3];

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << &arrays[i][j] << std::endl; //주소 출력
        }
        std::cout << std::endl;
    }

    int* p[3] = &arrays[0]; //연산자 우선순위에 의해 에러임
    int(*p)[3] = &arrays[0]; //맞는 표기법
}


