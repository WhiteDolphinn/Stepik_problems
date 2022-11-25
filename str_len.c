#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    size_t max_len = 0;
    char str[100];
    char max_str[100];

    while(scanf("%s", str) == 1)
    {
        if(strlen(str) > max_len)
        {
            strcpy(max_str, str);
          //  printf("max_str = <%s>\n", max_str);
            max_len = strlen(str);
        }
    }
    printf("\n%s %ld\n", max_str, max_len);
}


