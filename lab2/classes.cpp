#include <iostream>
#include <memory>

using namespace std;

class ShapeCalculator {
private:
    double length, breadth, height;

public:
    ShapeCalculator() : length(0), breadth(0), height(0) {}

    void setDimensions(double l, double b = 0, double h = 0) {
        length = l;
        breadth = b;
        height = h;
    }

    double calculateSquareArea() {
        return length * length;
    }

    double calculateCubeArea() {
        return 6 * (length * length);
    }

    double calculateRectangleArea() {
        return length * breadth;
    }

    double calculateCuboidArea() {
        return 2 * ((length * breadth) + (breadth * height) + (height * length));
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "a. Square\n";
    cout << "b. Cube\n";
    cout << "c. Rectangle\n";
    cout << "d. Cuboid\n";
    cout << "e. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    char choice;
    ShapeCalculator calculator;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd') {
            double length, breadth, height;

            switch (choice) {
                case 'a':
                    cout << "Enter the side of the square: ";
                    cin >> length;
                    if (length <= 0) {
                        cout << "Invalid input. Length must be positive." << endl;
                        continue;
                    }
                    calculator.setDimensions(length);
                    cout << "Area of the square: " << calculator.calculateSquareArea() << endl;
                    break;

                case 'b':
                    cout << "Enter the side of the cube: ";
                    cin >> length;
                    if (length <= 0) {
                        cout << "Invalid input. Length must be positive." << endl;
                        continue;
                    }
                    calculator.setDimensions(length);
                    cout << "Surface area of the cube: " << calculator.calculateCubeArea() << endl;
                    break;

                case 'c':
                    cout << "Enter the length and breadth of the rectangle: ";
                    cin >> length >> breadth;
                    if (length <= 0 || breadth <= 0) {
                        cout << "Invalid input. Length and breadth must be positive." << endl;
                        continue;
                    }
                    calculator.setDimensions(length, breadth);
                    cout << "Area of the rectangle: " << calculator.calculateRectangleArea() << endl;
                    break;

                case 'd':
                    cout << "Enter the length, breadth, and height of the cuboid: ";
                    cin >> length >> breadth >> height;
                    if (length <= 0 || breadth <= 0 || height <= 0) {
                        cout << "Invalid input. Length, breadth, and height must be positive." << endl;
                        continue;
                    }
                    calculator.setDimensions(length, breadth, height);
                    cout << "Surface area of the cuboid: " << calculator.calculateCuboidArea() << endl;
                    break;

                default:
                    break;
            }
        } else if (choice != 'e') {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'e');

    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}