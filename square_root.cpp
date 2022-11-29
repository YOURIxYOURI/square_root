#include <iostream>

using namespace std;

double sqaure_root(int number, int power, int decimal_point);
double newton_method(int number, int power);
double powerfun(double a, double n);

int main()
{
    cout << sqaure_root(125, 3, 10) << "\n"; // wynik 5
    cout << sqaure_root(25, 2, 10) << "\n"; // wynik 5
    cout << sqaure_root(500, 2, 10) << "\n"; // wynik 22 powinno byc 22.360
    cout << sqaure_root(531610, 2, 10) << "\n"; // wynik 729 powinno byc 729.115
    cout << newton_method(125, 3) << "\n"; // wynik 5
    cout << newton_method(25, 2) << "\n"; // wynik 5
    cout << newton_method(500, 2) << "\n"; // wynik 22.3607
    cout << newton_method(531610, 2) << "\n"; // wynik 822.644 powinno byc 729.115

}

//funkcja potegi
double powerfun(double a, double n) {
    double result = 1;
    for (int i = 0; i < n; i++) {
        result *= a;
    }
    return result;
}

//funkcja pierwiatkowania ktorą daje zaokrąglony wyniik bez miejsc po przecinku poniewaz nie moge uzyc funkcji pow a nie potrafie obsłużyć w potedze wykładnika ktory jest ulamkiem
// z użyciem funkcji pow funkcja działą w 100%
double sqaure_root(int number, int power, int decimal_point) {
    double x = 1;
    double check = 1;
    double y;
    double result, before_result;
    while (powerfun(x, power) <= number) {
        result = x;
        x++;
    }
    for (int i = 0; i < decimal_point; i++) {
        y = powerfun(10, -i);
        before_result = result;
        while (powerfun(before_result + y * check, power) <= number) {
            result = before_result + y * check;
            check++;
        }
    }
    return result;
}

//metoda newtona ktora moze zwracac liczbe z miejscem po przecinku ale metodta ma wyjatki ktore nie dzialają np liczba 531610 pod pierwsiatkiem kwadratowym;
double newton_method(int number, int power) {
    double result, y, z;
    for (int i = 0; i < 10; i++) {
        if (i == 0) { result = 1; }
        y = powerfun(result, power) - number;
        z = power * (powerfun(result, power - 1));
        result = result - (y / z);
    }
    return result;
}

