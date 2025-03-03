/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:43:46 by dioferre          #+#    #+#             */
/*   Updated: 2024/10/08 11:10:20 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include "libft.h"

int	ft_putnbr_hex(int n, char c);
int	ft_putnbr_u(unsigned int n);
int	ft_printptr(int n);
int	ft_nbrlen(int n);
*/
#include <limits.h>
#include "libft.h"

static int	ps_putstr_fd(char *s, int fd)

{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ps_putnbr_fd(int n, int fd)

{
	char	digit;
	int		result;

	result = ft_nbrlen(n);
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (n < 0)
	{
		write(fd, "-", 1);
		ps_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
		{
			ps_putnbr_fd((n / 10), fd);
			ps_putnbr_fd((n % 10), fd);
		}
		else
		{
			digit = n + 48;
			write(fd, &digit, 1);
		}
	}
	return (result);
}

int	print_format(char format, va_list args)

{
	char	c;
	int		result;

	result = 0;
	if (format == 'c')
	{
		c = va_arg(args, int);
		result += write(1, &c, 1);
	}
	else if (format == 's')
		result += ps_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
		result += ft_printptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		result += ps_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'u')
		result += ft_putnbr_u(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		result += ft_putnbr_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		result += write(1, "%", 1);
	return (result);
}

int	ft_printf(const char *format, ...)

{
	int		result;
	va_list	args;

	result = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			result += print_format(*(++format), args);
		}
		else
			result += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (result);
}
/*
 TESTS
	char	*c = NULL;
	char	ch = 'a';
	unsigned int u = 99999;
	int	i = 0;
	int	*ptr;

	ptr = malloc(3*sizeof(int));
	*ptr = 1;
//C
//
	ft_printf("---C\n");
	ft_printf("My output:\n");
	output = ft_printf("%c\n", ch);
	ft_printf("output: %d\n\n", output);
//
	printf("Original output:\n");
	output = printf("%c\n", ch);
	printf("output: %d\n", output);
//STR
//
	ft_printf("---STR\n");
	ft_printf("My output:\n");
	output = ft_printf("%s\n", c);
	ft_printf("output: %d\n\n", output);
//
	printf("Original output:\n");
	output = printf("%s\n", c);
	printf("output: %d\n", output);
//PTR
//
	ft_printf("---PTR\n");
	ft_printf("My output:\n");
	output = ft_printf("%p\n", ptr);
	ft_printf("output: %d\n\n", output);
//
	printf("Original output:\n");
	output = printf("%p\n", ptr);
	printf("output: %d\n", output);
// USIGNED
//
	ft_printf("---UNSIGNED\n");
	ft_printf("My output:\n");
	output = ft_printf("%u\n", u);
	ft_printf("output: %d\n\n", output);
//
	printf("Original output:\n");
	output = printf("%u\n", u);
	printf("output: %d\n", output);
//INT
//
	ft_printf("--INT\n");
	ft_printf("My output:\n");
	output = ft_printf("%i\n", i);
	ft_printf("output: %d\n\n", output);
//
	printf("Original output:\n");
	output = printf("%i\n", i);
	printf("output: %d\n", output);
//X
//
	ft_printf("---X\n");
	ft_printf("My output:\n");
	output = ft_printf("%x\n", i);
	ft_printf("output: %d\n\n", output);
//
	printf("Original output:\n");
	output = printf("%x\n", i);
	printf("output: %d\n", output);
}
*/
