/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:22:50 by nusamank          #+#    #+#             */
/*   Updated: 2024/03/11 12:20:16 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(long n)
{
	int		len;
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		return (print_int(-n) + 1);
	}
	else if (n > 9)
	{
		len = print_int(n / 10);
		return (len + print_int(n % 10));
	}
	else
	{
		c = n + '0';
		return (write(1, &c, 1));
	}
}
