/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalayci <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:53:39 by akalayci          #+#    #+#             */
/*   Updated: 2022/01/08 17:13:35 by akalayci         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(int number)
{
	long long	big;
	int			i;

	i = 1;
	big = number;
	if (big < 0)
	{
		i++;
		big *= -1;
	}
	while (big > 9)
	{
		big /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	big;
	int			len;
	char		*res;

	len = ft_nbr_len(n);
	big = n;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		big *= -1;
	}
	while (big)
	{
		res[--len] = (big % 10) + '0';
		big /= 10;
	}
	return (res);
}
