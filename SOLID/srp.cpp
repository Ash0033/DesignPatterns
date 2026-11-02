#include <iostream> 
#include <string> 
using namespace std;

class Employee {
     private: string name; double salary;
     public: Employee(string name, double salary) : name(name), salary(salary) {}

string getName() const {
    return name;
}

double getSalary() const {
    return salary;
}
};

class SalaryCalculator {
     public:
      double calculate(const Employee& employee) { return employee.getSalary(); }
};

class EmployeePrinter {
     public:
      void print(const Employee& employee) { 
        cout << "Employee: " << employee.getName() << endl; cout << "Salary: " << employee.getSalary() << endl; }
};

int main() { 
    Employee employee("Ashot", 250000);
    SalaryCalculator calculator;
    EmployeePrinter printer;

cout << "Calculated salary: "
     << calculator.calculate(employee) << endl;

printer.print(employee);

return 0;
}