#include <iostream>
#include <cmath>
using namespace std;

int add(int* x, int* y)
{
    int* a = x;
    int* b = y;
    return *a + *b;
}

int subtract(int* x, int* y)
{
    int* a = x;
    int* b = y;
    return *a - *b;
}

float divide(int* x, int* y)
{
    int* a = x;
    int* b = y;
    return static_cast<float> (*a) / *b;
}

double power(int* x, int* y)
{
    int* a = x;
    int* b = y;
    return pow(*a, *b);
}

void calulation1(void* x, void* y, int (*operation)(int*, int*))
{
    int* a = static_cast<int*>(x);
    int* b = static_cast<int*>(y);
    int rezultat = static_cast<int>(operation(a, b));
    cout << *a << " + " << *b << " = " << rezultat << endl;
}
void calulation2(void* x, void* y, int (*operation)(int*, int*))
{
    int* a = static_cast<int*>(x);
    int* b = static_cast<int*>(y);
    int rezultat = static_cast<int>(operation(a, b));
    cout << *a << " - " << *b << " = " << rezultat << endl;
}
void calulation3(void* x, void* y, double (*operation)(int*, int*))
{
    int* a = static_cast<int*>(x);
    int* b = static_cast<int*>(y);
    double rezultat = static_cast<double>(operation(a, b));
    cout << *a << " ^ " << *b << " = " << rezultat << endl;
}
void calulation4(void* x, void* y, float (*operation)(int*, int*))
{
    int* a = static_cast<int*>(x);
    int* b = static_cast<int*>(y);
    float rezultat = static_cast<float>(operation(a, b));
    cout << *a << " : " << *b << " = " << rezultat << endl;
}
int main()
{
    int n = static_cast<int>('N');
    int I = static_cast<int>('H');

    cout << "ASCII codes for characters 'N' and 'i': " << n << " and " << I << endl;

    int (*operation1)(int*, int*);
    operation1 = &add;
    calulation1(&n, &I, operation1);

    int (*operation2)(int*, int*);
    operation2 = &subtract;
    calulation2(&n, &I, operation2);

    double (*operation3)(int*, int*);
    operation3 = &power;
    calulation3(&n, &I, operation3);

    float (*operation4)(int*, int*);
    operation4 = &divide;
    calulation4(&n, &I, operation4);
    return 0;
}
