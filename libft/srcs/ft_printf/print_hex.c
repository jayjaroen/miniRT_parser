/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:53:54 by nusamank          #+#    #+#             */
/*   Updated: 2024/03/12 10:26:48 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, char x)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	if (n > 15)
	{
		len = print_hex(n / 16, x);
		return (len + print_hex(n % 16, x));
	}
	else
	{
		return (write(1, &base[n], 1));
	}
}
