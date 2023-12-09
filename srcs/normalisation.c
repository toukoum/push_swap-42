/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:29:06 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/09 13:04:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void 			swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int *tab, int start, int end)
{
	int pivot;
	int start_tab;

	start_tab = start;
	pivot = tab[start];
	start++;
	while (start <= end)
	{
		while (start <= end && tab[start] < pivot)
			start++;
		while (start <= end && tab[end] > pivot)
			end--;
		if (start < end)
			swap(tab + start, tab + end);
	}
	swap(tab + start_tab, tab + end);
	return (end);
}

void quick_sort(int *tab, int start, int end)
{
	int pivotIndex;
	if (start < end)
	{
		pivotIndex = partition(tab, start, end);
		quick_sort(tab, start, pivotIndex - 1);
		quick_sort(tab, pivotIndex + 1, end);
	}
}

void map_simple(t_stack *a, int *cpy_tab)
{
	int i;
	int j;

	i = 0;
	while (i < a->len)
	{
		j = 0;
		while (j < a->len)
		{
			if (a->tab[i] == cpy_tab[j])
			{
				a->tab[i] = j;
				break;
			}
			j++;			
		}
		i++;		
	}
}

void normalize(t_stack *a, t_stack *b)
{
	int *cpy_tab;
	int i;

	i = 0;
	cpy_tab = malloc(sizeof(int) * a->len);
	if (!cpy_tab)
		handle_error_stack(a, b);
	while (i < a->len)
	{
		cpy_tab[i] = a->tab[i];
		i++;
	}
	quick_sort(cpy_tab, 0, a->len - 1);
	map_simple(a, cpy_tab);		
	free(cpy_tab);
}
