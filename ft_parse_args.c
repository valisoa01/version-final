/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:21:02 by tolrafan          #+#    #+#             */
/*   Updated: 2026/04/16 22:00:22 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	clean_and_return(int *values, int ret)
{
	if (values)
		free(values);
	return (ret);
}

int	ft_parse_arg(int argc, char **argv, t_stack *a, t_flags *flags)
{
	int	*values;
	int	nb_values;

	ft_parse_flags(argc, argv, flags);
	nb_values = count_valid_number(argc, argv, 1);
	if (nb_values == 0)
		return (0);
	if (nb_values < 0)
		return (0);
	values = malloc(sizeof(int) * nb_values);
	if (!values)
		return (ft_print_error(), 0);
	if (!fill_values(argc, argv, 1, values))
		return (clean_and_return(values, 0));
	if (!ft_check_duplicates_values(values, nb_values))
		return (clean_and_return(values, 0));
	ft_stack_fill(a, values, nb_values);
	free(values);
	return (1);
}
