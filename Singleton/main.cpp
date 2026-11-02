#include <iostream> 
using namespace std;

class Singleton {
     private: static Singleton* instance;
   Singleton() { cout << "Singleton object created!" << endl; }
   
   Singleton(const Singleton&) = delete;
Singleton& operator=(const Singleton&) = delete;
      public: 
    static Singleton* getInstance() { if (instance == nullptr) { instance = new Singleton(); }
    return instance;
}

void showMessage() {
    cout << "Hello from Singleton!" << endl;
}
};

Singleton* Singleton::instance = nullptr;

int main() {
             Singleton* obj1 = Singleton::getInstance();
   obj1->showMessage();

Singleton* obj2 = Singleton::getInstance();
obj2->showMessage();

if (obj1 == obj2) {
    cout << "Both objects are the same instance!" << endl;
}

return 0;
}