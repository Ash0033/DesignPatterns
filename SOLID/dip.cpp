#include <iostream> 
#include <string> 
using namespace std;

class INotification {
     public: virtual void send(const string& message) = 0; virtual ~INotification() = default; 
};

class EmailNotification : public INotification {
     public: void send(const string& message) override { cout << "Email: " << message << endl; } 
};

class SMSNotification : public INotification {
     public: void send(const string& message) override { cout << "SMS: " << message << endl; } 
};

class NotificationService {
     private: INotification& notification;
public: NotificationService(INotification& notification) : notification(notification) {}
void sendMessage(const string& message) {
    notification.send(message);
}
};
int main() { 
    EmailNotification email; 
    SMSNotification sms;

NotificationService emailService(email);
NotificationService smsService(sms);

emailService.sendMessage("Order confirmed!");
smsService.sendMessage("Payment successful!");

return 0;
}