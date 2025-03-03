/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:14:44 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/08 11:06:50 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int n)

{
	int	len;

	len = 0;
	if (n <= 0)
	{
		if (n == 0)
			return (1);
		else
		{
			len += 1;
			n = -n;
		}
	}
	while (n / 10)
	{
		len += 1;
		n = n / 10;
	}
	if (n < 10)
		len += 1;
	return (len);
}

int	ft_nbrlen_hex(unsigned long n)

{
	int	len;

	len = 0;
	while (n / 16)
	{
		len += 1;
		n = n / 16;
	}
	if (n < 16)
		len += 1;
	return (len);
}

int	ft_nbrlen_u(unsigned int n)

{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n / 10)
	{
		len += 1;
		n = n / 10;
	}
	if (n < 10)
		len += 1;
	return (len);
}
