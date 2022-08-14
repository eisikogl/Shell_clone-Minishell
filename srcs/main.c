/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eisikogl <eisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:06:20 by eisikogl          #+#    #+#             */
/*   Updated: 2022/08/14 19:26:52 by eisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../libs/libft/libft.h"

int main(int argc, char **argv, char **envp)
{
    // char line[9999];
    // int i = 0;
    // while (envp[i])
    // {
    //     if (!ft_strncmp(envp[i], "PATH=",  5))
    //     {
    //         printf("%s: \n", envp[i] + 5);
    //         line = envp[i] + 5;
    //     }

    //     i++;
    //     /* code */
    // }
    
    char cmd[] = "/bin/ls";
    char *argve[] = {"ls", "-l", NULL};
    execve(cmd, argve, NULL);
}