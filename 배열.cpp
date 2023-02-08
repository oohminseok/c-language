#include <iostream>

int main()
{
    //배열(Array)
    int scores[10]{};

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Input score[" << i << "]:";
        std::cin >> scores[i];
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << ":" << scores[i] << std::endl;
    }

    //배열의 크기 지정
    //리터럴 
    int number[3]{ };
    //상수 및 열거형
    const int index = 3;
    int array[index]{};

    enum num1
    {
        size = 1
    };

    int num[size]{};

    //배열 초기화
    int numbers[10]{ 1,2,3,4,5,6,7,8,9,10 };
    int score[10]{ 1,2,3 };

    //구조체와 배열
    struct Point2D
    {
        double x;
        double y;
    };

    Point2D pts[3]{};
    pts[0].x = 1.1;
    pts[0].y = 1.1;

    //다차원 배열
    //0,0,1,0,0
    //0,1,1,1,0
    //1,1,1,1,1
    int myArray[15] = {
        0,0,1,0,0,
        0,1,1,1,0,
        1,1,1,1,1
    };

    for (int i = 0; i < 15; ++i)
    {
        std::cout << myArray[i];

        if ((i + 1) % 5 == 0)
        {
            std::cout << std::endl;
        }
    }

    //2차원 배열
    int meArray[3][5] =
    {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            std::cout << meArray[i][j];
        }
        std::cout << std::endl;
    }

    //문자열(Character Array,string)
    char myString[10];

    std::cout << "Input string";
    std::cin >> myString;

    std::cout << "Your string is\"" << myString << "\"" << std::endl;  // 준비된 공간을 넘어가면 버퍼넘침(buffer overflow,stack overflow)발생


    struct Student
    {
        char name[10];
        int number;
        int score;
    };

    Student tom;

    std::cout << "Input name, number, score:";
    std::cin >> tom.name >> tom.number >> tom.score;

    std::cout << "Name is" << tom.name << std::endl;
    std::cout << "Number is" << tom.number << std::endl;
    std::cout << "Score is" << tom.score << std::endl;
}
