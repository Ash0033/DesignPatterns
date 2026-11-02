#include <iostream> 
using namespace std;
class Payment {
     public: virtual void pay(double amount) = 0; virtual ~Payment() = default; 
};

class CardPayment : public Payment {
     public: void pay(double amount) override { cout << "Paid " << amount << " AMD by Card" << endl; } 
};

class CashPayment : public Payment {
     public: void pay(double amount) override { cout << "Paid " << amount << " AMD by Cash" << endl; } 
};

class PayPalPayment : public Payment {
     public: void pay(double amount) override { cout << "Paid " << amount << " AMD by PayPal" << endl; } 
};

class PaymentProcessor {
     public: void process(Payment& payment, double amount) { payment.pay(amount); } 
};

int main() { 
    PaymentProcessor processor;
CardPayment card;
CashPayment cash;
PayPalPayment paypal;

processor.process(card, 15000);
processor.process(cash, 10000);
processor.process(paypal, 20000);

return 0;
}