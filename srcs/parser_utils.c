/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:19:59 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/08 20:38:34 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	delete_content(int content)
{
	(void)content;
}

void	handle_error(t_list **lst_tab)
{
	ft_lstclear(lst_tab, &delete_content);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_find_disturb(char *arg, t_list **lst_tab)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == ' ' || arg[i] == '+'
			|| arg[i] == '-')
			i++;
		else
			handle_error(lst_tab);
	}
}

int	find_dubble(t_list *lst_tab, int n)
{
	while (lst_tab)
	{
		if (lst_tab->content == n)
			return (1);
		lst_tab = lst_tab->next;
	}
	return (0);
}
