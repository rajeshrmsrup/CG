/* Flood fill algorithm to fill a circle.
Enter the values of x and y:
200
200
Enter the value of new color: 6
Enter the value of old color: 0
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
void flood_fill(int, int, int, int);
void main()
{
    int gdriver = DETECT, gmode;
    int x, y, newcolor, oldcolor;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    printf("\nEnter the values of x and y:\n");
    scanf("%d%d", &x, &y);
    printf("\nEnter the value of new color: ");
    scanf("%d", &newcolor);
    printf("Enter the value of old color: ");
    scanf("%d", &oldcolor);
    circle(200, 200, 30);
    flood_fill(x, y, newcolor, oldcolor);
    getch();
}

void flood_fill(int x, int y, int newcolor, int oldcolor)
{
    int current = getpixel(x, y);
    if (current == oldcolor)
    {
        putpixel(x, y, newcolor);
        flood_fill(x + 1, y, newcolor, oldcolor);
        flood_fill(x - 1, y, newcolor, oldcolor);
        flood_fill(x, y + 1, newcolor, oldcolor);
        flood_fill(x, y - 1, newcolor, oldcolor);
    }
}
