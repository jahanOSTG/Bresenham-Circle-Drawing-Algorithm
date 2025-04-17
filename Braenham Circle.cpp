#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 3 - 2 * r; // Bresenham decision parameter

    // Draw initial 8 symmetric points
    while (x <= y) {
        // 8 symmetric points
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;

        if (p < 0) {
            p = p + 4 * x + 6;
        } else {
            y--;
            p = p + 4 * (x - y) + 10;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    int xc, yc, r;
    cout << "Enter center point (xc yc): ";
    cin >> xc >> yc;

    cout << "Enter radius r: ";
    cin >> r;

    drawCircle(xc, yc, r); // Call the function to draw circle

    getch();    // Wait for a key press
    closegraph(); // Close graphics window
    return 0;
}

