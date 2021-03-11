#include "Box.hpp"

int main()
{
    Box b1;
    b1.SetDimensions(5, 10, 15);

    cout << "Box has " << b1.GetWidth() << " - " << b1.GetHight() << " - " << b1.GetDepth() << endl;

    Box b2(20, 15, 80);

    cout << "Box has " << b2.GetWidth() << " - " << b2.GetHight() << " - " << b2.GetDepth() << endl;
    return 0;
}