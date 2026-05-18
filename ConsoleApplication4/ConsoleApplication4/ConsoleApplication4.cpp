//int -целые 2 147 483 648 (от - до +) применение: хп, уровень, кол-во чего-то
//float - дробные | координаты, скорость, время кадра
//double - более большое дробное число | точные расчеты, редакторы, физика вне realtime
//bool - логическое | правда или лож
//long long - большие числа | опыт, деньги и id
//char - символ или маленькое число
//size_t - размер контейнера (ячейка памяти, где лежит переменная), а также можно подучить индекс ячейки

//почему double не всегда лучше float
//double точнее, но занимает больше памяти
// float - 4 байта, а double - 8 байта

// Беззнаковые типы данных 
//ВАЖНО! Если допустить ошибку и выйти за диапазон в минус, ти число перевернуться
unsigned int gold = 100;
//gold = gold - 1; станет  147 483 648
// gold = std::max(0, gold-cost)
//Безопасный и максимальный вычет числа

//int damage = static_cast<int>(baseDamage*multiplier);
//явное изменение типа данных

//для использования in / out
#include <iostream>

// ля использования границ типов данных
#include <limits>

// для использования фиксированных типов данных
#include <cstdint>

#include <string>
#include <vector>
using namespace std;
enum class ItemType
{
    WEAPON,
    ARMOR,
    POTION
};

struct Item
{
    string id;
    string name;
    ItemType type;
    int MaxStack;
};

struct ItemStack
{
    Item item;
    int count;
};

struct Enemy
{
    mutable int hp;
 int armor;   
};

struct Player
{
    int baseDamage;     
    float critMultiplier;
    int armor;
};
//то функция которая переводит ItemType в текст
string ItemTypeToText(ItemType type)
{
    //выбирает ветку по enum
    switch (type)
    {
    case ItemType::WEAPON: return "Weapon"; //если в enum Weapon выбран, то вернуть текст
    case ItemType::ARMOR: return "Armor";
    case ItemType::POTION: return "Potion"; 
    }
    return "Unknown";
}

void PrintStack(const ItemStack& stack)
{
    cout << stack.item.name << endl;
    cout <<" x" << stack.count << endl;
    cout << " [" << ItemTypeToText(stack.item.type) << "]" << endl; //напишем тип предмета
    cout << endl;
}

int CalculateDamage(int baseDamage,float critMultiplier, int armor)
{
    int damage = baseDamage * critMultiplier;
    int finall_damage = damage - armor;
    if (finall_damage < 0) finall_damage = 0;
    
    return finall_damage;
}

void ApplyDamage(const Enemy& enemy, int damage)
{
    enemy.hp -= damage;
    if (enemy.hp <= 0)
    {
        enemy.hp = 0;
        cout << "Враг умер" << endl;
    }
    cout << "ХП: "<<enemy.hp << endl;
    
}
int main()
{   
    Item potion{"potion_heal", "Healing Potion" , ItemType::POTION, 12};
    Item sword {"sword", "Sword", ItemType::WEAPON, 1};
    
    vector<ItemStack> inventory;
    
    inventory.push_back(ItemStack{potion,6});
    inventory.push_back(ItemStack{sword,1});
    
    cout << "Inventory" << endl;

    for (const ItemStack& stack : inventory)
    {
        PrintStack(stack);
    }
    
    cout << "bool:" << sizeof(bool) <<"битов" << endl;
    cout << "char:" << sizeof(char) <<"битов" << endl;
    cout << "int:" << sizeof(int) <<"битов" << endl;
    cout << "float:" << sizeof(float) <<"битов" << endl;
    cout << "double:" << sizeof(bool) <<"double" << endl;
    
    cout << "Лимиты" << endl;
    cout << "int min:" << numeric_limits<int>::min() << endl;
    cout << "int max:" << numeric_limits<int>::max() << endl;
    
    cout << "float min:" << numeric_limits<float>::min() << endl;
    cout << "float max:" << numeric_limits<float>::max() << endl;
    
    cout <<"double min:" << numeric_limits<double>::min() << endl;
    cout << "double max:" << numeric_limits<double>::max() << endl;
    
    //return 0;//сообщаем ОС, что программа завершена успешна и очистить память
    int baseDamage = 20;
    float critMultiplier = 1.5f;
    int armor = 7;
    
    float rawDamage = baseDamage * critMultiplier;
    float afterArmor = rawDamage - armor;
    
    if (afterArmor < 0.0f) afterArmor = 0.0f;
    
    int finalDamage = static_cast<int>(round(afterArmor));
    
    cout <<"BaseDamage:"<< baseDamage <<endl;
    cout <<"CritMultiplier:"<< critMultiplier << endl;
    cout <<"Armor:"<< armor << endl;
    cout <<"RawDamage:"<< rawDamage << endl;
    cout <<"AfterArmor:"<< afterArmor << endl;
    cout <<"FinalDamage:"<< finalDamage << endl;
    
    ///////////////////////////////////////////
    // Калькулятор боевого урона
    // Нужно написать програму, которая:
    // у игрока есть базовый урон
    // у врага есть hp и броня
    // есть множитель критического урона
    // итоговый урон не может быть ниже 0
    // все изменения выводятся в консоль
    // Сделать простой тип данных Enum
    // Сделать функцию CalculateDamage(int baseDamage, float critDamage, int armor)
    // Функция считает:
    // урон с критом,
    // вычитает броню,
    // проверяет не стал ли урон ниже 0.0f
    // Функция округляет и возвращает int
    //
    // Написать функцию ApplyDamage(Enemy& enemy, int: damage) // функция применения урона к врагу
    // Отнимаем здоровье врага
    // проверяем не ушло ли ниже 0
    // Ничего не возвращаем
    
    
    
    Player player{10, 1.5f, 3};
    Enemy enemy{50,3};
    
    int PlayerAttackerNigger = CalculateDamage(player.baseDamage,player.critMultiplier,enemy.armor);
    ApplyDamage(enemy,PlayerAttackerNigger);
    
    cout <<"Урон :" << PlayerAttackerNigger << endl;
    cout <<"ХП : " << enemy.hp << endl;
    return 0;
    
    
    
    
    
    
    
}