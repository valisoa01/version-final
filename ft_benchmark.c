/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:52:34 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 21:56:38 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operations_init(t_operations *ops)
{
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->total = 0;
}

void	ft_putdouble_fd(double n, int fd)
{
	int	integer_part;
	int	decimal_part;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	integer_part = (int)n;
	decimal_part = (int)((n - integer_part) * 100);
	ft_putnbr_fd(integer_part, fd);
	write(fd, ".", 1);
	if (decimal_part < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(decimal_part, fd);
}

void	ft_print_operations(t_operations *ops)
{
	ft_putstr_fd("sa:  ", 2);
	ft_putnbr_fd(ops->sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(ops->sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(ops->ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(ops->pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(ops->pb, 2);
	ft_putstr_fd("\n[bench] ", 2);
	ft_putstr_fd("ra:  ", 2);
	ft_putnbr_fd(ops->ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(ops->rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(ops->rr, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(ops->rra, 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(ops->rrb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(ops->rrr, 2);
}

void	ft_print_benchmark(t_flags *flags, t_operations *ops)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putdouble_fd(flags->disorder * 100, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (flags->simple)
		ft_putstr_fd("Simple", 2);
	else if (flags->medium)
		ft_putstr_fd("Medium", 2);
	else if (flags->complex)
		ft_putstr_fd("Complex", 2);
	else
		ft_putstr_fd("Adaptive", 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(flags->complexity, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(ops->total, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ", 2);
	ft_print_operations(ops);
	ft_putstr_fd("\n", 2);
}
