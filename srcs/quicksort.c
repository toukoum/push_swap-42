/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:29:06 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/11 18:31:00 by rgiraud          ###   ########.fr       */
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

