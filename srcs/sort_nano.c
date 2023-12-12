/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nano.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:24:16 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/12 16:43:37 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_two(t_stack *a)
{
	if (!check_sort(a))
		sa(a);
}

void	ft_sort_three(t_stack *a)
{
	if (check_sort(a))
		return ;
	if (check_r_sort(a))
	{
		ra(a);
		sa(a);
	}
	else if (a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2])
		ra(a);
	else if (a->tab[0] < a->tab[1] && a->tab[0] > a->tab[2])
		rra(a);
	else if (a->tab[1] > a->tab[0] && a->tab[1] > a->tab[2])
	{
		rra(a);
		sa(a);
	}
	else
		sa(a);
}

void	ft_sort_four(t_stack *a, t_stack *stack_b)
{
	int	min;

	if (check_sort(a))
		return ;
	min = find_min(a);
	while (a->tab[0] != min && a->tab[a->len - 1] != min)
		ra(a);
	if (a->tab[a->len - 1] == min)
		rra(a);
	if (check_sort(a))
		return ;
	pb(a, stack_b);
	ft_sort_three(a);
	pa(a, stack_b);
}

void	ft_sort_five(t_stack *a, t_stack *stack_b)
{
	int	min;

	if (check_sort(a))
		return ;
	min = find_min(a);
	while (a->tab[0] != min && a->tab[a->len - 1] != min && a->tab[a->len
			- 2] != min)
		ra(a);
	if (a->tab[a->len - 1] == min)
		rra(a);
	else if (a->tab[a->len - 2] == min)
	{
		rra(a);
		rra(a);
	}
	if (check_sort(a))
		return ;
	pb(a, stack_b);
	ft_sort_four(a, stack_b);
	pa(a, stack_b);
}
