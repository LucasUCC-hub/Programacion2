#include <iostream>

class Cosa {
public:
    virtual void whatis() = 0;
};

class Animal : Cosa {
public:
    virtual void whatis() {std::cout << "Im an animal";}
    Dog d;
};

class Cat : Animal {
public:
    virtual void whatis() {std::cout << "Im a cat";}
};

class Dog : public Animal {
};

int main() {
    Animal *dog = new Animal();
    dog->d.whatis();

}