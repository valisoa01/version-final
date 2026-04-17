/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:49:40 by tolrafan          #+#    #+#             */
/*   Updated: 2026/02/10 09:27:06 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*content;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	content = *lst;
	while (content != NULL)
	{
		next = content->next;
		del(content->content);
		free(content);
		content = next;
	}
	*lst = NULL;
}
