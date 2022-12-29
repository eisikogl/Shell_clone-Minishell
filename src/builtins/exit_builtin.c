/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalayci <akalayci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:43:48 by akalayci          #+#    #+#             */
/*   Updated: 2022/12/11 00:45:56 by akalayci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	exit_builtin(void)
{
	g_minishell.exit_code = 0;
	free_minishell();
	exit(g_minishell.exit_code);
	return (g_minishell.exit_code);
}
