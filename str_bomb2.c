#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    fgets(str, 100, stdin);
    if(strstr(str, "bomb") == NULL)
        printf("NO");
    else
        printf("YES");

    return 0;
}
