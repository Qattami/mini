


int    is_valid(char *s)
{
    int    i;

    i = 0;
    if (!s[0])
        return (0);
    while (s[i])
    {
        if (ft_isspace(s[i]))
            return (0);
        i++;
    }
    return (1);
}

