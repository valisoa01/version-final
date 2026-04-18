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

#include "push_swap.h"

static void	ft_copy_array(int *dest, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	ft_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	ft_find_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_convert_to_indices(t_stack *stack, int *sorted, int *original)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		stack->array[i] = ft_find_index(sorted, stack->size, original[i]);
		i++;
	}
}

void	ft_normalize_by_index(t_stack *stack)
{
	int	*sorted;
	int	*original;
	int	size;

	size = stack->size;
	sorted = (int *)malloc(sizeof(int) * size);
	original = (int *)malloc(sizeof(int) * size);
	if (!sorted || !original)
	{
		free(sorted);
		free(original);
		return ;
	}
	ft_copy_array(original, stack->array, size);
	ft_copy_array(sorted, stack->array, size);
	ft_sort_array(sorted, size);
	ft_convert_to_indices(stack, sorted, original);
	free(sorted);
	free(original);
}