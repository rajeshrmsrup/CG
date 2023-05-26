/* Rotate a Triangle (clockwise direction)
Enter the values of triangle:
90
100
60
150
120
150
Enter the degree of rotation:
30
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#define pi 3.14
int main(void)
{
    float t[3][3], r[3][3], o[3][3];
    float x1, x2, x3, y1, y2, y3, d, i, j, k;
    float a;
    int gdriver = DETECT, gmode;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    printf("\nEnter the values of triangle:\n");
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("\nEnter the degree of rotation:\n");
    scanf("%f", &d);
    a = d * (pi / 180);
    printf("%f", a);
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
    r[0][0] = cos(a);
    r[0][1] = sin(a);
    r[0][2] = 0;
    r[1][0] = sin(-a);
    r[1][1] = cos(a);
    r[1][2] = 0;
    r[2][0] = 0;
    r[2][1] = 0;
    r[2][2] = 1;
    o[0][0] = x1;
    o[0][1] = x2;
    o[0][2] = x3;
    o[1][0] = y1;
    o[1][1] = y2;
    o[1][2] = y3;
    o[2][0] = 1;
    o[2][1] = 1;
    o[2][2] = 1;
    printf("\nAfter rotating in clockwise direction\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            t[i][j] = 0;

            for (k = 0; k < 3; k++)
            {
                t[i][j] = t[i][j] + r[i][k] * o[k][j];
            }
            printf("%f \t", t[i][j]);
        }
        printf("\n");
    }
    line(t[0][0], t[1][0], t[0][1], t[1][1]);
    line(t[0][0], t[1][0], t[0][2], t[1][2]);
    line(t[0][1], t[1][1], t[0][2], t[1][2]);
    getch();
    return (0);
}
