/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:46:53 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/18 18:34:10 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		buffer[256];
	unsigned char		*s1;
	const unsigned char	*s2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (n > sizeof(buffer))
		return (NULL);
	s1 = dest;
	s2 = src;
	while (i < n)
	{
		buffer[i] = s2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		s1[i] = buffer[i];
		i++;
	}
	return (dest);
}

/*int main()
{
    char str[] = "Hello, World!";
	char str2[] = "Hello, 42Bangkok!";

    ft_memmove(str + 7, str, 13);
    printf("%s\n", str);
	ft_memmove(str2 + 8, str2 + 7, 9);
    printf("%s\n", str2);
    return 0;
}*/
