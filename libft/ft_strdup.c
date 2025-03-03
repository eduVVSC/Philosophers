/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:07:31 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/21 15:11:34 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)

{
	char	*str;
	size_t	count;
	size_t	len;

	len = ft_strlen(s);
	count = 0;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[count] != '\0')
	{
		str[count] = s[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
