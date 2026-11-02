#include <iostream> 
#include <memory> 
using namespace std;

//product 
class Animal { public: virtual void sound() = 0;
virtual ~Animal() = default;
};

class Dog : public Animal {
     public: void sound() override { cout << "Dog says: Woof!" << endl; } 
};

class Cat : public Animal {
     public: void sound() override { cout << "Cat says: Meow!" << endl; } 
};

class AnimalFactory {
     public: virtual unique_ptr<Animal> createAnimal() = 0;
       virtual ~AnimalFactory() = default;
};

class DogFactory : public AnimalFactory { 
     public: unique_ptr<Animal> createAnimal() override { return make_unique<Dog>(); } 
};

class CatFactory : public AnimalFactory {
     public: unique_ptr<Animal> createAnimal() override { return make_unique<Cat>(); } 
};

int main() {
           unique_ptr<AnimalFactory> factory = make_unique<DogFactory>();
           unique_ptr<Animal> animal = factory->createAnimal();
                 animal->sound();
return 0;
}