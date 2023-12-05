/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:45:54 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/05 19:56:34 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int				*tab;
	t_parse_list	*parse_result;
	int				len_tab;

	if (argc == 1)
		return (0);
	parse_result = ft_parse(argc, argv);
	tab = parse_result->tab;
	len_tab = parse_result->len;
	for (int i = 0; i < len_tab; i++)
	{
		ft_printf("tab[%d]: %d\n", i, tab[i]);
	}
	free(tab);
	return (0);
}
