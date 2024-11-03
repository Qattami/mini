#ifndef MINISHELL
#define MINISHELL

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#define pipe 1
#define input 2
#define output 3
#define heredoc 4
#define redirection 5
#define squote 6
#define dquote 7
#define word 8
#define command 9
 
typedef struct f_env
{
    char *line;
    char *key;
    char *value;
    struct f_env *next;
} f_env;

typedef struct s_export {
    char *key;         
    char *value; 
    struct s_export *next; 
} t_export;




// char put_prompt();
// int sd_quotes(char *line);
// char    ft_strdup(const chars);
// int    count_word(char const str, char charset);
// char    **ft_split(charstr);
// void ft_free(char str);
// // void add_token(t_parse head, char content, int type);
// int cmp(charsplit);
// t_parse split_line(charline);
f_env *loop_env(char **env);
void print(f_env *lst);
void add_token(f_env **head, char *content, char *type);


//libft
void	ft_putstr_fd(char *s, int fd);
char	*strdupl(const char *s, int i);
char	*strdupl2(char *s, char c);
char	*ft_strrchr(const char *str, int character);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int ft_strlen(char *s);
char	*ft_strdup(const char *s);
#endif