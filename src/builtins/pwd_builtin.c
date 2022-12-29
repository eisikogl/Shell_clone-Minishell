/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalayci <akalayci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:43:53 by akalayci          #+#    #+#             */
/*   Updated: 2022/12/11 00:45:54 by akalayci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*get_pwd(void);

int	pwd_builtin(void)
{
	char	*pwd;

	pwd = get_pwd();
	if (!pwd)
	{
		free(pwd);
		pwd = search_env_value("PWD");
		printf("%s\n", pwd);
	}
	else
		printf("%s\n", pwd);
	free(pwd);
	return (0);
}

static char	*get_pwd(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 4096));
}
