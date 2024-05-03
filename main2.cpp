#include <iostream>

// Pure abstract class
class Shape {
public:
    // Pure virtual function makes the class abstract
    virtual void draw() const = 0;

    // Non-pure virtual function
    virtual void displayArea() const {
        std::cout << "Area is not defined for this shape." << std::endl;
    }

    // Virtual destructor (good practice for a base class with virtual functions)
    virtual ~Shape() {
        std::cout << "Shape destructor called." << std::endl;
    }
};

// Concrete class derived from the pure abstract class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override the pure virtual function
    void draw() const override {
        std::cout << "Drawing a circle with radius " << radius << std::endl;
    }

    // Override the non-pure virtual function
    void displayArea() const override {
        double area = 3.14 * radius * radius;
        std::cout << "Area of the circle: " << area << std::endl;
    }

    // Destructor
    ~Circle() override {
        std::cout << "Circle destructor called." << std::endl;
    }
};

int main() {
    // Attempting to create an object of the abstract class (will result in a compilation error)
    // Shape shape; // This line will cause a compilation error

    // Creating an object of the derived class
    Circle circle(5.0);

    // Calling virtual functions through the base class pointer
    Shape* shapePtr = &circle;
    shapePtr->draw();
    shapePtr->displayArea();

    return 0;
}
