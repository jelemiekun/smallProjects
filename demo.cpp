#include <iostream>
#include <ctime>

class point {
private:
    clock_t timer ;

public:
    point() {
        std::cout << "timer starting..." << '\n';
        timer = clock();
    }

    ~point() {
        clock_t end_time = clock();
        double elapsed_time = static_cast<double>(end_time - timer) / CLOCKS_PER_SEC;
        std::cout << "time elapsed: " << elapsed_time << '\n';
    }

    clock_t getTimer() const {
        return timer;
    }
};

int main() {
    point* e = new point();
    int i = 10;

    while (i > 0) {
        clock_t current_time = clock();
        if ((current_time - e->getTimer()) % 1000 == 0) {
            std::cout << i << '\n';
            i--;
        }
    }
    delete e;

    return EXIT_SUCCESS;
}