#include <iostream>

using namespace std;

float sqaure_root(int number, int power, int decimal_point);

int main()
{
    cout << sqaure_root(531610, 2, 10);
}

float sqaure_root(int number, int power, int decimal_point) {
    float x = 1;
    float check = 1;
    float y;
    float result, before_result;
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

