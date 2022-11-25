#include <stdio.h>

int is_gor(int sud[][9], int str);
int is_ver(int sud[][9], int stl);
int is_gor_row(int sud[][9], int row);
int is_ver_row(int sud[][9], int row);
int check_row(int* is_num);
int is_cube_one(int sud[][9], int l, int m);
int is_cube(int sud[][9]);

int main()
{
    int sud[9][9];

    for (int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            scanf("%d", &sud[i][j]);

    if(is_gor(sud, 9) == 0)
    {
        printf("NO");
        return 0;
    }

    if(is_ver(sud, 9) == 0)
    {
        printf("NO");
        return 0;
    }

    if(is_cube(sud) == 0)
    {
        printf("NO");
        return 0;
    }

    printf("YES");
    return 0;
}

int is_gor(int sud[][9], int str)
{
    for(int i = 0; i < str; i++)
        if(!is_gor_row(sud, i))
            return 0;

    return 1;
}

int is_gor_row(int sud[][9], int row)
{
    int is_num[9] = {0};
    for(int i = 0; i < 9; i++)
    {
        is_num[sud[i][row] - 1] = 1;
    }

    return check_row(is_num);
}

int is_ver_row(int sud[][9], int row)
{
    int is_num[9] = {0};
    for(int i = 0; i < 9; i++)
    {
        is_num[sud[row][i] - 1] = 1;
    }

    return check_row(is_num);
}

int is_ver(int sud[][9], int stl)
{
    for(int i = 0; i < stl; i++)
        if(!is_ver_row(sud, i))
            return 0;

    return 1;
}

int check_row(int* is_num)
{
    for(int i = 0; i < 9; i++)
        if(is_num[i] == 0)
            return 0;

    return 1;
}

int is_cube_one(int sud[][9], int l, int m)
{
    int is_num[9] = {0};
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            is_num[sud[i+l][j+m] - 1] = 1;

    return check_row(is_num);
}

int is_cube(int sud[][9])
{
    for(int i = 0; i < 9; i+=3)
        for(int j = 0; j < 9; j+=3)
            if(!is_cube_one(sud, i, j))
                return 0;

    return 1;
}
