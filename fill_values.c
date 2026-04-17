/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:44:47 by tolrafan          #+#    #+#             */
/*   Updated: 2026/04/16 22:00:07 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_value_if_valid(char *token, int *values, int *idx)
{
	if (!ft_is_flag(token) && !ft_is_empty_or_whitespace(token))
	{
		if (ft_is_valid_integer(token) && ft_is_within_int_range(token))
		{
			values[*idx] = ft_atoi(token);
			(*idx)++;
			return (1);
		}
		return (-1);
	}
	return (0);
}

static int	process_tokens_for_values(char **tokens, int *values, int *idx)
{
	int	j;
	int	ret;

	j = 0;
	while (tokens[j])
	{
		ret = add_value_if_valid(tokens[j], values, idx);
		if (ret == -1)
		{
			ft_free_split(tokens);
			return (0);
		}
		j++;
	}
	ft_free_split(tokens);
	return (1);
}

static int	fill_spaced_argument(char *arg, int *values, int *idx)
{
	char	**split_args;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (0);
	return (process_tokens_for_values(split_args, values, idx));
}

static int	fill_simple_argument(char *arg, int *values, int *idx)
{
	if (ft_is_flag(arg))
		return (1);
	if (!ft_is_empty_or_whitespace(arg))
	{
		if (ft_is_valid_integer(arg) && ft_is_within_int_range(arg))
		{
			values[*idx] = ft_atoi(arg);
			(*idx)++;
			return (1);
		}
		return (0);
	}
	return (1);
}

int	fill_values(int argc, char **argv, int start_idx, int *values)
{
	int	idx;
	int	i;
	int	ret;

	idx = 0;
	i = start_idx;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			ret = fill_spaced_argument(argv[i], values, &idx);
		else
			ret = fill_simple_argument(argv[i], values, &idx);
		if (ret == 0)
			return (0);
		i++;
	}
	return (1);
}
