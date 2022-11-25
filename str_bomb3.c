#include <stdio.h>
#include <string.h>
#include <ctype.h>

void string_to_lower(char* str);

int main()
{
    char str[100];
    fgets(str, 100, stdin);
    string_to_lower(str);

    if(strstr(str, "bomb") == NULL)
        printf("NO");
    else
        printf("YES");

    return 0;
}

void string_to_lower(char* str)
{
    for(int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}
