
#include <iostream>
#include <algorithm>

using namespace std;

// Лямбда-функция для проверки, является ли число составным
auto is_composite = [](int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return true;
    }
    return false;
};

int main() {
    int n;
    cout << "enter number: ";
    cin >> n;

    // Находим два составных числа, разность которых равна n
    int a, b;

    // Используем цикл для перебора чисел
    int it = n + 2; // Начинаем с n + 2
    while (true) {
        // Если число it является составным
        if (is_composite(it)) {
            // Проверяем, является ли число it - n составным
            if (is_composite(it - n)) {
                a = it;
                b = it - n;
                break;
            }
        }
        // Переходим к следующему числу
        ++it;
    }

    cout <<"number one: " << a << " \tnumber two: " << b << endl;

    return 0;
}
