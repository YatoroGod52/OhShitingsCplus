#include <iostream>
#include <cmath>
using namespace std;

struct Enemy
{
    string name;
    int health;
    int armor;
};
int CalculateDamage(int armor, float critMultiplier, int baseDamage)
{
    float rawDamage = critMultiplier * baseDamage;
    float afterArmor = rawDamage - armor;
    if (afterArmor < 0.0f) afterArmor = 0.0f;
    
    return static_cast<int>(afterArmor);
}
void ApplyDamage(Enemy& enemy, int damage)
{
    enemy.health = enemy.health - damage;
    
    if (enemy.health < 0)
    {
        enemy.health = 0;
    }
}

int main()
{
    Enemy crip{"Крипоек",50,3};
    int baseDamage = 20;
    float critMultiplier = 1.5f;
    
    int damage = CalculateDamage(crip.armor, critMultiplier, baseDamage);
    ApplyDamage(crip, damage);
    
    cout << "Damage: " << damage << endl;
    cout << "Enemy: "<< crip.name << endl;
    cout << "Enemy hp: " << crip.health << endl;
    
}

