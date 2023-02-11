#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

int cmp_Point(const void * p1, const void * p2);

int main()
{
    int n = 0;
    scanf("%d ", &n);
    struct Point* point_arr = (struct Point*)calloc(n, sizeof(struct Point));

    for(int i = 0; i < n; i++)
        scanf("%d%d", &point_arr[i].x, &point_arr[i].y);

    qsort(point_arr, n, sizeof(struct Point), cmp_Point);

    for(int i = 0; i < n; i++)
        printf("%d %d\n", point_arr[i].x, point_arr[i].y);

    free(point_arr);
    return 0;
}

int cmp_Point(const void * p1, const void * p2)
{
    struct Point point1 = *((struct Point*)p1);
    struct Point point2 = *((struct Point*)p2);

    int s1 = point1.x * point1.x + point1.y * point1.y;
    int s2 = point2.x * point2.x + point2.y * point2.y;

    if(s1 > s2)
        return 1;

    if(s1 < s2)
        return -1;
    //s1 == s2
    if(point1.x > point2.x)
        return 1;

    if(point1.x < point2.x)
        return -1;
    //x1 == x2
    if(point1.y > point2.y)
        return 1;
    if(point1.y < point2.y)
        return -1;

    return 0;
}
