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

char **echo_utility(t_minishell minishell)
{
    int i;
    char **str;

    i = 0;
    while (i < minishell.word_count)
    {
        str[i] = malloc(sizeof(char *) * 10);
        str[i] = minishell.commands[i];
        i++;
    }
    str[i] = malloc(sizeof(char *) * 10);
    str[i] = NULL;
    return str;
}


void envoirement(t_minishell minishell)
{
    int status;
    int pid;
    int i;
    char **argve;
    i = 0;

    pid = fork();
    if(pid == 0)
    {   
        char *cmd = ft_strjoin("/bin/",minishell.commands[0]);
        char *argve[minishell.word_count];
        while(i < minishell.word_count)
        {
            argve[i] = minishell.commands[i];
            i++;
        }
        argve[i] = NULL; 
        execve(cmd, argve, NULL);
        exit(0);
    }
    wait(&status);

    // while(i < minishell.word_count)
    // {
    //     pid = fork();
    //     if(pid == 0)
    //     {   
    //         char *cmd = ft_strjoin("/bin/",minishell.commands[0]);
    //         char *argve[] = {minishell.commands[0], echo_utility(minishell), NULL};
    //         execve(cmd, argve, NULL);
    //         exit(0);
    //     }
    //     wait(&status);
    //     i++;
    // }
    // if ((!ft_strncmp(minishell.line, "ls", 2)))
    // {
    //     pid = fork();
    //     if(pid == 0)
    //     {
    //         char cmd[] = "/bin/ls";
    //         char *argve[] = {"ls", minishell.commands[1], NULL};
    //         execve(cmd, argve, NULL);
    //         exit(0);
    //     }
    //     wait(&status);
    // }
    // if ((!ft_strncmp(minishell.line, "pwd", 3)))
    // {
    //     pid = fork();
    //     if(pid == 0)
    //     {
    //         char cmd[] = "/bin/pwd";
    //         char *argve[] = {"pwd", "-L", NULL};
    //         execve(cmd, argve, NULL);
    //         exit(0);
    //     }
    //     wait(&status);
    // }
    //  if ((!ft_strncmp(minishell.line, "echo", 4)))
    // {
    //     pid = fork();
    //     if(pid == 0)
    //     {
    //         char cmd[] = "/bin/echo";
    //         char *argve[] = {"echo", echo_utility(minishell), NULL};
    //         execve(cmd, argve, NULL);
            
    //         exit(0);
    //     }
    //     wait(&status);
    // }

    // if ((!ft_strncmp(minishell.line, "cat", 3)))
    // {
    //     int pid;
     
    //         int i;
    //         i = 1;
    //         while(i < minishell.word_count)
    //         {
    //             pid = fork();
    //             if(pid == 0)
    //             {
    //                 char cmd[] = "/bin/cat";
    //                 char *argve[] = {"cat", minishell.commands[i], NULL};
    //                 execve(cmd, argve, NULL);
    //                 exit(0);
    //             }
    //             wait(&status); 
    //             i++;          
    //         }
    //         printf("\n");
    // }

    // if ((!ft_strncmp(minishell.line, "mkdir", 5)))
    // {
    //       int pid;
     
    //         int i;
    //         i = 1;
    //         while(i < minishell.word_count)
    //         {
    //             pid = fork();
    //             if(pid == 0)
    //             {
    //                 char cmd[] = "/bin/mkdir";
    //                 char *argve[] = {"mkdir", minishell.commands[i], NULL};
    //                 execve(cmd, argve, NULL);
    //                 exit(0);
    //             }
    //             wait(&status); 
    //             i++;          
    //         }   
    // }

    //   if ((!ft_strncmp(minishell.line, "rmdir", 5)))
    // {
    //       int pid;
     
    //         int i;
    //         i = 1;
    //         while(i < minishell.word_count)
    //         {
    //             pid = fork();
    //             if(pid == 0)
    //             {
    //                 char cmd[] = "/bin/rmdir";
    //                 char *argve[] = {"rmdir", minishell.commands[i], NULL};
    //                 execve(cmd, argve, NULL);
    //                 exit(0);
    //             }
    //             wait(&status); 
    //             i++;          
    //         }   
    // }


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

// char *ma_parser(char **str, t_minishell minishell)
// {
//     int i = 0;
//     int j;

//     while(str[i][j])
//     {
//         j = 0;
//         while (str[i][j])
//         {
//             if(str[i][j] == '"')
//                 i++;
//             if (str[i][j] == '|' || str[i][j] == '<' || str[i][j] == '>' || str[i][j] == '<<' || str[i + 1] == ">>")
//             {
//                 // if (str[i + 1] == )
//             } 
//             if (ft_isalpha(str[i]))
//             {

//             }
//             // if (!ft_substr(str, i, 2), "cd", 2))
//             // {
//             //     printf("you win");
//             // }
//             // printf("%c", str[i]);
//             i++;
//         }
//     }
//     return NULL;
// }

int main(int argc, char *argv[], char **envp)
{
    t_minishell minishell;
    t_list  commands;
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