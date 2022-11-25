#include <stdio.h>
#include <math.h>
#define SIZE 256

void is_prime(char* prime, const int size);

int main()
{
    char prime[SIZE] = {0}, numbers[SIZE] = {0};
    int n = 0;
    is_prime(prime, SIZE);

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", numbers + i);

    for(int i = 0; i < n; i++)
        if(prime[numbers[i]] == 0)
            printf("%d ", numbers[i]);


    /*for(int i = 0; i < SIZE; i++)
    printf("%d ", prime[i]);*/

    return 0;
}

void is_prime(char* prime, const int size)
{
    prime[0] = -1;
    prime[1] = -1;

    for(int i = 2; i < sqrt(size); i++)
    {
        for(int j = i*i; j < size; j += i )
            prime[j] = 1;
    }
}
