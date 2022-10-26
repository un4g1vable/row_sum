#include <iostream>
#include <cmath>
using namespace std;


long double factorial(int N)
{
    if(N < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (N == 0) // если пользователь ввел ноль,
        return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
    else // Во всех остальных случаях
        return N * factorial(N - 1); // делаем рекурсию.
}

double formula (double x, int n) {
    double res = (pow((-1),(n+1)) * pow(x,(2*n-1)))/(pow(3,(n-1))*factorial(2*n-1));
    return res;
}
// ^ функция, считающая дробь по заданной формуле

int main() {
    setlocale(0, "");
    int n = 1;
    double x, epsilon, current, previous;
    double sum = 0;
    cout << "введите значение x: ";
    cin >> x;
    cout << "введите эпсилон: ";
    cin >> epsilon;
    current = formula(x,n); // записываем в current значение при n=1
    sum += current; // записываем в сумму ряда
    n++; // n = 2
    
    
    do {
        previous = current;
        current = formula(x,n);
        sum += current;
        n++;
    } while (abs(current-previous)>epsilon); //пока |an — an-1| > ε выполняется - цикл работает
    
    cout << "сумма ряда равна: " << sum << endl;
    
}
