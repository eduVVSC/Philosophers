/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:21:32 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/08 11:06:43 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>

int	ft_printnbr(int n);
int	ft_printptr(int n);
int	ft_nbrlen(int n);
int	ft_nbrlen_u(unsigned int n);

*/
#include "libft.h"

int	ft_putnbr_hex(unsigned long n, char c)

{
	char	digit;
	int		result;

	result = ft_nbrlen_hex(n);
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, c);
		ft_putnbr_hex((n % 16), c);
	}
	else if (n > 9 && n < 16)
	{
		digit = (n % 10) + (c - 23);
		write(1, &digit, 1);
	}
	else
		ft_printnbr(n);
	return (result);
}

int	ft_printnbr(int n)

{
	char	digit;
	int		result;

	result = ft_nbrlen(n);
	digit = n + '0';
	write(1, &digit, 1);
	return (result);
}

int	ft_putnbr_u(unsigned int n)
{
	char	digit;
	int		result;

	result = ft_nbrlen_u(n);
	if (n > 9)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
	{
		digit = n + 48;
		write(1, &digit, 1);
	}
	return (result);
}

int	ft_printptr(unsigned long n)

{
	int	result;

	if ((void *)n == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	result = ft_nbrlen_hex(n) + 2;
	write(1, "0x", 2);
	ft_putnbr_hex(n, 'x');
	return (result);
}
