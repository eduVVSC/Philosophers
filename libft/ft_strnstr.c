/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:17:45 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/24 13:17:00 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)

{
	size_t	strlen;

	strlen = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (len > 0 && *big)
	{
		if (!(ft_strncmp(big, little, strlen)) && len >= strlen)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
int	main(int argc, char **argv)

{
	char *str = ft_strnstr(argv[1], argv[2], ft_atoi(argv[3]));
	printf("%s\n", str);
//	printf("%s\n", ft_strnstr("teste", "abc", 4));
	return (0);
}*/
