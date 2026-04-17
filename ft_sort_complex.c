/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:51:16 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:22:23 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_complex(t_stack *a, t_stack *b, t_operations *ops)
{
	if (a->size <= 1)
		return ;
	if (a->size == 2)
	{
		ft_sort_two(a, ops);
		return ;
	}
	if (a->size == 3)
	{
		ft_sort_three(a, ops);
		return ;
	}
	ft_radix_sort(a, b, ops);
}
