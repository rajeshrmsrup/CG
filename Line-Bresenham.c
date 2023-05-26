/*Line using Bresenham
Enter the values of x1 and y1:
100
100
Enter the values of x1 and y2:
250
250
*/
#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
int main(void)
{
    int gdriver = DETECT, gmode;
    int x1, x2, y1, y2, dx, dy, p, x, y;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    printf("Enter the value of x1 and y1:\n");
    scanf("%d%d", &x1, &y1);
    printf("Enter the value of x2 and y2:\n");
    scanf("%d%d", &x2, &y2);
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 * dy - dx;
    x = x1;
    y = y1;
    putpixel(x, y, WHITE);
    while (x <= x2)
    {
        if (p < 0)
        {
            x = x + 1;
            y = y;
            p = p + 2 * dy;
        }
        else
        {
            x = x + 1;
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        putpixel(x, y, WHITE);
    }
    getch();
    return (0);
}

