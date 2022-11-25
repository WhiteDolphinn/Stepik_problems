#include <stdio.h>
#include <string.h>

int main()
{
    char str[30];
    int x = 0, y = 0;

    scanf("%9s", str);
    while(strcmp(str, "Treasure!") != 0)
    {
        int i = 0;
        scanf("%d", &i);

        if(strcmp(str, "North") == 0)
            y += i;

        if(strcmp(str, "South") == 0)
            y -= i;

        if(strcmp(str, "East") == 0)
            x += i;

        if(strcmp(str, "West") == 0)
            x -= i;

        i = 0;
        scanf("%9s", str);
    }

    printf("%d %d", x, y);
    return 0;
}
