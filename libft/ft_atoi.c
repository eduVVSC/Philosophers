/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:30:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/02/24 13:29:39 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_negs(const char *nptr, int i);
static int	ft_isspace(int c);

/*Takes a str as an argument and returns an int*/
int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	ncheck;

	i = 0;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	ncheck = handle_negs(nptr, i);
	if (ncheck == 0)
		return (0);
	while (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	if (ncheck != 1)
		result = -result;
	return (result);
}

static int	handle_negs(const char *nptr, int i)
{
	int	ncheck;
	int	sign;

	ncheck = 0;
	sign = 0;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			ncheck++;
		sign++;
		i++;
	}
	if (sign > 1)
		return (0);
	else if (ncheck == 1)
		return (-1);
	else
		return (1);
}

static int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}
