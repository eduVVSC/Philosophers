/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:51:31 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/21 14:13:28 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)

{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			count;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	count = 0;
	while (count < n)
	{
		if (str1[count] != str2[count])
			return ((str1[count] - str2[count]));
		count++ ;
	}
	return (0);
}
