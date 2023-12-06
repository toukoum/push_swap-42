/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:21:51 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/06 20:13:51 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void pa(t_stack *stack_a, t_stack *stack_b)
{
	int temp;
	if (stack_a->len < 2)
		return ;
	temp = stack_a->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = temp;	
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
	int temp;
	if (stack_b->len < 2)
		return ;
	temp = stack_b->tab[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->tab[1] = temp;	
}
