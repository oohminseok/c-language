#include <iostream>

int main()
{
    //타입 변환(type conversion)
    int myInteger = 1;
    long long myLongLong = myInteger; //형식변환

    int Integer = 1024;
    char myCharacter = myInteger; //축소변환

    //암시적변환(implicit conversion)
    int number = 5;
    std::cout << 5 / 2.0f;

    //명시적변환(explicit conversion)
    int count = 1000;
    unsigned char myCharacter = myInteger;

    std::cout << myInteger << std::endl;
    std::cout << int(myCharacter) << std::endl;


    //별칭(alias)
    typedef unsigned int uint;
    uint myUint = 1;

    //using(c++11)
    //using 별칭=기존형식
    using usnt = unsigned int;
    usnt myUint = 1;

    //열거형(Enumeration Type)
    enum AttackType{Physical,Magical,Fixed};

    AttackType type = Physical;

    switch (type)
    {
    case Physical:
        break;

    case Magical:

    case Fixed:
        break;

    }

    //플래그(Flag)
    int questComplete{ 0 };

    //1,3번 퀘스트 클리어
    questComplete |= 1;       //questComplete|=0x01, questComplete|=0b0001
    questComplete |= 4;       //questComplete|=0x04, questcomplete|=0b0100

    if (questComplete & 1 && questComplete & 4)
    {
        //5번 퀘스트 시작
    }

    enum QuestCleared
    {
        Quest1=0b0001,
        Quest2=0b0010,
        Quest3=0b0100,
        Quest4=0b0100,
    };

    int q{};

    q |= Quest1;
    q |= Quest3;

    //구조체(Structure)
    struct Ability
    {
        int HP;
        int MP;
        int Strength;
        int magic;
        int defense;
        int magicDefense;
    };
   
    struct Ability warriorAbility;

    warriorAbility.HP = 1000;
    warriorAbility.MP = 0;
    warriorAbility.Strength = 10;
    warriorAbility.magic = 0;
    warriorAbility.defense = 10;
    warriorAbility.magicDefense = 0;
    
    //구조체 초기화
    struct Monster
    {
        int HP;
        int MP;
        int Strength;
        int magic;
        int defense;
        int magicDefense;
    };

    Monster demon{ 300,100,10,10,10 };

    std::cout << demon.HP << std::endl;

    demon.MP = 150;

    std::cout << demon.MP << std::endl;


}
