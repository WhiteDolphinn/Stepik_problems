#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2);

int main()
{
    int n = 0;
    scanf("%d", &n);
    int* arr = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
}

int cmp(const void* p1, const void* p2)
{
    int x = *((int*)p1);
    int y = *((int*)p2);

    while(x != 0 || y != 0)
    {
        int last_x = x % 10;
        int last_y = y % 10;
        int val = (last_x > last_y) - (last_x < last_y);
        if(val != 0)
            return val;

        x /= 10;
        y /= 10;
    }
    return 0;
}
