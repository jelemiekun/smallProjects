#include <iostream>
#include "header.h"

void practice() {
    unsigned int meow = 'A';
    std::cout << meow << '\n';
}

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

void printMeow();

void drivers() {
    //fibonacci(11);
    //act3();
    practice();
    printMeow();
}

void ethan() {
    int a = 1;
    int b = 2;
    int c = 0;

    c = a + b;
    do {
        a = a + 2;
        c = c + a;
        std::cout << c << " ";
        b = b + 2;
        c = c + b;
        std::cout << c << " ";
    } while (b != 10);

    std::cout << "c = " << c << '\n';
}

struct Vector2 {
    float x;
    float y;

    Vector2(const float &r_x, const float &r_y) : x(r_x), y(r_y) {};

    Vector2 operator*(const Vector2 &r_other) {
        return Vector2(x * r_other.x, y * r_other.y);
    }

    void operator-() {
        std::cout << "Random! AJSKLDASDSA" << '\n';
    }
};

void vector() {
    Vector2 position(0.5F, 2.5F);
    Vector2 speed(1.40F, 2.60F);
    Vector2 result = position * speed;
    std::cout << "Result: " << result.x << " : " << result.y << '\n';
    -result;
}

int main() {
    int random = 50;
    const int* a = new int;

    a = &random;
    

    std::cout << *a;

    return EXIT_SUCCESS;
}