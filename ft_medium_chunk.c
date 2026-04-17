/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratiand <fratiand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:51:34 by fratiand          #+#    #+#             */
/*   Updated: 2026/04/16 22:20:55 by fratiand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_chunk_min(int chunk_index, int chunk_count, int min, int max)
{
	int	range;
	int	chunk_min;

	range = max - min;
	chunk_min = min + (chunk_index * range / chunk_count);
	return (chunk_min);
}

int	ft_get_chunk_max(int chunk_index, int chunk_count, int min, int max)
{
	int	range;
	int	chunk_max;

	range = max - min;
	chunk_max = min + ((chunk_index + 1) * range / chunk_count);
	if (chunk_index == chunk_count - 1)
		chunk_max = max;
	return (chunk_max);
}
