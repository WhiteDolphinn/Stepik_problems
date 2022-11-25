#include <stdio.h>

int main()
{
	int per[50] = {}, num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int p = 0, q = 0, t =0, a = 0, ost = 0; // a,t(per[])
	scanf("%d%d", &p, &q);
	a = p/q;
	p = p - a * q;
	for(int i = 0; i < 50, i++)
	{
		p = p * 10;
		per[i] = p / q;
		p = p % q;
		for(int j = 0; j < i; j++)
		{
			if
		}
	}
}

