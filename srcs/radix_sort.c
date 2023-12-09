/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:18:27 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/09 18:57:25 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_bits_max(int x)
{
	int	n;

	n = 0;
	while (x)
	{
		x >>= 1;
		n++;
	}
	return (n);
}

int	is_useless(t_stack *a, int j, int i, int size)
{
	int	k;

	k = 0;
	while (j < size)
	{
		if (((a->tab[k++] >> i) & 1) == 0)
			j++;
		else
			return (0);
	}
	return (1);
}

void	ft_next_bit(t_stack *a, t_stack *b, int i)
{
	int	j;
	int	size;

	j = 0;
	size = b->len;
	while (j < size)
	{
		if ((b->tab[0] >> (i + 1) & 1) == 0)
			rb(b);
		else
			pa(a, b);
		j++;
	}
}
void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int	bits_max;
	int	i;
	int	j;
	int	size;

	i = 0;
	normalize(a, b);
	bits_max = ft_bits_max(a->len - 1);
	while (i < bits_max && !check_sort(a))
	{
		j = 0;
		size = a->len;
		while (j < size)
		{
			if (is_useless(a, j, i, size))
				break ;
			if (((a->tab[0] >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		ft_next_bit(a, b, i);
		i++;
	}
	while (b->len)
		pa(a, b);
}
