/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:51:02 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:21:36 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_by_bit(t_stack *a, t_stack *b, int bit, t_operations *ops)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (((a->array[0] >> bit) & 1) == 1)
			ft_ra(a, ops);
		else
			ft_pb(a, b, ops);
		i++;
	}
	while (b->size > 0)
		ft_pa(a, b, ops);
}

void	ft_radix_sort(t_stack *a, t_stack *b, t_operations *ops)
{
	int	max_bits;
	int	bit;
	int	min_value;

	ft_normalize_stack(a, &min_value);
	max_bits = ft_get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		ft_sort_by_bit(a, b, bit, ops);
		bit++;
	}
	ft_restore_stack(a, min_value);
}
