/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:42:42 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:21:47 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, t_operations *ops)
{
	int	tmp;
	int	i;

	if (a->size >= 2)
	{
		tmp = a->array[a->size - 1];
		i = a->size - 1;
		while (i > 0)
		{
			a->array[i] = a->array[i - 1];
			i--;
		}
		a->array[0] = tmp;
		if (ops)
		{
			ops->rra++;
			ops->total++;
		}
		write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_stack *b, t_operations *ops)
{
	int	tmp;
	int	i;

	if (b->size >= 2)
	{
		tmp = b->array[b->size - 1];
		i = b->size - 1;
		while (i > 0)
		{
			b->array[i] = b->array[i - 1];
			i--;
		}
		b->array[0] = tmp;
		if (ops)
		{
			ops->rrb++;
			ops->total++;
		}
		write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_stack *a, t_stack *b, t_operations *ops)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = 0;
	rotated_b = 0;
	if (a->size >= 2)
	{
		ft_rra(a, NULL);
		rotated_a = 1;
	}
	if (b->size >= 2)
	{
		ft_rrb(b, NULL);
		rotated_b = 1;
	}
	if ((rotated_a || rotated_b) && ops)
	{
		ops->rrr++;
		ops->total++;
		write(1, "rrr\n", 4);
	}
}
