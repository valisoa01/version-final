/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:51:39 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:21:07 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_remaining_in_chunk(t_stack *a, int chunk_min,
		int chunk_max)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->array[i] >= chunk_min && a->array[i] <= chunk_max)
			count++;
		i++;
	}
	return (count);
}

static void	ft_push_chunk_elements(t_stack *a, t_stack *b, int bounds[2],
		t_operations *ops)
{
	int	remaining;
	int	chunk_min;
	int	chunk_max;

	chunk_min = bounds[0];
	chunk_max = bounds[1];
	remaining = ft_count_remaining_in_chunk(a, chunk_min, chunk_max);
	while (remaining > 0 && a->size > 0)
	{
		if (ft_is_in_chunk(a->array[0], chunk_min, chunk_max))
		{
			ft_pb(a, b, ops);
			remaining--;
		}
		else
		{
			ft_ra(a, ops);
		}
	}
}

void	ft_distribute_chunks(t_stack *a, t_stack *b, int chunk_count,
		t_operations *ops)
{
	int	chunk;
	int	min;
	int	max;
	int	bounds[2];

	min = ft_find_min(a);
	max = ft_find_max(a);
	chunk = 0;
	while (chunk < chunk_count && a->size > 0)
	{
		bounds[0] = ft_get_chunk_min(chunk, chunk_count, min, max);
		bounds[1] = ft_get_chunk_max(chunk, chunk_count, min, max);
		ft_push_chunk_elements(a, b, bounds, ops);
		chunk++;
	}
}
