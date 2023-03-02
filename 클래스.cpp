#include <iostream>

int main()
{
    //클래스#1
    //클래스 정의
    //클래스(Class)는 멤버들의 집합으로 이뤄진 데이터 형식
    class <클래스이름>
    {
        [접근제한자1]:
        <멤버>
            [접근제한자2]:
            <멤버>
    };

    class Dog
    {
    private:
        unsigned int mAge;

    public:
        unsigned int mWeigth;

    public:
        int mColor;

    public:
        void Bark();
    };

    //접근제한자(Access Modifiers)
    //public
    //클래스 내부/외부에서 모두 사용이 가능
    //protected
    // 자신과 자신을 기반으로 하는 파생클래스에서 사용이 가능
    //private
    //클래스 내부에서만사용이 가능
    //기본값으로 생략하면 private이다.

    //클래스와 구조체
    //구조체는 모든 멤버가 public인 클래스의 일부분이라고 봐도 무방하다.
    //
    struct Position
    {
        int x;
        int y;
        void Print();
    };

    class Position
    {
    public:
        int x;
        int y;
        void Print();
    };

    //멤버 함수의 구현
    class Dog
    {
    public:
        void Bark()
        {
            std::cout << "멍!" << std::endl;
        }
        int GetAge();
    };

    //범위해결연산자(scope resolution operator)->::
    //클래스이름::함수명 형태로 멤버함수의 소속 클래스를 명시
    
    void Dog::Bark()
    {
        std::cout << "멍!" << std::endl;
    }

    //멤버함수의 선언 순서
    //일반적인 함수는 선언의 순서가 중요하지만 클래스의 경우 제약이 없다.

    class MyClass
    {
        void f1()
        {
            f2();
        }

        void f2()
        {

        }
    };

    //this키워드
    //this는 멤버함수를 호출한 객체의 포인터를 나타낸다. 
    int Dog::GetAge()
    {
        return mAge; //암시적 표현
    }

    int Dog::GetAge()
    {
        return this->mAge; //명시적 표현
    }

    //클래스 객체의 사용법
    //클래스 멤버에 접근하기 위해서는 구조체와 마찬가지로 점 연산자를 사용하면 된다.
    
    Dog myDog; //Dog는 클래스이며 myDog는 클래스의 인스턴스

    myDog.mWeight = 2;
    myDog.mAge = 10;
    myDog.Bark();

}


