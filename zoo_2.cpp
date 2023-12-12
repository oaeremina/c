#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal {
public:
    Animal(string name, int age) : name_(name), age_(age) {}
    void eat() {
        cout << name_ << " ест." << endl;
    }

    void sleep() {
        cout << name_ << " спит." << endl;
    }

    virtual void move() {
        cout << name_ << " двигается." << endl;
    }

    string name_;
    int age_;
    };


class Fish : public Animal {
public:
    Fish(string name, int age, bool saltwater) : Animal(name, age), saltwater_(saltwater) {}

    void swim() {
        cout << name_ << " плавает." << endl;
    }
    void move() override {
        cout << name_ << " двигается." << endl;
    }
    bool saltwater_;
};

class Cat : public Animal {
public:
    Cat(string name, int age, bool black) : Animal(name, age), black_(black) {}

    void meow() {
        cout << "Котик мяукает: meow meow!" << endl;
    }
    void move() override{
        cout << name_<< " царапает медель(" << endl;
    }
    bool black_;
};


class Bird : public Animal {
public:
    Bird(string name, int age, bool canSwim) : Animal(name, age), canSwim_(canSwim) {}
     
    void sing() {
    cout << "Птица поет!" << endl;
    }
    void move() override {
        cout << name_ << " летает." << endl;
    }
    bool canSwim_;
};


void addAnimal(vector<Animal*>& animals) {
    string name;
    int age;
    char type;

    cout << "Введите имя животного: ";
    cin >> name;

    cout << "Введите возраст животного: ";
    cin >> age;

    cout << "Выберите: (F - Рыба, C - кошка, B - птица): ";
    cin >> type;

    if (type == 'F') {
        bool saltwater;
        cout << "Это морская рыба (Y/N)? ";
        char salt;
        cin >> salt;
        saltwater = (salt == 'Y');
        animals.push_back(new Fish(name, age, saltwater));
    }
    else if (type == 'B') {
        bool canSwim;
        cout << "Птица умеет плавать (Y/N)? ";
        char swim;
        cin >> swim;
        canSwim = (swim == 'Y');
        animals.push_back(new Bird(name, age, canSwim));
    }
    else if (type == 'C') {
        bool black;
        cout << "Кошка черная (Y/N)? ";
        char color;
        cin >> color;
        black = (color == 'Y');
        animals.push_back(new Cat(name, age, black));
    }
    else {
        cout << "Такого животного нет." << endl;
    }
}
int main() {
    vector<Animal*> animals;
    animals.push_back(new Fish("Рыба-клоун", 1, true));
    animals.push_back(new Bird("Пингвин", 3, false));
    animals.push_back(new Cat("Леопард", 6, true));

    addAnimal(animals);
    addAnimal(animals);
    addAnimal(animals);

    for (Animal* animal : animals) {
        animal->eat();
        animal->sleep();
        animal->move();

        Fish* fish = dynamic_cast<Fish*>(animal);
        if (fish != nullptr) {
            fish->swim();
        }

        Cat* cat = dynamic_cast<Cat*>(animal);
        if (cat != nullptr) {
            cat->meow();
            if (cat->black_) {
                cout << cat->name_ << " - черная." << endl;
            }
            else {
                cout << cat->name_ << " не черная." << endl;
            }
        }

        Bird* bird = dynamic_cast<Bird*>(animal);
        if (bird != nullptr) {
            bird->sing();
        }
        cout << endl;
    }

    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}