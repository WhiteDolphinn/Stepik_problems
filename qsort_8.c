#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

int cmp_Point(const void * p1, const void * p2);

int main()
{
    struct Point a, b;
    scanf("%d%d", &a.x, &a.y);
    scanf("%d%d", &b.x, &b.y);

    int res = cmp_Point(&a, &b);

    if (res < 0)
        printf("<\n");
    else if (res > 0)
        printf(">\n");
    else
        printf("=\n");

    return 0;
}

int cmp_Point(const void * p1, const void * p2)
{
    struct Point point1 = *((struct Point*)p1);
    struct Point point2 = *((struct Point*)p2);

    int s1 = point1.x * point1.x + point1.y * point1.y;
    int s2 = point2.x * point2.x + point2.y * point2.y;

    return (s1 > s2) - (s1 < s2);
}
