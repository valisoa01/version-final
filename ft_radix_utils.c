/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:51:10 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:21:42 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_value(t_stack *stack)
{
	int	min;
	int	i;

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

static int	ft_find_max_value(t_stack *stack)
{
	int	max;
	int	i;

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

void	ft_restore_stack(t_stack *stack, int min_value)
{
	int	i;

	if (min_value == 0)
		return ;
	i = 0;
	while (i < stack->size)
	{
		stack->array[i] = stack->array[i] + min_value;
		i++;
	}
}

void	ft_normalize_stack(t_stack *stack, int *min_value)
{
	int	i;

	*min_value = ft_find_min_value(stack);
	if (*min_value == 0)
		return ;
	i = 0;
	while (i < stack->size)
	{
		stack->array[i] = stack->array[i] - *min_value;
		i++;
	}
}

int	ft_get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = ft_find_max_value(stack);
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}
