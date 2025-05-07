#include <iostream> //c언어의 #include <stdio.h>와 동일 

class ExampleClass      //전역에 있어야함 
{   //접근 제한자 
    public:
        int num;
        static int count;

        ExampleClass(int num)
        {
            count++;
            this -> num = num;      //생성자 //함수와 똑같은 이름으로 생성됨, 객체 초기화
                                    //생성자로, 값에 직접 접근하는 것은 좋지 않음        
        }
        void show_num()
        {
            std::cout << this -> num << std::endl;
        }
        void set_num(int num)
        {
            this -> num = num;
        }
        int get_num()
        {
            return num;
        }
        ~ExampleClass() //파괴자(이 객체가 파괴될떄 사용, 구분하기 위해 물결을 사용)
        {
            count--;
        }
};
int ExampleClass::count = 0;

//자식 class -직접 부모를 호출하여 생성자를 생성
class ChildExampleClass : public ExampleClass
{
    public:     //private일 경우 오버라이딩 불가
        ChildExampleClass(int num): ExampleClass(num){}

        void show_num()         //위의 부모 함수와 같은 이름의 함수, 전역에 있지만 오버라이딩해서 사용 가능
        {
            std::cout << "자식 클래스의 "<< this -> num <<std::endl;
        }
};
//this는 자기 자신을 가리키는 것? 일단 포인터라고 생각하면 됨 
//this->a 는 a의 값을 가리키는 것 ?

int main()
{
    //a와b는 모두 num과 count를 가지고 있다
    ExampleClass a = ExampleClass(10);  //Exampleclass의 a라는 인스턴스가 만들어진다,
    ExampleClass b = ExampleClass(20);
    ChildExampleClass c = ChildExampleClass(30);
    {   //지역 함수
        ExampleClass c = ExampleClass(30);
        std::cout <<a.count<<std::endl;
    }
    // std::cout <<a.count<<std::endl;    

    a.show_num();
    b.show_num();
    c.show_num();


    // std::cout <<a.count<<std::endl;
    // std::cout <<b.count<<std::endl;
    // // std::cout <<c.count<<std::endl;
    return 0;
}