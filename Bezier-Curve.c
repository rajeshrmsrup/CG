/*
Enter the x and y coordinates for the four control points:
x1 and y1 are:
100
100
x2 and y2 are:
200
200
x3 and y3 are:
300
100
x4 and y4 are:
400
200
*/

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void bezier(int x[4], int y[4])
{
    int gd = DETECT, gm, i;
    double u;
    clrscr();
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    setcolor(15);
    outtextxy(400, 400, "-> Control Points");
    outtextxy(400, 430, "-> Polygon");
    outtextxy(400, 460, "-> Bezier Curve");
    setcolor(RED);
    setfillstyle(1, RED);
    circle(390, 400, 5);
    floodfill(390, 400, RED);
    setcolor(YELLOW);
    setfillstyle(1, YELLOW);
    circle(390, 430, 5);
    floodfill(390, 430, YELLOW);
    setcolor(WHITE);
    setfillstyle(1, WHITE);
    circle(390, 460, 5);
    floodfill(390, 460, WHITE);
    delay(10);
    for (u = 0.0; u < 1.0; u += 0.0002)
    {
        double xu = pow(1 - u, 3) * x[0] + 3 * u * pow(1 - u, 2) * x[1] + 3 * pow(u, 2) * (1 - u) * x[2] + pow(u, 3) * x[3];
        double yu = pow(1 - u, 3) * y[0] + 3 * u * pow(1 - u, 2) * y[1] + 3 * pow(u, 2) * (1 - u) * y[2] + pow(u, 3) * y[3];
        putpixel(xu, yu, WHITE);
        delay(1);
    }

    for (i = 0; i < 4; i++)
    {
        setcolor(RED);
        setfillstyle(1, RED);
        circle(x[i], y[i], 4);
        floodfill(x[i], y[i], RED);
        delay(1);
    }

    for (i = 0; i < 3; i++)
    {
        setcolor(YELLOW);
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
}

void main()
{
    int x[4], y[4], i;
    clrscr();
    printf("\n\n====Bezier Curve====\n\n");
    printf("Enter the x and y coordinates for the four control points:\n");
    for (i = 0; i < 4; i++)
    {
        printf("x%d and y%d are :\n", i + 1, i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }
    bezier(x, y);
    getch();
    closegraph();
}

