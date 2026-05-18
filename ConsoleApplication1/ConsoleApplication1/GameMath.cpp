// <> - для системных файлов
// " " - для пользовательских

#include <iostream>
#include "GameMath.h"
#include <cmath>

using namespace std;

namespace GameMath
{
    //ФИЗ ДАМАГ
    int calculateDamage(int attackPower, int defence)
    {
        int damage = attackPower - defence;
        
        if (damage < 0)
        {
            damage = 0;
        }
        return damage;
    }
    //МАГ ДАМАГ
    float calculateDamage(float magicPower, float magicResistacne, int spellLevel)
    {
        float baseDamage = magicPower * (1.0f - magicResistacne);
        float levelMultiplier = 1.0f *(spellLevel *0.1f);
        
        float damage = baseDamage * levelMultiplier;
        cout << "Магический урон: сила = " << magicPower << "Сопротивление = "<< magicResistacne << "уровень = "<<spellLevel << "Урон = " << damage<< endl;
    }
    
    //КРИТЫ
    int calculateDamage(int attackPower, int defence, float criticalMultiplier)
    {
        int damage = attackPower - defence;
        if (damage < 0)
        {
            damage = 0;
        }
        
        float damageCrit = damage * criticalMultiplier;
        static_cast<int>(damageCrit);
        
        cout << "Критический урон = " << damageCrit << "Крит = "<< criticalMultiplier << endl;  
    }
    //КОМБО ВОМБО
    float calculateDamage(int physicalPower, int defence, float magicPower, float magicResistance)
    {
        int damage = physicalPower - defence;
        float baseDamage = magicPower * (1.0f - magicResistacne);
    }
}





















