//конструктор - это специальная функция, которая вызывается автоматически при создании объекта
struct  Player
{
    int hp;
    Player()
    {
        hp = 100;
    }
};

Player player;
//Вызваться Player() - контруктор
 #include <iostream>
#include <string>
using namespace std;


struct Character
{
    std::string name;
    int hp;
    Character(const string& startName, int starHp )
    {
        //конструктор без параметров
        name = startName;
        hp = starHp;
    }
    
    //Деструктор - спец. Функця, которая вызывается автоматически, когда объект уничтожаеться
    ~Character()
    {
        //Не принимает параметры, не имеет типа возвращаемого значения, совпадают с именем коасса
        cout << "Destroyed: " << name << endl;
        
        //Деструктор важен для динамической памяти
        //Если обьект владеет памятью
        //lines = new string[maxLines]
        //То он обязательно должен был освободить
        //delete[] lines;
        //Деструктор позовлит сделать это автоматически
    }
};

class EventLog
{
private:
    string* lines;
    int capacity;
    int count;
    
public:
    EventLog(int maxLines)
    {
        lines = new string[maxLines];
        capacity = maxLines;
        count = 0;
    }
    ~EventLog()
    {
        delete[] lines;
        lines = nullptr;
        capacity = 0;
        count = 0;
    }
    
    void AddEvent(const string& line)
    {
        if (count < capacity)
        {
            lines[count] = line;
            count++; // count = count + 1
            return;
        }

        for (int i = 0; i < count; ++i)
        {
            lines[i] = lines[i + 1];
        }
        lines[capacity - 1] = line; // кладем нновую строку в конец списк
    }
    void Print()
    {
        cout << "Event Log:"<< endl;
        for (int i = 0; i < count; ++i)
        {
            cout <<"- "<< lines[i] << endl;
        }
    }
};

enum class ItemType
{
    Weapon,
    Potion,
    QuestionItem,
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

class InventoryBuffer
{
private:
    InventorySlot* slots;
    int size;
public:
    InventoryBuffer(int slotCount)
    {
        slots = new InventorySlot[slotCount]; //выделяем память под слоты
        size = slotCount;
        
        for (int i = 0; i < size; ++i)
        {
            slots[i].isEmpty = true;
            slots[i].count = 0;
        }
    }
    ~InventoryBuffer()
    {
        delete[] slots;
        slots = nullptr;
        size = 0;
    }
    InventorySlot* GetSlot(int index)
    {
        if (index < 0 || index >= size) //Проверка границы
        {
            return nullptr;
        }
        return &slots[index];
    }
    
    void PutItem(int index, const Item& item,int count)
    {
        InventorySlot* slot = GetSlot(index);
        if (slot == nullptr)
        {
            cout << "Invalid slot index" << endl;
            return;
        }
        
        slot->item = item;
        slot -> isEmpty = false;
        slot -> count = count;
    }
    
    void Print()const
    {
        for (int i = 0; i < size; ++i)
        {
            cout << "SLOT "<<i<< ": "<< endl;
            
            if (slots[i].isEmpty)
            {
                cout << "EMPTY "<< endl;
            }
            else
            {
                cout << slots[i].item.name<< " x"<< slots[i].count << endl;
            }
        }
    }
};

struct DamageRecord
{
    string attackerName;
    string targetName;
    int damage;
};

class DamageHistory
{
    private:
    DamageRecord* records;
    int capacity;
    int count;
    public:
    DamageHistory(int maxRecords)
    {
        records = new DamageRecord[maxRecords];
        capacity = maxRecords;
        count = 0;
        if (maxRecords <= 0)
        {
            cout << "Max records cannot be zero" << endl;
        }
    }
    ~DamageHistory()
    {
        delete[] records;
        records = nullptr;
        capacity = 0;
        count = 0;
    }
    
    void AddRecord(const std::string& attacer, const std::string& target, int damage)
    {
        if (damage < 0)
        {
            damage = 0;
            cout << "Damage cannot be negative" << endl;
            return;
        }
        if (count < capacity)
        {
            records[count].attackerName = attacer;
            records[count].targetName = target;
            records[count].damage = damage;
            count++;
        }
        records[capacity - 1] = DamageRecord{ attacer, target, damage };
    
    }
    
    void PrintRecord()
    {
        for (int i = 0; i < count; ++i)
        
        {
            cout << "Record "<<i<< ": "<< endl;
            if (count == 0)
            {
                cout << "Record empty" << endl;
            }else
            {
                cout << records[i].attackerName << endl;
            }
        }
    };
    
    void GetTotalDamage()const
    {
        for (int i = 0; i < count; ++i)
        {
            records[i].damage = records[i].damage + records[i].damage;
        }
        cout << "Total damage: " << records[0].damage << endl;
    }

};









int main()
{
    Item potion{"potion_heal", "Healing potion", ItemType::Potion, 6};
    InventoryBuffer intentory(9);
    intentory.PutItem(0, potion, 3);
    intentory.Print();
    
    
    DamageHistory damageHistory(10);
    damageHistory.AddRecord("Oleg", "Stas", 15);
    damageHistory.GetTotalDamage();
    damageHistory.PrintRecord();
    
    return 0;
}













