#include <iostream>
#include <cmath>

using namespace std;

class Rectangle
{
protected:
    float width, height;

public:
    Rectangle(float w, float h) : width(w), height(h) {}

    float perimeter()
    {
        return (2 * (width + height));
    }

    float area()
    {
        return width * height;
    }
};

class Triangle
{
protected:
    float width, height;

public:
    Triangle(float w, float h) : width(w), height(h) {}

    float area()
    {
        return (width * height / 2);
    }

    float perimeter()
    {
        return (width + height + sqrt(width*width + height*height));
    }


protected:
    float calculateHypotenuse()
    {
        return sqrt(width*width + height*height);
    }
};

class HypotenuseTriangle : public Triangle
{
private:
    float hypotenuse;

public:
    HypotenuseTriangle(float w, float h) : Triangle(w, h)
    {
        hypotenuse = calculateHypotenuse();
    }


    float getHypotenuse()
    {
        return hypotenuse;
    }
};

int main()
{
    float heightR, widthR, heightT, widthT;

    cout << "Enter height and width for the rectangle: ";
    cin >> heightR >> widthR;

    Rectangle rectangle(widthR, heightR);
    cout << "Perimeter of the rectangle is: " << rectangle.perimeter() << endl;
    cout << "Area of the rectangle is: " << rectangle.area() << endl;

    cout << "Enter height and width for the right-angled triangle: ";
    cin >> heightT >> widthT;

    Triangle triangle(widthT, heightT);
    cout << "Area of the right-angled triangle is: " << triangle.area() << endl;
    cout << "Perimeter of the right-angled triangle is: " << triangle.perimeter() << endl;

    HypotenuseTriangle hypotenuseTriangle(widthT, heightT);
    cout << "Hypotenuse of the right-angled triangle is: " << hypotenuseTriangle.getHypotenuse() << endl;

    return 0;
}
