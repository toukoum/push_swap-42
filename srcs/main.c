/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:45:54 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/06 20:04:07 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void display_stack(t_stack *stack)
{
	int		len_tab;
	int		*tab;

	ft_printf("\n============ Affichage de la Stack =============\n\n");
	tab = stack->tab;
	len_tab = stack->len;
	for (int i = 0; i < len_tab; i++)
	{
		ft_printf("tab[%d]: %d\n", i, tab[i]);
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
	init_stack_b(stack_a, stack_b);

	display_stack(stack_a);
	sa(stack_a);
	display_stack(stack_a);
	
	return (0);
}
