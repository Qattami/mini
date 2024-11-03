
#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int is_number_(const char *str) {
    int i = 0;

    if (str[0] == '-' || str[0] == '+') {
        i++;
    }
    for (; str[i] != '\0'; i++) {
        if (!ft_isdigit(str[i])) {
            return 0;  
        }
    }
    if (i == 0 || (i == 1 && (str[0] == '-' || str[0] == '+'))) {
        return 0;
    }
    return 1;
}

void exit_(char **args) {
    int status = 0;  
    if (args[1]) {
        if (args[2]) {
            fprintf(stderr, "exit: too many arguments\n");
            return;  
        }
        if (is_number_(args[1])) {
            status = atoi(args[1]);  
        } else {
            fprintf(stderr, "exit: %s: numeric argument required\n", args[1]);
            exit(255); 
        }
    }
    exit(status);
}
