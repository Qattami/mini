#include "mini.h"

#include <string.h>

void print(f_env *lst)
{
	f_env *tmp;

	tmp = lst;
	while(tmp)
	{
		printf("declare -x %s", tmp->key);
		if(tmp->value)
			printf("= %s\n", tmp->value);
		tmp = tmp->next;
	}
}
// int valid_str(char *str)
// {

// }
int	strchr_idx(char *str, char character)
{
	int	i;
	i = 0;
	if (!str)  
        return -1;
	while (str[i])
	{
		if (str[i] == character)
			return (i);
		
		i++;
	}

	return (-1);
}


void export_env0(char *key, char *value, f_env *lst) {
    f_env *tmp = lst;
    f_env *tmp2 = lst;
    int key_exists = 0;

    // while (tmp) {
    //     if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0) {  
    //         free(tmp->value);
    //         tmp->value = value ? ft_strdup(value) : NULL;  
    //         key_exists = 1;
    //         break;
    //     }
    //     tmp = tmp->next;
    // }
    if (!key_exists) 
        add_token(&lst, key, value);
}

// f_env *export_env(char *str, f_env *lst)
// {
// 	int i;
// 	char *key;
// 	char *value;
// 	char c;

// 	c = '+';
// 	i = 0;
// 	i = strchr_idx(str, c);
	
// 	if(i > 0)
// 	{
// 		key  = strdupl(str, i);
// 		value = ft_strjoin(strdupl2(str, '='), lst->value);
// 	}
// 	else{
// 		if(strchr_idx(str, '=') != -1)
// 		{
// 			key  = strdupl(str, i);
// 			value = strdupl2(str, '=');
// 		}
// 	}
// 	key = ft_strdup(str);
// 	value = ft_strdup("''");
	
// 	// printf("%s = %s\n", key, value);
// 	export_env0(key, value, lst);
// 	return lst;
// }

f_env *export_env(char *str, f_env *lst) {
    int idx = strchr_idx(str, '=');
    int append_idx = strchr_idx(str, '+');
    char *key = NULL;
    char *value = NULL;
    char *new_value = NULL;
    
    if (append_idx != -1 && str[append_idx + 1] == '=') {

        key = strndup(str, append_idx);  // Get the key before '+='
        value = strdup(str + append_idx + 2);  // Get the value after '='
        f_env *tmp = lst;
        while (tmp) {
            if (strcmp(tmp->key, key) == 0 && append_idx != -1) {
                      
                new_value = ft_strjoin(tmp->value, value);
                free(tmp->value);
                tmp->value = new_value;
                free(key);
                free(value);
                break;
            }
            tmp = tmp->next;
        }
    } else if (idx != -1) {  
        key = strndup(str, idx);
        value = strdup(str + idx + 1);
    } else {  
        key = strdup(str);
        value = NULL;
    }
    export_env0(key, value, lst);
    return lst;
}



int main(int ac, char **av, char **env) {
    if (ac > 2) { 
        f_env *lst = NULL;
        lst = loop_env(env); 
        lst = export_env(av[2], lst);
        print(lst);  
    } else {
        printf("Usage: ./a.out <env_var>\n");
    }
    return 0;
}

