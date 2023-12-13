/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:45:54 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/13 11:16:06 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = ft_parse(argc, argv);
	init_stack_b(stack_a, &stack_b);
	if (stack_a->len == 2)
		ft_sort_two(stack_a);
	else if (stack_a->len == 3)
		ft_sort_three(stack_a);
	else if (stack_a->len == 4)
		ft_sort_four(stack_a, stack_b);
	else if (stack_a->len == 5)
		ft_sort_five(stack_a, stack_b);
	else
		opti_sort(stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}
