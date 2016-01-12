#include <iostream>
#include <fstream>

/* in data.in first line is the number of holes, the second line  contains the dimensions of the board and next are the holes coordinates
FORMAT X(width) and Y(height); the center of the axsis is top left.
*/

using namespace std;

struct maxim
{
    int x;
    int y;
    int a;
    int h;
    int w;
};
maxim m;

int  *gx, *gy, n;

void holes(int w, int h, int coordx, int coordy)
{
    bool sw = true;
    for (int i = 0; i < n; i++)
    {
        if(gx[i] > coordx && gx[i] < coordx + w && gy[i] > coordy && gy[i] < coordy + h)
        {
            sw = false;
            holes(gx[i] - coordx, h, coordx, coordy);
            holes(coordx + w - gx[i], h, coordx + gx[i], coordy);
            holes(w, gy[i] - coordy, coordx, coordy);
            holes(w, coordy + h - gy[i], coordx, gy[i]);

        }
    }
    if (w * h > m.a && sw)
    {
        m.x = coordx;
        m.y = coordy;
        m.a = w * h;
        m.h = h;
        m.w = w;
    }
}



int main(int argc, char const *argv[])
{
    m.a = 0;
    ifstream f("data.in");
    int height, width;
    f >> n >> width >> height;
    gx = new int[n];
    gy = new int[n];
    for (int i = 0; i < n; i++)
        f >> gx[i] >> gy[i];
    holes(width, height, 0, 0);
    cout << "X: " << m.x << "; Y: " << m.y << ";\narea: " << m.a << "\nH: " << m.h << "\nW: " << m.w << "\n";

    return 0;
}
