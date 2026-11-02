#include <iostream> 
using namespace std;

class Shape {
     public: virtual double getArea() const = 0; virtual ~Shape() = default; 
};

class Rectangle : public Shape {
     private: double width; double height;
public: Rectangle(double width, double height) : width(width), height(height) {}

double getArea() const override {
    return width * height;
}
};

class Circle : public Shape {
     private: double radius;
public: Circle(double radius) : radius(radius) {}

double getArea() const override {
    return 3.14 * radius * radius;
}
};

void printArea(const Shape& shape) { 
    cout << "Area: " << shape.getArea() << endl; 
}

int main() { 
    Rectangle rectangle(5, 4); 
    Circle circle(3);

Shape& shape1 = rectangle;
Shape& shape2 = circle;

printArea(shape1);
printArea(shape2);

return 0;
}