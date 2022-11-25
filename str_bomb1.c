#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];

    while(scanf("%s", str) == 1)
        if(strcmp(str, "bomb") == 0)
        {
            printf("YES");
            return 0;
        }


    printf("NO");
    return 0;
}
