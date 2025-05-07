#include <iostream>
#include <string>

//이것이 있으면 std::을 사용하지 않아도 됨
using namespace std;    //이 파일에 있는 모든 함수 정의에 영향을 준다

//class만듬
class item
{
    public:
        string name;
        int weight;
        string img_path;

        item(string name, int weight, string img_path="")
        {
            this->name = name;
            if(weight > 0)
            {
                this->weight = weight;
            }
            else
            {
                this->weight = 0;
            }
            this->img_path = img_path;
        }
        string get_name(){return this->name;}
        int get_weight(){return this-> weight;}
        void show_image(){cout << this -> img_path << endl;}
};

//item이 부모, 자식으로 warable item을 만듬
class WearableItem : public item
{
    public:
        short location;
        bool state;

        WearableItem(string name, int weight, short location, string img_path="",bool state = false)
        :item(name, weight, img_path)
        {
            this->location = location;
            this->state = state;
        }
        //헤더쪽에서는 정의나 초기화하지않는 것이 원칙 
        string get_name(){return"장비:"+this->name;}
        short get_location(){return this-> location;}
        bool get_state(){return this->state;}
};

//WearableItem 이 부모, WeaponItem이 자식
class WeaponItem : public WearableItem
{
    public:
        int attack_damage;
        float attack_speed; 
        //순서 동일해야함
        WeaponItem(string name, int weight, short location, int attack_damage=1, float attack_speed=1.0, string img_path="",bool state = false)
        :WearableItem(name, weight, location, img_path, state)
        {
            this-> attack_damage = attack_damage;
            this-> attack_speed = attack_speed;
        }

        // int get_attack(){return attack_damage}
        //헤더쪽에서는 정의나 초기화하지않는 것이 원칙 
        string get_name(){return"장비:"+this->name;}
        short get_location(){return this-> location;}
        bool get_state(){return this->state;}
        int get_attack_damage(){return this->attack_damage;}
        float get_attack_speed(){return this-> attack_speed;}
        // int attack(){return this->attack_damage*attack_speed;}  == 내가 쓴 오답 int 
        int attck(){return(int)(this->attack_damage * this->attack_speed);}

};

//WeaponItem의 자식을 2개 만듬
//상속은 1대 다수로도 가능하다
class MeleeWeapeon :  public WeaponItem{};
class RangeWeapeon :  public WeaponItem{};