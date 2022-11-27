#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2);

int main()
{
    int n = 0;
    scanf("%d", &n);
    float* arr = calloc(n, sizeof(float));

    for(int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    qsort(arr, n, sizeof(float), cmp);

    for(int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    free(arr);
}

int cmp(const void* p1, const void* p2)
{
    float x = *((float*)p1);
    float y = *((float*)p2);
    return ((x > y) - (x < y));
}
