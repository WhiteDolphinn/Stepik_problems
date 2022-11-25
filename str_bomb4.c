#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int n = 0;

    while(scanf("%s", str) == 1)
    {
        if(strstr(str, "bomb") != NULL)
            n++
    }
    printf("%d", n);
    return 0;
}
