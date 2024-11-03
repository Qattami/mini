#include <stdio.h>
#include <string.h>

int new_line(char *str)
{
    int i;

    i = 2;
    if(str[0] == '-' && str[1] == 'n')
    while(str[i])
    {
        if(str[i] != 'n')
            return 0;
        i++;
    }
    return 1;
}

void echo_(char **av)
{
    int newline;
    int i;

    newline = 0;
    i = 2;
    if(av[2] && new_line(av[2]))
    {
        newline = 1;
        i++;
    }
    while(av[i])
    {
        put_str_fd(av[i]);
        write(1, " ", 1);
        i++;
    }
    if(!newline)
        write(1, "\n", 1);
}

