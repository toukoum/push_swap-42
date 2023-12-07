/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:28:21 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/07 11:09:13 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack_a)
{
	int	i;
	int	temp;

	if (stack_a->len < 2)
		return ;
	i = 0;
	temp = stack_a->tab[0];
	while (i < stack_a->len - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[i] = temp;
}

void	rb(t_stack *stack_b)
{
	int	i;
	int	temp;

	if (stack_b->len < 2)
		return ;
	i = 0;
	temp = stack_b->tab[0];
	while (i < stack_b->len - 1)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	stack_b->tab[i] = temp;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}