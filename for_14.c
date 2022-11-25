#include <stdio.h>

int main()
{
    const int  SIZE = 500;
    int into = 0, right = 1;
    char str[SIZE];
    scanf("%s", str);
    for(int i = 0; *(str + i) != '\0'; i++)
    {
        if(*(str + i) == '(')
            into++;

        if(*(str + i) == ')')
            into--;
        if(into < 0)
        {
            right = 0;
            break;
        }
    }
    if(right == 0 || into != 0)
        printf("NO");
    else
        printf("YES");
}
