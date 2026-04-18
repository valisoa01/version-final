/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:50:24 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/18 06:44:31 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_init_stacks(t_stack **a, t_stack **b, int size)
{
	*a = ft_stack_init(size, 'a');
	*b = ft_stack_init(size, 'b');
	if (!*a || !*b)
		return (0);
	return (1);
}

static void	ft_cleanup(t_stack *a, t_stack *b)
{
	ft_stack_free(a);
	ft_stack_free(b);
}

static int	ft_handle_already_sorted(t_stack *a, t_stack *b, t_flags *flags,
		t_operations *ops)
{
	if (!ft_stack_is_sorted(a))
		return (0);
	if (flags->bench)
	{
		flags->strategy_name = "None (already sorted)";
		flags->complexity = "O(1)";
		ft_print_benchmark(flags, ops);
	}
	ft_cleanup(a, b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	t_operations	ops;
	t_flags			flags;
	int valid_numbers;
	
	valid_numbers = count_valid_number(argc, argv, 1);
	if (!ft_init_stacks(&a, &b, valid_numbers))
		return (1);
	ft_operations_init(&ops);
	ft_memset(&flags, 0, sizeof(t_flags));
	if (!ft_parse_arg(argc, argv, a, &flags))
	{
		ft_cleanup(a, b);
		return (1);
	}
	flags.disorder = ft_compute_disorder(a);
	if (ft_handle_already_sorted(a, b, &flags, &ops))
		return (0);
	ft_select_strategy(a, b, &ops, &flags);
	if (flags.bench)
		ft_print_benchmark(&flags, &ops);
	ft_cleanup(a, b);
	return (0);
}
