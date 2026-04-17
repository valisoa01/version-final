/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:52:40 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:22:42 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_init(int capacity, int name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = (int *)malloc(sizeof(int) * capacity);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	stack->name = name;
	return (stack);
}

void	ft_stack_free(t_stack *stack)
{
	if (stack)
	{
		if (stack->array)
			free(stack->array);
		free(stack);
	}
}

int	ft_stack_is_sorted(t_stack *stack)
{
	int	i;

	if (stack->size <= 1)
		return (1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_stack_fill(t_stack *a, int *values, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		a->array[i] = values[i];
		i++;
	}
	a->size = size;
}
