/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:28:21 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/12 14:32:02 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack_a)
{
	int	i;
	int	temp;

	if (stack_a->len < 2)
		return ;
	i = stack_a->len - 1;
	temp = stack_a->tab[stack_a->len - 1];
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = temp;
	ft_printf("rra\n");
}
void	rrb(t_stack *stack_b)
{
	int	i;
	int	temp;

	if (stack_b->len < 2)
		return ;
	i = stack_b->len - 1;
	temp = stack_b->tab[stack_b->len - 1];
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = temp;
	ft_printf("rrb\n");
}
void	rra_quiet(t_stack *stack_a)
{
	int	i;
	int	temp;

	if (stack_a->len < 2)
		return ;
	i = stack_a->len - 1;
	temp = stack_a->tab[stack_a->len - 1];
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = temp;
}
void	rrb_quiet(t_stack *stack_b)
{
	int	i;
	int	temp;

	if (stack_b->len < 2)
		return ;
	i = stack_b->len - 1;
	temp = stack_b->tab[stack_b->len - 1];
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = temp;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra_quiet(stack_a);
	rrb_quiet(stack_b);
	ft_printf("rrr\n");
}