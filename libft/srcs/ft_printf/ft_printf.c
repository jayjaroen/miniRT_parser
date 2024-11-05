/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:23:07 by nusamank          #+#    #+#             */
/*   Updated: 2024/03/12 11:45:10 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(const char *specifier, va_list args)
{
	int	len;

	len = 0;
	if (*specifier == 'c')
		len += print_c(va_arg(args, int));
	else if (*specifier == 's')
		len += print_str(va_arg(args, char *));
	else if (*specifier == 'p')
		len += print_ptr(va_arg(args, void *));
	else if (*specifier == 'd' || *specifier == 'i')
		len += print_int((long)va_arg(args, int));
	else if (*specifier == 'u')
		len += print_int((long)va_arg(args, unsigned int));
	else if (*specifier == 'x' || *specifier == 'X')
		len += print_hex(va_arg(args, unsigned int), *specifier);
	else
	{
		write(1, specifier, 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (format == NULL)
		return (-1);
	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += print_format(format, args);
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}

/*#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	len1;
	int	len2;
	int	c = 'a';
	char	*s = "Hello";
	void	*ptr;


	len1 = printf("c: %c, s: %s\n", c, s);
	len2 = ft_printf("c: %c, s: %s\n", c, s);
	printf("%d\n", len1);
	ft_printf("%d\n", len2);
	printf("INT_MIN: %d INT_MAX: %d\n", INT_MIN, INT_MAX);
	ft_printf("INT_MIN: %d INT_MAX: %d\n", INT_MIN, INT_MAX);
	printf("UINT_MAX: %u\n", UINT_MAX);
	ft_printf("UINT_MAX: %u\n", UINT_MAX);
	printf("hex: %x, HEX: %X\n", 123456789, 123456789);
	ft_printf("hex: %x, HEX: %X\n", 123456789, 123456789);
	printf("hex: %x, HEX: %X\n", UINT_MAX, UINT_MAX);
	ft_printf("hex: %x, HEX: %X\n", UINT_MAX, UINT_MAX);
	ptr = &s;
	printf("ptr: %p, str: %s\n", ptr, s);
	ft_printf("ptr: %p, str: %s\n", ptr, s);
	ptr = NULL;
	s = NULL;
	len1 = printf("ptr: %p, str: %s, c: %c\n", ptr, s, 0);
	len2 = ft_printf("ptr: %p, str: %s, c: %c\n", ptr, s, 0);
	printf("%i\n", len1);
	ft_printf("%i\n", len2);
}*/
