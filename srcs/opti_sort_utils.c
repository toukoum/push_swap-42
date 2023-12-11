/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:51:58 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/11 19:03:24 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_max_value(int x, t_max_value *mv)
{
	return (x == mv->max_first || x == mv->max_second || x == mv->max_third
		|| x == mv->max_fifth || x == mv->max_fourth);
}