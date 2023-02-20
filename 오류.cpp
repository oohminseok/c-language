#include <iostream>

int Add(int a, int b)
{
    return a + b;
}

int Add2(int a, int b);

double linear_equation(int a, int b)
{
    if (a == 0)
    {
        throw std::logic_error("divide by zero");
    }
    return -((double)b / a);
}

int average(int a, int b, int c)
{
    if (!(a > 0 && a < b && b < c))
    {
        throw std::logic_error("a,b,c should positive and a<b<c");
    }

    int average{ 0 };
    average = (double)(a + b + c) / 3.0;

    if (average < 0)
    {
        throw std::logic_error("average is negative!");
    }
    return average;
}

int main()
{

    //오류의 종류
    //1.컴파일 시간 오류(complie-time error)
    //컴파일러가 찾아 낸 오류
    // 문법 오류 : c++의 정해진 문법을 지키지 않아서 발생
    // 타입 오류: 타입에 지원되지 않는 연산을 수행할때 발생
    //오류(error):오류가 발생하면 컴파일 진행X 프로그램 실행을 할수 없다.
    //경고(warning):컴파일이 성공적으로 진행되며,프로그램도 실행할 수 있지만 의도치 않은 결과가 나올수 있다.

    //int sum1 = Add(10, 1; //컴파일 오류 세미콜론 앞에 괄호가 빠져있다.
    //int sum2 = Add(10, 10.1);  //Add함수 2번쨰 인자 int타입이지만 double 타입을 축소변환이 일어난다.

    
    //2.링크 타임 오류(link-time error)
    //링커가 탐지한 오류
    int sum3 = Add(10, 1); // 함수를 선언했지만 정의가 없다.

    //3.실행 시간 오류(run-time error)
    //프로그램을 실행하는 동안 발생하는 오류

    //4.논리 오류(logic error)
    //디버깅을 하면서 잘못된 부분을 하나씩 추적해서 오류를 수정해야함


    //예외(exception)
    //1.오류 발생
    // 오류가 발생하면 프로그래머가 return이 아닌 예외를 준다(throw)
    //예외 탐지 및 처리
    //함수를 호출한 모든 쪽에서 계산을 시도(try)해보고 예외를 잡아(catch) 예외에 대한 처리를 수행

    int a;
    int b;
    
    std::cout << "두 정수를 입력하세요:";
    std::cin >> a >> b;

    //기본 예외 처리
    try
    {
        std::cout << linear_equation(a, b); //함수를 사용하기전 try구문으로 계산시도
    }
    catch (std::logic_error) //try블록에서 던져진 예외를 catch한다.
    {
        std::cerr << "divide by zero!" << std::endl; //예외에 대응
    }

   /* try
    {
        return 0;
    }
    catch (std::exception e)
    {
        std::cerr << "error:" << e.what() << std::endl;
        return 1;
    }
    catch (.....)
    {
        std::cerr << "unknown error!" << std::endl;
        return 2;
    }*/

    int q, w, e;
    std::cout << "세 정수를 입력하십시오";
    std::cin >> q >> w >> e;

    try 
    {
        std::cout << average(q, w, e) << std::endl;
    }
    catch (std::logic_error)
    {
        std::cerr << "divide by zero!" << std::endl;
    }


}


