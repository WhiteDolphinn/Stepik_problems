#include <stdio.h>
#include <string.h>

int main()
{
    const char* bomb = "bomb";
    char str[1000];
     char str2[1000];

    fgets(str, 1000, stdin);

    char* ptr = strstr(str, bomb);
    strncpy(str2, str, ptr-str-1);
    strcat(str2, "watermelon");
    ptr += strlen("bomb");
    strcat(str2, ptr);

    printf("%s", str2);

    return 0;
}
