#include <stdio.h>
#include <stdlib.h>

#define N 1000

char * replace (const char * src);

int main()
{
    char s[N];   // нужно объявить переменную - место для читаемой строки
    char * d;    // указатель на динамический массив, память еще не выделена

    while (NULL != fgets(s, N, stdin)) {  // пока можем прочитать строку
        d = replace(s);                   // тут память выделяем
        printf("+++%s+++\n", d);
        free(d);                          // тут память освобождаем
    }
    return 0;
}

char * replace (const char * src)
{

}
