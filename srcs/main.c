/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:45:54 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/07 21:02:15 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n============ Affichage des Stacks =============\n");
	ft_printf("Stack A\n");
	for (int i = 0; i < stack_a->len; i++)
	{
		ft_printf("tab[%d]: %d\n", i, stack_a->tab[i]);
	}
	ft_printf("\n---------------------\nStack B\n");
	for (int i = 0; i < stack_b->len; i++)
	{
		ft_printf("tab[%d]: %d\n", i, stack_b->tab[i]);
	}
}

void ft_bubble_sort(t_stack *stack_a)
{
	int i = 0;
	int j;
	int swap = 1;
	
	while (swap)
	{
		j = 0;
		swap = 0;
		if (stack_a->tab[0] > stack_a->tab[1])
		{
			sa(stack_a);
			swap = 1;
		}
		while (j < stack_a->len - 2)
		{
			ra(stack_a);
			if (stack_a->tab[0] > stack_a->tab[1])
			{
				sa(stack_a);
				swap = 1;	
			}
			j++;
		}
		while (j-- > 0)
			rra(stack_a);		
		i++;
	}
	
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = ft_parse(argc, argv);
	init_stack_b(stack_a, &stack_b);
	display_stack(stack_a, stack_b);
	ft_bubble_sort(stack_a);
	display_stack(stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}
