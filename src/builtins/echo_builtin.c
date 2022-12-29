/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalayci <akalayci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:43:44 by akalayci          #+#    #+#             */
/*   Updated: 2022/12/11 00:45:58 by akalayci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	echo_builtin(char **exec)
{
	int	i;

	i = 1;
	while (strcmp_eq(exec[i], "-n"))
		i++;
	while (exec[i] != NULL)
	{
		printf("%s", exec[i]);
		if (exec[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!strcmp_eq(exec[1], "-n"))
		printf("\n");
	return (0);
}
