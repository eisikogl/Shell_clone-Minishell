#include "../includes/minishell.h"

size_t	ft_count_words(const char *s, char c)
{
	char	pre_c;
	size_t	i;

	i = 0;
	pre_c = c;
	while (*s)
	{
		if (pre_c == c && *s != c)
			i++;
		pre_c = *s;
		s++;
	}
	return (i);
}

char *echo_utility(t_minishell minishell)
{
    int i;
    char *str;

    i = 1;
    while (i <= minishell.word_count)
    {
        if(!(i == minishell.word_count))
            minishell.commands[i] = ft_strjoin(minishell.commands[i]," ");
        str = ft_strjoin(str,minishell.commands[i]);
        i++;
    }
    return str;
}

void envoirement(t_minishell minishell)
{
    int status;
    int pid;
    if ((!ft_strncmp(minishell.line, "ls", 2)))
    {
        pid = fork();
        if(pid == 0)
        {
            char cmd[] = "/bin/ls";
            char *argve[] = {"ls", "-l", NULL};
            execve(cmd, argve, NULL);
            exit(0);
        }
        wait(&status);
    }
    if ((!ft_strncmp(minishell.line, "pwd", 3)))
    {
        pid = fork();
        if(pid == 0)
        {
            char cmd[] = "/bin/pwd";
            char *argve[] = {"pwd", "-L", NULL};
            execve(cmd, argve, NULL);
            exit(0);
        }
        wait(&status);
    }
     if ((!ft_strncmp(minishell.line, "echo", 4)))
    {
        pid = fork();
        if(pid == 0)
        {
            char cmd[] = "/bin/echo";
            char *argve[] = {"echo", echo_utility(minishell), NULL};
            execve(cmd, argve, NULL);
            
            exit(0);
        }
        wait(&status);
    }

     if ((!ft_strncmp(minishell.line, "cat", 3)))
    {
        int pid2;
        pid = fork();
        if(pid == 0)
        {
            int i;
            i = 1;
            while(i < minishell.word_count)
            {
                pid2 = fork();
                if(pid2 == 0)
                {
                    char cmd[] = "/bin/cat";
                    char *argve[] = {"cat", minishell.commands[i], NULL};
                    execve(cmd, argve, NULL);
                    exit(0);
                }
                wait(&status);  
                i++;          
            }
            exit(0);
        }
        wait(&status);
    }
}

// void ignore_all_spaces(char *str, int *i)
// {
//     while ((str[*i] == 32) || (str[*i] >= 9 && str[*i] <= 13))
//         (*i)++;
// }

// char *commands(char *str)
// {
//     return NULL;
// }

// char *ma_parser(char *str, t_minishell minishell)
// {
//     int i = 0;

//     ignore_all_spaces(str, &i);

//     while (str[i])
//     {
//         if(str[i] == '"')
//             i++;
//         if (str[i] == '|' || str[i] == '<' || str[i] == '>' || str[i] == '<<' || str[i + 1] == ">>")
//         {
//             // if (str[i + 1] == )
//         } 
//         if (ft_isalpha(str[i]))
//         {

//         }
//         // if (!ft_substr(str, i, 2), "cd", 2))
//         // {
//         //     printf("you win");
//         // }
//         // printf("%c", str[i]);
//         i++;
//     }
//     return NULL;
// }

int main(int argc, char *argv[], char **envp)
{
    t_minishell minishell;
    char *env = getenv("PATH");
    minishell.program_name = "$ma_minisel % ";
    // printf("%s", env);
    while (1)
    {
        minishell.line = readline(ft_strjoin(minishell.program_name, ""));
        minishell.commands = ft_split(minishell.line, ' ');
        minishell.word_count = ft_count_words(minishell.line, ' ');
        add_history(minishell.line);

        envoirement(minishell);

    }
    // int process;
    // int i = 0;

    // while(i < number of commands in pipeline)
    // {
    //     process = fork();

    // }
    return 0;
}