/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:10:19 by tolrafan          #+#    #+#             */
/*   Updated: 2026/04/18 15:10:21 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates_values(int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
			{
				ft_print_error();
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_is_flag(const char *str)
{
	if (!str || str[0] != '-' || str[1] != '-')
		return (0);
	if (ft_strcmp((char *)str, "--simple") == 0 || ft_strcmp((char *)str,
			"--medium") == 0 || ft_strcmp((char *)str, "--complex") == 0
		|| ft_strcmp((char *)str, "--adaptive") == 0 || ft_strcmp((char *)str,
			"--bench") == 0)
		return (1);
	return (0);
}

void	apply_final_flags(t_flags *flags, int last_strategy, int bench)
{
	if (last_strategy == 1)
		flags->simple = 1;
	if (last_strategy == 2)
		flags->medium = 1;
	if (last_strategy == 3)
		flags->complex = 1;
	if (last_strategy == 4)
		flags->adaptive = 1;
	flags->bench = bench;
	if (flags->simple == 0 && flags->medium == 0 && flags->complex == 0
		&& flags->adaptive == 0)
		flags->adaptive = 1;
}
