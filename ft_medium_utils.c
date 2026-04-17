/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:51:52 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:21:21 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calculate_chunk_count(int size)
{
	int	chunk_count;

	chunk_count = 1;
	while (chunk_count * chunk_count < size)
		chunk_count++;
	return (chunk_count);
}

int	ft_is_in_chunk(int value, int chunk_min, int chunk_max)
{
	return (value >= chunk_min && value <= chunk_max);
}

int	ft_find_min(t_stack *stack)
{
	int	min;
	int	i;

	if (stack->size == 0)
		return (0);
	min = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}

int	ft_find_max(t_stack *stack)
{
	int	max;
	int	i;

	if (stack->size == 0)
		return (0);
	max = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	return (max);
}
