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
    
    //클래스 #3
    //상수 클래스(Const Class)
    class Myclass
    {
    public:
        int mValue1;
        int mValue2;

        MyClass():MyClass(1, 1)
        {

        }

        MyClass(int v1, int v2) :mValue1{ v1 }, mValue2{ v2 }
        {

        }

        void SetValue1(int x)
        {
            mValue1 = x;
        }

        void DoNothing()
        {

        }
    };

    const MyClass c1; //기본 생성자로 초기화한 상수 객체
    const MyClass c2(2, 2);  //매개변수 2개인 생성자로 초기화한 상수 객체
    const MyClass c3{ 3,3 }; //유니폼 초기화를 사용한 상수 객체

    c1.mVaue1 = 10; //상수라서 멤버변수값을 수정할수 없으며 에러이다.
    c2.SetValue1(10); //상수라서 매개변수를 주면 멤버변수 값이 변경되므로 에러이다.

    //정적 멤버(static member)
    //클래스 내부에서만 존재해서 클래스 변수(class variable)라고도 표현한다
    //클래스 종속이라 this포인터가 넘어가지 않는다.
    class MyClass
    {
    public:
        static int mValue; //선언
    };

    int MyClass::mValue{ 1 };//정의

    //정적멤버 변수의 활용 예시
    
    class MyClass
    {
    public:
        static int sCount; 

        MyClass()
        {
            sCount++;
        }
        ~MyClass()
        {
            sCount--;
        }
    };

    int MyClass::sCount{ 0 };

    MyClass c1; //객체가 생성되서 생성자를 통해 스태틱 변수 값 증가
    MyClass c2;
    MyClass c3; 

    std::cout << c3.sCount << std::endl; //
    std::cout << MyClass::sCount << std::endl;

    //정적멤버 변수의 활용 예시
    class MyIDGenerator
    {
    public:
        static int sID;

        static int CreateNewID()
        {
            return ++sID;
        }
    };

    int MyIDGenerator::sID{ 0 };

    std::cout << MyIDGenerator::CreateNewID() << std::endl; //객체가 생성되서 생성자를 통해 스태틱 변수 값 증가
    std::cout << MyIDGenerator::CreateNewID() << std::endl;
    std::cout << MyIDGenerator::CreateNewID() << std::endl;

    //친구(friend)
    //친구 클래스
    //친구인 클래스는 private,protected 멤버에 까지 접근이 가능하다

    class Sword
    {
        friend class Warrior; //warrior를 sword의 친구로 지정
    private:
        int mAttackDamage;
        
    public:
        Sword(int damage):mAttackDamage{damage}
    };

    class Warrior
    {
    public:
        void AttackWith(Sword& sword)
        {
            std::cout << "칼을 휘둘러" << sword.mAttackDamage //warrior를 친구로 지정했으므로 sword의 private 멤버변수 접근가능
                << "만큼 피해를 주었다!" << std::endl;
        }
    };

    Sword shorSword{ 10 };
    Warrior w;

    w.AttackWith(shorSword);

    //친구 함수
    class Sword
    {
    private:
        int mAttackDamage;

    public:
        Sword(int damage) :mAttackDamage{ damage }
        {

        }
        friend void DamageBuff(Sword& sword) //멤버함수처럼 보이지만 전역함수이다.
        {
            int oldDamage = sword.mAttackDamage;
            sword.mAttackDamage = oldDamage * 2;

            std::cout << "검을 강화했다" << oldDamage
                << "->" << sword.mAttackDamage << std::endl;
        }
    };

    Sword shortSword(10);
    DamageBuff(shorSword);
    
    //친구멤버함수
    //전방선언 및 정의 분리하여 친구라는 것을 확인해서 사용해야된다.
    class Sword;
    
    class Warrior
    {
    public:
        void AttackWith(Sword& sword);
    };

    class Sword
    {
    private:
        int attackDamage;

    public:
        Sword(int damage) : attackDamage{ damage }
        {

        }

        friend void Warrior::AttackWith(Sword& sword)
        {
            std::cout << "칼을 휘둘러" << sword.attackDamage
                << "만큼 피해를 주었다!" << std::endl;
        }
    };


    //연산자 오버로딩
    //일반 함수형태
    class Point2D
    {
    private:
        int mX{};
        int mY{};

    public:
        Point2D() = default;
        Point2D(int x, int y) :mX{ x }, mY{ y }
        {

        }

        void Print()
        {
            std::cout << "(" << mX << "," << mY << ")" << std::endl;
        }

        friend Point2D operator+(Point2D& x, Point2D& y);
    };

    Point2D operator+(Point2D& x, Point2D& y)
    {
        Point2D newPt{ 0,0 };

        newPt.mX = x.mX + y.mX;
        newPt.mY = x.mY + y.mY;

        return newPt;
    }
   
    Point2D pt1{ 2,3 };
    Point2D pt2{ 3,4 };
    Point2D pt3{};
    Point2D pt4{};

    pt3 = pt1 + pt2; 
    pt3.Print();

    pt4 = (pt1 + pt2) + pt3; // 에러발생 pt1+pt2의 값이 무명객체이므로 const 참조형을 사용해야만 한다.
    
    //멤버 함수형태
    class Point2D
    {
    private:
        int mX{};
        int mY{};

    public:
        Point2D() = default;
        Point2D(int x, int y) :mX{ x }, mY{ y }
        {

        }

        void Print()
        {
            std::cout << "(" << mX << "," << mY << ")" << std::endl;
        }

       Point2D operator+(const Point2D& point); //+연산자
        {
            return Point2D(mX + point.mX, mY + point.mY);
        };
        Point2D operator++() //전위 연산자
        {
            Point2D temp(mX, mY);
            ++(*this);

            return temp;
        }

        Point2D operator++(int) //후위 연산자
        {
            ++mX;
            ++mY;

            return *this;
        }
    }
    class MyArray
    {
    private:
        int mArray[10];

    public:
        MyArray() :mArray{}
        {

        }

        int& operator[](int index) //첨자 연산자
        {
            return mArray[index];
        }
    }
    MyArray array1;

    array1[0] = 1;

    std::cout << array1[0] << std::endl;
    std::cout << array1[1] << std::endl;

    //스트림 삽입 연산자

    std::cout << pt;
    std::cout.operator<<(pt);//이 형태에서 <<는 좌측 cout개체의 멤버 함수로 만들수 있지만 cout를 수정할수 없다.


    //얕은 복사
    //얕은 복사(swallow copy)는 주어진 객체의 각 멤버 변수를 새 객체의 멤버 변수에 배정

    class DogHouse
    {
        Dog* owner;
    }

    DogHouse house1;
    DogHouse house2(house1);
    //포인터 변수에 얕은 복사를 사용하여 값을 복사하면 동일한 heap를 가르키는 포인터 변수가 된다.
    //만약 house1이 소멸되고 house2.onwer에 접근하면 심각한 오류 발생

    //깊은 복사(deep copy)
    //새로운 메모리를 할당해서 얕은 복사의 소유권 문제를 해결할수 있다.
    
    
    
    //클래스-상속과 다형성
    //파생 구문
    //class 파생클래스:[virtual][접근제한자]기반클래스,...

    //1.class 파생클래스:기반클래스
    //기본 표기법 만약 Animal을 기반으로 Dog를 파생하려면 다음과 같이 표현한다.
    class Dog :Animal;

    //2.[virtual]
    //[]는 생략이 가능하며 virtual은 가상 상속 개념이다.

    //3.[접근제한자]
    //기반 클래스의 멤버를 상속 받는 범위를 지정하는데, private는 접근불가이다.

    class Developer
    {
    public:
        std::string mName;
        int mAge;
    };

    class Programmer :public Developer
    {
    public:
        void Coding();
        void Debugging();
    };

    class Designer :public Developer
    {
    public:
        void Documentation();
        void Presentation();
    };
   
    class ChiefProgrammer :public Programmer
    {
    public:
        void Architecture();
        void Scheduling();
    };
   
    class Animal
    {
    protected:
        int mAge;
        int mWeight;

    public:
        Animal():mAge{1},mWeight{1}
        {

        }
        ~Animal()
        {

        }

        int GetAge() const
        {
            return mAge;
        }
        void SetAge(int age)
        {
            mAge = age;
        }
        int GetWeight() const
        {
            return mWeight;
        }
        void SetWeight(int weight)
        {
            mWeight = weight;
        }

        void Sound()
        {
            std::cout << "Make a noise..." << std::endl;
        }
    };

    class Dog :public Animal
    {
    public:
        enum BREED
        {
            BEAGE,
            DOBERMAN,
            BERNARD,
            CHIHUAHUA,
            HUSKY,
            RETRIEVER
        };

    private:
        BREED mBreed;

    public:
        Dog():mBreed{BREED::RETRIEVER}
        {

        }
        ~Dog();

        Dog::BREED GetBreed()const
        {
            return mBreed;
        }

        void SetBreed(Dog::BREED breed)
        {
            mBreed = breed;
        }

        void Roll()
        {
            std::cout << "Rolling..." << std::endl;
        }
    };

    Dog john; //Dog 타입의 존이라는 객체 생성

    john.Sound(); //sound는 부모의 특징이지만 상속을 받았으므로 사용가능
    john.Roll();// roll은 자기자신의 특징이므로 당연히 사용가능
    
     //파생관계에서의 생성자와 소멸자
    //부모가 먼저 만들어지고 그다음 자식이 만들어지며 소멸될때는 자식먼저 그 다음 부모가 소멸된다.

    //멤버함수 오버라이딩(overriding)
    //부모클래스의 함수를 자식이 재정의 하는것
    //예시

    class Character
    {
        virtual void Attack();
    };

    class Warrior :public Character
    {
        void Attack()
        {
            std::cout << "칼을 휘둘렀다";
        }
    };

    class Archer :public Character
    {
        void Attack()
        {
            std::cout << "화살을 쐈다";
        }
    };

    //이른 바인딩(early binding)vs늦은 바인딩(late binding)
    //바인딩은 프로그램에서 사용하는 변수/함수등의 이름을 값으로 연결해 주는 과정을 말한다.

    int a = 10;
    //정수형 변수 공간에 a라고 이름을 붙여주는 바인딩의 예시 이 경우 빠르게 바인딩이 발생

    p->vfunc();
    //가상함수 호출은 늦은 시간에 바인딩이 발생, p의 객체가 실제로 무엇인지 알아야 하기 떄문이다.

    class Character
    {
       
    };

    class Warrior :public Character
    {
        
    };
    
    //warrior의 인스턴스를 만들떄는 character생성자가 먼저 호출되고 그 다음 warrior 생성자가 호출되어 만들어진다.
    //이 중에서 character를 생성하려고 봤을떄 가상함수가 들어있으면
    //이 함수는 아직 누가 대상인지 모르기 떄문에 별도의 가상함수 테이블(virtual function table)에 옮겨둔다
    //그리고 인스턴스에 가상함수 테이블을 가르키는 포인터(vptr)을 만들어 연결해둔다.
    //다음으로 warrior 생성자가 호출되면 이제 가상함수 테이블은 객체가 어떤 타입인지 알수 있으니 Warrior의 함수에 연결해 준다.
    
    
}


