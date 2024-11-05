/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:26:56 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/18 18:34:10 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}

/*void free_content(void *content) {
    free(content);
}

int main() {
    t_list *node = malloc(sizeof(t_list));
    node->content = "Hello, World!";

    printf("Content before deletion: %s\n", (char *)node->content);

    ft_lstdelone(node, free_content);

    // Accessing content after deletion is undefined behavior
    printf("Content after deletion: %s\n", (char *)node->content);

    return 0;
}*/
