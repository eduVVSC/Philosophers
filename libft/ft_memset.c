/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:17:42 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/21 15:10:57 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)

{
	unsigned char	*str;
	size_t			count;

	str = s;
	count = 0;
	while (count < n)
	{
		str[count] = c;
		count ++;
	}
	return (s);
}
