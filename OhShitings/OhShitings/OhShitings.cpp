#include <iostream>
#include <ostream>
#include <string>
using namespace std;
int CalculateDamage(int baseDamage, float multiplier);

    //Сообщаем компилятору, что такая фукнция будет существовать
    //Она вернет int и принимает int, float


////////////////////////////////////////////////////////////
//передеча параметров функции:
//1-по значению
//2- по ссылке
//3-по const-ссылке
//4-указатель

////////////////////////
//1 -
void TakeDamage(int hp, int damage)
{
    hp = hp - damage;
}
//Если вызвать, то int PlayerHp = 100;
//TakeDamage(PlayerHp,30)
//PlayerHp -> останеться 100

//Когда исползовать:
//1-когда тип маленький
//2-функция не должна менять оригинал
//3- когда нужна независимая копия

//////////////////////////////////////
// 2-
void TakeDamage(int& hp, int& damage)
{
    hp = hp - damage;
}
//& - озаначает хп - ссылка на оригинальную переменную
//Когда хп передан по ссылке, функция меняет оригинал
//TakeDamage(PlayerHp,30)
//НР  передает по ссылке
//playerHp измениться на 30 и станет 30

//////////////////////////////////////
//3-
//Если обьект большой, но функция не должна его менять, то передает по const-ссылке
//void PrintPlayer(const CharacterStats &stats)
//сonst - запрещает меенять обьект 
//& - позволяет не копировать обьект

struct CharacterStats
{
    std::string name;
    int hp;
    int maxHp;
    int damage;
};
void PrintStats(const CharacterStats& stats)
{
    std::cout << "Name: " << stats.name << std::endl;
    std::cout << "HP: " << stats.hp << std::endl;
    std::cout << "Max HP: " << stats.maxHp << std::endl;
    std::cout << "Damage: " << stats.damage << std::endl;
}


//4
//указатель почти тоже самое что и ссылка но он может быть пустым
void Heal(int* hp, int amaunt);
//функция принимает адрес переменной HP

void HealByPointer(int* hp, int amaunt, int maxHP)
{
    //hp - указатель на int и может быть 0
    if (hp == nullptr)
    {
        //проверка на пустой ли указатель
        return;
    }
    //Разименовываем указатель и меняем оригинальное значений
    *hp = *hp - amaunt;
    
    if (*hp > maxHP)
    {
        *hp = maxHP;
    }
}

//Что выбрать и когда: ссылка или указатель
//ССылку надо использовать если обьект обязателен

//Const-ССылку выбираем если надо просто читать
//ТО ест ь когда печатать можно, а менять запрещено

//Используем указатель если обьект даже в теории может отсутсвовать
//Например, когда персонажа может и не быть Например цель не найдена



void TakeDamage(int& hp, int damage)
{
    hp = hp& - damage;
    if (hp < 0)
    {
        hp = 0;
        cout << "Умер" << endl;
    }
}

void Heal(int& hp, int maxHP,int amaunt)
{
    hp = hp& + amaunt;
    if (hp > maxHP)
    {
        hp = 100;
        cout << "У вас максимальный предел хр" << hp << endl;
    }
}



int main()
{
    CharacterStats hero{"Olge",80,100,10};
    PrintStats(hero);
    
    int playerHp = 50;
    int maxHp = 100;
    
    HealByPointer(&playerHp,30,maxHp);
    cout << playerHp << endl;
    //&playerHp - адрес в памяти переменно playerHp
    //*hp - значение по адресу
    
    TakeDamage(playerHp,20);
    HealByPointer(&playerHp,50,maxHp);
    cout <<"HP: " << playerHp << endl;
    return 0;
}

int CalculateDamage(int baseDamage, float multiplier)
{
    return static_cast<int>(baseDamage * multiplier);
    //fun definition - определение функции
}



//Создайте void TakeDamage в котором hp передаеться по ссылку и функция меняет оригинал
//проверка на меньше 0 через мин или макс
//создаем void Heal в которой hp передаеться по ссылке msxHp по значению
//тоже проверка не стало ли больше максхп
//внитри мейна
//вызываем TakeDamage,Heal
//выводим hp




`