/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:42:49 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:21:52 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, t_operations *ops)
{
	int	tmp;
	int	i;

	if (a->size >= 2)
	{
		tmp = a->array[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->array[i] = a->array[i + 1];
			i++;
		}
		a->array[a->size - 1] = tmp;
		if (ops)
		{
			ops->ra++;
			ops->total++;
		}
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stack *b, t_operations *ops)
{
	int	tmp;
	int	i;

	if (b->size >= 2)
	{
		tmp = b->array[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->array[i] = b->array[i + 1];
			i++;
		}
		b->array[b->size - 1] = tmp;
		if (ops)
		{
			ops->rb++;
			ops->total++;
		}
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_stack *a, t_stack *b, t_operations *ops)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = 0;
	rotated_b = 0;
	if (a->size >= 2)
	{
		ft_ra(a, NULL);
		rotated_a = 1;
	}
	if (b->size >= 2)
	{
		ft_rb(b, NULL);
		rotated_b = 1;
	}
	if ((rotated_a || rotated_b) && ops)
	{
		ops->rr++;
		ops->total++;
		write(1, "rr\n", 3);
	}
}
