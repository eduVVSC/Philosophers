/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:05:29 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/21 15:06:16 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	unsigned char	*ptr_s;
	unsigned char	uc;
	size_t			count;

	ptr_s = (unsigned char *)s;
	uc = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		if (ptr_s[count] == uc)
			return ((void *)&ptr_s[count]);
		count++;
	}
	return (NULL);
}
