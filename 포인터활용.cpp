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

int Sum(int* input, int count) //(모호성) int타입을 가르키므로 배열도 가르킬수 있으며 일반 정수 타입도 가르킬수 있다. 포인터의 장점이자 단점
{
    int sum{};

    int* p = input;
    for (int i = 0; i < count; ++i)
    {
        sum += *p++;
    }

    return sum;
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
    const int q{ 10 };
    const int& re = q; // 상수 참조 타입 
    re = 1; //참조가 상수 타입이므로 값 변경 불가

    int e{ 20 };
    const int& re2 = e; //상수 포인터와 동일하게 일반 변수를 참조 할수 있다.
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
    
    std::cout << Sum(&arrays[0][0], 2 * 3) << std::endl;
    
    //문자열과 포인터

    char c[6];
    char* pc;
    c[0] = 'd';
    c[1] = 'o';
    c[2] = 'g';
    c[3] = 'g';
    c[4] = 'y';

    std::cout << c << std::endl; //출력하면 쓰레기 값이 붙어서 출력된다. 

    pc = &c[0];
    std::cout << pc << std::endl; //위와 동일하게 쓰레기 값이 붙어서 출력된다.
    c[5] = '\0'; //쓰레기값 없이 문자만 출력할려면 끝 부분에 '\0'문자를 붙여야 한다.
    std::cout << pc << std::endl;//쓰레기값 없이 출력된다.

    char myString[] = "Doggy"; //" "리터럴을 사용하면 null문자열이 만들어진다.
    char* pt = myString;


    std::cout << pt << std::endl; //쓰레기값 없이 출력된다.

    int myInteger = 5;
    char myString[] = { "is integer value." };
    char myString2[] = { "는 정수입니다." };
    
    std::cout << myString + myInteger << std::endl; //5칸(5byte)을 건너뛴 "nteger value"가 출력된다.
    std::cout << myString2 + myInteger << std::endl;//한글은 아스키 코드로 표기가 불가하므로 2바이트씩 저장된다 그러므로 "수입니다"가 출력된다.

    wchar_t myString3[] = { L"는 정수입니다." };
    //한글은 유니코드 문자로 표기되며 일반문자와 구분하기 위해 wchar_t라는 형식과 리터럴에 L이라는 접두어가 붙는다.
    
    std::locale myLocale("kor"); //한글을 표현하기 위해서는 로케일에 "kor"을 지정해줘야 한다.
    std::wcout.imbue(myLocale);

    std::wcout << myString + myInteger << std::endl; //화면에 출력하기 위해서는 cout가 아닌 wcout를 사용한다.
    
    
}


