/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:00:31 by tolrafan          #+#    #+#             */
/*   Updated: 2026/04/16 22:22:04 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_position(t_stack *stack)
{
	int	min;
	int	pos;
	int	i;

	min = stack->array[0];
	pos = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] < min)
		{
			min = stack->array[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	ft_bring_to_top(t_stack *stack, int position, t_operations *ops)
{
	int	size;

	size = stack->size;
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ft_ra(stack, ops);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			ft_rra(stack, ops);
			position++;
		}
	}
}

static void	ft_extract_all_to_b(t_stack *a, t_stack *b, t_operations *ops)
{
	int	min_pos;

	while (a->size > 0)
	{
		min_pos = ft_find_min_position(a);
		ft_bring_to_top(a, min_pos, ops);
		ft_pb(a, b, ops);
	}
}

static void	ft_push_all_back_to_a(t_stack *a, t_stack *b, t_operations *ops)
{
	while (b->size > 0)
		ft_pa(a, b, ops);
}

void	ft_selection_sort(t_stack *a, t_stack *b, t_operations *ops)
{
	ft_extract_all_to_b(a, b, ops);
	ft_push_all_back_to_a(a, b, ops);
}
