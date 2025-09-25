#include <iostream>
#include <nod.h>
using namespace std;

   int main() {
    int a, b;
    cout << "Введите числа: ";
    cin >> a >> b;
    
    int res = calculateNOD(a, b);
    cout << "Наименьший общий делитель: " << res<< endl;
    
    return 0;
}
