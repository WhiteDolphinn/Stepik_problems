#include <stdio.h>

int num_in_koeff(int j, int k);

int main()
{
   // const int SIZE = 68 * 67 / 2;

    unsigned long long koeff[68*67/2] = {};
    int num = 0;
    koeff[0] = 1;
    koeff[1] = 1;                          // k number from j строки  n = 1 + 2 + ... + j-1 + k - 1
    scanf("%d", &num);                     // n = j*(j+1) / 2 + k - 1
    for(int i = 2; i <= num; i++)
    {
        koeff[num_in_koeff(i, 1)] = 1;
        koeff[num_in_koeff(i, i+1)] = 1;

        for(int j = 2; j <= i; j++)
        {
            koeff[num_in_koeff(i, j)] = koeff[num_in_koeff(i-1, j-1)] + koeff[num_in_koeff(i-1, j)];
        }
    }
    for(int k = 1; k <= num + 1; k++)
    {
        printf("%lld ", koeff[num_in_koeff(num, k)]);
    }
}

int num_in_koeff(int j, int k)
{
    int n = j*(j+1) / 2 + k - 2;
    return n;
}

