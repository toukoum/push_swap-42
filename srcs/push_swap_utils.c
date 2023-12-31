/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:33:18 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/13 16:40:07 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_error_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->tab);
	free(stack_b->tab);
	free(stack_a);
	free(stack_b);
	exit(EXIT_FAILURE);
}

void	init_stack_b(t_stack *stack_a, t_stack **stack_b)
{
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_b)
		handle_error_stack(stack_a, *stack_b);
	(*stack_b)->tab = malloc(stack_a->len * sizeof(int));
	if (!(*stack_b)->tab)
		handle_error_stack(stack_a, (*stack_b));
	(*stack_b)->len = 0;
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->tab);
	free(stack_b->tab);
	free(stack_a);
	free(stack_b);
}

int	check_sort(t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < stack_a->len)
	{
		if (stack_a->tab[i - 1] > stack_a->tab[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_r_sort(t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < stack_a->len)
	{
		if (stack_a->tab[i - 1] < stack_a->tab[i])
			return (0);
		i++;
	}
	return (1);
}
