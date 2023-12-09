/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:25:59 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/08 16:35:48 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack)
{
	int min;
	int i;

	i = 1;
	min = stack->tab[0];
	while (i < stack->len)
	{
			if (stack->tab[i] < min)
				min = stack->tab[i];
			i++;		
	}
	return (min);
}