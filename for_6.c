#include <stdio.h>
#include <stdlib.h>

int main()
{
    char d;
    scanf("%c", &d);
    char str[999];
    fgets(str, 999, stdin);
    int num = 0;
    for(int i = 0; *(str + i) != '\0'; i++)
    {
        if(*(str + i) == d)
            num++;
    }

    printf("%c", d);
    for(int i = 0; *(str + i + 1) != '\0'; i++)
        putchar(*(str + i));
    printf(" %d", num);
}
