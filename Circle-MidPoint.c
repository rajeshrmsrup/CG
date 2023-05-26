/* Circle using Mid Point
Enter the value of x, y and radius:
200
200
100
*/

#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
int main(void)
{
    int gdriver = DETECT, gmode;
    int x, y, r, p, xc, yc;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    printf("Enter the value of x, y and radius:\n");
    scanf("%d%d%d", &xc, &yc, &r);
    p = 1 - r;
    x = 0;
    y = r;
    do
    {
        if (p < 0)
        {
            x = x + 1;
            y = y;
            p = p + (2 * x) + 1;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + (2 * x) - (2 * y) + 1;
        }
        putpixel(xc + x, yc + y, 5);
        putpixel(xc - y, yc - x, 5);
        putpixel(xc + y, yc - x, 5);
        putpixel(xc - y, yc + x, 5);
        putpixel(xc + y, yc + x, 5);
        putpixel(xc - x, yc - y, 5);
        putpixel(xc + x, yc - y, 5);
        putpixel(xc - x, yc + y, 5);
    } while (x <= y);
    getch();
    return (0);
}
