/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:21:51 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/08 14:33:52 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
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
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
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
	ft_printf("pb\n");
}
