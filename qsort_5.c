#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1, const void* p2);

int main()
{
   /* int n = 0;
    scanf("%d", &n);*/
    int n = 1000;
    char* arr = (char*)calloc(n, sizeof(char));

    n = 0;
  /*  fread(arr, sizeof(char), n, stdin);
    n = strlen(arr);*/
    for(int i = 0; i < 1000; i++)
    {
        scanf("%c", &arr[i]);
        if(arr[i] == '.')
            break;
        //printf("arr[i] = %c\n", arr[i]);
        n++;
    }
    arr = (char*)realloc(arr, n);
    qsort(arr, n, sizeof(char), cmp);

    for(int i = 0; i < n; i++)
        printf("%c", arr[i]);

    printf(".");
    free(arr);
}

int cmp(const void* p1, const void* p2)
{
    char x = *((char*)p1);
    char y = *((char*)p2);
    return ((x > y) - (x < y));
}
