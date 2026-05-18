#include  <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void showHealthBar(string name, int hp, int maxHP){
    cout << name << "[";
    
    // Вычисляем количество делений нашего Health HUD Bars (полосок здоровья)
    int bars = (hp * 10) / maxHP;
    if (bars < 0) bars = 0;
    
    for (int i = 0; i < bars; i++){
        cout << "█"; // Заполненная часть
    }
    for (int i = bars; i < 10; i++){
        cout << "░"; // Пустая (потраченная часть) бара
    }
    
    cout << "] " << hp << "/" << maxHP << "HP" << endl;
}

int main(){
    setlocale(LC_ALL, "Russian.UTF-8");
    
    srand(time(0));
    
    // === НАЧАЛЬНЫЕ ХАРАКТЕРИСТИКИ === //
    int playerHP = 80;
    int maxPlayerHP = 100;
    int enemyHp = 90;
    int maxEnemyHP = 110;
    int potions = 3;
    int round = 0;
    
    // === СТАТИСТИКА === //
    int totalDamageDealt = 0;
    int totalDamageTaken = 0;
    int totalHealing = 0;
    int potionUsed = 0;
    int defendsUsed = 0;
    
    cout << "╔═══════════════════════════════╗" << endl;
    cout << "║  ЭПИЧЕСКАЯ БИТВА С ПРОВЕРКОЙ  ║" << endl;
    cout << "╚═══════════════════════════════╝" << endl;
    
    // ОСНОВНОЙ ИГРОВОЙ ПРОЦЕСС В ЦИКЛЕ
    while (playerHP > 0 && enemyHp > 0){
        round++; // round++ - round = round + 1
        
        cout << "╔════════ РАУНД " << round << " ══════════╗" << endl;
        cout << endl;
        
        // === ПОКАЗЫВАЕМ СТАТУС ИГРОКА ===
        showHealthBar("ИГРОК ", playerHP, maxPlayerHP);
        showHealthBar("ВРАГ ", enemyHp, maxEnemyHP);
        cout << "Зелий осталось: " << potions << endl;
        cout << endl;
        
        if (playerHP < maxPlayerHP){
            int regen = 8;
            playerHP += regen; // playerHP = playerHP + regen
            
            // Проверка на превышение максимума
            if (playerHP > maxPlayerHP){
                regen = regen - (playerHP - maxPlayerHP); // Корректировка показанного нам значения
                playerHP = maxPlayerHP;
            }
            cout << "РЕГЕНЕРАЦИЯ: +" << regen << " HP" << endl;
            totalHealing = totalHealing + regen;
            cout << endl;
        }
        
        // === МЕНЮ ДЕЙСТВИЙ (do-while) === //
        int choice;
        bool validChoice = false; // Флаг правильного выбора

        do{
            cout << "----- Твой ход ----- " << endl;
            cout << "1. Атаковать" << endl;
            cout << "2. Защититься (50% резист урона) + двойная регенерация" << endl;
            cout << "3. Использовать зелье (+20 HP)" << endl;
            if (potions == 0){
                cout << "[НЕТ ЗЕЛИЙ]" << endl;
            }
            cout << endl;
            cout << "Ваш выбор: ";
            cin >> choice;
            
            // Проверка ввода игрока
            if (choice >= 1 && choice <= 3){
                if (choice == 3 && potions == 0){
                    cout << "У тебя не осталось зелий, Выбери другое действие";
                }else{
                    validChoice = true;
                }
            }else{
                cout << "Неверный выбор, жди докс, и выбери от 1 до 3" << endl;
            }
        }
        while (!validChoice);
        
        cout << endl;
        
        // ОБРАБОТКА ВЫБОРА ИГРОКА
        int playerDamage = 0;
        bool isDefending = false; // Флаг защиты

        switch (choice){
            case 1:{ // АТАКА
                // Случайный урон от 15 до 25
                playerDamage = rand() % 25 + 15;
                // playerDamage = 15 + rand() % 11
                // rand() % 11 дает 0-11, + 15 = 15-25
                
                enemyHp -= playerDamage;
                totalDamageDealt += playerDamage;
                
                cout << "Ты атакуешь!" << endl;
                cout << "Урон: " << playerDamage << endl;
                break;
            }
            case 2:{ // ЗАЩИТА
                isDefending = true;
                defendsUsed++;
                cout << "МАКСИМУМ ЗАЩИТЫ!" << endl;
                cout << "ТЫ КОНТРИШЬ 50% урона" << endl;
                cout << "Регенерация в следующем раунде будет 2x" << endl;
                break;
            }
            case 3:{
                int healing = 20;
                playerHP += healing;
                
                if (playerHP > maxPlayerHP){
                    healing = healing - (playerHP - maxPlayerHP);
                    playerHP = maxPlayerHP;
                }
                
                potions--;
                potionUsed++;
                totalHealing += healing;
                
                cout << "Ты пьешь зелье!" << endl;
                cout << "Восстановлено: + " << healing << endl;
                break;
            }
        }
        cout << endl;
        showHealthBar("Враг ", enemyHp, maxEnemyHP);

        if (enemyHp <= 0){
            cout << endl;
            cout << "╔══════════════════════════════╗" << endl;
            cout << "║         УРА ПОБЕДА           ║" << endl;
            break;
        }
        
        cout << endl;
        // ДОМАШНЕЕ ЗАДАНИЕ !
        // ХОД ВРАГА
        // 1. Случайный урон врага от 10 до 20
        // 2. Проверка, если игрок защищается, то уменьшить сгенерированный урон драга вдвое
        // 3. Нанести урон игроку + записать в статистику полученный урон   
        // 4. Выводим инфу что нам наносять N-ое число урона
        // 5. Показываем здоровье игрока
        // 6. Проверяем жив ли нащ игрок (если нет - врервать while)
        // 7. Если да - новый раунд (итерация while)
    }
    
    cout << "╚══════════════════════════════╝" << endl << endl;
}














