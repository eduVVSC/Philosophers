/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:55:11 by dioferre          #+#    #+#             */
/*   Updated: 2025/02/27 15:10:41 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_len(long n);
static char	*put_itoa(char *str, int len, long n);

char	*ft_itoa(int n)

{
	int		len;
	long	nr;
	char	*str;

	nr = n;
	len = get_len(nr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (put_itoa(str, len, nr));
}

static char	*put_itoa(char *str, int len, long n)

{
	int	i;

	i = len - 1;
	if (n <= 0)
	{
		if (n == 0)
			str[0] = '0';
		else
		{
			str[0] = '-';
			n = -n;
		}
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}

static int	get_len(long n)

{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		len++;
	}
	if (n >= 0)
		len++;
	return (len);
}
/*
int	main(int argc, char **argv)

{
	int	nr;

	nr = atoi(argv[1]);
	printf("%s\n", ft_itoa(nr));
	return (0);
}*/
