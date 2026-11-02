#include <iostream> 
#include <string> 
using namespace std;

//հիմնական ինտերֆեյսը 
class IPayment { public: 
                    virtual void pay(double amount) = 0;

                virtual ~IPayment() = default;
};

// Արտաքին վճարման համակարգ/այս class-ը չենք փոփոխում
class ForeignPayment { 
    public: void makeTransaction(double amount, string currency) {
        cout << "Transaction: " << amount << " " << currency << endl; } 
};

class PaymentAdapter : public IPayment { 
    private: ForeignPayment foreignPayment;
    public: void pay(double amount) override { 
        foreignPayment.makeTransaction(amount, "AMD"); 
        } 
};

int main() {
        
        IPayment* payment = new PaymentAdapter();
        payment->pay(15000);

delete payment;

return 0;
}