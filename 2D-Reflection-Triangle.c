
/* 2D Reflection of a Triangle.
Enter the points:
90
100
60
150
120
150

---Press---
1. x-axis
2. y-axis
3. y=x
4. y=-x
Enter your choice: 1
Reflection about x-axis
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
int main(void)
{
    int a[3][3], b[3][3], c[3][3];
    int ch, x1, y1, x2, y2, x3, y3, i, j, k, x, y, p, q;
    int gdriver = DETECT, gmode;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    x = getmaxx() / 2;
    y = getmaxy() / 2;
    p = getmaxx();
    q = getmaxy();
    line(0, y, p, y);
    line(x, 0, x, q);
    printf("\nEnter the points:\n");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    line(x + x1, y - y1, x + x2, y - y2);
    line(x + x1, y - y1, x + x3, y - y3);
    line(x + x2, y - y2, x + x3, y - y3);
    b[0][0] = x1;
    b[0][1] = x2;
    b[0][2] = x3;
    b[1][0] = y1;
    b[1][1] = y2;
    b[1][2] = y3;
    b[2][0] = 1;
    b[2][1] = 1;
    b[2][2] = 1;
    printf("\n---Press---\n 1. x-axis \n 2. y-axis \n 3. y=x \n 4. y=-x");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nReflection about x-axis");
        a[0][0] = 1;
        a[0][1] = 0;
        a[0][2] = 0;
        a[1][0] = 0;
        a[1][1] = -1;
        a[1][2] = 0;
        a[2][0] = 0;
        a[2][1] = 0;

        a[2][2] = 1;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < 3; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        line((c[0][0] + x), (y - c[1][0]), (x + c[0][1]), (y - c[1][1]));
        line((x + c[0][0]), (y - c[1][0]), (x + c[0][2]), (y - c[1][2]));
        line((x + c[0][1]), (y - c[1][1]), (x + c[0][2]), (y - c[1][2]));
        break;
    case 2:
        printf("\nReflection about y-axis");
        a[0][0] = -1;
        a[0][1] = 0;
        a[0][2] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
        a[1][2] = 0;
        a[2][0] = 0;
        a[2][1] = 0;
        a[2][2] = 1;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < 3; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        line((c[0][0] + x), (y - c[1][0]), (x + c[0][1]), (y - c[1][1]));
        line((x + c[0][0]), (y - c[1][0]), (x + c[0][2]), (y - c[1][2]));
        line((x + c[0][1]), (y - c[1][1]), (x + c[0][2]), (y - c[1][2]));
        break;
    case 3:
        printf("\nReflection about y=x");
        a[0][0] = 0;
        a[0][1] = 1;
        a[0][2] = 0;

        a[1][0] = 1;
        a[1][1] = 0;
        a[1][2] = 0;
        a[2][0] = 0;
        a[2][1] = 0;
        a[2][2] = 1;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < 3; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        line((c[0][0] + x), (y - c[1][0]), (x + c[0][1]), (y - c[1][1]));
        line((x + c[0][0]), (y - c[1][0]), (x + c[0][2]), (y - c[1][2]));
        line((x + c[0][1]), (y - c[1][1]), (x + c[0][2]), (y - c[1][2]));
        break;
    case 4:
        printf("\nReflection about y=-x");
        a[0][0] = 0;
        a[0][1] = -1;
        a[0][2] = 0;
        a[1][0] = -1;
        a[1][1] = 0;
        a[1][2] = 0;
        a[2][0] = 0;
        a[2][1] = 0;
        a[2][2] = 1;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < 3; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        line((c[0][0] + x), (y - c[1][0]), (x + c[0][1]), (y - c[1][1]));
        line((x + c[0][0]), (y - c[1][0]), (x + c[0][2]), (y - c[1][2]));
        line((x + c[0][1]), (y - c[1][1]), (x + c[0][2]), (y - c[1][2]));
        break;

    default:
        printf("\n wrong choice\n");
    }
    getch();
    return (0);
}
