#include <iostream> 
using namespace std;

class IPrinter {
     public: virtual void print() = 0; virtual ~IPrinter() = default; 
};

class IScanner {
     public: virtual void scan() = 0; virtual ~IScanner() = default; 
};

class SimplePrinter : public IPrinter {
     public: void print() override { cout << "Printing document..." << endl; } 
};

class AdvancedPrinter : public IPrinter, public IScanner {
     public: void print() override { cout << "Printing document..." << endl; }
void scan() override {
    cout << "Scanning document..." << endl;
}
};

int main() { 
    SimplePrinter printer; 
    AdvancedPrinter advancedPrinter;

printer.print();

advancedPrinter.print();
advancedPrinter.scan();

return 0;
}