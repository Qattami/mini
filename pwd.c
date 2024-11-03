#include "mini.h"

void    pwd_(void)
{
    char    *buf;

    buf = malloc(sizeof(char) * 4096);
    if (getcwd(buf, 4096) != NULL)
        printf("%s\n", buf);
    else
        ft_putstr_fd("getcwd: could not get the current working directory\n",
            2);
    free(buf);
}

char    *get_pwd(void)
{
    char    *buf;

    buf = malloc(sizeof(char) * 4096);
    if (getcwd(buf, 4096) != NULL)
        return (buf);
    free(buf);
    return (NULL);
}

int main()
{
    char *s1;
    s1 = NULL;
    s1 = get_pwd();
    printf("%s\n", s1);
}