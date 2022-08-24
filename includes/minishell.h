#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "../libs/Libft/libft.h"

typedef struct s_minishell
{
    char *line;
    char *program_name;
    char **commands;
    pid_t pid;
} t_minishell;

