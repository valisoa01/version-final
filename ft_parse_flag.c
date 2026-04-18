/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:14:14 by tolrafan          #+#    #+#             */
/*   Updated: 2026/04/18 15:11:16 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_strategy_flag(char *token, int *last_strategy)
{
	if (ft_strcmp(token, "--simple") == 0)
		*last_strategy = 1;
	else if (ft_strcmp(token, "--medium") == 0)
		*last_strategy = 2;
	else if (ft_strcmp(token, "--complex") == 0)
		*last_strategy = 3;
	else if (ft_strcmp(token, "--adaptive") == 0)
		*last_strategy = 4;
}

static void	process_flag_tokens(char **tokens, int *last_strategy, int *bench)
{
	int	j;

	j = 0;
	while (tokens[j])
	{
		if (ft_strcmp(tokens[j], "--bench") == 0)
			*bench = 1;
		else
			update_strategy_flag(tokens[j], last_strategy);
		j++;
	}
}

static void	parse_flags_in_spaced(char *arg, int *last_strategy, int *bench)
{
	char	**split_args;

	split_args = ft_split(arg, ' ');
	if (split_args)
	{
		process_flag_tokens(split_args, last_strategy, bench);
		ft_free_split(split_args);
	}
}

void	parse_flags_in_simple(char *arg, int *last_strategy, int *bench)
{
	if (ft_strcmp(arg, "--bench") == 0)
		*bench = 1;
	else
		update_strategy_flag(arg, last_strategy);
}

int	ft_parse_flags(int argc, char **argv, t_flags *flags)
{
	int	i;
	int	last_strategy;
	int	bench;

	last_strategy = 0;
	bench = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			parse_flags_in_spaced(argv[i], &last_strategy, &bench);
		else
			parse_flags_in_simple(argv[i], &last_strategy, &bench);
		i++;
	}
	apply_final_flags(flags, last_strategy, bench);
	return (1);
}
