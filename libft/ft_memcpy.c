/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:23:48 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/21 15:49:46 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)

{
	char	*str_dst;
	char	*str_src;
	size_t	count;

	str_dst = (char *) dest;
	str_src = (char *) src;
	count = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (count < n)
	{
		str_dst[count] = str_src[count];
		count ++;
	}
	return (dest);
}
