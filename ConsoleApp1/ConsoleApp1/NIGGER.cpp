#include  <iostream>
#include <string>
using namespace std;
int main()
{
    setlocate(LC_ALL, "Russian.UTF-8");
    
    int bronze;
    int silver;
    int gold ;
    int platinum;
    cout << "Введите кол-во бронзовых монет: " << endl;
    cin >> bronze;
    cout << "Введите кол-во серебряных монет: " << endl;
    cin >> silver;
    cout << "Введите кол-во золотых монет: " << endl;
    cin >> gold;
    cout << "Введите кол-во платиновых монет: " << endl;
    cin >> platinum;
    int sum = bronze + silver*100 + gold *1000 + platinum*10000;
    std::cout << sum << std::endl;
}