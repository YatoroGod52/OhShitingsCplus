//grob 
//ТЕСТ:
//1.1 - c
//1.2 - b
//1.3 - c







/////// задание 2

#include <iostream>
#include <string>
using namespace std;

class EventLog
{
private:
    string* lines;
    int capacity;
    int count;
    
public:
    
    EventLog(const EventLog&) = delete;
    EventLog& operator=(const EventLog&) = delete;
    
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
    
    void Add(const std::string& line)
    {
        if (count < capacity)
        {
            lines[count] = line;
            count++; 
            return;
        }

        for (int i = 0; i < count; ++i)
        {
            lines[i] = lines[i + 1];
        }
        lines[capacity - 1] = line; 
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







struct  DamageRecord
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
        if (maxRecords <= 0)
        {
            maxRecords = 1;
        }
        
        records = new DamageRecord[maxRecords];
        capacity = maxRecords;
        count = 0;
    }
    
    ~DamageHistory()
    {
        delete[] records;
        records = nullptr;
        capacity = 0;
        count = 0;
    }
    
    DamageHistory(const DamageHistory& other)
    {
        capacity = other.capacity; 
        count = other.count;
        records = new DamageRecord[capacity];
        
        for (int i = 0; i < count; i++)
        {
            records[i] = other.records[i];
        }
    }
    DamageHistory& operator=(const DamageHistory& other)
    {
        if (this == &other)
        {
            return *this; 
        }
        
        delete[] records; 
        
        capacity = other.capacity; 
        count = other.count;
        records = new DamageRecord[capacity];
        
        for (int i = 0; i < count; i++)
        {
            records[i] = other.records[i];
        }
        return *this; 
    }
    
    void Add(const string& attacker, const string& target, int damage)
    {
        
        if (count < capacity)
        {
            records[count] = DamageRecord{attacker,target,damage}; 
            count++;
            return;
        }
        
        for (int i = 0; i < capacity; i++)
        {
            
            records[i-1] = records[i];
        }
        records[capacity -1 ] = DamageRecord{attacker,target,damage};
    }
    
    void Print() const
    {
        cout << "История урона: " << endl;
        
        for (int i = 0; i < count; i++)
        {
            cout << i+1 << ". ";
            cout << records[i].attackerName << " -> ";
            cout << records[i].targetName << ": ";
            cout << records[i].damage << " урона";
            cout << endl;
        }
    }
};





int main()
{
    //////////////////////////////////////// 1
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
    cout <<"totalDamage: "<<totalDamage<<endl;
    delete[] damages;
    damages = nullptr;
    
    ///////////////////////////////////////
    
    DamageHistory damage_history(3);
     
    damage_history.Add("Stas","Kirill",15);
    damage_history.Add("Kirill","Stas",40);
    
    cout << "History of битва" << endl;
    damage_history.Print();
    
    EventLog event_log(5);
    
    event_log.Add("Кирилл проснулся");
    event_log.Add("Кирилл завалил ОГЭ");
    
    cout <<"LOgи : " << endl;
    event_log.Print();
    return 0;
}


