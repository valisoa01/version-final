/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:51:58 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:22:29 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_medium(t_stack *a, t_stack *b, t_operations *ops)
{
	int	chunk_count;

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
	chunk_count = ft_calculate_chunk_count(a->size);
	ft_distribute_chunks(a, b, chunk_count, ops);
	ft_restore_from_b(a, b, ops);
}
