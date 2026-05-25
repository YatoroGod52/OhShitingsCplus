//Стек - это памяьт для локальных переменных

void Test()
{
    int hp = 100;
}
//хп существует только внутри функции

//Куча - это память для объектов, которые создаются вручную и могут жить дольше текущей функции
//Новый создается через new, а удаляется через del
//int*hp = new int(100)
//delete hp

//new int(100) создает в куче
//int*hp - хранит адрес этого числа

#include <iostream>
#include <string>
using namespace std;

//Утечка памяти - ситуация когда программа выделила память, но потягала возможность ее освободить
//пример критической потери памяти
void BadFunction()
{
    int* hp = new int(100);
    //Когда закончиться указатель хп исчезнет, потому что он локальный
    //Но объект созданный останется в куче
    //То есть адрес потерян, память им занята, освободить ее уже нельзя
}
//Висячий указатель
//После delete hp память уже освобождена
//НО указатель еще хранит адрес на данную переменную в куче

//Двойной delete - программа упадет сразу, потому что это критическая ошибка

struct Character
{
    string name;
    int hp;
    int damage;
};

void PrintCharacter(const Character* character)
{
    if (character == nullptr)
    {
        cout <<"Character is nullptr"<<endl;
        return;
    }
    cout <<character -> name <<"hp: "<< character -> hp <<endl;
}

//new[] delete[]
//Чтобы создать или очистить память для массива
// int*damages = new int[5];
// delete[] damages

//С массивом через new[] мы сами отвечаем за размер, удаление, защиту от выхода за границу массива, правильный delete

enum class ItemType
{
    Weapon,
    Potion,
    QuestItem
};

struct Item
{
    string id;
    string name;
    ItemType type;
    int maxStack;
};

struct InventorySlot
{
    bool isEmpty;
    Item item;
    int count;
};

void PrintItem(const InventorySlot* slots, int size)
{
    if (slots == nullptr)
    {
        cout <<"Item is nullptr"<<endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Slot "<< i << ":";
        if (slots[i].isEmpty)
        {
            cout <<"Empty"<<endl;
        }else
        {
            cout << slots[i].item.name << " x"<< slots[i].count << endl;
        }
    }
}

struct EventLog
{
    string* lines;
    int capacity;
    int count;
};

void InitEventLog(EventLog& log, int maxLines)
{
    log.lines = new string[maxLines];
    log.capacity = maxLines;
    log.count = 0;
}

void DestroyEventLog(EventLog& log)
{
    delete[] log.lines;
    log.capacity = 0;
    log.count = 0;
    log.lines = nullptr;
}

void AddLog(EventLog& log, const string& line)
{
    log.lines[log.count] = line;
    log.count++;
    if (log.count >= log.capacity)
    {
        cout <<"FULL"<<endl;
    }
}

void PrintEventLog(const EventLog& log)
{
    for (int i = 0; i < log.count; i++)
    {
        cout << log.lines[i] << endl;
        return;
    }
}

int main()
{
    int*hp = new int(100);
    //создаем int в куче и сохраняем адрес в указателе hp
    cout <<"hp "<<*hp<<endl;
    
    *hp = 200;
    //Меняем значение обьекта в куче
    cout <<"hp "<<*hp<<endl;
    
    delete hp;
    //Освобождаем память, которую выделили через new
    hp = nullptr;
    //Обнуляем указатель, чтобы не показывад на освобожденную память
    
    //Создаем указатель в куче
    Character* oleg = new Character{"Oleg",100,25};
    
    //Передает указатель в функцию печати
    PrintCharacter(oleg);
    delete oleg;
    oleg = nullptr;
    PrintCharacter(oleg);
    
    //Динамический массив урона
    int count = 5;
    int* damages = new int[count];
    for (int i = 0; i < count; i++)
    {
        damages[i] = (i+1) * 10;
    }
    
    int totalDamage = 0;
    for (int i = 0; i < count; i++)
    {
        //добавляем текущий урон к сумме уронов
        totalDamage += damages[i];
    }
    cout <<"totalDamage "<<totalDamage<<endl;
    delete[] damages;
    damages = nullptr;
    
    ////////////////////
    const int slotCount = 9;
    InventorySlot* slots = new InventorySlot[slotCount];
    for (int i = 0; i < slotCount; i++)
    {
        slots[i].isEmpty = true;
        slots[i].count = 0;
    }
    Item potion{"poiton_heal","Healing potion", ItemType::Potion,6};
        
    slots[0].isEmpty = false;
    slots[0].item = potion;
    slots[0].count = 3;
        
    PrintItem(slots, slotCount);
    delete[] slots;
    slots = nullptr;
    
   
    
    
    
    
    
    
    
    EventLog log;
    log.count = 15;
    log.capacity = 15;
    InitEventLog(log,3);
    AddLog(log,"Player Picked up sword");
    PrintEventLog(log);
    DestroyEventLog(log);
    
    
    
    
    
    
    
    
    
    
    
    return 0;
    
}

//RAIL ПЕРВЫЙ ВБРОС
//Rail означает ресурс, который захватывает в конструкторе и особождаеться в деструктор
//Объект сам убирает за собой
//Класс выделил память в конструкторе

//InventoryBuffer()
//{
//    slots = new InventorySlot[100];
//}

//И освободил в деструкторе 
//InventorySlotBuffer()
//{
//    delete[] slots;
//}

//Благодаря этому пользовать класса не должен каждый раз помyить про del


















