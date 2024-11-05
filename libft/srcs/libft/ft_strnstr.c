/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:13:29 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/18 18:34:10 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	i;

	i = 0;
	if (!(*little))
		return ((char *)big);
	if (len == 0)
		return (0);
	n = ft_strlen(little);
	while (*big && i < len - n + 1)
	{
		if (ft_strncmp(big, little, n) == 0)
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
