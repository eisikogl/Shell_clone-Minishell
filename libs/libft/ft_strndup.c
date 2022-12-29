/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalayci <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:54:00 by akalayci          #+#    #+#             */
/*   Updated: 2022/12/04 10:54:02 by akalayci         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int length)
{
	char	*ret;

	if (!length)
		return (NULL);
	ret = malloc((length + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, str, length);
	ret[length] = '\0';
	return (ret);
}
