#include "./items.h"        //items.h 헤더파일을 불러오기 위해 씀, 따로 다른 선언은 하지않아도 된다.

int main()
{
    item SWORD = item("칼",100,"./img/sword.jpg");
    std::cout << SWORD.get_name() <<std::endl;

    WearableItem WEAR = WearableItem("황금 갑옷", 300,1, "./img/WEAR.jpg", 1 );
    std::cout << WEAR.get_name() <<std::endl;
    
    WeaponItem weapon_1 = WeaponItem("sword", 5, 5,10, 1.0, "./img/sword.jpg", false);
    std::cout << weapon_1.get_name() <<std::endl;

    WeaponItem weapon_2 = WeaponItem("bow", 3, 5,10, 1.0, "./img/bow.jpg", false);
    std::cout << weapon_2.get_name() <<std::endl;
        
    return 0;
}



// class WeaponItem : public WearableItem
// {
//     public:
//         int attack_dam;
//         float attack_spe;

//     WeaponItem(string name, int weight, short location, int attack_dam = 1, float attack_spe = 1.0, string img_path="", bool state=false)
//     :WearableItem(name, weight, location, img_path,state)
//     {
//         this->attack_dam = attack_dam;
//         this->attack_spe = attack_spe;
//     }

//     string get_name(){return"무기" + this->name;}
//     short get_location(){return this->location;}
//     bool get_state(){return this->state;}
//     int get_attck_dam(){return this->attack_dam;}
//     float get_attack_spe(){return this-> attack_spe;}
//     int attack(){return(int)(this->attack_dam*this->attack_spe);}


// };

// class WeaponItem : public WearableItem
// {
//     public:
//         int attack_damage;
//         float attack_speed; 
        
//     WeaponItem(string name, int weight, short location, int attack_damage=1, float attack_speed=1.0, string img_path="",bool state = false)
//     :WearableItem(name, weight, img_path, location, state)
//     {
//         this->attack_damage = attack_damage;
//         this-> attack_speed = attack_speed;
//     }
//     // int get_attack(){return attack_damage}
//     //헤더쪽에서는 정의나 초기화하지않는 것이 원칙 
//     string get_name(){return"장비:"+this->name;}
//     short get_location(){return this-> location;}
//     bool get_state(){return this->state;}
//     int get_attack_damage(){return this->attack_damage;}
//     float get_attack_speed(){return this-> attack_speed;}
//     // int attack(){return this->attack_damage*attack_speed;}내가 쓴 오답
//     int attck(){return(int)(this->attack_damage * this->attack_speed);}

// };
