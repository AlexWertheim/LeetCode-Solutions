#include <iostream>
#include <cmath>

int rectArea(int x1, int x2, int y1, int y2)
{
    return (x2 - x1) * (y2 - y1);
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area1 = rectArea(ax1, ax2, ay1, ay2);
    int area2 = rectArea(bx1, bx2, by1, by2);
    if (ax2 <= bx1 || bx2 <= ax1 || ay2 <= by1 || by2 <= ay1)
    {
        return area1 + area2;
    }
    int x1 = max(ax1, bx1);
    int x2 = min(ax2, bx2);
    int y1 = max(ay1, by1);
    int y2 = min(ay2, by2);
    // cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
    int interArea = rectArea(x1, x2, y1, y2);
    // cout << area1 << endl << area2 << endl << interArea << endl;
    return (area1 - interArea) + area2;
}

int main()
{
    return 0;
}