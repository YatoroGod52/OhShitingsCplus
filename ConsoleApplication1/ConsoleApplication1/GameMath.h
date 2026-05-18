#ifndef GAMEMATH_H
#define GAMEMATH_H
#include <string>
using namespace std;
namespace GameMath
{
        //Функция calculateDamage  разным типами атаки
        //вариант 1: для физдамага(int)
        int calculateDamage(int attackPower, int defence);
        //вариант 2: для магдамага(float)
        float calculateDamage(float magicPower, float magicResistacne, int spellLevel);
        //варинат 3: для крита(смножетелем int)
        int calculateDamage(int attackPower, int defence, float criticalMultiplier);
        //вариант 4: для комбинации(физ+маг демедж)
        float calculateDamage(int physicalPower, int defence, float magicPower, float magicResistance);
        //рекурсия - функция, которая вызывает сама себя, ВАЖНОЕ УТОЧНЕНИЕ РЕКУРСИЯ ДОЛЖНА ИМЕТЬ УСЛОВИЕ ВЫХОДА
        
        unsigned long long factorial(int n);
        //РАсчет геомкетрической прогрессии
        float geometricSeriesSum(float first, float ratio, int terms);
        int findSkillValue(int skillTree[], int target, int currentIndex = 0);
        template <typename T>
        void swapValues(T& a, T& b);
}
//Включаем реализацию шаблонных функций(обычно это делается в .h файле)
// Для шаблонов реализация должна быть в момент компиляции кода файла

#include "GameMath.tpp"
#endif
