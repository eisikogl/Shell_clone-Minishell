/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop_signals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalayci <akalayci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:44:56 by akalayci          #+#    #+#             */
/*   Updated: 2022/12/11 00:45:26 by akalayci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	shell_loop_handler(int signal);

void	shell_loop_signal(void)
{
	signal(SIGINT, shell_loop_handler);
	signal(SIGQUIT, SIG_IGN);
}

static void	shell_loop_handler(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
