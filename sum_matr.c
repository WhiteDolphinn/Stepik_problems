#include <stdio.h>

void sum(int rows, int cols, int a[10][10], int b[10][10], int c[10][10]);

int main()
{
    int a[10][10], b[10][10], c[10][10];

    int n = 0, m = 0;
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);

    sum(n, m, a, b, c);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d ", c[i][j]);

        printf("\n");
    }
    return 0;
}


void sum(int rows, int cols, int a[10][10], int b[10][10], int c[10][10])
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            c[i][j] = a[i][j] + b[i][j];
}
