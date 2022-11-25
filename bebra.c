#include <stdio.h>

long long pow(int a, int k);

int main()
{
	int k = 0, a = 2, a1 = 1;
	long long n = 0;
	scanf("%lld %d", &n, &k);
	
	while(n / pow(a, k) != 1)
	{
		while(n % pow(a, k) != 0)
		{
			a++;
			continue;
		}
		printf("%d %lld\n", a, n / pow(a, k));
		a1 *= a;
		a++;
	}
	printf("%d", a1);
	return 0;
	
}

long long pow(int a, int k)
{
	long long res = 1;
	for(int i = 0; i < k; i++)
	{
		res *= (long long)a;	
	}
	return res;
}
