/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_quiet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:49:34 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/13 10:52:05 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr_quiet(t_stack *stack_a, t_stack *stack_b)
{
	rra_quiet(stack_a);
	rrb_quiet(stack_b);
}

void	ss_quiet(t_stack *stack_a, t_stack *stack_b)
{
	sa_quiet(stack_a);
	sb_quiet(stack_b);
}

void	pa_quiet(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_a->len;
	if (stack_b->len == 0)
		return ;
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = stack_b->tab[0];
	stack_a->len++;
	stack_b->len--;
	while (i < stack_b->len)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
}

void	pb_quiet(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->len;
	if (stack_a->len == 0)
		return ;
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = stack_a->tab[0];
	stack_b->len++;
	stack_a->len--;
	while (i < stack_a->len)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
}

void	rr_quiet(t_stack *stack_a, t_stack *stack_b)
{
	ra_quiet(stack_a);
	rb_quiet(stack_b);
}
