#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void showHealthBar(string name, int hp, int maxHP)
{
    cout << name << "[";
    int bars = (hp *10)/ maxHP;
    
    if (bars < 0) bars = 0;
    
    for (int i = 0; i < bars; i++)
    {
        cout << "█";
    }
    for (int i = 0; i < 10; i++)
    {
        cout << " ▒";
    }
    cout << "]"<< hp << maxHP << "HP" << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian.UTF-8");
    
    srand(time(0));
    
    int playerHP = 80;
    int maxPlayerHP = 100;
    int enemyHP = 90;
    int maxEnemyHP = 110;
    int potions = 3;
    int round = 0;
    
    
    int totalDamageDealt = 0;
    int totalDamageTaken = 0;
    int totalHealing = 0;
    int potionsUsed = 0;
    int defendsUsed = 0;
    
    cout << "╔══════════════════════════════════════════════╗" << endl;
    cout << "║          Эпическая битва за респект          ║" << endl;
    cout << "╚══════════════════════════════════════════════╝" << endl;
    
    
    
    while (playerHP > 0 && enemyHP >0)
    {
        round++;
        cout <<"╔═════ Раунд "<< round << "═════╗"<< endl;
        cout << endl;
        
        showHealthBar("ИГРОК", playerHP, maxPlayerHP);
        showHealthBar("ВРАГ", enemyHP, maxEnemyHP);
        cout << "Зелей осталось: "<< potions << endl;
        cout << endl;
        if (playerHP < maxPlayerHP)
        {
            int regen = 8;
            playerHP += regen;
            
            if (playerHP > maxPlayerHP)
            {
                regen = regen - (playerHP - maxPlayerHP);
                playerHP = maxPlayerHP;
            }
            cout << "Регенерация: +"<< regen << "HP"<< endl;
            
            totalHealing += regen;
            cout << endl;
        }
        int choice;
        bool validChoice = false;
        
        
        do
        {
            cout << "--- Твой ход ---" << endl;
            cout << "1 Атаковать" << endl;
            cout << "1 Защищаться" << endl;
            cout << "1 Использовать зелье" << endl;
            if (potions == 0)
            {
                cout << endl;
                cout << "Ваш выбор";
                cin >> choice;
            }
            if (choice >= 1 && choice <= 3)
            {
                if (choice == 3 && potions == 0)
                {
                    cout << "У тебя не осталось зелей дебил" << endl;
                }
                else
                {
                    validChoice = true;
                }
            }
            else
            {   
                cout << "Неверный выбоп" << endl;
            }
        }
        while (!validChoice);
        cout << endl;
        int playerDamage = 0;
        bool isDefending = false;
        switch (choice)
        {
            case 1:
                {
                    playerDamage = rand() % 25 + 15;
                    enemyHP -= playerDamage;
                    totalDamageDealt += playerDamage;
                    cout <<"ТЫ АТАКУЕШЬ" << endl;
                }
            case 2:
                {
                    isDefending = true;
                    defendsUsed ++;
                    cout << "ТЫ ЗАЩИЩАЕТЬСЯ" << endl;
                    break;
                }
            case 3:
                {
                    int healing = 20;
                    playerHP += healing;
                    if (playerHP > maxPlayerHP)
                    {
                        healing = healing - (playerHP - maxPlayerHP);
                        playerHP = maxPlayerHP;
                    }
                    potions--;
                    potionsUsed ++;
                    totalHealing += healing;
                    cout <<"Ты пьешь зелье!" << endl;
                    break;
                }
        }
        cout << endl;
        showHealthBar("Враг", enemyHP, maxEnemyHP);
        if (enemyHP <=0)
        {
            cout << endl;
            cout << "╔═══════════════════════════════╗" << endl;
            cout << "║          УРА ПОБЕДА!          ║" << endl;
            cout << "╚═══════════════════════════════╝" << endl;
            break;
        }
        cout << endl;
        
    }
                                       
    cout <<"╚══════════════════════════╝"<< endl << endl;
}
