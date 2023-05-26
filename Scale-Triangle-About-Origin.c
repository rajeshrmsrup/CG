/* Scale a Triangle about origin
Enter the points:
20
40
40
20
40
60
Enter scaling factor in x:
7
Enter scaling factor in y:
7
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
int main(void)
{
    int gdriver = DETECT, gmode;
    int t[3][3], x[3][3], w[3][3];
    int x1, y1, x2, y2, x3, y3, i, j, k, sx, sy;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    printf("\nEnter the points:\n");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("Enter scaling factor in x:\n");
    scanf("%d", &sx);
    printf("Enter scaling factor in y:\n");
    scanf("%d", &sy);
    printf("Before scaling\n");
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x1, y1, x3, y3);
    t[0][0] = sx;
    t[0][1] = 0;
    t[0][2] = 0;
    t[1][0] = 0;
    t[1][1] = sy;
    t[1][2] = 0;
    t[2][0] = 0;
    t[2][1] = 0;
    t[2][2] = 1;
    x[0][0] = x1;
    x[1][0] = y1;
    x[0][1] = x2;
    x[1][1] = y2;
    x[0][2] = x3;
    x[1][2] = y3;
    x[2][0] = 1;
    x[2][1] = 1;
    x[2][2] = 1;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            w[i][j] = 0;
            for (k = 0; k < 3; k++)
            {

                w[i][j] = w[i][j] + t[i][k] * x[k][j];
            }
        }
    }
    printf("After scaling");
    line(w[0][0], w[1][0], w[0][1], w[1][1]);
    line(w[0][0], w[1][0], w[0][2], w[1][2]);
    line(w[0][1], w[1][1], w[0][2], w[1][2]);
    getch();
    return (0);
}


