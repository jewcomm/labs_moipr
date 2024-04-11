#include <iostream>
#include <cmath> // Для использования функций sin и cos

struct vector
{
    double x1;
    double x2;
};

// Функция, которую нужно минимизировать
double f(vector v) {
    return (2*pow(v.x1, 2) + v.x1 * v.x2 + pow(v.x2, 2));
}

// Градиент функции 
vector gradient(vector v) {
    return vector{(4 * v.x1) + v.x2, v.x1 + (2 * v.x2)};
}

int main() {
    vector x_init{0.5, 1}; // Начальные значения
    const double stepSize = 0.01; // Размер шага
    int maxIterations = 1000; // Максимальное количество итераций
    double epsilon = 0.01; // Значение, которое будет считаться минимальным
    double currentValue = f(x_init); // Текущее значение функции

    for (int i = 0; i < maxIterations; ++i) {
        vector grad = gradient(x_init); // Вычисляем градиент функции по x
        x_init.x1 -= stepSize * grad.x1; // Делаем шаг в направлении градиента по x
        x_init.x2 -= stepSize * grad.x2; // Делаем шаг в направлении градиента по y
        currentValue = f(x_init); // Обновляем текущее значение функции

        if (currentValue < epsilon) {
            epsilon = currentValue; // Если нашли лучшее значение, сохраняем его
        } else {
            break; // Если значение стало хуже, прерываем цикл
        }
    }

    std::cout << "Минимальное значение функции: " << epsilon << std::endl;
    std::cout << "Значения переменных x и y, при которых достигается минимум: " << x_init.x1 << " " << x_init.x2 << std::endl;

    return 0;
}