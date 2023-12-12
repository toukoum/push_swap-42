/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:51:58 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/12 16:39:05 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_best_moves(t_best_moves *bm)
{
	bm->nra = 0;
	bm->nrb = 0;
	bm->nrr = 0;
	bm->nrrr = 0;
	bm->tt = INT_MAX;
	bm->nrra = 0;
	bm->nrrb = 0;
}

int	is_max_value(int x, t_max_value *mv)
{
	return (x == mv->max_first || x == mv->max_second || x == mv->max_third
		|| x == mv->max_fifth || x == mv->max_fourth);
}

void	handle_big_error(t_stack *a, t_stack *b, t_max_value *mv,
		t_best_moves *bm)
{
	free(a->tab);
	free(b->tab);
	free(a);
	free(b);
	free(mv);
	free(bm);
	exit(EXIT_FAILURE);
}
