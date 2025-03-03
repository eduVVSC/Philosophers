/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:14:08 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/25 12:22:39 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(const char *s1, const char *set)

{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set || s1[0] == '\0')
		return (ft_strdup(""));
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strrchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}
/*
int	main(int argc, char **argv)

{
	printf("%s\n", ft_strtrim(argv[1], argv[2]));
	return (0);
}*/
