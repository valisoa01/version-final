/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tolrafan <tolrafan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:37:24 by tolrafan          #+#    #+#             */
/*   Updated: 2026/04/15 19:16:35 by tolrafan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*array;
	int		size;
	int		capacity;
	int		name;
}			t_stack;

typedef struct s_operations
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
}			t_operations;

typedef struct s_flags
{
	int		simple;
	int		medium;
	int		complex;
	int		adaptive;
	int		bench;
	char	*strategy_name;
	char	*complexity;
	double	disorder;
}			t_flags;

int			ft_parse_arg(int argc, char **argv, t_stack *a, t_flags *flags);
int			ft_check_duplicates_values(int *values, int size);
int			ft_is_valid_integer(char *str);
int			ft_is_within_int_range(char *str);
void		ft_print_error(void);
int			ft_parse_flags(int argc, char **argv, t_flags *flags);
void		ft_free_split(char **split);
int			ft_is_empty_or_whitespace(const char *str);
int			ft_strcmp(char *s1, char *s2);
long long	ft_atoll(const char *str);
int			ft_is_flag(const char *str);
int			fill_values(int argc, char **argv, int start_idx, int *values);
int			count_valid_number(int argc, char **argv, int start_idx);
void		parse_flags_in_simple(char *arg, int *last_strategy, int *bench);
void		update_strategy_flag(char *token, int *last_strategy);
void		apply_final_flags(t_flags *flags, int last_strategy, int bench);

void		ft_sa(t_stack *a, t_operations *ops);
void		ft_sb(t_stack *b, t_operations *ops);
void		ft_ss(t_stack *a, t_stack *b, t_operations *ops);
void		ft_pa(t_stack *a, t_stack *b, t_operations *ops);
void		ft_pb(t_stack *a, t_stack *b, t_operations *ops);
void		ft_ra(t_stack *a, t_operations *ops);
void		ft_rb(t_stack *b, t_operations *ops);
void		ft_rr(t_stack *a, t_stack *b, t_operations *ops);
void		ft_rra(t_stack *a, t_operations *ops);
void		ft_rrb(t_stack *b, t_operations *ops);
void		ft_rrr(t_stack *a, t_stack *b, t_operations *ops);

t_stack		*ft_stack_init(int capacity, int name);
void		ft_stack_free(t_stack *stack);
int			ft_stack_is_sorted(t_stack *stack);
void		ft_stack_fill(t_stack *a, int *values, int size);

void		ft_sort_simple(t_stack *a, t_stack *b, t_operations *ops);
void		ft_selection_sort(t_stack *a, t_stack *b, t_operations *ops);

int			ft_calculate_chunk_count(int size);
int			ft_find_min(t_stack *stack);
int			ft_find_max(t_stack *stack);
int			ft_get_chunk_min(int chunk_index, int chunk_count, int min,
				int max);
int			ft_get_chunk_max(int chunk_index, int chunk_count, int min,
				int max);
int			ft_is_in_chunk(int value, int chunk_min, int chunk_max);
void		ft_distribute_chunks(t_stack *a, t_stack *b, int chunk_count,
				t_operations *ops);
void		ft_restore_from_b(t_stack *a, t_stack *b, t_operations *ops);
void		ft_sort_medium(t_stack *a, t_stack *b, t_operations *ops);

void		ft_sort_complex(t_stack *a, t_stack *b, t_operations *ops);
void		ft_normalize_stack(t_stack *stack, int *min_value);
void		ft_restore_stack(t_stack *stack, int min_value);
int			ft_get_max_bits(t_stack *stack);
void		ft_radix_sort(t_stack *a, t_stack *b, t_operations *ops);

double		ft_compute_disorder(t_stack *a);
void		ft_sort_adaptive(t_stack *a, t_stack *b, t_operations *ops,
				t_flags *flags);

void		ft_operations_init(t_operations *ops);
void		ft_print_benchmark(t_flags *flags, t_operations *ops);
void		ft_print_operations(t_operations *ops);
void		ft_putdouble_fd(double n, int fd);
void		ft_sort_two(t_stack *a, t_operations *ops);
void		ft_sort_three(t_stack *a, t_operations *ops);

void		ft_select_strategy(t_stack *a, t_stack *b, t_operations *ops,
				t_flags *flags);

#endif