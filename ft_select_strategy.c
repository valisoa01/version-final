/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_strategy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:50:34 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:21:58 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_select_strategy(t_stack *a, t_stack *b, t_operations *ops,
		t_flags *flags)
{
	if (flags->simple)
	{
		flags->strategy_name = "Simple";
		flags->complexity = "O(n²)";
		ft_sort_simple(a, b, ops);
	}
	else if (flags->medium)
	{
		flags->strategy_name = "Medium";
		flags->complexity = "O(n√n)";
		ft_sort_medium(a, b, ops);
	}
	else if (flags->complex)
	{
		flags->strategy_name = "Complex";
		flags->complexity = "O(n log n)";
		ft_sort_complex(a, b, ops);
	}
	else if (flags->adaptive)
	{
		flags->strategy_name = "Adaptive";
		flags->complexity = "depends on disorder";
		ft_sort_adaptive(a, b, ops, flags);
	}
}
