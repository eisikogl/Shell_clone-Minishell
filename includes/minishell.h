#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "../libs/libft/libft.h"

typedef struct s_minishell
{
    char *line;
    char *clean_line;
    char *program_name;
    char **commands;
    int word_count;
    pid_t pid;
} t_minishell;

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;
