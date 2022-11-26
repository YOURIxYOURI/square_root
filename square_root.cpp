#include <iostream>

using namespace std;

double sqaure_root(int number, int power, int decimal_point);
double newton_method(int number, int power);

int main()
{
    //cout << sqaure_root(531610, 2, 10);
    cout << newton_method(500, 2);
}

double sqaure_root(int number, int power, int decimal_point) {
    double x = 1;
    double check = 1;
    double y;
    double result, before_result;
    while (pow(x, power) <= number) {
        result = x;
        x++;
    }
    for (int i = 0; i < decimal_point; i++) {
        y = pow(10, -i);
        before_result = result;
        while (pow(before_result + y * check, power) <= number) {
            result = before_result + y * check;
            check++;
        }
    }
    return result;
}

double newton_method(int number, int power) {
    double result, y, z;
    for (int i = 0; i < 10; i++) {
        if (i == 0) { result = 1; }
        y = pow(result, power) - number;
        z = power * (pow(result, power - 1));
        result = result - (y / z);
    }
    return result;
}



