/* Boundary fill algorithm to fill a triangle.
Enter the values of x and y:
240
100
Enter the value of fill: 4
Enter the value of boundary: 15
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
void boundary_fill(int, int, int, int);
void main()
{
    int gdriver = DETECT, gmode;
    int x, y, fill, boundary;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    printf("\nEnter the values of x and y:\n");
    scanf("%d%d", &x, &y);
    printf("\nEnter the value of fill: ");
    scanf("%d", &fill);
    printf("Enter the value of boundary: ");
    scanf("%d", &boundary);
    line(240, 60, 220, 120);
    line(220, 120, 260, 120);
    line(240, 60, 260, 120);
    boundary_fill(x, y, fill, boundary);
    getch();
}

void boundary_fill(int x, int y, int fill, int boundary)
{
    int current = getpixel(x, y);
    if ((current != boundary) && (current != fill))
    {
        putpixel(x, y, fill);
        boundary_fill(x + 1, y, fill, boundary);
        boundary_fill(x - 1, y, fill, boundary);
        boundary_fill(x, y + 1, fill, boundary);
        boundary_fill(x, y - 1, fill, boundary);
    }
}
