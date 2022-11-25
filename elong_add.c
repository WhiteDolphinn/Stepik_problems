#include <stdio.h>
#define N 100
typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
}Decimal;

void elong_print(Decimal x);
Decimal add (Decimal x, Decimal y);

int main(){
    Decimal x = {{7, 4, 1}, 2};  // set number 147
    Decimal y = {{3, 1}, 1};     // set number 13
    Decimal res;

    res = add(x, y);             // res = x+y = 147+13 = 160
    elong_print(res);              // print 160

    return 0;
}

Decimal add (Decimal x, Decimal y)
{
    int max_n = 0;
    int min_n = 0;
    if(x.n >= y.n)
    {
        max_n = x.n;
        min_n = y.n;
    }
    else
    {
        max_n = y.n;
        min_n = x.n;
    }
    Decimal res = {{0}, max_n};

    for(int i = 0; i <= max_n; i++)
    {
        res.a[i] += (x.a[i] + y.a[i]) % 10;
        res.a[i+1] += (x.a[i] + y.a[i]) / 10;
    }

    return res;
}

void elong_print(Decimal x)
{
    for(int i = x.n; i >= 0; i--)
    {
        printf("%d", x.a[i]);
    }
    printf("\n");
}
