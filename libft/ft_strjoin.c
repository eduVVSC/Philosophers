/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:47:00 by dioferre          #+#    #+#             */
/*   Updated: 2024/04/21 16:03:02 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)

{
	char	*str;
	int		count;
	int		count2;
	int		len;

	count = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (count < len && s1[count] != '\0')
	{
		str[count] = s1[count];
		count++;
	}
	count2 = 0;
	while (count < len && s2[count2] != '\0')
	{
		str[count] = s2[count2];
		count++;
		count2++;
	}
	str[count] = '\0';
	return (str);
}
