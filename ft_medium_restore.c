/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_restore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:51:46 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:21:14 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_to_top(t_stack *b, int position, t_operations *ops)
{
	int	size;

	size = b->size;
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ft_rb(b, ops);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			ft_rrb(b, ops);
			position++;
		}
	}
}

static int	ft_find_position_of_value(t_stack *b, int value)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if (b->array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_push_largest_to_a(t_stack *a, t_stack *b, t_operations *ops)
{
	int	max_value;
	int	position;

	while (b->size > 0)
	{
		max_value = ft_find_max(b);
		position = ft_find_position_of_value(b, max_value);
		ft_rotate_to_top(b, position, ops);
		ft_pa(a, b, ops);
	}
}

void	ft_restore_from_b(t_stack *a, t_stack *b, t_operations *ops)
{
	ft_push_largest_to_a(a, b, ops);
}
