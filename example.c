#include <stdio.h>

int rusDel(int a, int b);

int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	printf("%d", rusDel(a, b));
	return 0;
}

int rusDel(int a, int b)
{
	static int res = 1;
	
	if(a == 0)
	{
		
		printf("1\n");
		return a;
	}
	
	if(a != 0)
	{
		if(a % 2 == 0)
		{
			int mult = 2;
			int rem = 0;
			a = a/2;
			if(a != 0)
				printf("%d %d %d\n",a, mult, rem);
			res = rusDel(a, b);
			if (res != 0)
				printf("%d * %d + %d = %d\n", res, mult, rem, res*mult+rem);
			res = res * mult + rem;
		}
		else
		{
			int mult = 1;
			int rem = 1;
			a = a - b;
			if(a != 0)
				printf("%d %d %d\n",a, mult, rem);
			res = rusDel(a, b);
			if(res != 0)
				printf("%d * %d + %d = %d\n", res, mult, rem, res*mult+rem);
			res = res * mult + rem;
		}
	}
	return res;
}

