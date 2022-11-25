#include <stdio.h>

void number_mult(int k, int rows, int colums, int arr[][colums]);

int main()
{
    int rows = 0, colums = 0;
    scanf("%d", &rows);
    scanf("%d", &colums);
    int arr[rows][colums];

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < colums; j++)
            scanf("%d", &arr[i][j]);

    int k = 0;
    scanf("%d", &k);

    number_mult(k, rows, colums, arr);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < colums; j++)
            printf("%d ", arr[i][j]);

        printf("\n");
    }

    return 0;
}

void number_mult(int k, int rows, int colums, int arr[][colums])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
           /* int* pos = (int*)(arr + i);
            pos += j;
            *pos *= k;
            printf("%d ", *pos);*/
            arr[i][j] *= k;
           // printf("%d", arr[i][j]);
        }
       // printf("\n");
    }
}
