/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:13:37 by nusamank          #+#    #+#             */
/*   Updated: 2024/03/12 11:42:23 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_ptr(uintptr_t n)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		len = write_ptr(n / 16);
		return (len + write_ptr(n % 16));
	}
	else
	{
		return (write(1, &base[n], 1));
	}
}

int	print_ptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	len = write_ptr((uintptr_t)ptr);
	return (len + 2);
}
