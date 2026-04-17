/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_adaptive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:50:50 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:22:18 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_adaptive(t_stack *a, t_stack *b, t_operations *ops,
		t_flags *flags)
{
	double	disorder;

	disorder = ft_compute_disorder(a);
	if (disorder < 0.2)
	{
		flags->complexity = "O(n²)";
		ft_sort_simple(a, b, ops);
	}
	else if (disorder < 0.5)
	{
		flags->complexity = "O(n√n)";
		ft_sort_medium(a, b, ops);
	}
	else
	{
		flags->complexity = "O(n log n)";
		ft_sort_complex(a, b, ops);
	}
}
