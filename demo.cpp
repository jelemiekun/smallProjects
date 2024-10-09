#include <iostream>

void driverTictactoe();

void fibonacci(int n) {
    int a = 0, b = 1, next;

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            std::cout << a << " ";
            continue;
        }
        if (i == 1) {
            std::cout << b << " ";
            continue;
        }
        next = a + b;
        std::cout << next << " ";
        a = b;
        b = next;
    }
    std::cout << '\n';
}

void act3() {
    int sum = 0;
    for (int i = 0; i <= 10; i++) {
        sum += i;
    }

    std::cout << "Sum total: " << sum;
}

int main() {
    //fibonacci(11);
    //act3();
    driverTictactoe();
    return EXIT_SUCCESS;
}