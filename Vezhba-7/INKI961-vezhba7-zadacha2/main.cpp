#include <iostream>
#include <cmath>

using namespace std;

class operations
{
//declaring member variables
public:
    int num1, num2;
//defining member function or methods
public:
    void input()
    {
        cout << "Enter two numbers to perform operations on: \n";
        cin >> num1 >> num2;
        cout << "\n";

    }
public:
    void addition()
    {
        cout << "Addition = " << num1 + num2;
        cout << "\n";
    }
    void subtraction()
    {
        cout << "Subtraction = " << num1 - num2;
        cout << "\n";
    }
    void multiplication()
    {
        cout << "Multiplication = " << num1 * num2;
        cout << "\n";
    }
    void division()
    {
        cout << "Division = " << (float) num1 / num2;
        cout << "\n";
    }

    void power()
    {
        cout << "Power = " << (float) pow(num1, num2);
        cout << "\n";
    }

    void exponential()
    {
        cout << "Exponential = " << (float)exp(num1 + num2);
        cout << "\n";
    }
};
//Defining the main method to access the members of the class
int main()
{
    cout << " ===== Program to perform basic operations using Class, in CPP ===== \n\n";
    operations op;

    cout << "\nCalling the input() function from the main() method\n";
    op.input();

    cout << "\nCalling the addition() function from the main() method\n";
    op.addition();

    cout << "\nCalling the subtraction() function from the main() method\n";
    op.subtraction();

    cout << "\nCalling the multiplication() function from the main() method\n";
    op.multiplication();

    cout << "\nCalling the division() function from the main() method\n";
    op.division();

    cout << "\nCalling the power() function from the main() method\n";
    op.power();

    cout << "\nCalling the exponential () function from the main() method\n";
    op.exponential();

    cout << "\nExiting the main() method\n\n\n";

    return 0;
}
