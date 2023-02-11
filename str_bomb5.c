#include <stdio.h>
#include <string.h>

int main()
{
    const char* bomb = "bomb";
    const char* watermelon = "watermelon";
    char str[1000];
     char str2[1000] = {};

    //fgets(str, 1000, stdin);
    while(scanf("%s", str) == 1)
    {
        char* ptr1 = str;
        char* ptr2 = strstr(str, bomb);
        int sch = 0;

        while(ptr2 != NULL)
        {
            sch += ptr2 - ptr1;
            int n = ptr2 - ptr1;
            //printf("%s %d\n", ptr1, n);
        //  printf("%d ", n);
            strncat(str2, ptr1, n);
            //printf("%s\n", str2);
            str2[sch] = '\0';
            strcat(str2, watermelon);
            ptr1 = ptr2 + strlen(bomb);
            ptr2 = strstr(ptr1, bomb);
        //  printf("%s\n\n", str2);
            sch += strlen(watermelon);
        }
            strcat(str2, ptr1);

        printf("%s", str2);
    }
    return 0;
}
