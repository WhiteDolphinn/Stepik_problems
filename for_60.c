#include <stdio.h>

int kolvo_num(unsigned int k);
int how_many_d(int k, int d, int count);

int main()
{
    unsigned int k = 0;
    int d = 0, count_k = 0, num = 0;
    scanf("%d %u", &d, &k);
    count_k = kolvo_num(k);
    num = how_many_d(k, d, count_k);

    printf("%d %u %d", d, k, num);
    return 0;
}

int kolvo_num(unsigned int k)
{
    int i = 1;
    for (i; k / 10 != 0; i++)
        k /= 10;

    return i;
}

int how_many_d(int k, int d, int count)
{
    int num = 0;

    for(int i = 1; i <= count; i++)
    {
        if(k % 10 == d)
            num++;

        k /= 10;
    }
    return num;
}
