#include <stdio.h>
#define SIZE 10000

int main()
{
    //long long timestamp[SIZE] = {};
    int id[SIZE] = {};
    int is_id[SIZE] = {0};
  //  long long recept_id[SIZE] = {};
    int n = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        static long long buffer = 0;
        scanf("%lld", &buffer);
        scanf("%d", id + i);
        scanf("%lld", &buffer);
        if(is_id[id[i]] == 0)
            is_id[id[i]] = 1;
    }

    int res = 0;
    for(int i = 0; i < SIZE; i++)
        if(is_id[i] == 1)
            res++;

    printf("%d", res);

    return 0;
}
