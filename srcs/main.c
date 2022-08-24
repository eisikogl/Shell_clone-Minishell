#include "../includes/minishell.h"

void ignore_all_spaces(char *str, int *i)
{
    while ((str[*i] == 32) || (str[*i] >= 9 && str[*i] <= 13))
        (*i)++;
}

char *commands(char *str)
{
    return NULL;
}

char *ma_parser(char *str, t_minishell minishell)
{
    int i = 0;

    ignore_all_spaces(str, &i);

    while (str[i])
    {
        if(str[i] == '"')
            i++;
        if (str[i] == '|' || str[i] == '<' || str[i] == '>' || str[i] == '<<' || str[i + 1] == ">>")
        {
            // if (str[i + 1] == )
        }
        if (ft_isalpha(str[i]))
        {

        }
        // if (!ft_substr(str, i, 2), "cd", 2))
        // {
        //     printf("you win");
        // }
        // printf("%c", str[i]);
        i++;
    }
    return NULL;
}

int main(int argc, char *argv[], char **envp)
{
    t_minishell minishell;
    char *env = getenv("PATH");
    minishell.program_name = "$ma_minisel % ";
    // printf("%s", env);
    int status;
   
    while (1)
    {
        minishell.line = readline(ft_strjoin(minishell.program_name, ""));
        //printf("%s",minishell.line);
        ma_parser(minishell.line, minishell);
        add_history(minishell.line);

        if (!ft_strncmp(minishell.line, "ls", 2))
        {
            //printf("somone wrote LSLSLSLSLLSLSL");
            char cmd[] = "/bin/ls";
            char *argve[] = {"ls", "-l", NULL};
            execve(cmd, argve, NULL);
        }

    }
    // int process;
    // int i = 0;

    // while(i < number of commands in pipeline)
    // {
    //     process = fork();

    // }
    return 0;
}