
#include "mini.h"
f_env	*ft_lstnew(char *s1, char *s2)
{
	f_env	*node;

	node = (f_env *)malloc(sizeof(f_env));
	if (node == NULL)
		return (NULL);
	node->key = ft_strdup(s1);
	if(!s2)
		node->value = NULL;
	else
    	node->value = ft_strdup(s2);
	node->next = NULL;
	return (node);
}

f_env	*ft_lstlast(f_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(f_env **lst, f_env *new)
{
	f_env	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	tmp = *lst;
	if (tmp)
	{
		tmp = ft_lstlast(tmp);
		tmp->next = new;
	}
	else
		*lst = new;
}

void add_token(f_env **head, char *content, char *type)
{
    f_env *new_node = ft_lstnew(content, type);
    if (!new_node)
        return;
    if (!head && !(*head))
        *head = new_node  ; 
    else
    {
       ft_lstadd_back(head, new_node);
    }
}
void fill_env(f_env **lst, char *str)
{
	char *s1 = NULL;
	char *s2 = NULL;
	int i ;
	int j;
	
	i = 0;
	j = 0;

	while(str[i] != '=')
		i++;
	s1 = malloc((sizeof(char) * i) + 1);
	s2 = malloc(sizeof(char) * ft_strlen(str) - i);
    i = 0;
	while(str[i] != '=')
	{
		s1[i] = str[i];
		i++;
	}
	s1[i++] = '\0';
	while(str[i])
		s2[j++] = str[i++];
	s2[j] = '\0';
    add_token(lst, s1, s2);
	free(s1);
	free(s2);
}


f_env *loop_env(char **env) {
    int i = 0;
    f_env *lst = NULL;

    while (env[i])
        fill_env(&lst, env[i++]);

    return lst;
}
