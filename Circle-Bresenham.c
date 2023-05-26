/*Circle using Bresenham
Enter the center of the circle::
200
200
Enter the radius of the circle:
100
*/
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
int main(void)
{
    int xc, yc, x, y, r, p;
    int gdriver = DETECT, gmode;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    printf("Enter the center of the circle:\n");
    scanf("%d%d", &xc, &yc);
    printf("Enter the radius of the circle:\n");
    scanf("%d", &r);
    p = 3 - 2 * r;
    x = 0;
    y = r;
    do
    {
        if (p < 0)
        {
            x = x + 1;
            y = y;
            p = p + 4 * x + 1;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 4 * x - 4 * y + 1;
        }
        putpixel(xc + x, yc + y, 1);
        putpixel(xc - y, yc - x, 2);
        putpixel(xc + y, yc - x, 3);
        putpixel(xc - y, yc + x, 4);
        putpixel(xc + y, yc + x, 5);
        putpixel(xc - x, yc - y, 6);
        putpixel(xc + x, yc - y, 7);
        putpixel(xc - x, yc + y, 8);
    } while (x <= y);
    getch();
    return (0);
}

