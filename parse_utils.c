/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:09:48 by tolrafan          #+#    #+#             */
/*   Updated: 2026/04/18 15:09:49 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
#include "push_swap.h"

int	ft_is_valid_integer(char *str)
{
	int	i;

	if (!str || ft_is_empty_or_whitespace(str))
		return (0);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atoll_skip(const char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static long long	ft_atoll_convert(const char *str, int start, int sign)
{
	long long	result;
	int			i;

	result = 0;
	i = start;
	while (str[i] >= '0' && str[i] <= '9')
	{
		
		if (result > (LLONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == -1)
				return (LLONG_MIN);
			return (LLONG_MAX);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

long long	ft_atoll(const char *str)
{
	int	start;
	int	sign;

	start = ft_atoll_skip(str, &sign);
	return (ft_atoll_convert(str, start, sign));
}
