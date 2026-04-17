/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:12:55 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/17 16:23:13 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack *a, t_operations *ops)
{
	if (a->size == 2 && a->array[0] > a->array[1])
		ft_sa(a, ops);
}

void	ft_sort_three(t_stack *a, t_operations *ops)
{
	int	first;
	int	second;
	int	third;

	first = a->array[0];
	second = a->array[1];
	third = a->array[2];
	if (first < second && second > third && first < third)
	{
		ft_sa(a, ops);
		ft_ra(a, ops);
	}
	else if (first > second && second < third && first < third)
		ft_sa(a, ops);
	else if (first < second && second > third && first > third)
		ft_rra(a, ops);
	else if (first > second && second < third && first > third)
		ft_ra(a, ops);
	else if (first > second && second > third)
	{
		ft_sa(a, ops);
		ft_rra(a, ops);
	}
}
