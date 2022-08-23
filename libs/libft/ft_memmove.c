/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalayci <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:54:13 by akalayci          #+#    #+#             */
/*   Updated: 2022/01/06 17:57:51 by akalayci         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*sr;
	char	*dst;
	size_t	i;

	i = 0;
	dst = dest;
	sr = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (len--)
		{
			dst[len] = sr[len];
		}
	}
	else
	{
		while (len--)
		{
			dst[i] = sr[i];
			i++;
		}
	}
	return (dst);
}
