/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:46:01 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/05 19:59:08 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_parse_string(t_list *lst_tab, char *arg)
{
	(void)lst_tab;
	(void)arg;
	return ;
}

void	ft_add_arg(t_list **lst_tab, char *arg)
{
	t_list	*node;
	int		result;

	if (ft_strchr(arg, ' '))
		ft_parse_string(*lst_tab, arg);
	else
	{
		result = ft_atoi(arg);
		if (!result)
			handle_error(lst_tab);
		node = ft_lstnew(result);
		ft_lstadd_back(lst_tab, node);
	}
}

t_parse_list	*ft_copy_lst_tab(t_list **lst_tab, t_parse_list *result)
{
	int		len_tab;
	t_list	*temp;

	len_tab = 0;
	temp = *lst_tab;
	while (temp)
	{
		len_tab++;
		temp = temp->next;
	}
	result->tab = malloc((len_tab) * sizeof(int));
	if (!result->tab)
		handle_error(lst_tab);
	len_tab = 0;
	temp = *lst_tab;
	while (temp)
	{
		result->tab[len_tab++] = temp->content;
		temp = temp->next;
	}
	ft_lstclear(lst_tab, &delete_content);
	result->len = len_tab;
	return (result);
}

t_parse_list	*ft_parse(int argc, char **argv)
{
	t_list			*lst_tab;
	t_parse_list	*result;
	int				i;

	lst_tab = NULL;
	i = 1;
	while (i < argc)
	{
		ft_add_arg(&lst_tab, argv[i++]);
	}
	result = malloc(sizeof(t_parse_list));
	if (!result)
		handle_error(&lst_tab);
	return (ft_copy_lst_tab(&lst_tab, result));
}
