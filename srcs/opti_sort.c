/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:51:15 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/11 19:07:11 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_max_value	*copy_tab(t_stack *a, t_stack *b)
{
	int			i;
	int			*result;
	t_max_value	*max_value;

	max_value = malloc(sizeof(t_max_value));
	if (!max_value)
		handle_error_stack(a, b);
	result = malloc(a->len * sizeof(int));
	if (!result)
		handle_error_stack(a, b);
	i = -1;
	while (++i < a->len)
		result[i] = a->tab[i];
	quick_sort(result, 0, a->len - 1);
	if (a->len % 2 == 0)
		max_value->median = result[(a->len - 2) / 2];
	else
		max_value->median = result[(a->len - 1) / 2];
	max_value->min = result[0];
	max_value->max_first = result[a->len - 1];
	max_value->max_second = result[a->len - 2];
	max_value->max_third = result[a->len - 3];
	max_value->max_fourth = result[a->len - 4];
	max_value->max_fifth = result[a->len - 5];
	return (max_value);
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
		while (shortest--)
			ra(a);
	}
	pb(a, b);
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
	t_max_value *mv;
	
	mv = copy_tab(a, b);
	push_median(a, b, mv->median);
	push_pre_sort(a, b, mv);
	ft_sort_five(a, b);
	//ft_back_to_back(a, b, mv);
	free(mv);
}