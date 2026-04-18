/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:12:30 by tolrafan          #+#    #+#             */
/*   Updated: 2026/04/18 15:12:33 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_number_token(char *token, int *count)
{
	if (!ft_is_empty_or_whitespace(token))
	{
		if (ft_is_valid_integer(token) && ft_is_within_int_range(token))
		{
			(*count)++;
			return (1);
		}
		return (-1);
	}
	return (0);
}

static int	process_tokens(char **tokens, int *count)
{
	int	j;
	int	ret;

	j = 0;
	while (tokens[j])
	{
		if (!ft_is_flag(tokens[j]))
		{
			ret = process_number_token(tokens[j], count);
			if (ret == -1)
			{
				ft_free_split(tokens);
				ft_print_error();
				return (-1);
			}
		}
		j++;
	}
	ft_free_split(tokens);
	return (0);
}

static int	handle_spaced_argument(char *arg, int *count)
{
	char	**split_args;
	int		ret;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (-1);
	ret = process_tokens(split_args, count);
	return (ret);
}

static int	handle_simple_argument(char *arg, int *count)
{
	if (ft_is_flag(arg))
		return (0);
	if (ft_is_valid_integer(arg) && ft_is_within_int_range(arg))
	{
		(*count)++;
		return (0);
	}
	ft_print_error();
	return (-1);
}

int	count_valid_number(int argc, char **argv, int start_idx)
{
	int	count;
	int	i;
	int	ret;

	count = 0;
	i = start_idx;
	while (i < argc)
	{
		if (ft_is_empty_or_whitespace(argv[i]))
		{
			ft_print_error();
			return (-1);
		}
		if (ft_strchr(argv[i], ' '))
			ret = handle_spaced_argument(argv[i], &count);
		else
			ret = handle_simple_argument(argv[i], &count);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (count);
}
