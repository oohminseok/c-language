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

     //클래스#2
    //생성자(constructor)
    //클래스의 객체가 인스턴스화될 때 자동적으로 호출되는 특별한 멤버함수 생성자
    //1.클래스와 동일한 이름이어야 한다.
    //2.반환 타입이 없다.

    class MyClass
    {
    public:
        MyClass() //생성자
        {
            std::cout << "[Constructor]" << std::endl; 
        }
    };

    //기본 생성자(Default Constructor)
    //기본 생성자는 매개변수가 없는 생성자의 형태로 멤버들을 기본값으로 초기화하는 생성자
    class Quest
    {
    private:
        int mID;
        int mExp;

    public:
        Quest()
        {
            mID = 1;
        }

        void Print()
        {
            std::cout << "QuestID:" << mID << std::endl;
            std::cout << "EXP:" << mExp << std::endl;
        }
    };

    Quest q1;

    //생성자의 형태
    //매개변수가 다른 동일한 생성자도 여러개 만들수 있다
    class Quest
    {
    private:
        int mID;
        int mExp;

    public:
        Quest()
        {
            mID = 1;
        }
        Quest(int id, int exp = 1)
        {
            mID = id;
            mExp = exp;
        }

        void Print()
        {
            std::cout << "QuestID:" << mID << std::endl;
            std::cout << "EXP:" << mExp << std::endl;
        }
    };
    
    Quest q2(2, 100);

    //초기화 방식
    //정수형의 경우
    int a = 2; //복사 초기화(copy initialization) 배정문을 통해 값을 대입하는 방식
    int b(2); //직접 초기화(direct initialization) 함수 형태로 초기화를 수행하는 것으로 생성자와 같은 방식
    int c{ 2 }; //유니폼 초기화(uniform initialization) 형변환이 허용되지 않고 안전하며 빠르다
    int d = { 2 }; //유니폼 복사 초기화(uniform initialization) //유니폼 초기화로 객체를 생성한후 복사하는 방식
 
    //클래스의 경우
    Quest q1 = Quest(); //복사 초기화(copy initialization) 새로 객체를 만들어 배정한다.
    Quest q2(2); //직접 초기화(direct initialization) 생성자를 직접 호출하여 초기화
    MyClass c3{ 2,1.0f }; //유니폼 초기화(uniform initialization) public변수들을 초기화하는 유니폼 초기화
    MyClass c4 = { 2,1.0f }; //유니폼 복사 초기화(uniform initialization) 유니폼 초기화로 객체를 생성한후 복사하는 방식
    
    //멤버 초기화 리스트
    //<생성자>:<초기화식1>,<초기화식2>,<초기화식3>...
    class Quest
    {
    private:
        int mID;
        int mExp;

    public:
        Quest(int id, int exp = 1) : mID{ id }, mExp{ exp } //유니폼 초기화
        {

        }
        Quest(int id, int exp = 1) : mID(id), mExp(exp) //복사 초기화
        {

        }
    };

    //대리 생성자(Delegating Constructor)
    class Quest
    {
    private:
        int mID;
        int mExp;

    public:
        Quest():mID{1},mExp{1}
        {
            //1:기본 퀘스트 초기화
        }
        Quest(std::string excel) : Quest{} //대리생성자
        {
            //2:엑셀에서 퀘스트 정보 가져온 후
        }
    };

    Quest q1 = Quest("1.xlsx");
    q1.Print();

    //위 코드는 다음과 같은 과정을 거친다.
    //1. Quest q1 = Quest("1.xlsx"); 인스턴스화
    //2.Quest(std::string)생성자
    //a.Quest()생성자
    // 1.멤버 초기화식
    // 2.기본 퀘스트 초기화
    //b.엑셀에서 퀘스트 정보 읽기

    //소멸자(Destructor)
    //소멸자는 생성자와 마찬가지로 특별한 멤버 함수로 객체의 소멸에 자동적으로 사용되는 기능

    class MyArray
    {
    private:
        int mLength;
        int* mArray;

    public:
        MyArray(int length) : mLength{ length }
        {
            mArray = new int[length] {};
        }
        ~MyArray()
        {
            delete[] mArray;
        }
    };


    MyArray Array{ 10 };
    // 위에서 소멸자가 없다면 인스턴스화할떄 동적할당한 int 10개는 유지되므로 메모리 누수가 발생
    
    
}


