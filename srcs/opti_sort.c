/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:51:15 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/12 16:38:48 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_max_value	*init_mv(t_stack *a, t_stack *b)
{
	int			i;
	t_max_value	*mv;

	mv = malloc(sizeof(t_max_value));
	if (!mv)
		handle_error_stack(a, b);
	mv->copy_tab = malloc(a->len * sizeof(int));
	if (!mv->copy_tab)
		handle_error_stack(a, b);
	mv->len = a->len;
	i = -1;
	while (++i < a->len)
		mv->copy_tab[i] = a->tab[i];
	quick_sort(mv->copy_tab, 0, a->len - 1);
	if (a->len % 2 == 0)
		mv->median = mv->copy_tab[(a->len - 2) / 2];
	else
		mv->median = mv->copy_tab[(a->len - 1) / 2];
	mv->min = mv->copy_tab[0];
	mv->max_first = mv->copy_tab[a->len - 1];
	mv->max_second = mv->copy_tab[a->len - 2];
	mv->max_third = mv->copy_tab[a->len - 3];
	mv->max_fourth = mv->copy_tab[a->len - 4];
	mv->max_fifth = mv->copy_tab[a->len - 5];
	return (mv);
}

void	push_median(t_stack *a, t_stack *b, int median)
{
	int	shortest;

	shortest = 0;
	while (a->tab[shortest] != median)
		shortest++;
	if (shortest <= a->len - shortest)
	{
		while (shortest--)
			ra(a);
	}
	else
	{
		shortest = a->len - shortest;
		while (shortest--)
			rra(a);
	}
	pb(a, b);
}

void	ft_back_to_back(t_stack *a, t_stack *b, t_max_value *mv, int shortest)
{
	t_best_moves	*bm;

	bm = malloc(sizeof(t_best_moves));
	if (!bm)
		handle_big_error(a, b, mv, bm);
	init_best_moves(bm);
	while (b->len)
	{
		calculate_best_moves(a, b, bm, mv);
		apply_best_moves(a, b, bm);
		bm->tt = INT_MAX;
	}
	while (a->tab[shortest] != mv->min)
		shortest++;
	if (shortest <= a->len - shortest)
		while (shortest--)
			ra(a);
	else
	{
		shortest = a->len - shortest;
		while (shortest--)
			rra(a);
	}
	free(bm);
}

void	push_pre_sort(t_stack *a, t_stack *b, t_max_value *mv)
{
	int	i;
	int	size_a;

	size_a = a->len;
	i = 0;
	while (i < size_a)
	{
		if (!is_max_value(a->tab[0], mv))
		{
			pb(a, b);
			if (b->tab[0] > mv->median)
				rb(b);
		}
		else
			ra(a);
		i++;
	}
}

void	opti_sort(t_stack *a, t_stack *b)
{
	t_max_value	*mv;

	if (check_sort(a))
		return ;
	mv = init_mv(a, b);
	push_median(a, b, mv->median);
	push_pre_sort(a, b, mv);
	ft_sort_five(a, b);
	ft_back_to_back(a, b, mv, 0);
	free(mv->copy_tab);
	free(mv);
}
