/*Line using DDA
Enter the values of x1 and y1:
00
00
Enter the values of x1 and y2:
100
100
*/
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(void)
{
    int gdriver = DETECT, gmode;
    int x1, x2, y1, y2;
    float a, b;
    int i = 1, dx, dy, steps;
    float x, y;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    printf("Enter the values of x1 and y1:\n");
    scanf("%d%d", &x1, &y1);
    printf("Enter the values of x2 and y2:\n");
    scanf("%d%d", &x2, &y2);
    dx = abs(x2 - x1);
    printf("dx=%d", dx);
    dy = abs(y2 - y1);
    printf("dy=%d", dy);
    if (dx > dy)
    {
        steps = dx;
    }
    else
    {
        steps = dy;
    }
    printf("no.of steps=%d", steps);
    x = dx / steps;
    y = dy / steps;
    while (i <= steps)
    {
        a = a + x;
        b = b + y;
        putpixel(a, b, RED);
        i++;
    }
    getch();
    return (0);
}
