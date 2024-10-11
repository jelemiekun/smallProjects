#include <iostream>

class Entity {
private:
    std::string name;
public:
    Entity() {
        std::cout << "Entity created!";
    }

    ~Entity() {
        std::cout << "Entity destroyed!";
    }
};

class ScopedPtr {
private:
    Entity* e;
public:
    ScopedPtr(Entity* ePtr) : e(ePtr) {}

    ~ScopedPtr() {
        std::cout << "ScopedPtr deleted!";
        delete e;
    }
};

int main() {
    {
         ScopedPtr e = new Entity();
    }

    int a = 50;
    std::cout << '\n';
    a = 50;
    std::cout << a;

    return EXIT_SUCCESS;
}