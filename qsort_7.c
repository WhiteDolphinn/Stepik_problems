#include <stdio.h>
#include <stdlib.h>

#define POISON 0xEDA

int cmp(const void* p1, const void* p2);

int main()
{
    int n = 0;
    scanf("%d", &n);
    int* arr = (int*)calloc(n, sizeof(int));
    int* arr_ch = (int*)calloc(n, sizeof(int));
    int* arr_nech = (int*)calloc(2*n, sizeof(int));

    for(int i = 0; i < 2*n; i++)
        arr_nech[i] = POISON;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int cur_ch = 0, cur_nech = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 1)
        {
        arr_nech[cur_nech++] = arr[i];
        arr_nech[cur_nech++] = i;
        }
        else
        {
        arr_ch[cur_ch++] = arr[i];
        }
    }
   /* for(int i = 0; i < cur_nech; i++)
        printf("%d ", arr_nech[i]);

    printf("\n");

    for(int i = 0; i < cur_ch; i++)
        printf("%d ", arr_ch[i]);

    printf("\n");*/


    if(cur_ch != 0)
        qsort(arr_ch, cur_ch, sizeof(int), cmp);

    /*for(int i = 0; i < 3; i++)
        printf("%d ", arr_ch[i]);
        printf("\n");*/

    cur_nech = 1;
    cur_ch = 0;
    int is_last = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr_nech[2*cur_nech - 1] == i && is_last == 0)
        {
            printf("%d ", arr_nech[2*cur_nech - 2]);
            if(cur_nech < n)
                cur_nech++;
            else
                is_last = 1;
        }
        else
            printf("%d ", arr_ch[cur_ch++]);
    }

    free(arr);
    free(arr_ch);
    free(arr_nech);
}

int cmp(const void* p1, const void* p2)
{
    int* px = (int*)p1;
    int* py = (int*)p2;

    return (*px > *py) - (*px < *py);
}
