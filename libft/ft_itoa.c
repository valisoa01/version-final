/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:49:08 by tolrafan          #+#    #+#             */
/*   Updated: 2026/02/09 15:49:10 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_fill(char *str, long num, int len)
{
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*str;

	num = n;
	len = ft_numlen(num);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (num < 0)
		num = -num;
	ft_fill(str, num, len);
	if (n < 0)
		str[0] = '-';
	return (str);
}
