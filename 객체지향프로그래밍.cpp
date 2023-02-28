#include <iostream>

int main()
{
    //절차적 프로그래밍(Procedural Programming)
    //함수단위를 바탕으로 작성

    //객체 지향 프로그래밍(Object Orienetd Programming)
    //Object-객체
    //현실의 대상을 둘러싼 하나의 객체라고 볼수 있으며 이를 이용하며 프로그래밍을 하는방법이 객체지향 프로그래밍
    //객체는 상태(State)와 행동(Behavior)를 가지고 있다.

    //Class -클래스
    //객체를 표현하기 위한 설계도 또는 틀
    //아래의 추상적인 정보가 클래스

    //클래스 예시
    class Dog
    {
        //상태
        char breed[];
        int age;
        int weight;

        //행동
        짖기();
        구르기();
        물어뜯기();
    };

    //Instance -인스턴스
    //추상적인 정보인 클래스에서 구체적인 객체를 생성해서 만들어진 것을 인스턴스라고 부른다.

    Dog 똘이; //Dog라는 클래스를 이용해 구체적으로 똘이라는 객체 인스턴스를 만듬

    //C++의 클래스
    //언어      상태(State)      행동(Behavior)
    //C++        멤버변수           멤버함수
    // C#        필드(Field)        매서드(Method)
    //           속성(Property) 
    //Java       필드(Field)        매서드(Method)


    //OOP의 특징
    // 1.객체(Object)
    // 2.클래스(Class)
    // 3.캡슐화(encapsulation)
    // 캡슐화의 기본적인 목적은 안에 뭐가 들어있는지 모르게 하는것
    // 캡슐화는 정보은닉(Information Hiding)의 개념으로도 사용됨 
    // 4.상속(Inheritance)
    // 상속(Inheritance) 또는 파생(Derivation)이라고도 부른다.
    //                      동물(Aniaml)  
    //         개(Dog)                           고양이(Cat) 
    //          똘이
    // 
    //         상속(Inheritance)            파생(Derivation)
    //      부모 클래스(Parent Class)    기반 클래스(Base Class)
    //      자식 클래스(Child Class)    파생 클래스(Derived Class)
    //      똘이는 개를 상속 받았다.    똘이는 개에서 파생되었다.
    //         똘이-Child Class              똘이-Derived Class
    //         개- Parent Class              개- Base Class

    // 상속 예시
    class Animal
    {
    public:
        int age :
        int weight;

    public:
        void 걷기()
        {

        }
    }

    class Dog :Animal
    {
    public:
        char breed[];

    public:
        void 짖기()
        {

        }
        void 구르기()
        {

        }
    };

    Dog Dool;

    Dool.age = 10;
    Dool.걷기();
    Dool.짖기();

    // 5.다형성(Poltmorphism)
    //위에 예시로 똘이는 '개'이면서 '동물'이다.
    //하나의 객체가 어떤 경우에는 동물로 취급될수도 있고 개로 취급될수도 있음
    //상황에 따라 서로 다른형태로 사용되는 것을 다형성이라고 한다.

    //다형성 예시
    Dog* 똘이 = new Dog();
    똘이->age = 10;

    Animal* 동물 = 똘이;

    동물->걷기();

    //생성자(Constructor)/소멸자(Destructor)
    //객체가 생성될때 불리는 것이 생성자 이고 사라질떄 불리는 것이 소멸자이다.


    //정적 멤버(Static Member)
    //정적 멤버는 인스턴화 해서 객체로 만들지 않아도 클래에서 바로 사용할수 있다.

    //추상 클래스(Abstract Class)
    //추상적인 개념을 담고 있기 때문에 스스로 인스턴스화 할수 없다.
    //인스턴스화 하려면 추상클래스를 상속받아 자식 클래스에서 인스턴스화 해야한다.

    //인터페이스(Interface)
    //서로 다른 두 장치를 접속시켜주는 뜻, USB와 같은 것을 의미
    //상태는 없고 행동만 있으며, 실제 행동을 구현하지는 않는다.

    //오버로딩(Overloading)과 오버라이딩(Overriding)
    //오버로딩은 하나의 행동을 매개변수만 다르게 해서 여러개를 정의하는 것
    //오버라이딩은 부모 클래스의 행동을 자식 클래스에서 재정의


}