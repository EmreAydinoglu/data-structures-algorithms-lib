#include <iostream>
using namespace std;

class CalcuClass {
public:
    double summation(double array[], int n) {
        double s = 0;
        for (int i = 0; i < n; i++) {
            s += array[i];
        }
        return s;
    }

    double multiply(double array[], int n) {
        double product = 1;
        for (int i = 0; i < n; i++) {
            product *= array[i];
        }
        return product;
    }

    double division(double array[], int n) {
        if (n == 0) return 0;
        double result = array[0];
        for (int i = 1; i < n; i++) {
            if (array[i] == 0) {
                cout << "Error: Division by zero!" << endl;
                return 0;
            }
            result /= array[i];
        }
        return result;
    }

    double subtract(double array[], int n) {
        if (n == 0) return 0;
        double result = array[0];
        for (int i = 1; i < n; i++) {
            result -= array[i];
        }
        return result;
    }
};

int main() {
    int n, choice;

    cout << "\n===========================================" << endl;
    cout << "=============== By (Your Name) ==============" << endl;
    cout << "Advisor: Dr. Mohammed Al-hubaishi" << endl;
    cout << "~~ WELCOME to Data Structure Algorithms Program ~~" << endl;
    cout << "===========================================\n" << endl;

    cout << "Select or Enter Your Choice from the Menu:" << endl;
    cout << "1. + Summation and print the results" << endl;
    cout << "2. * Multiply and print the results" << endl;
    cout << "3. / Division and print the results" << endl;
    cout << "4. - Subtract and print the results" << endl;
    cout << "5. Exit" << endl;
    cout << "=======================================================\n";

    cout << "Enter the number of elements: ";
    cin >> n;

    double* numbers = new double[n];
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    CalcuClass calculator;

    do {
        cout << "\n===========================================" << endl;
        cout << "=============== By (Your Name) ==============" << endl;
        cout << "Advisor: Dr. Mohammed Al-hubaishi" << endl;
        cout << "~~ WELCOME to Data Structure Algorithms Program ~~" << endl;
        cout << "===========================================\n" << endl;
        cout << "Select or Enter Your Choice from the Menu:" << endl;
        cout << "1. + Summation and print the results" << endl;
        cout << "2. * Multiply and print the results" << endl;
        cout << "3. / Division and print the results" << endl;
        cout << "4. - Subtract and print the results" << endl;
        cout << "5. Exit" << endl;
        cout << "=======================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Summation = " << calculator.summation(numbers, n) << endl;
                break;
            case 2:
                cout << "Multiplication = " << calculator.multiply(numbers, n) << endl;
                break;
            case 3:
                cout << "Division = " << calculator.division(numbers, n) << endl;
                break;
            case 4:
                cout << "Subtraction = " << calculator.subtract(numbers, n) << endl;
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
    delete[] numbers;
    return 0;
}
