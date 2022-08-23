/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalayci <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:22:10 by akalayci          #+#    #+#             */
/*   Updated: 2022/01/06 17:08:11 by akalayci         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*iter;

	iter = *lst;
	while (iter != NULL)
	{
		temp = iter -> next;
		del(iter -> content);
		free(iter);
		iter = temp;
	}
	*lst = NULL;
}
