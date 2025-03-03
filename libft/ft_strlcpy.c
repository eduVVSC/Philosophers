/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:26:21 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/24 11:43:18 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
//#include <bsd/string.h>

/*

	DEST: 123456789
	SRC: HELLO
	SIZE: 3

	HEL456789

*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)

{
	size_t	count;
	size_t	src_len;

	src_len = ft_strlen(src);
	count = 0;
	if (size == 0)
		return (src_len);
	while (src[count] != '\0' && count < (size - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (src_len);
}
/*
int	main()

{
	char	*test;
	char	*test2;

	test = malloc(strlen("123456789") + 1);
	test2 = "Hello";
	printf("Original Output: %zu\n", strlcpy(test, test2, 0));
	printf("Original Test: %s\n", test);
	free(test);
	test = malloc(strlen("123456789") + 1);
	test2 = "Hello";
	printf("My Output: %zu\n", ft_strlcpy(test, test2, 0));
	printf("My Test: %s\n", test);
	free(test);
	return (0);
}*/
