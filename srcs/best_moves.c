/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:06:37 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/12 16:22:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	next_x(int x, t_stack *a)
{
	int	i;
	int	n_x;
	int	found;

	found = 0;
	i = 0;
	n_x = INT_MAX;
	while (i < a->len)
	{
		if (a->tab[i] > x && a->tab[i] < n_x)
		{
			n_x = a->tab[i];
			found = 1;
		}
		i++;
	}
	if (!found)
	{
		n_x = a->tab[0];
		i = 0;
		while (++i < a->len)
			if (a->tab[i] < n_x)
				n_x = a->tab[i];
	}
	return (n_x);
}

void	smart_rotate_a(t_stack *a, int n_x, t_best_moves *bm)
{
	int	shortest;

	shortest = 0;
	while (shortest < a->len && a->tab[shortest] != n_x)
		shortest++;
	if (shortest <= a->len - shortest)
		bm->nra = shortest;
	else
		bm->nrra = a->len - shortest;
}

int	bm_total(t_best_moves *bm)
{
	int	tt;

	tt = bm->nra + bm->nrb + bm->nrrb + bm->nrra + bm->nrr + bm->nrrr;
	bm->tt = tt;
	return (tt);
}

void	calculate_double_rot(t_best_moves *bm)
{
	while (bm->nra && bm->nrb)
	{
		bm->nra--;
		bm->nrb--;
		bm->nrr++;
	}
	while (bm->nrra && bm->nrrb)
	{
		bm->nrra--;
		bm->nrrb--;
		bm->nrrr++;
	}
}

void	calculate_best_moves(t_stack *a, t_stack *b, t_best_moves *bm,
		t_max_value *mv)
{
	int				i;
	int				n_x;
	t_best_moves	*bm_temp;

	bm_temp = malloc(sizeof(t_best_moves));
	if (!bm_temp)
		handle_big_error(a, b, mv, bm);
	i = 0;
	while (i < b->len)
	{
		init_best_moves(bm_temp);
		if (i <= b->len - i)
			bm_temp->nrb = i;
		else
			bm_temp->nrrb = b->len - i;
		n_x = next_x(b->tab[i], a);
		smart_rotate_a(a, n_x, bm_temp);
		calculate_double_rot(bm_temp);
		if (bm_total(bm_temp) < bm->tt)
			ft_copy_best_move(bm, bm_temp);
		if (bm->tt == 0 || bm->tt == 1)
			break ;
		i++;
	}
	free(bm_temp);
}
