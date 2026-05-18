#ifndef GAMMATH_TPP
#define GAMMATH_TPP

template <typename T>
void GameMath:: swapValues(T& a, T& b)
{
    T temp = a;//Копируем значение, которое храниться по адресу указанному в ссылке
    a = b;
    b = temp;
    //ПАМЯТЬЖ: temp уничтожаетcя при выходе из функции
}