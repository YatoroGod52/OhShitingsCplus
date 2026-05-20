#include <iostream>
#include <vector>
using namespace std;

int hp = 100;
int* hpPointer = &hp;
//int* -> указывает на int
//hpPointer -> имя указателя
//&hp - адресс переменной hp
//hpPointer не хранит 100

//Две роли символов & и *
//& в тиме это ссылка
//int& ref = hp;
//Здесь & значит ссылку
//В выражениях - взять адрес
//int* ptr = &hp
//*
//в типе указатель
///int* ptr
//здась * означает ptr - это указатель на int
//В выражении - разименование
//*ptr = 50;
// здесь * означает изменить значение по адресу






void ApplyDamage(int* hp, int damage)
{
    //ункция принмает указатель на хп
    if (hp == nullptr)
    {
        return;
    }
    *hp = *hp - damage;
    //разыменовываем указатель и уменьшаем оригинальное hp
    if (*hp < 0)
    {
        *hp = 0;
    }
}

//Плохой пример -> разименование nullptr
int* ptr = nullptr;
//cout << *ptr << endl; это ошибка
//ptr - указатель
//Говорим прогрмамме иди никуда и возьми там значение

//Ссылка против указателя:
//void Heal(Character& character)
//Подойдет если персонаж точно существует
//Функция обязана получить настоящего персонажа
//Указатель
//void Heal(Character* character)
//Персонаж может существовать , а может нет

// . и ->
//Если обычный обьект используем .
//Character Oleg;
//Oleg.hp = 100;
//Если указатель - используем стрелку
//Character* target = &oleg;
// target -> hp =100;
//Можно и точку, но тогда запись будет такая:
//(*targe).hp == target -> hp

struct Character
{
    string name;
    int hp;
};

//Функция принимает указатель на цель(хп)
void DamageTarget(Character* target, int damage)
{
    if (target == nullptr)
    {
        cout <<"Нету цели для атаки"<< endl;
        return;
    }
    //Уменьшаем хп цели через указатель
    target->hp = target ->hp - damage;
    if (target->hp < 0)
    {
        target->hp = 0;
    }
    cout << target ->name <<" получил " << damage << " урона " << endl;
}


//Указатель как ответ на вопрос нашел или не нашел
//В пример у нас есть список врагов

vector<Character> enemies;
//И нам надо найти врага по его имени
//И получить ответ: если нашли то вернуть адрес, если нет то вернуть nullptr

Character* FindEnemyByName(vector<Character>& enemies, const string& name)
{
    for (Character& enemy : enemies)
    {
        if (enemy.name == name)
        {
            return &enemy;
        }
    }
}

enum class ItemType
{
    Weapon,
    Potion,
    QuestItem
};
struct Item
{
    string name;
    string id;
    ItemType type;
    int maxStack;
};

struct ItemStack
{
    Item item;
    int count;
};

ostream operator<<(const ostream& lhs, const ItemStack& rhs);

void PrintInventory(const vector<ItemStack>& inventory)
{
   
    for (const ItemStack& item : inventory)
    {
        string& inventory = inventory;
        if (inventory.size() == 0)
        {
            cout <<"Пустой инвентарь" << endl;
            return;
        }
        cout << "Предметы " << item.item.name << endl;
    }
}

ItemStack* FindStackById(vector<ItemStack>& inventory, const string& itemid){
    for (ItemStack& item : inventory)
    {
        if (item.item.id == itemid)
        {
            return &item;
        }
        else
        {
            return nullptr;
        }
    }
};

int addToExistingStack(ItemStack* stack, int addCount)
{
    if (stack == nullptr)
    {
        return addCount;
    }
    int null;
    if (stack->count !=null )
}



int main()
{
    int hp = 100;
    int* hpPointer = &hp;
    cout<<"Значение переменной :" << hp << endl;
    cout<<"Адресс переменной :"  << &hp << endl;
    cout <<"Адрес с указателем :" << hpPointer << endl;
    cout <<"Значение в указателе : " << *hpPointer << endl;
    
    ApplyDamage(&hp,35); // передаем адрес hp в функцию
    cout <<"HP: " << hp << endl;
    
    Character stas{"Stas", 50};
    //Указатель который хранит адрес Стаса
    Character* selectedTarget = &stas;
    
    DamageTarget(selectedTarget, 25);
    //Сбрасываем выьранную цель
    selectedTarget = nullptr;
    
    //Пробуем нанести урон без выбранной цели
    DamageTarget(selectedTarget, 50);
    cout <<"STAS HP: " << stas.hp << endl;
    
    vector<Character> enemies;
    
    enemies.push_back(Character{"Stas", 40});
    enemies.push_back(Character{"Innokentiy", 40});
    enemies.push_back(Character{"Nigger", 40});
    
    //Ищем иннокентия
    Character* target = FindEnemyByName(enemies, "Innokentiy");
    
    DamageTarget(target,35);
    
    Character* missingtarget = FindEnemyByName(enemies,"Migel");
    DamageTarget(missingtarget,50);
    
    for (const Character& enemy: enemies)
    {
        cout << enemy.name << "HP: " << enemy.hp << endl;
    }
    
    //
    return 0;
}