#include <iostream> 
using namespace std;
//products
class Chair {
     public: 
     virtual void create() = 0; virtual ~Chair() = default; 
};
class Sofa {
     public: 
     virtual void create() = 0; virtual ~Sofa() = default; 
};

class ModernChair : public Chair {
     public: void create() override { 
        cout << "Modern Chair created\n" ; 
        } 
};

class ModernSofa : public Sofa {
     public: void create() override {
         cout << "Modern Sofa created\n" ; 
         } 
};

class VictorianChair : public Chair {
     public: void create() override {
         cout << "Victorian Chair created\n" ; 
         }
};
class VictorianSofa : public Sofa {
     public: void create() override {
         cout << "Victorian Sofa created\n" ; 
         } 
};

class FurnitureFactory {
     public: 
      virtual Chair* createChair() = 0; 
      virtual Sofa* createSofa() = 0;
      virtual ~FurnitureFactory() = default;
};

class ModernFactory : public FurnitureFactory {
     public: 
     Chair* createChair() override { return new ModernChair(); }
     Sofa* createSofa() override {
 return new ModernSofa();
}
};

class VictorianFactory : public FurnitureFactory {
     public: Chair* createChair() override { return new VictorianChair(); }
             Sofa* createSofa() override {
 return new VictorianSofa();
}
};

int main() {
          FurnitureFactory* factory = new ModernFactory();

        Chair* chair = factory->createChair();
        Sofa* sofa = factory->createSofa();

    chair->create();
    sofa->create();

delete chair;
delete sofa;
delete factory;

return 0;
}