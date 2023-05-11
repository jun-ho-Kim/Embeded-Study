#include <iostream>
using namespace std;

void doSomething(int students_scores[20]) // 컴파일러는 매개변수를 포인터로 처리한다.
{
    cout << (int)&students_scores << endl;  //1547303540
    // 포인터 변수 첫번째 주소값을 저장하는 포인터 변수이다.
    cout << (int)&students_scores[0] << endl;//1547303520
    cout << students_scores[0] << endl;     //1 
    cout << students_scores[1] << endl;     //2
    cout << "Size in doSomething" << sizeof(students_scores) << endl;
}


int main()
{
    const int num_students = 20;

    int students_scores[num_students] = {1,2,3,4,5,};
    cout << (int)students_scores << endl;       //1547303520
    cout << (int)&students_scores << endl;      //1547303520
    cout << (int)&students_scores[0] << endl;   //1547303520
    cout << (int)&students_scores[1] << endl;   //1547303524
    cout << (int)&students_scores[2] << endl;   //1547303528
    cout << (int)&students_scores[3] << endl;   //1547303532
    cout << (int)&students_scores[4] << endl;   //1547303536
    cout << "Size in main" << sizeof(students_scores) << endl;

    cout << "doSomething func start" << endl;


    doSomething(students_scores);
}
