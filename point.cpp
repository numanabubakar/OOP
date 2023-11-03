#include <iostream>
using namespace std;
class Point
{
protected:
    int x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x2, int y2)
    {
        x = x2;
        y = y2;
    }
    ~Point()
    {
        x = 0;
        y = 0;
    }
    void set(int x2, int y2)
    {
        x = x2;
        y = y2;
    }
    void setx(int x2)
    {
        x = x2;
    }
    void sety(int y2)
    {
        y = y2;
    }
    void display()
    {
        cout << "x coordinate is :" << x << endl;
        cout << "y coordinate is :" << y << endl;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
};

class threeDPoints : public Point
{
    int z;

public:
    threeDPoints(int x2, int y2, int z2) : Point(x2, y2)
    {
        z = z2;
    }

    void setz(int z2)
    {
        z = z2;
    }
    void set(int x2, int y2, int z2)
    {
        x = x2;
        y = y2;
        z = z2;
    }
    int getz()
    {
        return z;
    }
    void display()
    {
        cout << "x coordinate is :" << x << endl;
        cout << "y coordinate is :" << y << endl;
        cout << "z coordinate is :" << z << endl;
    }
};

int main()
{

    Point p1(2, 5), p2(0, 0), p3(7, 4);

    p1.display();
    p2.display();
    p3.display();

    p2.set(5, 8);
    p3.sety(9);
    p2.display();
    p3.display();

    threeDPoints TP1(7, 2, 4), TP2(0, 0, 0);
    TP1.display();
    TP2.display();

    TP1.set(3, 1, 7);
    TP1.display();

    return 0;
}