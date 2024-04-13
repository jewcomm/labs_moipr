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

double norma(vector v){
    return (std::sqrt(pow(v.x1, 2) + pow(v.x2, 2)));
}

int main(){
    // step 1
    int k = 0;
    double x1_0 = 0.5;
    double x2_0 = 1;

    double x1_k = 0;
    double x2_k = 0;
    
    double e = 0.01;

    while(1){
        printf("\nШаг(k) = %i ; x1_%i = %f ; x2_%i = %f\n", k, k, x1_0, k, x2_0);
        // step 2
        vector vecK = {x1_0, x2_0};
        printf("Вычислим значение градиента в заданной точке (%f, %f)\n", gradient(vecK).x1, gradient(vecK).x2);
        printf("Норма вектора = %f\nСравнивним норму с е1\n", norma(gradient(vecK)));
        // step 3
        if (norma(gradient(vecK)) < e){
            printf("Условие выполнено. Расчет закончен\n");
            return 0;
        }
        printf("Норма вектора больше е\n");

        // step 4
        double step = 0.5;

        while (1)
        {
            printf("Зададим величину шага t = %f\n", step);
            // step 5
            x1_k = (x1_0 - (step * (gradient(vecK).x1)));
            x2_k = (x2_0 - (step * (gradient(vecK).x2)));
            printf("Вычислим x%i\nx1_%i = %f\nx2_%i = %f\n", k, k, x1_k, k, x2_k);
            printf("Сравним f(x%i) и f(x%i): ", k, k-1);
            // step 6
            if(f({x1_k, x2_k}) - f({x1_0, x2_0}) < 0) {
                printf("f(x%i) меньше f(x%i)\n", k, k-1);
                // step 7
                break;
            }
            printf("f(x%i) больше f(x%i). t делим на 2\n", k, k-1);
            // go to step 5
            step = step/2;
        }

        // step 7
        printf("Проверим выполнение условия || x%i - x%i || < e и |f(x%i) - f(x%i)| < e: ", k, k-1, k, k-1);
        if(norma({x1_k - x1_0, x2_k - x2_0}) < e && fabs(f({x1_k, x2_k}) - f({x1_0, x2_0}))){
            printf("Оба условия выполнены\n");
            break;
        } 
        // go to step 2        
        x1_0 = x1_k;
        x2_0 = x2_k;
        k = k + 1;
    }
    printf("Ответ:\nK = %i\nx1 = %f\nx2 = %f\nf(x1, x2) = %f\n", k, x1_k, x2_k, f({x1_k, x2_k}));
}