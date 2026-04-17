/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:59:49 by tolrafan          #+#    #+#             */
/*   Updated: 2026/04/16 22:22:36 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_simple(t_stack *a, t_stack *b, t_operations *ops)
{
	if (a->size <= 1)
		return ;
	if (a->size == 2)
	{
		ft_sort_two(a, ops);
		return ;
	}
	if (a->size == 3)
	{
		ft_sort_three(a, ops);
		return ;
	}
	ft_selection_sort(a, b, ops);
}
