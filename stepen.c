#include <stdio.h>
#include <math.h>

int main()
{
    long long n = 0;
    int k = 0, osn = 1;
    scanf("%lld%d", &n, &k);
    const int n0 = n;

    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % (int)pow(i, k) == 0)
        {
            osn *= i;
            n /= pow(i, k);
            printf("%d %lld\n", i, n);
            i = 1;
        }
    }
    if(pow(osn, k) != n0)
        osn = -1;
    printf("%d", osn);
}
