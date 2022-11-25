#include <stdio.h>
#define ROWS 3
#define COLUMS 3

int main()
{
    int arr[ROWS][COLUMS];

    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLUMS; j++)
            scanf("%d", &arr[i][j]);

    int magic_num = arr[0][0] + arr[0][1] + arr[0][2];

    for(int i = 0, n = 0; i < ROWS; i++, n = 0)
    {
        for(int j = 0; j < COLUMS; j++)
            n+= arr[i][j];

        if(n != magic_num)
        {
            printf("NO");
            return 0;
        }
    }

    for(int j = 0, n = 0; j < COLUMS; j++, n = 0)
    {
        for(int i = 0; i < ROWS; i++)
            n+= arr[i][j];

        if(n != magic_num)
        {
            printf("NO");
            return 0;
        }
    }

    if(arr[0][0] + arr[1][1] + arr[2][2] != magic_num || arr[0][2] + arr[1][1] + arr[2][0] != magic_num)
    {
        printf("NO");
        return 0;
    }

    printf("MAGIC");
    return 0;
}
