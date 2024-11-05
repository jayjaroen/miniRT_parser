/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:07 by jjaroens          #+#    #+#             */
/*   Updated: 2024/11/05 21:27:50 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../../libft/includes/get_next_line.h" //get_next_line didn't link

// to check not empty && can open
// check each parameter in another function
static bool is_file_valid(char *file_name)
{
    char    *line;
    int     fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr_fd("Error: file opening\n", 2);
        return (false);
    }
    line = get_next_line(fd);
    if (line == NULL)
    {
        ft_putstr_fd("Error: file empty\n", 2);
        close(fd);
        return (false);
    }
    free(line);
    close(fd);
    return (true);
}

bool check_file(char *str)
{
    int len;
    int i;

    len = ft_strlen(str);
    i = 0;
    while (str[i] && ft_strncmp(&str[i], ".rt", 3))
    {
        i++;
        len--;
    }
    if (len != 3)
    {
        ft_putstr_fd("Error: wrong file type\n", 2);
        return (false);
    }
    if (!is_file_valid(str))
        return (false);
    return (true);
}


