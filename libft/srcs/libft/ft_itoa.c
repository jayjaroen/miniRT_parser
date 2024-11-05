/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:55:52 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/18 18:34:10 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_num_digits(long nbr)
{
	int	num_digits;

	num_digits = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		num_digits++;
	while (nbr != 0)
	{
		nbr /= 10;
		num_digits++;
	}
	return (num_digits);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	long	num;

	num = n;
	i = ft_num_digits(num);
	result = (char *)malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[i] = '\0';
	i--;
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		result[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		result[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
