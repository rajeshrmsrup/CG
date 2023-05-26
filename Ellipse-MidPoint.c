/* Ellipse using midpoint ellipse generation algorithm.
Enter the center points for ellipse:
100
100

Enter the half of major and minor axis:
40
20
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
int main(void)
{
    int gdriver = DETECT, gmode;
    float a, b, x, y, p, q, xc, yc;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    printf("\nEnter the center points for ellipse:\n");
    scanf("%f%f", &xc, &yc);
    printf("\nEnter the half of major and minor axis:\n");
    scanf("%f%f", &a, &b);
    x = 0;
    y = b;
    p = (b * b) + (a * a) / 4 - a * a * b;
    while ((2 * b * b * x) < (2 * a * a * y))
    {
        if (p < 0)
        {
            x = x + 1;
            y = y;
            p = p + (2 * b * b * x) + b * b;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + (2 * b * b * x) - (2 * a * a * y) + b * b;
        }
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }

    q = (b * b) * (x + 0.5) * (x + 0.5) + ((a * a) * (y - 1) * (y - 1)) - (a * a) * (b * b);
    while (y >= 0)
    {
        if (q < 0)
        {
            x = x + 1;
            y = y - 1;
            q = q + (2 * b * b * x) - (2 * a * a * y) + a * a;
        }
        else
        {
            x = x;
            y = y - 1;
            q = q + (a * a) - (2 * a * a * y);
        }
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
    }
    getch();
    return (0);
}

