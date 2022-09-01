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

    i = 0;
    pid = fork();
    if(pid == 0)
    {   
        char *cmd;
        if(!ft_strncmp(minishell.commands[0],"/bin/",5))
            cmd = minishell.commands[0];
        else
            cmd = ft_strjoin("/bin/",minishell.commands[0]);
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

// void ma_parser(t_minishell minishell)
// {
//     int i = 0;
//     int k;
//     int j;

//     while(minishell.commands[i])
//     {
//         j = 0;
//         while (minishell.commands[i][j])
//         {
//             if(minishell.commands[i][j] == '"')
//             {
//                 k = j;
//                 while (minishell.commands[i][k])
//                 {
//                     if(minishell.commands[i][k+1] == '\0')
//                         minishell.commands[i][k] = '\0';
//                     else
//                         minishell.commands[i][k] = minishell.commands[i][k+1];
//                     k++;
//                 }
//             }
//             j++;
//         }
//         i++;
//     }
// }

void ma_parser(t_minishell minishell)
{
    int i = 0;
    int j;

    while(minishell.line[i])
    {
        j = i;
        if(minishell.line[i] == '"')
        {
            while (minishell.line[j])
            {
                if(minishell.line[j+1] == '\0')
                    minishell.line[j] = '\0';
                else
                    minishell.line[j] = minishell.line[j+1];
                j++;
            }
            i = -1;
        }
        i++;
    }
}

int main(int argc, char *argv[], char **envp)
{
    t_minishell minishell;
    t_list  commands;
    char *env = getenv("PATH");
    minishell.program_name = "$ma_minishell > ";
    // printf("%s", env);
    while (1)
    {
        minishell.line = readline(ft_strjoin(minishell.program_name, ""));
        ma_parser(minishell);
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