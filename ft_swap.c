/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:42:54 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:22:48 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, t_operations *ops)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = tmp;
	ops->sa++;
	ops->total++;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, t_operations *ops)
{
	int	tmp;

	if (b->size >= 2)
	{
		tmp = b->array[0];
		b->array[0] = b->array[1];
		b->array[1] = tmp;
		if (ops)
		{
			ops->sb++;
			ops->total++;
		}
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_stack *a, t_stack *b, t_operations *ops)
{
	int	tmp_a;
	int	tmp_b;

	if (a->size >= 2)
	{
		tmp_a = a->array[0];
		a->array[0] = a->array[1];
		a->array[1] = tmp_a;
	}
	if (b->size >= 2)
	{
		tmp_b = b->array[0];
		b->array[0] = b->array[1];
		b->array[1] = tmp_b;
	}
	if ((a->size >= 2 || b->size >= 2) && ops)
	{
		ops->ss++;
		ops->total++;
		write(1, "ss\n", 3);
	}
}
