/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:18:27 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/09 15:03:43 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_bits_max(int x)
{
	int n = 0;
	
	while (x)
	{
		x >>= 1;
		n++;
	}
	return (n);
}

void ft_radix_sort(t_stack *a, t_stack *b)
{
    int bits_max;
    int i;
    int j;
	int size;

	i = 0;
    normalize(a, b);
    bits_max = ft_bits_max(a->len - 1);
    while(i < bits_max && !check_sort(a))
    {
        j = 0;
		size = a->len;
        while (j < size)
        {
            if (((a->tab[0] >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j++;
        }
        while (b->len > 0)
            pa(a, b);
		i++;
    }
}
