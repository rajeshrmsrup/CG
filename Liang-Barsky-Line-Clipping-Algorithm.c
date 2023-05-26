/* Liang-Barsky line clipping algorithm.
Enter the windows left xmin, top boundary ymin:
0
0
Enter the windows right xmax, bottom boundary ymax:
100
100
Enter line: x1, y1 coordinates:
0
0
Enter line: x2,y2 coordinates:
200
150
*/
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
void main()
{
    int gdriver = DETECT, gmode;
    int x1, x2, y1, y2;
    int wxmin, wymin, wxmax, wymax;
    float u1 = 0.0, u2 = 1.0;
    int p1, q1, p2, q2, p3, q3, p4, q4;
    float r1, r2, r3, r4;
    int x11, y11, x22, y22;
    clrscr();
    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    printf("\nEnter the windows left xmin, top boundary ymin:\n");
    scanf("%d%d", &wxmin, &wymin);
    printf("\nEnter the windows right xmax, bottom boundary ymax:\n");
    scanf("%d%d", &wxmax, &wymax);
    printf("\nEnter line: x1, y1 coordinates:\n");
    scanf("%d%d", &x1, &y1);
    printf("\nEnter line: x2,y2 coordinates:\n");
    scanf("%d%d", &x2, &y2);
    printf("\nLiang barsky express these 4 inequalities using lpk=qr\n");
    p1 = -(x2 - x1);
    q1 = x1 - wxmin;
    p2 = (x2 - x1);
    q2 = wxmax - x1;
    p3 = -(y2 - y1);
    q3 = y1 - wymin;
    p4 = (y2 - y1);
    q4 = wymax - y1;
    printf("\n p1=0 line is parallel to left clipping \n");
    printf("\n p2=0 line is parallel to right clipping \n");
    printf("\n p3=0 line is parallel to bottom clipping \n");
    printf("\n p4=0 line is parallel to top clipping \n");
    if (((p1 == 0.0) && (q1 < 0.0)) || ((p2 == 0.0) && (q2 < 0.0)) || ((p3 == 0.0) && (q3 < 0.0)) || ((p4 == 0.0) && (q4 < 0.0)))
    {
        printf("\n Line is rejected:");
        getch();
        detectgraph(&gdriver, &gmode);
        initgraph(&gdriver, &gmode, " ");
        setcolor(RED);
        rectangle(wxmin, wymax, wxmax, wymin);

        setcolor(BLUE);
        line(x1, y1, x2, y2);
        getch();
        setcolor(WHITE);
        line(x1, y1, x2, y2);
        getch();
    }
    else
    {
        if (p1 != 0.0)
        {
            r1 = (float)q1 / p1;
            if (p1 < 0)
                u1 = max(r1, u1);
            else
                u2 = min(r1, u2);
        }
        if (p2 != 0.0)
        {
            r2 = (float)q2 / p2;
            if (p2 < 0)
                u1 = max(r2, u1);
            else
                u2 = min(r2, u2);
        }
        if (p3 != 0.0)
        {
            r3 = (float)q3 / p3;
            if (p3 < 0)
                u1 = max(r3, u1);
            else
                u2 = min(r3, u2);
        }
        if (p4 != 0.0)
        {
            r4 = (float)q4 / p4;
            if (p4 < 0)
                u1 = max(r4, u1);
            else
                u2 = min(r4, u2);
        }
        if (u1 > u2)
            printf("\n line rejected:");
        else
        {
            x11 = x1 + u1 * (x2 - x1);
            y11 = y1 + u1 * (y2 - y1);

            x22 = x1 + u2 * (x2 - x1);
            y22 = y1 + u2 * (y2 - y1);
            printf("\n original line coordinates\n");
            printf("\n x1=%d y1=%d x2=%d y2=%d\n", x1, y1, x2, y2);
            printf("\n windows coordinates are:\n");
            printf("\n wxmin=%d,wymin=%d,wxmax=%d,wymax=%d", wxmin, wymin, wxmax, wymax);
            printf("\n new coordinates are ;\n");
            printf("\n x1=%d,y1=%d,x2=%d,y2=%d\n", x11, y11, x22, y22);
            detectgraph(&gdriver, &gmode);
            initgraph(&gdriver, &gmode, "");
            setcolor(2);
            rectangle(wxmin, wymax, wxmax, wymin);
            setcolor(1);
            line(x1, y1, x2, y2);
            getch();
            setcolor(0);
            line(x1, y1, x2, y2);
            setcolor(3);
            line(x11, y11, x22, y22);
            getch();
        }
    }
}
